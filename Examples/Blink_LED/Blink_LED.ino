/*
  Blink LED
*/


int led = 3;

// =================== SETUP =====================
void setup() {
  pinMode(led, OUTPUT);
}

// ================== LOOP ======================
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
