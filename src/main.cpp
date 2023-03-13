#include <Arduino.h>
#include <WiFi.h>

#define WIFI_SSID "WIFI_NAME"
#define WIFI_PASSWORD "WIFI_PASSWORD"

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("starting");
}

bool isConnected = false;

void loop()

{
  if (WiFi.status() == WL_CONNECTED && !isConnected)
  {
    Serial.println("Connected");
    digitalWrite(LED_BUILTIN, HIGH);
    isConnected = true;
  }
  if (WiFi.status() != WL_CONNECTED)
  {
    isConnected = false;
    Serial.println(".");
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(1000);
  }
}