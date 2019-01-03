/*
   Arduino NANO Strong with BMP180 temperature, pressure, altutide sensor
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
#include "Wire.h"
#include "Adafruit_BMP085.h"

Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);
  bmp.begin();
}

void loop() {
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  // Calculate altitude assuming 'standard' barometric
  // pressure of 1013.25 millibar = 101325 Pascal
  Serial.print("Altitude = ");
  Serial.print(bmp.readAltitude(102500));
  Serial.println(" meters");

  Serial.println();
  delay(500);
}
