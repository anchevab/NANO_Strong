/*
  Arduino NANO Strong BME280/BMP180 with Analog/Digital Moisture sensor
  Byala Robots Club
  author: Anton Anchev
  february, 2018

  # стойности на сензора
  # 0  ~300     във вода
  # 300~700     влажна почва
  # 700~950     суха почва
*/
#define analog_moisture A1
#define digit_moisture 5

// ================= SETUP ==================
void setup() {
  Serial.begin(9600);
}

// ================ LOOP ==================
void loop() {
  Serial.print("Moisture Sensor Analog Value: ");
  Serial.print(analogRead(analog_moisture));
  Serial.print("\t");
  Serial.print("Digital Value: ");
  Serial.println(digitalRead(digit_moisture));
  delay(100);
}
