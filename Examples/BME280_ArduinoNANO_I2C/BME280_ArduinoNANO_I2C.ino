/*
   Arduino NANO Strong with BME280 temperature, humidity, pressure, altutide sensor
   Byala Robots Club
   eng.Anton Anchev

     wire .....
    BME 280        Arduino NANO
    ===========================
     VIN              +5V
     GND              GND
     SCL              A5
     SDA              A4
*/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1031)                              // задаване на атмосферното налягане на морското равнище (Варна) в деня, когато включваме сензора

Adafruit_BME280 bme;                                             // от Adafruit_BME280.h избираме обект bme за I2C комуникация

// ============================== SETUP ==================================
void setup() {
  Serial.begin(9600);
  bme.begin();
  Serial.println(F("BME280 test"));
}

// ============================== LOOP ==================================
void loop() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());                          // функцията readTemperature() измерва температурата
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);                    // функцията readPressure() измерва атмосферното налягане
  Serial.println(" hPa");

  Serial.print("Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));         // функцията readAltitude() измерва надморската височина
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());                             // функцията readHumidity() измерва температурата
  Serial.println(" %");

  Serial.println();
  delay(2000);
}
