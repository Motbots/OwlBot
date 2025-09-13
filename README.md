![GitHub_How to Make an OwlBot_The Bird Intimidator](https://github.com/user-attachments/assets/4dcf55fe-17c7-4249-aaab-37bc04a30ba7)

# How to Make an OwlBot: The Bird Intimidator

Welcome to the OwlBot project series! The OwlBot is a device that can be used as a bird intimidation tool to scare away pesky birds in the yard,
around the house or barn, at restaurants, or in trees, bushes, and gardens. Hence, the phrase, “The Bird Intimidator”.

The OwlBot (a.k.a. “The Bird Intimidator”) has been done in several parts. The OwlBot is an ambitious project. When complete, the OwlBot will sense motion. When motion is detected,
the OwlBot should make owl sounds, perform varying movements, and flash its red eyes to intimidate and scare away pests. I’ve split each process we want the OwlBot to do into easy to accomplish chunks or parts.

## A Multi-Part Series

As of writing this, the OwlBot is currently in its 5th part in this multi-part series for this project. <strong><ins>Part 5 of this build series is the part where all of the code is complete for the OwlBot</ins>.</strong> Any parts after this
are to finish the OwlBot as a whole. There's a lot to do to create the OwlBot, so the process has been divided into certain tasks along the way on the Motbots website. Those individual tasks to develop the OwlBot are as follows:

* <strong>Motion Sensing</strong>
* <strong>Making Sounds</strong>
* <strong>Flashing Red LED Eyes</strong>
* <strong>Upgrading the Power Supply</strong>
* <strong>Mechanical Movement</strong>

All of the OwlBot's functionality is controlled by an Arduino Uno. The code that has been provided here is for each part of the process of providing those certain tasks listed in the bullet-points above. You may observe
the entire, detailed build process of this project on the Motbots page titled <a href="https://motbots.com/the-owlbot-project/" rel="noopener noreferrer nofollow" target="_blank"><em>The OwlBot Project Series</em></a>.

## The Parts of Code

### owlbot_part_1

The Arduino code for <a href="https://github.com/Motbots/owlbot-remote/blob/main/owlbot_part_1/owlbot_part_1.ino" rel="noopener noreferrer nofollow" target="_blank">owlbot_part_1</a> is for Part 1 of the OwlBot project series.
Here, we begin the prototyping process of the OwlBot on the breadboard, discuss the HC-SR501 motion sensor that we're using to capture infrared motion for this project, as well as go over the Arduino Uno itself and the code
we write for it to begin the initial characteristic of the OwlBot's ability to "see" motion. The following bullet-points show topics of discussion given in 
<a href="https://motbots.com/owlbot-part-1-motion-sensing/" rel="noopener noreferrer nofollow" target="_blank">Part 1 of this OwlBot series on the Motbots website</a>:

* Goal of Part 1 of the OwlBot Project
* The HC-SR501 PIR Sensor
* The Arduino Uno (ATmega328P)
* Parts List
* Tools Used in Project
* Prototyping the Circuit
* Programming the Arduino to Sense Motion
* The Code Explained
* Compiling and Uploading the Code to Arduino
* Testing What We’ve Done
* <a href="https://youtu.be/bw8tSOb7NII?si=EdZKsQBFnZmqqt3q" rel="noopener noreferrer nofollow" target="_blank">Video Build of the OwlBot: Part 1 – Motion Sensing</a>

### owlbot_part_2

The Arduino code for <a href="https://github.com/Motbots/owlbot-remote/blob/main/owlbot_part_2/owlbot_part_2.ino" rel="noopener noreferrer nofollow" target="_blank">owlbot_part_2</a> is for Part 2 of the OwlBot project series.
Here, we add to our OwlBot prototype circuit the ability to make owl sounds using a DFPlayer Pro Mini MP3 Player. The following bullet-points show topics of discussion given in 
<a href="https://motbots.com/owlbot-part-2-making-sounds/" rel="noopener noreferrer nofollow" target="_blank">Part 2 of this OwlBot series on the Motbots website</a>:

* Goal of Part 2 of the OwlBot Project
* DFPlayer Pro Mini MP3 Player
* Parts List
* Tools Used
* Prototyping the Circuit
* Soldering the Header Pins to the DFPlayer Pro
* Connecting the DFPlayer Pro for Sound
    - <a href="https://motbots.com/owlbot-part-2-making-sounds/#Step_7_%E2%80%93_Loading_an_MP3_File_Onto_the_DFPlayer_Pro" rel="noopener noreferrer nofollow" target="_blank">Loading an MP3 File Onto the DFPlayer Pro</a>
      - <a href="https://freesound.org/people/CGEffex/sounds/92640/" rel="noopener noreferrer nofollow" target="_blank">MP3 file location</a> (Owl Sound)
* Programming the Arduino to Make Sounds
* The Code Explained
* Compiling and Uploading the Code to Arduino
* Testing What We’ve Done
* Improving Sound Quality on the DFPlayer Pro
* <a href="https://youtu.be/DLSxWn_sw-k?si=D45K4992JyC8iMPl" rel="noopener noreferrer nofollow" target="_blank">Video Build of the OwlBot: Part 2 – Making Sounds</a>

### owlbot_part_3

The Arduino code for <a href="https://github.com/Motbots/owlbot-remote/blob/main/owlbot_part-3/owlbot_part-3.ino" rel="noopener noreferrer nofollow" target="_blank">owlbot_part_3</a> is for Part 3 of the OwlBot project series.
Here, we add to our OwlBot prototype the characteristic of having red LED eyes. In code, we get the Arduino to flash its red LED eyes when motion is detected by the PIR sensor we added in Part 1 of this build series.
The following bullet-points show topics of discussion given in <a href="https://motbots.com/owlbot-part-3-flashing-red-led-eyes/" rel="noopener noreferrer nofollow" target="_blank">Part 3 of this OwlBot series on the Motbots website</a>:

* Goal of Part 3 of the OwlBot Project
* Flat Top Clear Lens Red LEDs
* Parts List
* Tools Used
* Adding the LEDs to the Prototype
* Programming the Arduino to Flash the LEDs
* The Code Explained
* Compiling and Uploading the Code to Arduino
*  <a href="https://youtu.be/7eB6UiLbll4?si=xMIFs4B75650DUFA" rel="noopener noreferrer nofollow" target="_blank">Video Build of the OwlBot: Part 3 – Flashing Red LED Eyes</a>

### No Code for Part 4

There is no code for Part 4 of this project series. In Part 4 of the OwlBot project, we go over the power supply of our prototype circuit and learn how we can upgrade it to make sure that all our components and modules in our
circuit function properly by having their correct supply voltages. The following bullet-points show topics of discussion given in
<a href="https://motbots.com/owlbot-part-4-upgrading-the-power-supply/" rel="noopener noreferrer nofollow" target="_blank">Part 4 of this OwlBot series on the Motbots website</a>:

* Power Supply Dilemma
* Choosing a More Suitable Power Source
* Forming a Common Ground
* Connecting the Secondary Power Supply
* <a href="https://youtu.be/7f1Q-0OhCE8?si=3w0HYCl59netleqQ" rel="noopener noreferrer nofollow" target="_blank">Video Build of the OwlBot: Part 4 – Upgrading the Power Supply</a>

### owlbot_part_5

The Arduino code for <a href="https://github.com/Motbots/owlbot-remote/blob/main/owlbot_part_5/owlbot_part_5.ino" rel="noopener noreferrer nofollow" target="_blank">owlbot_part_5</a> is for Part 5 of the OwlBot project series.
Here, we add to our OwlBot prototype its ability to perform mechanical movement with the use of a DC motor and a couple of solenoids. The following bullet-points show topics of discussion given in
<a href="https://motbots.com/owlbot-part-5-mechanical-movement/" rel="noopener noreferrer nofollow" target="_blank">Part 5 of this OwlBot series on the Motbots website</a>:

* Goal of Part 5 of the OwlBot Project
* Solenoids
* DC Motor w/ Propeller
* Parts List
* Tools Used
* Arduino Uno’s ATmega328P Absolute Max Ratings
* Adding the Solenoids
* Adding the DC Motor w/ Propeller
* Solenoids and DC Motor Connections
* Programming the Arduino to Activate the Solenoids and Spin the Motor
* The Code Explained
* Compiling and Uploading the Code to Arduino
* <a href="https://youtu.be/BIOF-xTXSRM?si=6nCQOtiWt_tYTOxd" rel="noopener noreferrer nofollow" target="_blank">Video Build of the OwlBot: Part 5 – Mechanical Movement</a>

### No Code for Part 6 (Sections I & II)

There is no code for either section of Part 6 of this project series. In Part 6 of the OwlBot project, we transfer our components from the breadboard prototype circuit, to the PCB. Part 6 is divided into two sections:

* Section I: Here we began the process of preparing the Arduino shield board for power, and we solder the MP3 player in place. We also transfer the resistors we used on our breadboard prototype circuit to the shield board, as well as make our own wire connectors for the red LED eyes of the OwlBot. You can find the entire process and instructions for <a href="https://motbots.com/owlbot-part-6-section-1-pcb-circuit-build/" rel="noopener noreferrer nofollow" target="_blank">Part 6, Section I of the OwlBot project on the Motbots website</a>.
* Section II: This is where we finish up the process of transferring our components from the breadboard prototype circuit to our PCBs. We continue the process of making wire connectors and begin making connections for the speakers to the MP3 player. We use the help of a smaller PCB to hold all the components we used on the breadboard prototype circuit to control things like the solenoids and the DC motor. This section is where we finish up all the permanent wiring we need to have a working circuit for the OwlBot before we move on to placing all of our circuitry into the owl figure we will use as the body of the OwlBot.

## The OwlBot Project Series

You may find The OwlBot Project Series, in its entirety at the <a href="https://motbots.com/the-owlbot-project/" rel="noopener noreferrer nofollow" target="_blank">Motbots website here.
