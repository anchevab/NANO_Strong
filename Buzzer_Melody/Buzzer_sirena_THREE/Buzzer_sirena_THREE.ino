/*
   Buzzer melody THREE
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
  three();
}
// -------------- THREE Melody -----------------
void three() {              //This function produces the 3rd siren(AMBULANCE) sound with led transition.
  tone(buzz, 440, 200);
  delay(300);
  for (int i = 3; i <= 6; i++)
    digitalWrite(i, HIGH);
  noTone(buzz);
  tone(buzz, 494, 500);
  delay(300);
  for (int i = 3; i <= 6; i++) {
    digitalWrite(i, LOW);
    digitalWrite(i + 6, HIGH);
  }
  noTone(buzz);
  tone(buzz, 523, 300);
  delay(200);
  digitalWrite(7, HIGH);
  delay(50);
  digitalWrite(8, HIGH);
  delay(50);
  noTone(buzz);
}
