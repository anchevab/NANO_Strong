/*
   NANO Strong DS18B20 sensor shield with servo MG90
   BYala Robots Club
   eng.Anton Anchev , may 2015
*/
#include <Servo.h>

Servo myservo;                                 // създаване на обект servo за управление на servo mottor

#define potpin A1                              // аналогов пин за потенциометъра
#define servo 5                                // асоциираме servo с пин D5  
int val;                                       // променлива за данните от аналоговия вход на потециометъра

// ================= SETUP =====================
void setup()
{
  myservo.attach(servo);                       // свързване на пин 9  към серво обекта
}

// ================== LOOP ====================
void loop()
{
  val = analogRead(potpin);                   // четене на стойностите от потециометъра (стойности между 0 и 1023)
  val = map(val, 0, 1023, 0, 179);            // ma]ab na izpolzwane na serwoto (0-180)
  myservo.write(val);                         // определя серво положение съгласно намалена стойност
  delay(20);
}
