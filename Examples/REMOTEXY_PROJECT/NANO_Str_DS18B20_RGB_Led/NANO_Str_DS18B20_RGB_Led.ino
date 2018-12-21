/*
   RGB_LED_NANO_Strong_DS18B20_shield with RemoteXY interface for Android smartphone
   Byala Robots Club
   author: eng.A.Anchev
   Byala, september 2017
*/

// ------- RemoteXY select connection mode and include library
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <RemoteXY.h>

// ------ RemoteXY connection settings
#define REMOTEXY_SERIAL_RX 3
#define REMOTEXY_SERIAL_TX 2
#define REMOTEXY_SERIAL_SPEED 9600

// ------- RGB Led connection settings
#define PIN 4
#define LED_COUNT 1            // number of RGB Led on shield
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

// ------ RemoteXY configurate
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
{ 255, 3, 0, 0, 0, 88, 0, 8, 13, 1,
  6, 0, 6, 37, 51, 51, 2, 26, 130, 1,
  2, 2, 59, 17, 123, 129, 0, 8, 4, 46,
  6, 50, 82, 71, 66, 32, 209, 129, 208, 178,
  208, 181, 209, 130, 208, 190, 208, 180, 208, 184,
  208, 190, 208, 180, 0, 129, 0, 12, 12, 40,
  4, 175, 208, 154, 208, 187, 209, 131, 208, 177,
  32, 34, 208, 160, 208, 190, 208, 177, 208, 190,
  209, 130, 208, 184, 45, 208, 145, 209, 143, 208,
  187, 208, 176, 34, 0
};

// ------ VARIABLES for control interface
struct {

  // input variable
  uint8_t rgb_1_r; // =0..255 Red color value
  uint8_t rgb_1_g; // =0..255 Green color value
  uint8_t rgb_1_b; // =0..255 Blue color value

  // ----- other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)

// =================== SETUP ==================
void setup()
{
  RemoteXY_Init ();
  leds.begin();
  leds.setBrightness(220);
  leds.clear();
  leds.show();
}

// ================== LOOP ====================
void loop()
{
  RemoteXY_Handler ();
  int red = RemoteXY.rgb_1_r;
  int green = RemoteXY.rgb_1_g;
  int blue = RemoteXY.rgb_1_b;
  leds.clear();
  leds.setPixelColor(0, red, green, blue);
  leds.show();
}
