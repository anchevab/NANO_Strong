/*
   light_sensor_NANO_Str_DS18B20_shield with light sensor
   Byala Robots Club
   author: eng.A.Anchev
   Byala, september,2017
*/

// ---- RemoteXY select connection mode and include library
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// ----- RemoteXY connection settings
#define REMOTEXY_SERIAL_RX 3
#define REMOTEXY_SERIAL_TX 2
#define REMOTEXY_SERIAL_SPEED 9600

#define LightSensor A0

// ----- RemoteXY configurate
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
{ 255, 0, 0, 1, 0, 254, 0, 8, 13, 1,
  130, 1, 1, 1, 61, 22, 92, 129, 0, 11,
  14, 40, 4, 175, 208, 154, 208, 187, 209, 131,
  208, 177, 32, 34, 208, 160, 208, 190, 208, 177,
  208, 190, 209, 130, 208, 184, 45, 208, 145, 209,
  143, 208, 187, 208, 176, 34, 0, 129, 0, 7,
  5, 49, 5, 233, 208, 161, 208, 181, 208, 189,
  208, 183, 208, 190, 209, 128, 32, 208, 183, 208,
  176, 32, 209, 129, 208, 178, 208, 181, 209, 130,
  208, 187, 208, 184, 208, 189, 208, 176, 0, 129,
  0, 17, 78, 7, 3, 108, 208, 157, 208, 190,
  209, 137, 0, 66, 0, 30, 33, 17, 54, 107,
  26, 129, 0, 9, 72, 15, 3, 108, 208, 159,
  209, 128, 208, 184, 208, 178, 208, 181, 209, 135,
  208, 181, 209, 128, 0, 129, 0, 14, 58, 7,
  3, 108, 0, 129, 0, 6, 62, 18, 3, 165,
  208, 156, 209, 138, 208, 179, 208, 187, 208, 184,
  208, 178, 32, 208, 180, 208, 181, 208, 189, 0,
  129, 0, 4, 56, 20, 3, 164, 208, 158, 208,
  177, 208, 187, 208, 176, 209, 135, 208, 181, 208,
  189, 32, 208, 180, 208, 181, 208, 189, 0, 129,
  0, 10, 45, 14, 3, 108, 208, 175, 209, 129,
  208, 181, 208, 189, 32, 208, 180, 208, 181, 208,
  189, 0, 129, 0, 4, 39, 20, 3, 108, 208,
  161, 208, 187, 209, 138, 208, 189, 209, 135, 208,
  181, 208, 178, 32, 208, 180, 208, 181, 208, 189,
  0
};

// ---- Variables of your control interface
struct {

  // ----- output variable
  int8_t level_1; // =0..100 level position

  // ----- other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)

// ===================== SETUP ========================
void setup()
{
  RemoteXY_Init ();
}

// ==================== LOOP =======================
void loop()
{
  RemoteXY_Handler ();
  int light = analogRead(LightSensor);
  RemoteXY.level_1 = map(light, 1023, 0, 0, 100);
}
