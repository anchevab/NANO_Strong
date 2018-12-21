/*
   NANO Strong DS18B20 sensor shield
   BYala Robots Club
   eng.Anton Anchev , may 2015
*/

#include <OneWire.h>                      // библиотека, която ни дава възможност да комуникираме със сензори чрез 1 връзка (проводник)
#include <DallasTemperature.h>            // библиотека за управление на сензора DS18B20
#include <Adafruit_NeoPixel.h>

#define PIN 4                  // DIN на пин 4
#define LED_COUNT 1            // брой на светодиодите на шийлда
#define ONE_WIRE_BUS 7                    // дефиниране на сензора към пин 7 на Arduino NANO 
// ------------- създаване на обект с име "leds", който е част от класа Adafruit_NeoPixel
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

OneWire oneWire(ONE_WIRE_BUS);            // създаване на обект oneWire за комуникация със сезора DS18B20 чрез пин 2
DallasTemperature sensors(&oneWire);      // свързване на обектът oneWire с библиотеката.

// ================================ SETUP ==========================================
void setup(void)
{
  Serial.begin(9600);
  Serial.println("Read temperature from DS18B20");
  sensors.begin();                        // резолюцията по подразбиране е 9 бита.Ако е малка, можем да я вдигнем до 12 бита.
  leds.begin();                  // активира светодиодите
  leds.setBrightness(220);       // задава сила на светене на светодиодите в интервала 0-255
  leds.clear();                  // изчиства светодиодите
  leds.show();                   // светва светодиодите
}

// ================================ LOOP ===========================================
void loop(void)
{
  sensors.requestTemperatures();                   // изпращане на команда за получаване на стойностт на температурата
  Serial.print("Temperature is: ");
  Serial.println(sensors.getTempCByIndex(0));     // използваме getTempCByIndex(0)защото може да имаме закачен повече от един сензор ,
  //така че искаме данни от първия сензор (IC - интергрална схема)
  float temp = sensors.getTempCByIndex(0);
  if (temp < 20) {
    leds.clear();
    leds.setPixelColor(0, 0, 0, 255);          // задава червен цвят на 1-ия светодиод
    leds.show();                               // светва светодиода
  }
  if ((temp > 20) & (temp < 30)) {
    leds.clear();
    leds.setPixelColor(0, 0, 255, 0);          // задава червен цвят на 1-ия светодиод
    leds.show();                               // светва светодиода
  }
  if ((temp > 30) & (temp < 40)) {
    leds.clear();
    leds.setPixelColor(0, 255, 0, 0);          // задава червен цвят на 1-ия светодиод
    leds.show();                               // светва светодиода
  }
  delay(70);
}
