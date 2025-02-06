
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6c8eoJi2L"
#define BLYNK_TEMPLATE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "YERNribqD5FNGaYiit1t4ePW5vnOHf_e"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(115200);

  // Инициализация датчика AHT10/AHT20
  if (!aht.begin()) {
    Serial.println("Could not find a valid AHT10/AHT20 sensor, check wiring!");
    while (1);
  }

  Blynk.begin(BLYNK_AUTH_TOKEN, "login", "passvord");
}

void sendSensorData() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  Blynk.virtualWrite(V5, temp.temperature);
  Blynk.virtualWrite(V6, humidity.relative_humidity);
}

void loop() {
  Blynk.run();
  sendSensorData();
  delay(100);
}
