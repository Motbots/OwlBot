/* ------------------------------------------------------------------------------
 * Project: OwlBot: The Bird Intimidator - Part 5: Mechanical Movement
 * Written by: Dustin Hodges (Motbots)
 * Date Created: 10/11/2024
 * Date Last Modified: 03/22/2025
 * Description: This is part five of the OwlBot project and its prototype process. Here, we
 * are adding to our code from Part 3 of the build the ability to activate two solenoids
 * simultaneously and to spin a propeller on a DC motor when motion is detected by a PIR
 * sensor that was added to the prototype in Part 1 of the build process.
 *
 * Microcontroller Board: Arduino Uno R3
 * IDE Version: Arduino IDE 2.3.4
 * Modules Used: HC-SR501 PIR sensor, DFRobot DFPlayer Pro Mini MP3 Player
 * Components Used: 2x Flat Top Clear Lens Red LEDs, 2x RFP30N06 MOSFETs, 1x IRF840 MOSFET,
 *                  2X 6V linear solenoids, 1x DC motor
 *
 * ------------------------------- REFERENCES -----------------------------------
 *
 * Solenoid Reference: Matt Inglot (YouTube): "Control a Solenoid with an Arduino (Tutorial)"
 * URL: https://www.youtube.com/watch?v=nwVRMU9grSI
 *
 * DC Motor Reference: Science Buddies (YouTube): "Control a DC Motor with Arduino (Lesson #16)"
 * URL: https://www.youtube.com/watch?v=XrJ_zLWFGFw
 *
 * Arduino "Multitasking" Reference: Amrit Aryal (YouTube): "How to do multiple tasks in Arduino |
 * Beginners | millis() function"
 * URL: https://www.youtube.com/watch?v=Ol6x5mjeu4w
 *
 * DFPlayer Pro Reference 1: Toms Trains and Things (YouTube): “How I Setup & Program DFPlayer
 * Pro With Arduino Uno”
 * URL: https://www.youtube.com/watch?v=Ct8sVkWTptU
 *
 * DFPlayer Pro Reference 2: ModelSceneryTutorials (YouTube): “DFPlayer Pro Voice Prompt Removal:
 * A Comprehensive Tutorial To Unlocking the Full Potential”
 * URL: https://www.youtube.com/watch?v=dMyJDyrESxQ
 *
 * DFPlayer Mini Reference 1: Rachel De Barros (YouTube): "Motion-activated Sound Effects with
 * Arduino, PIR Sensor & MP3 Player"
 * URL: https://www.youtube.com/watch?v=mL0epDFNHqY
 *
 * DFPlayer Mini Reference 2: The Last Outpost Workshop (YouTube): “Sound problems with the
 * MP3-TF-16p DFPlayer Mini?”
 * URL: https://www.youtube.com/shorts/0lyhvAHV20k
 *
 * ------------------------------------------------------------------------------
 */

#include <DFRobot_DF1201S.h> // The DFRobot_DF1201S library for the DFPlayer Pro Mini MP3 Player
#include <SoftwareSerial.h>  // The SoftwareSerial library allows serial communication on
                             // other digital pins of an Arduino board.

/* The follwing is the initial setup of variables for the HC-SR051 PIR sensor. */
const int PIR = 12;          // Signal pin from PIR sensor to pin 12 on Arduino
const int RX = 3;            // This is what we'll designate as the RX pin on the Arduino (not the DF0768's RX pin)
const int TX = 2;            // This is what we'll designate as the TX pin on the Arduino (not the DF0768's TX pin)
int motionStatus = LOW;      // Current motion status or signal pin reading (0 = LOW, 1 = HIGH). Initially set to 0 or LOW.
int pirState = LOW;          // The state of the PIR signal pin (HIGH/LOW). Initially set to LOW.

SoftwareSerial soundFxSerial(RX, TX);   // Creating an object for our sound effects serial, saying which pins to use
                                        // for receiving (RX) and transmission (TX).
                                        // The SoftwareSerial is used to communicate with the DFPlayer Pro module.
DFRobot_DF1201S soundFxPlayer;          // We'll use this object when referring to the sound effects player (MP3 player).

/* The following is the initial setup of the variables for the OwlBot's blinking LED eyes. */
const int LEFT_EYE = 4;    // Red LED pin 4, for the owl's left eye (arbitrary).
const int RIGHT_EYE = 5;   // Red LED pin 5, for the owl's right eye (arbitrary).

/* The following is the initial setup of the variables for the owl's solenoid wings. */
const int LEFT_WING = 7;   // Will be an output pin from Arduino to control the owl's left wing (arbitrary) using a solenoid.
const int RIGHT_WING = 8;  // Will be an output pin from Arduino to control the owl's right wing (arbitrary) using a solenoid.
unsigned long prevTime_1, prevTime_2 = millis(); // Both variables will be used as a previous time mark used in code later for multitasking.
const long TIME_INTERVAL_1 = 250;                // Variable for a time interval initiallized to 250 (later for 250 milliseconds)
const long TIME_INTERVAL_2 = 750;                // Variable for a time interval initiallized to 750 (later for 750 milliseconds)

/* The following is the initial setup of the variable for the owl's propeller. */
const int PROPELLER = 9;

/* The setup function does all the initial setting up of everything we need. When code is
 compiled and ran, the setup function is only entered into during processing once. */                                    
void setup() {
    // Pin modes
    pinMode(PIR, INPUT);            // Pin 12 on Arduino (signal line from PIR) is set as an input pin.
    pinMode(RX, INPUT);             // Our receiving pin for the Arduino needs to be an input.
    pinMode(TX, OUTPUT);            // Our transmission pin for the Arduino needs to be an output.
    pinMode(LEFT_EYE, OUTPUT);      // Make pin for left eye of owl (red LED pin 4) an output.
    pinMode(RIGHT_EYE, OUTPUT);     // Make pin for right eye of owl (red LED pin 5) an output.
    pinMode(LEFT_WING, OUTPUT);     // Make pin for left wing of owl an ouput.
    pinMode(RIGHT_WING, OUTPUT);    // Make pin for right wing of owl an ouput.
    pinMode(PROPELLER, OUTPUT);     // Make pin for propeller of owl an output.

    // Initially turn off both eyes, both wings, and propeller of the owl.
    digitalWrite(LEFT_EYE, LOW);
    digitalWrite(RIGHT_EYE, LOW);
    digitalWrite(LEFT_WING, LOW);
    digitalWrite(RIGHT_WING, LOW);
    digitalWrite(PROPELLER, LOW);
    
    // Serial setup
    Serial.begin(115200);               // Want to be able to use Serial Monitor for debugging purposes.
    soundFxSerial.begin(115200);        // Setting up the serial for the sound effects serial.
    soundFxPlayer.begin(soundFxSerial); // Telling the sound effects player to use the sound effects serial.

    // Player setup
    soundFxPlayer.setVol(30);                           // Set volume for the sound effects player.
    soundFxPlayer.switchFunction(soundFxPlayer.MUSIC);  // Enter music mode.
    soundFxPlayer.setPrompt(false);                     // Silence voice prompt at start.
    delay(2000);                                        // Delay for two seconds to allow everything to calibrate before proceeding.
    soundFxPlayer.setPlayMode(soundFxPlayer.ALLCYCLE);  // Set playback mode to "repeat all"
}

/* The loop function is an infinite loop, meaning once the code is compiled and ran, the
 processes of the code will continually run what's within the loop, until the processes are
 stopped, either within the code, or by the user, or by some other act of God. */
void loop() {
    motionStatus = digitalRead(PIR);  // Get the motion status from pin 12 (Is the signal HIGH or LOW?)
    
    /* If there's motion detected by the PIR sensor, do what's inside the loop. */
    if(motionStatus == HIGH) {
        // If the pirState is LOW (it's initially set to LOW)
        if(pirState == LOW) {
            Serial.println("Motion has been detected!");  // Print message to serial monitor.
            /* Going to need to change the pirState to HIGH, since motion has been detected. */
            pirState = HIGH;

            if(!soundFxPlayer.isPlaying()) {  // If the owl FX not playing...
              playOwl();                      // Play the owl MP3 audio.
            }
        }
    }
    /* Else, if no motion has been detected by the PIR sensor, do what's inside here: */
    else {
        // If the pirState is HIGH
        if(pirState == HIGH) {
            Serial.println("No motion detected.");  // Print message to serial monitor.
            /* Going to need to change the pirState to LOW, since no motion has been detected. */
            pirState = LOW;

            if(soundFxPlayer.isPlaying()) { // If the owl FX is still playing...
              pauseOwl();                   // Make absolute sure we pause the owl.
            }
        }
    }
}

/* The playOwl() function is called when we want to play the owl MP3 file to make owl sounds. */
void playOwl() {
  uint16_t fileNum = soundFxPlayer.getCurFileNumber();  // Getting the current file number in our MP3
                                                        // player and setting it to the variable 'fileNum'.
  soundFxPlayer.playFileNum(1);   // Play file #1, the numbers are arranged according to the sequence
                                  // of the files copied into the U-disk.
  soundFxPlayer.setPlayTime(0);   // Starts the file 0 seconds in (or at the very beginning).
  soundFxPlayer.start();          // Start playing sound FX.
  blinkEyes();                    // Blink the owl's spooky eyes.
  delay(250);                     // Wait 250 milliseconds (1/4 second)
  pauseOwl();                     // Pause the owl's FX as soon as we're done playing the FX.
}

/* The pauseOwl() function is called when we need to pause the audio playing from the MP3 file. */
void pauseOwl() {
  soundFxPlayer.pause();          // Pause the sound FX player.
}

/* The blinkEyes() function blinks the OwlBot's red LED eyes at a rapid pace for approximately 10 seconds or so. */
void blinkEyes() {
  delay(250); // Wait 250 milliseconds (1/4 second)

  for(int i = 0; i < 5; i++) {    // Do this loop ten times.
    for(int j = 4; j > 0; j--) {  // Do this loop four times.
      unsigned long currentTime = millis();

      digitalWrite(LEFT_EYE, HIGH);   // Turn left eye on.
      digitalWrite(RIGHT_EYE, HIGH);  // Turn right eye on.
      delay(125);                     // Wait 125 milliseconds (1/8 second)

      if(currentTime - prevTime_2 > TIME_INTERVAL_2) {
          spinPropeller();
          prevTime_2 = currentTime;
      }

      if(currentTime - prevTime_1 > TIME_INTERVAL_1) {
        flapWings();
        prevTime_1 = currentTime;
      }

      digitalWrite(LEFT_EYE, LOW);  // Turn left eye off.
      digitalWrite(RIGHT_EYE, LOW); // Turn right eye off.
      delay(125);                   // Wait 125 milliseconds (1/8 second)
    }
  }
}

/* The flapWings() function activates the two solenoids used for the OwlBots wings. The solenoids create the mechanical
   movement needed to move the OwlBot's faux wings, creating a "life-like" action for the OwlBot. */
void flapWings() {
  digitalWrite(LEFT_WING, HIGH);    // Flap left wing.
  digitalWrite(RIGHT_WING, HIGH);   // Flap right wing.
  delay(150);

  digitalWrite(LEFT_WING, LOW);     // Stop flapping left wing.
  digitalWrite(RIGHT_WING, LOW);    // Stop flapping right wing.
  delay(150);
}

/* The spinPropeller() function activates the DC motor to create an extra form of movement for the OwlBot by spinning
   a propeller mounted on the motor's shaft. */
void spinPropeller() {
  digitalWrite(PROPELLER, HIGH);
  delay(250);
  digitalWrite(PROPELLER, LOW);
  delay(250);
}