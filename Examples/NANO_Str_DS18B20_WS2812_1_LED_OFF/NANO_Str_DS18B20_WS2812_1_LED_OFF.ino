/* NANO Strong DS18B20 extended shield with RGB LED WS2812
  Byala Robots Club
  eng.Anton Anchev
  july 25, 2018
*/
#include <Adafruit_NeoPixel.h>

#define PIN 4                  // DIN на пин 4
#define LED_COUNT 1            // брой на светодиодите на шийлда

// ------ създаване на обект с име "leds", който е част от класа Adafruit_NeoPixel
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

// ============================ SETUP =======================================
void setup()
{
  leds.begin();                  // активира светодиодите
  leds.clear();                  // изчиства светодиодите
  leds.show();                   // светва светодиодите
}

// =========================== LOOP =========================================
void loop()
{

}

