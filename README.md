# Arduino-ESP8266

Since I worked with microcontrollers let them connect to the internet was one of my goals.
In this example I will show you how you can do that and more. We are going to use Thingspeak IoT cloud service for display the data.

You can even you this example to acquire ADC data and send it to Thingspeak for example Voltage level display, Temperature or Humidity levels through time.

![Image of Thingspeak data diplay](https://github.com/nicolaquartieri/Arduino-ESP8266/img/fielddata.png)

Features:
 * Update every 15sec with new data.

Materials: 
 1. Arduino Uno.
 2. ESP8266 ESP-12 ([on DX](http://www.dx.com/p/esp-12-esp8266-serial-wi-fi-wireless-module-w-built-in-antenna-compatible-3-3v-5v-for-arduino-403072#.WKRZxRIrKRs))
 3. USB cable to Arduino to PC.
 4. Flat cable to connect the Arduino to the ESP-12.
 
Toolchain
 * Arduino IDE.

OBS: For use this example you must create an Thingspeak account and get an "api_key" and then use it in the code.
```C
//Call service URL for Thingspeak: "api_key" must be acquired when you create an account.
char *prefix = "GET /update?api_key=YOUR-API_KEY&field1=";
```
