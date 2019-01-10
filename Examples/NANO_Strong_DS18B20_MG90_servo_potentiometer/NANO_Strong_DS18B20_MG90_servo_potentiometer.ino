/*
   NANO Strong DS18B20 sensor shield with servo MG90
   BYala Robots Club
   eng.Anton Anchev , may 2015
*/

#include <VarSpeedServo.h>

VarSpeedServo myservo;           // --- create servo object to control a servo

const int potPin = A1;           // ---- analog pin used to connect the potentiometer
const int servoPin = 5;          // ---- the digital pin used for the servo

int val;                         // ---- variable to read the value from the analog pin


void setup() {
  myservo.attach(servoPin);       // ---- attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potPin);            // ---- reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // ---- scale it to use it with the servo (value from 0 and 180)
  myservo.write(val);                  // ---- sets the servo position according to the scaled value
  delay(15);                           // ---- waits a bit before the next value is read and written
}
