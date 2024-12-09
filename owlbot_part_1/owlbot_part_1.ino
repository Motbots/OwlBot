/* ------------------------------------------------------------------------------
 * Project: OwlBot: The Bird Intimidator - Part 1: Motion Sensing
 * Written by: Dustin Hodges (Motbots)
 * Date Created: 10/11/2024
 * Date Last Modified: 12/08/2024
 * Description: This is part one of the OwlBot project and its prototype process. Here, we
 * are starting out getting the OwlBot to sense infrared motion from its surroundings
 * using an HC-SR051 PIR sensor. The following is the code written for an Arduino Uno.
 *
 * Microcontroller Board: Arduino Uno R3
 * IDE Version: Arduino IDE 2.3.4
 * Modules Used: HC-SR501 PIR sensor
 *
 * PIR Sensor Code Reference: Rachel De Barros (YouTube): "Motion-activated Sound Effects with
 * Arduino, PIR Sensor & MP3 Player"
 * ------------------------------------------------------------------------------
 */

#include <SoftwareSerial.h>  // The SoftwareSerial library allows serial communication on
                             // other digital pins of an Arduino board.

/* The follwing is the initial setup of variables for the HC-SR051 PIR sensor. */
const int PIR = 12;          // Signal pin from PIR sensor to pin 12 on Arduino
int motionStatus = LOW;      // Current motion status or signal pin reading (0 = LOW, 1 = HIGH).
                             // Initially set to 0 or LOW.
int pirState = LOW;          // The state of the PIR signal pin (HIGH/LOW). Initially set to LOW.

/* The setup function does all the initial setting up of everything we need. When code is
 compiled and ran, the setup function is only entered into during processing once. */                                    
void setup() {
    // Pin modes
    pinMode(PIR, INPUT);      // Pin 12 on Arduino (signal line from PIR) is set as an input pin.
    
    // Serial setup
    Serial.begin(9600);       // Want to be able to use Serial Monitor for debugging purposes.
    
    delay(2000);              // Delay for two seconds to allow everything to calibrate before
                              // proceeding.
}

/* The loop function is an infinite loop, meaning once the code is compiled and ran, the
 processes of the code will continually run what's within the loop, until the processes are
 stopped, either within the code, or by the user, or by some other act of God. */
void loop() {
    motionStatus = digitalRead(PIR);  // Get the motion status from pin 12 (Is the signal HIGH
                                      // or LOW?)
    
    /* If there's motion detected by the PIR sensor, do what's inside the loop. */
    if(motionStatus == HIGH) {
        // If the pirState is LOW (it's initially set to LOW)
        if(pirState == LOW) {
            Serial.println("Motion has been detected!");  // Print message to serial monitor.
            /* Going to need to change the pirState to HIGH, since motion has been detected. */
            pirState = HIGH;
        }
    }
    /* Else, if no motion has been detected by the PIR sensor, do what's inside here: */
    else {
        // If the pirState is HIGH
        if(pirState == HIGH) {
            Serial.println("No motion detected.");        // Print message to serial monitor.
            /* Going to need to change the pirState to LOW, since no motion has been detected. */
            pirState = LOW;
        }
    }
}