/*
   Buzzer melody sirena
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
  four();
}
// -------------- Sirena Melody -----------------
void four() {                             //This function produces the 4th siren(POLICE) sound with led transition.
  for (int i = 3; i <= 11; i += 2)
    digitalWrite(i, HIGH);
  for (int hz = 440; hz < 1000; hz++) {
    tone(buzz, hz, 50);
    delay(5);
  }
  for (int i = 3; i <= 11; i += 2)
    digitalWrite(i, LOW);
  for (int i = 4; i <= 12; i += 2)
    digitalWrite(i, HIGH);
  for (int hz = 1000; hz > 440; hz--) {
    tone(buzz, hz, 50);
    delay(5);
  }
}
