#include <VarSpeedServo.h>

// -------- create servo object to control a servo
VarSpeedServo myservo1;
// --------- VARIABLES
int LEF = 0;
int RIG = 180;
int SPEED = 0;

// =============== SETUP =================
void setup() {

  //Serial.begin(9600);
  myservo1.attach(5);
}

// =============== LOOP ==================
void loop() {
  int pot = analogRead(A1);
  SPEED = map(pot, 0, 1023, 70, 255);
  myservo1.write(LEF, SPEED);
  myservo1.wait();
  myservo1.write(RIG, SPEED);
  myservo1.wait();
  delay(15);
}
