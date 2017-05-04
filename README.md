# Esp8266 Multiple Belkin Wemo Switch Emulator

This project aims at emulating up to 14 Belkin Wemo Switches on a single ESP8266 chip. 
The software creates multiple servers on different ports and mimics a Wemo Switch protocol on each. 
Later, smart devices like Amazon's Alexa/Echo/Dot are able to broadcast/find such "devices"(emulated) and control them.

## How to use:
1. Download/clone the code;
2. Open the file wemos.ino in the Arduino editor;
2. Change the WI-FI settings;
3. Define switches, corresponding pins, and callbacks;
3. Flash;
4. Enjoy.



### Articles about the Wemos switch

* [monkeytypewritr](https://medium.com/@monkeytypewritr/amazon-echo-esp8266-iot-a42076daafa5#.oc4od1xa0)


### Credits

- [makermusings](https://github.com/makermusings/fauxmo)
- [Aruna Tennakoon](https://github.com/kakopappa) and others
- [arduino-esp8266-alexa-multiple-wemo-switch](https://github.com/kakopappa/arduino-esp8266-alexa-multiple-wemo-switch)
