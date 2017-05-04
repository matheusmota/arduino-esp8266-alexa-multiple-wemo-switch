#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <functional>
#include "Switch.h"
#include "UpnpBroadcastResponder.h"
#include "CallbackFunction.h"


// Change this before you flash
const char* ssid = "ssid";
const char* password = "password";

/***********
 Prototypes
*************/

//general
boolean connectWifi();


//on/off callbacks 
void switch1_on();
void switch1_off();
void switch2_on();
void switch2_off();


boolean wifiConnected = false;

UpnpBroadcastResponder upnpBroadcastResponder;

Switch *switch1    = NULL;
int     switch1Pin = D2;  // Pin to toggle
Switch *switch2 = NULL;
int     switch2Pin = D3;  // Pin to toggle

//Switch *switch3 = NULL;
//Switch *switch4 = NULL;

void setup()
{
  // Begin Serial:
  Serial.begin(115200);
   
  // Initialise wifi connection
  wifiConnected = connectWifi();
  
  if(wifiConnected){
    upnpBroadcastResponder.beginUdpMulticast();
    
    // Define your switches here. Max 14
    // Format: Alexa invocation name, local port no, on callback, off callback
    switch1 = new Switch("light", 80, switch1_on, switch1_off);
    pinMode(switch1Pin, OUTPUT);
    digitalWrite(switch1Pin, HIGH);  // Start with switch on -- change to LOW for off
        
    switch2 = new Switch("fan", 81, switch2_on, switch2_off);
    pinMode(switch2Pin, OUTPUT);
    digitalWrite(switch2Pin, HIGH);  // Start with switch on -- change to LOW for off

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
    digitalWrite(switch1Pin, LOW); // turn on relay with voltage LOW (depends on your setup)

}

void switch1_off() {
    Serial.print("Switch 1 turn off ...");
    digitalWrite(switch1Pin, HIGH); // turn on relay with voltage HIGH (depends on your setup)

}

void switch2_on() {
    Serial.print("Switch 2 turn on ...");
    digitalWrite(switch2Pin, LOW); // turn on relay with voltage LOW (depends on your setup)
}

void switch2_off() {
  Serial.print("Switch 2 turn off ...");
  digitalWrite(switch2Pin, HIGH); // turn off relay with voltage HIGH (depends on your setup)

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
