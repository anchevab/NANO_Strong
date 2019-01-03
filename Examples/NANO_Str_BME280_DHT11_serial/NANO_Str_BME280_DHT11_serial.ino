/*
   NANO Strong BME280 shield with DHT11
   Byala Robots Club
   eng.A.Anchev , 2015
*/
#include "DHT.h"
#define DHTPIN 4                                           // пин 4 свързан към сензора
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ==================== SETUP =======================
void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();
}

// =================== LOOP ========================
void loop() {
  int h = dht.readHumidity();                               // прочитане на данни за влажността
  int t = dht.readTemperature();                            // прочитане на данни за температурата

  if (isnan(t) || isnan(h)) {                               //проверка дали прочетените стойности са числови стойности, ако не са значи има някакъв проблем
    Serial.println("Error on read DHT1 sensor");
  } else {
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C");
  }
  delay(1000);
}
