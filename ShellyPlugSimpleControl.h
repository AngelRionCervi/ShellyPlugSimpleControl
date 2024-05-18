#include <unordered_map>
#include <map>
#include <ArduinoHttpClient.h>
#include "WiFi.h"
#include "ShellyPlug.h"

class ShellyPlugSimpleControl {
private:
  WiFiClient wifiClient;
public:
  std::unordered_map<std::string, ShellyPlug> shellies;
public:
  ShellyPlugSimpleControl(WiFiClient _wifiClient);
  void setPlug(const char* name, bool _state);
  ShellyPlug getInfo(const char* name);
  void addShellyPlug(const char* name, const char* address, int port = 80);
};
