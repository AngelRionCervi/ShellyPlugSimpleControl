#include <unordered_map>
#include <ArduinoHttpClient.h>
#include "WiFiS3.h"
#include "ShellyPlug.h"

class ShellyPlugSimpleControl {
private:
  WiFiClient _wifiClient;
public:
  std::unordered_map<std::string, ShellyPlug> shellies;
public:
  ShellyPlugSimpleControl(WiFiClient wifiClient);
  void setPlug(char name[], bool state);
  ShellyPlug getInfo(char name[]);
  void addShellyPlug(char name[], char address[], int port = 80);
};
