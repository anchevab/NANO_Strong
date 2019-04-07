/*
   Buzzer melody ONE_А
   Byala Robots Club
   Author: A.Anchev
*/
int buzz = 5; // Buzzer Pin
int j = 3;
int k = 12;
// =============== SETUP ==========
void setup() {
  pinMode(5, OUTPUT);
}
// ============== LOOP ============
void loop() {
  oneA();
}
// -------------- ONE А Melody -----------------
void oneA() {                //This function produces differnt transition on 1st siren.

  // Whoop up
  for (int hz = 440; hz < 1000; hz += 25) {
    tone(buzz, hz, 50);
    delay(5);
  }
  if (j >= 3) {
    digitalWrite(j, HIGH);
    j = j + 1;
    digitalWrite(k, HIGH);
    k = k - 1;
    if (j == 8)
      j = 3;
    if (k == 7)
      k = 12;
  }
  // Whoop down
  for (int hz = 1000; hz > 440; hz -= 25) {
    tone(buzz, hz, 50);
    delay(5);
  }
}
