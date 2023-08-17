/*
  This sketch connects to the internet via WiFi,
  registers 2 shelly plugs and allows to simply control their on / off state.

  This example is written for a network using WPA encryption. For
  WEP or WPA, change the WiFi.begin() call accordingly.

  created 17 August 2023
  by AngelRionCervi
 */

#include "WiFiS3.h"
#include "arduino_secrets.h"
#include "ShellyPlugSimpleControl.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

int wifiStatus = WL_IDLE_STATUS;

WiFiClient wifiClient;

// initiate a ShellyPlugSimpleControl class instance
ShellyPlugSimpleControl shellyPlug = ShellyPlugSimpleControl(wifiClient);

void connectToWifiNetwork(char ssid[], char password[]) {
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true)
      ;
  }

  while (wifiStatus != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    wifiStatus = WiFi.begin(ssid, password);

    delay(3000);
  }

  Serial.print("Connected to: ");
  Serial.println(ssid);
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  // connect to WiFi
  connectToWifiNetwork(ssid, pass);

  // register 2 shelly plugs, 3 argument "port" is optional and defaults on 80
  // change ip / address accordingly
  shellyPlug.addShellyPlug("room heater", "192.131.9.23");
  shellyPlug.addShellyPlug("bedroom", "someplug/somewhere", 70);

  // prints the address of the registred "room heater" plug
  Serial.println(shellyPlug.getInfo("room heater").address);

  // switch on and off the room heater
  shellyPlug.setPlug("room heater", true);
  delay(5000);
  shellyPlug.setPlug("room heater", false);
}

void loop() {}
