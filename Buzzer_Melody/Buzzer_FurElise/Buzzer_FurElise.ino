#include "pitches.h"

#define SIXTEENTHNOTE 1
#define EIGHTHNOTE 2
#define DOTTEDEIGHTNOTE 3
#define QUARTERNOTE 4
#define DOTTEDQUARTERNOTE 6
#define HALFNOTE 8
#define DOTTEDHALFNOTE 12
#define WHOLENOTE 16

// --------- SETTINGS
#define speakerPin 5                //Speaker or Piezo buzzer on this pin
int tempo = 120;
boolean continuePlaying = true;     //Set to true to continuously play (otherwise, false)
int continueDelay = 0;              //Time to wait before continuing playing

// ==================== SETUP ===============
void setup()
{
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

// ===================== LOOP =========================
void loop()
{
  // Song goes here
  //note(NOTE_G5, HALFNOTE);

  //Measure 1
  note(NOTE_E6, EIGHTHNOTE);
  note(NOTE_DS6, EIGHTHNOTE);

  //Measure 2
  note(NOTE_E6, EIGHTHNOTE);
  note(NOTE_DS6, EIGHTHNOTE);
  note(NOTE_E6, EIGHTHNOTE);
  note(NOTE_B5, EIGHTHNOTE);
  note(NOTE_D6, EIGHTHNOTE);
  note(NOTE_C6, EIGHTHNOTE);

  //Measure 3
  note(NOTE_A3, EIGHTHNOTE);
  note(NOTE_E4, EIGHTHNOTE);
  note(NOTE_A4, EIGHTHNOTE);
  note(NOTE_C5, EIGHTHNOTE);
  note(NOTE_E5, EIGHTHNOTE);
  note(NOTE_A5, EIGHTHNOTE);

  //Measure 4
  note(NOTE_E3, EIGHTHNOTE);
  note(NOTE_E4, EIGHTHNOTE);
  note(NOTE_GS4, EIGHTHNOTE);
  note(NOTE_E5, EIGHTHNOTE);
  note(NOTE_GS5, EIGHTHNOTE);
  note(NOTE_B5, EIGHTHNOTE);

  //Measure 5
  note(NOTE_A3, EIGHTHNOTE);
  note(NOTE_E4, EIGHTHNOTE);
  note(NOTE_A4, EIGHTHNOTE);
  note(NOTE_E5, EIGHTHNOTE);
  note(NOTE_E6, EIGHTHNOTE);
  note(NOTE_DS6, EIGHTHNOTE);

  //Measure 6
  note(NOTE_E6, EIGHTHNOTE);
  note(NOTE_DS6, EIGHTHNOTE);
  note(NOTE_E6, EIGHTHNOTE);
  note(NOTE_B5, EIGHTHNOTE);
  note(NOTE_D6, EIGHTHNOTE);
  note(NOTE_C6, EIGHTHNOTE);

  //Measure 7
  note(NOTE_A3, EIGHTHNOTE);
  note(NOTE_E4, EIGHTHNOTE);
  note(NOTE_A4, EIGHTHNOTE);
  note(NOTE_C5, EIGHTHNOTE);
  note(NOTE_E5, EIGHTHNOTE);
  note(NOTE_A5, EIGHTHNOTE);

  //Measure 8
  note(NOTE_E3, EIGHTHNOTE);
  note(NOTE_E4, EIGHTHNOTE);
  note(NOTE_GS4, EIGHTHNOTE);
  note(NOTE_E5, EIGHTHNOTE);
  note(NOTE_GS5, EIGHTHNOTE);
  note(NOTE_B5, EIGHTHNOTE);

  //Measure 9
  note(NOTE_A3, EIGHTHNOTE);
  note(NOTE_E4, EIGHTHNOTE);
  note(NOTE_A4, EIGHTHNOTE);
  note(NOTE_E5, EIGHTHNOTE);
  note(NOTE_C6, EIGHTHNOTE);
  note(NOTE_D6, EIGHTHNOTE);

  //Measure 10
  note(NOTE_C4, EIGHTHNOTE);
  note(NOTE_G4, EIGHTHNOTE);
  note(NOTE_C5, EIGHTHNOTE);
  note(NOTE_G5, EIGHTHNOTE);
  note(NOTE_F6, EIGHTHNOTE);
  note(NOTE_E6, EIGHTHNOTE);

  //Measure 11
  note(NOTE_G3, EIGHTHNOTE);
  note(NOTE_G4, EIGHTHNOTE);
  note(NOTE_B4, EIGHTHNOTE);
  note(NOTE_F5, EIGHTHNOTE);
  note(NOTE_E6, EIGHTHNOTE);
  note(NOTE_D6, EIGHTHNOTE);

  //Measure 12
  note(NOTE_A3, EIGHTHNOTE);
  note(NOTE_E4, EIGHTHNOTE);
  note(NOTE_A4, EIGHTHNOTE);
  note(NOTE_E5, EIGHTHNOTE);
  note(NOTE_D6, EIGHTHNOTE);
  note(NOTE_C6, EIGHTHNOTE);

  //Measure 13
  note(NOTE_E3, EIGHTHNOTE);
  note(NOTE_E4, EIGHTHNOTE);
  note(NOTE_A5, EIGHTHNOTE);
  rest(EIGHTHNOTE);



  /////// KEEP ALL CODE BELOW UNCHANGED, CHANGE VARS ABOVE ////////
  noTone(speakerPin);
  while (continuePlaying == false);
  delay(continueDelay);
}

// -------------------------------
void spacedNote(int frequencyInHertz, int noteLength)
{
  tone(speakerPin, frequencyInHertz);
  float delayTime = (1000 / tempo) * (60 / 4) * noteLength;
  delay(delayTime - 50);
  noTone(speakerPin);
  delay(50);
}
// -------------------------------
void note(int frequencyInHertz, int noteLength)  //Code to take care of the note
{
  tone(speakerPin, frequencyInHertz);
  float delayTime = (1000 / tempo) * (60 / 4) * noteLength;
  delay(delayTime);
}
// -------------------------
void rest(int restLength)
{
  noTone(speakerPin);
  float delayTime = (1000 / tempo) * (60 / 4) * restLength;
  delay(delayTime);
}
