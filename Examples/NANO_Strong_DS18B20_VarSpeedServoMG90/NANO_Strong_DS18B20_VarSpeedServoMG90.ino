#include <VarSpeedServo.h>

// -------- create servo object to control a servo
VarSpeedServo myservo1;
// --------- VARIABLES
int LEF = 0;
int RIG = 180;
int SPEED1 = 100;
int SPEED2 = 100;

// =============== SETUP =================
void setup() {

  //Serial.begin(9600);
  myservo1.attach(5);
}

// =============== LOOP ==================
void loop() {

  myservo1.write(LEF, SPEED1);
  myservo1.wait();
  myservo1.write(RIG, SPEED1);
  myservo1.write(LEF, SPEED1);
  myservo1.wait();
  myservo1.write(RIG, SPEED1);
  myservo1.wait();
  delay(3000);
}
