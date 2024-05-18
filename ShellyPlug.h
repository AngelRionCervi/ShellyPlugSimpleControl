#include <ArduinoHttpClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"

class ShellyPlug {
public:
  const char* address;
  int port = 80;
  bool state;
  bool hasInit = false;
  WiFiClient wifiClient;
public:
  ShellyPlug(const char* _address, int _port, WiFiClient _wifiClient);
  void setState(bool _state);
  void init();
};
