/*
   Buzzer melody ONE
   Byala Robots Club
   Author: A.Anchev
*/
int buzz = 5; // Buzzer Pin

// =============== SETUP ==========
void setup() {
  pinMode(5, OUTPUT);
}
// ============== LOOP ============
void loop() {
  one();
}
// -------------- ONE Melody -----------------
void one() {         //This function produces the 1st siren sound with ON/OFF led transition.
  // Whoop up
  for (int hz = 440; hz < 1000; hz += 25) {
    tone(buzz, hz, 50);
    delay(5);
    for (int i = 3; i <= 7; i++)
      digitalWrite(i, HIGH);
  }
  // Whoop down
  for (int hz = 1000; hz > 440; hz -= 25) {
    tone(buzz, hz, 50);
    delay(5);
    for (int i = 3; i <= 7; i++)
    {
      digitalWrite(i, LOW);
      digitalWrite(i + 5, HIGH);
    }
  }
}
