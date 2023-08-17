#include "ShellyPlugSimpleControl.h"

ShellyPlugSimpleControl::ShellyPlugSimpleControl(WiFiClient wifiClient) {
  _wifiClient = wifiClient;
}

void ShellyPlugSimpleControl::setPlug(char name[], bool state) {
  ShellyPlug shelly = shellies.at(name);
  shelly.setState(state);
}

void ShellyPlugSimpleControl::addShellyPlug(char name[], char address[], int port) {
  HttpClient httpClient = HttpClient(_wifiClient, address, port);

  ShellyPlug newShellyPlug(address, port, httpClient);
  shellies.emplace(name, newShellyPlug);
}

ShellyPlug ShellyPlugSimpleControl::getInfo(char name[]) {
  return shellies.at(name);
}
