/*
   Arduino NANO Strong 4 digits 7 segment display witn light sensor
   Byala Robots Club
   Created by eng.Anton Anchev
   Byala, may 2015
*/
#include "TM1637.h"

#define CLK 15
#define DIO 5
#define PAUSE 50     // време за изчакване

TM1637 tm1637(CLK, DIO);            //  създаване на обект за комуникация с дисплея
int pot = 0;
int d0, d1, d2, d3;                // за получаванe на отделните цифри от стойността на потециометъра

// =========================== SETUP ===============================
void setup() {

  Serial.begin(9600);
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);            //BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
  for (int i = 0; i < 4; i++) {
    tm1637.display(i, 8);                // тест на дисплея
  }
  tm1637.clearDisplay();
}//

// ========================== LOOP =================================
void loop() {

  pot = analogRead(A0);            // потенциометър свързан с A0
  // --------------- разлагане на стойността от потенциометъра
  d3 = pot % 10;
  pot = pot / 10;
  d2 = pot % 10;
  pot = pot / 10;
  d1 = pot % 10;
  pot = pot / 10;
  d0 = pot % 10;
  //---------------- извеждане на цифри
  tm1637.display(0, d0);
  tm1637.display(1, d1);
  tm1637.display(2, d2);
  tm1637.display(3, d3);
  delay(PAUSE);
}
