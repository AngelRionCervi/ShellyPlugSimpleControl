#include "ShellyPlugSimpleControl.h"

ShellyPlugSimpleControl::ShellyPlugSimpleControl(WiFiClient _wifiClient)
  : wifiClient(_wifiClient) {}

void ShellyPlugSimpleControl::setPlug(const char* name, bool _state) {
  ShellyPlug& shelly = shellies.at(name);
  shelly.setState(_state);
}

void ShellyPlugSimpleControl::addShellyPlug(const char* name, const char* address, int port) {
  ShellyPlug newShellyPlug(address, port, wifiClient);
  shellies.emplace(name, newShellyPlug);
  ShellyPlug& shelly = shellies.at(name);
  shelly.init();
}

ShellyPlug ShellyPlugSimpleControl::getInfo(const char* name) {
  return shellies.at(name);
}
