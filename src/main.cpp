#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4
#define DHTTYPE DHT11
DHT_Unified dht(DHTPIN, DHTTYPE);


void setup() {
    dht.begin();
    Serial.begin(9600);
}

void loop() {
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    Serial.print("Temperature (C): ");
    Serial.println(event.temperature);
    dht.humidity().getEvent(&event);
    Serial.print("Humidity (%): ");
    Serial.println(event.relative_humidity);
    delay(2000);
}
