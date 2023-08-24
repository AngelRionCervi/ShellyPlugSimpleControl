#include <ArduinoHttpClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"

class ShellyPlug {
public:
  char* address;
  int port = 80;
  bool state;
  bool hasInit = false;
  WiFiClient wifiClient;
public:
  ShellyPlug(char* _address, int _port, WiFiClient _wifiClient);
  void setState(bool _state);
  void init();
};
