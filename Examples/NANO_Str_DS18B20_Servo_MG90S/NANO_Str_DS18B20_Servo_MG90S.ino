/*
   NANO Strong DS18B20 sensor shield with servo MG90
   BYala Robots Club
   eng.Anton Anchev , may 2015
*/
#include <Servo.h>

#define servo 5                                // асоциираме servo с пин D5

Servo myservo;                                 // създаване на обект servo за управление на servo mottor

int servoPosition = 90;                       // променлива за задаване на ъгъла на завъртане на сервомотора

// ================= SETUP =====================
void setup()
{
  myservo.attach(servo);                       // свързване на пин D5  към серво обекта
}

// ================== LOOP ====================
void loop()
{
  myservo.write(servoPosition);               // задава ъгъла на завъртане на серво мотора
  delay(20);
}
