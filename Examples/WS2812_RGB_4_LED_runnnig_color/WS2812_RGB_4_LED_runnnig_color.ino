/* RGB LED WS2812 NANO Strong extended shield
  Byala Robots Club
  eng.Anton Anchev
  july 25, 2018
*/
#include <Adafruit_NeoPixel.h>

#define PIN 2                  // DIN на пин 2
#define LED_COUNT 4            // брой на светодиодите на шийлда

// ------ създаване на обект с име "leds", който е част от класа Adafruit_NeoPixel
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_RGB + NEO_KHZ800);

// ============================ SETUP =======================================
void setup()
{
  leds.begin();                  // активира светодиодите
  leds.setBrightness(64);        // задава сила на светене на светодиодите в интервала 0-255
  leds.clear();                  // изчиства светодиодите
  leds.show();                   // светва светодиодите
}

// =========================== LOOP =========================================
void loop()
{
  leds.clear();
  for (int i = 0; i <= 3; i++) {
    leds.setPixelColor(i, 255, 0, 0);          // задава червен цвят на 1-ия светодиод
    leds.show();                               // светва светодиода
    delay(200);                                // време на светене на светодиода
    leds.clear();                              // изгасва светодиодите
  }
}

