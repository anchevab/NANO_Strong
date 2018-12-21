/*
   NANO_Str_DS18B20_shield with temperature sensor
   Byala Robots Club
   author: eng.A.Anchev
   september, 2017, Byala
*/

#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>
#include <RemoteXY.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// ---- RemoteXY connection settings
#define REMOTEXY_SERIAL_RX 3
#define REMOTEXY_SERIAL_TX 2
#define REMOTEXY_SERIAL_SPEED 9600

#define ONE_WIRE_BUS 7
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// ---- RemoteXY configurate
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
{ 255, 0, 0, 12, 0, 252, 0, 8, 13, 1,
  130, 1, 2, 2, 59, 24, 123, 129, 0, 8,
  5, 46, 4, 50, 208, 161, 208, 181, 208, 189,
  208, 183, 208, 190, 209, 128, 32, 208, 183, 208,
  176, 32, 209, 130, 208, 181, 208, 188, 208, 191,
  208, 181, 209, 128, 208, 176, 209, 130, 209, 131,
  209, 128, 208, 176, 0, 129, 0, 12, 18, 40,
  4, 175, 208, 154, 208, 187, 209, 131, 208, 177,
  32, 34, 208, 160, 208, 190, 208, 177, 208, 190,
  209, 130, 208, 184, 45, 208, 145, 209, 143, 208,
  187, 208, 176, 34, 0, 129, 0, 19, 11, 26,
  6, 233, 68, 83, 49, 56, 66, 50, 48, 0,
  66, 132, 12, 44, 38, 30, 93, 36, 129, 0,
  5, 65, 4, 3, 36, 45, 49, 48, 0, 129,
  0, 9, 74, 4, 3, 36, 45, 50, 48, 0,
  129, 0, 8, 56, 2, 3, 36, 48, 0, 129,
  0, 11, 47, 4, 3, 36, 49, 48, 0, 129,
  0, 19, 40, 4, 3, 36, 50, 48, 0, 129,
  0, 29, 38, 3, 3, 36, 51, 48, 0, 129,
  0, 39, 40, 3, 3, 36, 52, 48, 0, 129,
  0, 48, 46, 3, 3, 36, 53, 48, 0, 129,
  0, 52, 55, 4, 3, 36, 54, 48, 0, 129,
  0, 52, 65, 4, 3, 36, 55, 48, 0, 129,
  0, 49, 74, 4, 3, 36, 56, 48, 0, 67,
  6, 18, 83, 20, 8, 93, 13, 11, 129, 0,
  38, 84, 7, 6, 93, 194, 176, 67, 0
};

// ---- Variables of your control interface
struct {

  // ---- output variable
  int8_t level_temp;        // =0..100 level position
  char text_temp[11];       // string UTF8 end zero

  // ---- other variable
  uint8_t connect_flag;     // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)

// ================ SETUP =====================
void setup()
{
  RemoteXY_Init ();
  Serial.begin(9600);
  sensors.begin();
}

// ================ LOOP =====================
void loop()
{
  RemoteXY_Handler ();
  sensors.requestTemperatures();
  double temp = sensors.getTempCByIndex(0);
  double temp1 = map(temp, -55, 125, 0, 100);
  RemoteXY.level_temp = temp1;
  dtostrf(temp, 0, 1, RemoteXY.text_temp);
}
