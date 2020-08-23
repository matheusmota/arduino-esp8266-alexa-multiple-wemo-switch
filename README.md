# Esp8266 Multiple Belkin Wemo Switch Emulator

This project aims at emulating up to 14 Belkin Wemo Switches on a single ESP8266 chip. 
The software creates multiple servers on different ports and mimics a Wemo Switch protocol on each. 

Smart devices like Amazon's Alexa/Echo/Dot are able to broadcast/find the "devices" emulated and control[on/off] them according to your needs -- you can assing different tasks by implementing the callbacks.

We are assuming here that you already [flashed](https://nodemcu.readthedocs.io/en/master/en/flash/) your esp8266 device with [NodeMCU](http://nodemcu.com/index_en.html) firmware and [prepared the Arduino IDE to support esp8266 devices](http://www.instructables.com/id/Quick-Start-to-Nodemcu-ESP8266-on-Arduino-IDE/#intro)

## Preparing the environment
1. Download the Arduino IDE ( https://www.arduino.cc/en/Main/Software )
2. In the Arduino IDE, open File > Preferences and add `http://arduino.esp8266.com/stable/package_esp8266com_index.json` to the `Additional Board Managers URLs`
3. Open Tools > Board > Board Manager
4. Find and install the `esp8266` item
5. Set your ESP8266 board


## How to use:
1. Download/clone the code;
2. Open the file wemos.ino in the Arduino IDE;
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
