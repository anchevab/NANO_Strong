/*
   Arduino NANO Strong DS18B20 shield with 4 digits 7 segment display
   Byala Robots Club
   Created by eng.Anton Anchev , april 2017
*/
#include "TM1637.h"
#include <OneWire.h>                      // библиотека, която ни дава възможност да комуникираме със сензори чрез 1 връзка (проводник)
#include <DallasTemperature.h>            // библиотека за управление на сензора DS18B20

//--------- дисплей
#define CLK 15
#define DIO 5
TM1637 tm1637(CLK, DIO);

//--------- сензор DS18B20
#define ONE_WIRE_BUS 7                    // дефиниране на сензора към пин 7 на Arduino NANO Strong
OneWire oneWire(ONE_WIRE_BUS);            // създаване на обект oneWire за комуникация със сезора DS18B20 чрез пин 7
DallasTemperature sensors(&oneWire);      // свързване на обектът oneWire с библиотеката.

#define PAUSE 60                        // пауза на програмата

// =========================== SETUP ===============================
void setup() {

  Serial.begin(9600);
  //  Serial.println("Read temperature from DS18B20");
  sensors.begin();
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);      //BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

// ========================== LOOP =================================
void loop() {

  sensors.requestTemperatures();                   // изпращане на команда за получаване на стойностт на температурата
  int temp = sensors.getTempCByIndex(0);
  //Serial.print("Temperature is: ");
  //Serial.println(temp);

  //-------- извеждане на температурата
  int temp1 = temp / 10;
  int temp2 = temp % 10;
  tm1637.display(0, temp1);
  tm1637.display(1, temp2);

  //-------- извеждане на oC
  setSegments(2, 0b1100011);               // извеждане на символ за градус
  setSegments(3, 0b0111001);               // извеждане на буква C
  delay(PAUSE);
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
