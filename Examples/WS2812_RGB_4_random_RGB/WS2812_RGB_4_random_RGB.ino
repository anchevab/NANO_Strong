/* Arduino NANO Strong with WS2812 RGB LED
   create by ing.A.Anchev
   april, 2015
*/

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#define PIN            2                                  // управляващ пин на Arduino NANO
#define NUMPIXELS      4                                  // колко светодиода са свързани

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

long randRED;               // променлива за червения цвят
long randGREEN;             // променлива за зеления цвят
long randBLUE;              // променлива за синия цвят
int delayval = 150;          // време за светене на светодиодите
// ---------------------------- SETUP ------------------------------------------
void setup() {
  pixels.begin();               // инициализира библиотеката Adafruit NeoPixel
  pixels.setBrightness(64);        // задава сила на светене на светодиодите в интервала 0-255
}
// ---------------------------- LOOP -------------------------------------------
void loop() {
  for (int i = 0; i < NUMPIXELS; i++) {                                     // цикъл за адресиране на цвета на всеки RGB LED
    randRED = random(255);                                                  // генериране на случаен цвят
    randGREEN = random(255);
    randBLUE = random(255);
    pixels.setPixelColor(i, pixels.Color(randRED, randGREEN, randBLUE));     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.show();                                                           // This sends the updated pixel color to the hardware.
    delay(delayval);
  }
}
