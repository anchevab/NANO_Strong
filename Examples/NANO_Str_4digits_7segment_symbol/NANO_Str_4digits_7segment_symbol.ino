/*
   NANO Strong 4 digits 7 segments display symbol test
   Byala Robots Club
   Author: eng.A.Anchev
   Byala, sptemebr, 2015
*/

#include "TM1637.h"

//--------- дисплей
#define CLK 15
#define DIO 5

TM1637 tm1637(CLK, DIO);

// ===================== SETUP =========================
void setup() {
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);      //BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

// ==================== LOOP ===========================
void loop() {
  setSegments(0, 0b1101101);               // извежда символ S
  setSegments(1, 0b1111001);               // извежда символ Е
  setSegments(2, 0b1100011);               // извеждане на символ за градус
  setSegments(3, 0b0111001);               // извеждане на буква C

}
//-------------------- SET SEGMENT функция за извеждане на символи ----------------
void setSegments(byte addr, byte data)
{
  tm1637.start();
  tm1637.writeByte(ADDR_FIXED);
  tm1637.stop();
  tm1637.start();
  tm1637.writeByte(addr | 0xc0);
  tm1637.writeByte(data);
  tm1637.stop();
  tm1637.start();
  tm1637.writeByte(tm1637.Cmd_DispCtrl);
  tm1637.stop();
}
