/* RGB LED WS2812 NANO Strong extended shield
  Byala Robots Club
  eng.Anton Anchev
  july 25, 2018
*/
#include <Adafruit_NeoPixel.h>

#define PIN 2                  // DIN на пин 2
#define LED_COUNT 4            // брой на светодиодите на шийлда

// ------------- създаване на обект с име "leds", който е част от класа Adafruit_NeoPixel
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_RGB + NEO_KHZ800);

// ============================ SETUP =======================================
void setup()
{
  Serial.begin(9600);
  leds.begin();                  // активира светодиодите
  leds.setBrightness(64);        // задава сила на светене на светодиодите в интервала 0-255
  leds.clear();                  // изчиства светодиодите
  leds.show();                   // светва светодиодите
}

// =========================== LOOP =========================================
void loop()
{
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  leds.clear();
  if (sensorValue < 500) {
    leds.setPixelColor(0, 255, 0, 0);          // задава червен цвят на 1-ия светодиод
    leds.setPixelColor(1, 255, 0, 0);          // задава червен цвят на 1-ия светодиод
    leds.setPixelColor(2, 255, 0, 0);          // задава червен цвят на 1-ия светодиод
    leds.setPixelColor(3, 255, 0, 0);          // задава червен цвят на 1-ия светодиод
    leds.show();
  }
  if ((sensorValue > 500) & (sensorValue < 800)) {
    leds.setPixelColor(0, 0, 255, 0);          // задава червен цвят на 1-ия светодиод
    leds.setPixelColor(1, 0, 255, 0);          // задава червен цвят на 1-ия светодиод
    leds.setPixelColor(2, 0, 255, 0);          // задава червен цвят на 1-ия светодиод
    leds.setPixelColor(3, 0, 255, 0);          // задава червен цвят на 1-ия светодиод
    leds.show();
  }
  if (sensorValue > 800) {
    leds.setPixelColor(0, 255, 255, 0);          // задава червен цвят на 1-ия светодиод
    leds.setPixelColor(1, 255, 255, 0);          // задава червен цвят на 1-ия светодиод
    leds.setPixelColor(2, 255, 255, 0);          // задава червен цвят на 1-ия светодиод
    leds.setPixelColor(3, 255, 255, 0);          // задава червен цвят на 1-ия светодиод
    leds.show();
  }
  delay(50);
}
