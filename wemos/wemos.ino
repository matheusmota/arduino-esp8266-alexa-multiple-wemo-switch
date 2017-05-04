#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <functional>
#include "Switch.h"
#include "UpnpBroadcastResponder.h"
#include "CallbackFunction.h"

// prototypes
boolean connectWifi();

//on/off callbacks 
void officeLightsOn();
void officeLightsOff();
void kitchenLightsOn();
void kitchenLightsOff();

// Change this before you flash
const char* ssid = "ilheus";
const char* password = "7332318430";

boolean wifiConnected = false;

UpnpBroadcastResponder upnpBroadcastResponder;

Switch *switch1 = NULL;
Switch *switch2 = NULL;

void setup()
{
  Serial.begin(9600);
   
  // Initialise wifi connection
  wifiConnected = connectWifi();
  
  if(wifiConnected){
    upnpBroadcastResponder.beginUdpMulticast();
    
    // Define your switches here. Max 14
    // Format: Alexa invocation name, local port no, on callback, off callback
    switch1 = new Switch("light", 80, switch1_on, switch1_off);
    switch2 = new Switch("fan", 81, switch2_on, switch2_off);

    Serial.println("Adding switches upnp broadcast responder");
    upnpBroadcastResponder.addDevice(*switch1);
    upnpBroadcastResponder.addDevice(*switch2);
  }
}
 
void loop()
{
   if(wifiConnected){
      upnpBroadcastResponder.serverLoop();
      
      switch1->serverLoop();
      switch2->serverLoop();
   }
}

void switch1_on() {
    Serial.print("Switch 1 turn on ...");
}

void switch1_off() {
    Serial.print("Switch 1 turn off ...");
}

void switch2_on() {
    Serial.print("Switch 2 turn on ...");
}

void switch2_off() {
  Serial.print("Switch 2 turn off ...");
}

// connect to wifi – returns true if successful or false if not
boolean connectWifi(){
  boolean state = true;
  int i = 0;
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting ...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 10){
      state = false;
      break;
    }
    i++;
  }
  
  if (state){
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("");
    Serial.println("Connection failed.");
  }
  
  return state;
}
