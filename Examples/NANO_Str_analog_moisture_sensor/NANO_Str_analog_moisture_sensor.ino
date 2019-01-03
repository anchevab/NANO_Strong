/*
  Arduino NANO Strong BME280/BMP180 with Analog Moisture sensor
  Byala Robots Club
  author: Anton Anchev
  february, 2018
*/

#define moisture A0

// ==================== SETUP ===================
void setup() {
  Serial.begin(9600);
}

// =================== LOOP ======================
void loop() {
  int sensorValue = analogRead(moisture);
  Serial.println(sensorValue);
  delay(50);
}
