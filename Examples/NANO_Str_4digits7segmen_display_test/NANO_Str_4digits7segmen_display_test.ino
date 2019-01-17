/*
   NANO Strong DS18B20 shield 4 digits 7 segment display
   Byala Robots Club
   Autho:eng.A.Anchev
   Byala,may,2016
*/
#include "TM1637.h"
#define CLK 15
#define DIO 5

TM1637 tm1637(CLK, DIO);        // обект за работа с дисплея

// ===================== SETUP ========================
void setup()
{
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

// ==================== LOOP ==========================
void loop()
{
  int8_t NumTab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};  //------- 0,1,2,3,4,5,6,7,8,9,A,b,C,d,E,F
  int8_t ListDisp[4];
  unsigned char i = 0;
  unsigned char count = 0;
  // ---- извеждане на цифри
  tm1637.display(0, 1);
  tm1637.display(1, 2);
  tm1637.display(2, 3);
  tm1637.display(3, 4);
  delay(2000);
  // ----- извеждане на букви
  tm1637.display(0, 10);
  tm1637.display(1, 11);
  tm1637.display(2, 12);
  tm1637.display(3, 13);
  delay(2000);
}
