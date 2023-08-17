#include "ShellyPlug.h"

ShellyPlug::ShellyPlug(char _address[], int _port, HttpClient _httpClient)
  : address(_address), port(_port), httpClient(_httpClient) {}

void ShellyPlug::setState(bool state) {
  String stateParam = state ? "on" : "off";
  String request = String("/relay/0?turn=") + stateParam;

  httpClient.get(request);
}