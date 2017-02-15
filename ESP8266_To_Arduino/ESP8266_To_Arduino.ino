
#include "ESP8266.h"
#include <SoftwareSerial.h>

//Simulate UART for just the ESP8266 and let native UART (Serial) for Debbuging.
SoftwareSerial Serial1(3, 2); /* RX:D3, TX:D2 */
ESP8266 wifi(Serial1, 115200);

//Thingspeak.com IoT Cloud Service.
#define HOST_NAME   "184.106.153.149"
#define HOST_PORT   (80)

//Call service URL for Thingspeak: "api_key" must be acquired when you create an account.
char *prefix = "GET /update?api_key=&field1=";
char *postfix = " HTTP/1.1\r\nHost: 184.106.153.149\r\nConnection: close\r\n\r\n";

void setup(void) {
  Serial.begin(115200);

  Serial.print("Setup Begin...\r\n");

  Serial1.setTimeout(1000);

  delay(8000);

  Serial.print("Setup End.\r\n");
}

//Success call service count for debugging purpose.
int count = 0;

void loop(void) {
  while (!wifi.createTCP(HOST_NAME, HOST_PORT)) { //sATCIPSTARTSingle
    Serial.print("Created TCP: Error > Try Again!\r\n");
  }
  Serial.print("Created TCP: OK!\r\n");

  //Simulate ADC random numbers.
  String number_string = String(random(0, 10));
  String url = prefix + number_string + postfix;
  const char *url_complete = url.c_str();
  Serial.print("Call: " + url);

  while (!wifi.send((uint8_t*) url_complete, strlen(url_complete))) { //sATCIPSENDSingle
    Serial.println("Send: fail!");
  }
  count = count + 1;
  Serial.print("Send: Success! ");
  Serial.println(count);

  wifi.releaseTCP(); //eATCIPCLOSESingle
  Serial.println("################### End Loop ###################");
  
  //Thingspeak needs 15sec between each call.
  //Wait for 12.5sec + 3sec (sATCIPSTARTSingle + sATCIPSENDSingle + eATCIPCLOSESingle) = 15.5sec
  delay(12500);
}
