#include <ArduinoHttpClient.h>

class ShellyPlug {
public:
  char* address;
  int port = 80;
  HttpClient httpClient;
public:
  ShellyPlug(char _address[], int _port, HttpClient _httpClient);
  void setState(bool state);
};
