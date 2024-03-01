# FireAlert

## Overview

FireAlert is an Arduino-based project designed to detect flames using an infrared (IR) sensor. Originally developed during my senior high school days, this project serves as a proactive fire detection system. Upon detecting flames, FireAlert is programmed to send an immediate text notification to the owner and optionally initiate a call to a predefined number, which could be the fire station or the owner's emergency contact.

## Features
* Flame detection using an IR sensor
* Instant text notifications to the owner upon flame detection
* Call initiation to a predefined number (fire station or emergency contact)
* Audible alerts using a sound buzzer to notify nearby users

## Getting Started

To setup FireAlert, follow these steps

### Hardware Setup:

1. **Gather Components**: Collect the following components:
  * Arduino UNO R3 Board
  * IR Sensor
  * GSM SIM800L v2 module
  * Sound Buzzer
  * Male-Male Wires Jumper Wires
  * Male-Female Jumper Wires
  * Breadboard
  * Power Supply Adapter (or you can use any power supply generator you have)
2. **Connect components**: Refer to the provided schematic diagram to wire the components to the Arduino board properly.
    
![Picture1](https://github.com/Jaermis/FireAlert/assets/138207746/daa457f3-455b-421f-b05d-3faa40921683)

### Configuration

1. **Phone Number Setup**: Open the Arduino code (FireAlert.ino) in the Arduino IDE. Locate the section where the phone number for text notifications and call initiation is defined. Replace the placeholder phone number with the desired phone number.

2. **Optional Settings**: Modify any other settings in the code as per your requirements, such as notification thresholds or sensor sensitivity.

### Testing

1. **Power On**: Switch on FireAlert by supplying power to the Arduino board.
2. **Testing Flame Detection**: Place a flame source within the detection range of the IR sensor. Verify that FireAlert correctly detects the flame and initiates the notification and call process.
3. **Audible Alert Test**: Check if the sound buzzer provides audible alerts upon flame detection.

### Troubleshooting

* If FireAlert does not function as expected, double-check the connections according to the schematic diagram and ensure that all components are properly wired.
* Verify that the GSM SIM800L v2 module has an active SIM card with network coverage for text messaging and call initiation.

### Recommendation

While FireAlert is designed to detect flames using the IR sensor, I recommend the additional use of smoke and temperature sensors for maximum accuracy in fire detection. Although these sensors are not currently integrated into FireAlert, incorporating them in future iterations can enhance its capabilities and provide more comprehensive fire detection and alerting functionalities.

