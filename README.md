# How to Make an OwlBot: The Bird Intimidator

Welcome to the OwlBot project series! The OwlBot is a device that can be used as a bird intimidation tool to scare away pesky birds in the yard,
around the house or barn, at restaurants, or in trees, bushes, and gardens. Hence, the phrase, “The Bird Intimidator”.

The OwlBot (a.k.a. “The Bird Intimidator”) has been done in several parts. The OwlBot is an ambitious project. When complete, the OwlBot will sense motion. When motion is detected,
the OwlBot should make owl sounds, perform varying movements, and flash its red eyes to intimidate and scare away pests. I’ve split each process we want the OwlBot to do into easy to accomplish chunks or parts.

## A Multi-Part Series

As of writing this, the OwlBot is currently in its 5th part in this multi-part series for this project. There's a lot to do to create the OwlBot, so the process has been divided into certain tasks along the
way on the Motbots website. Those individual tasks to develop the OwlBot are as follows:

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
* Programming the Arduino to Make Sounds
* The Code Explained
* Compiling and Uploading the Code to Arduino
* Testing What We’ve Done
* Improving Sound Quality on the DFPlayer Pro
* <a href="https://youtu.be/DLSxWn_sw-k?si=D45K4992JyC8iMPl" rel="noopener noreferrer nofollow" target="_blank">Video Build of the OwlBot: Part 2 – Making Sounds</a>
