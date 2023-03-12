#include <Arduino.h>
#include <WiFiMulti.h>

#define WIFI_SSID "WIFI_NAME"
#define WIFI_PASSWORD "WIFI_PASSWORD"

WiFiMulti wifiMulti;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Hello from the setup");

  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);
  while (wifiMulti.run() != WL_CONNECTED)
  {
    delay(100);
    Serial.println("...");
  }

  Serial.println("Connected");
}

void loop()
{
  digitalWrite(LED_BUILTIN, WiFi.status() == WL_CONNECTED);
}