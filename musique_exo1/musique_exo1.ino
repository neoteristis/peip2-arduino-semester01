#include "pitches.h"

// notes in the melody:
int melody[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

const int led=2;
const int button=4;
const int musique=6;

int val=1;
int ancien_val=1;
int etat=1;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  pinMode(musique, OUTPUT);

  Serial.begin(9600);

  Serial.println("--- Program Started ---");
  digitalWrite(led, HIGH);
  delay(2000);
  digitalWrite(led, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(button);
  
  if ((val==LOW) && (ancien_val==HIGH)) {
    etat=1-etat;
    delay(200);
    }

  if (etat==0) {
    digitalWrite(led, HIGH);
    Serial.println("MUSICA !!!!");

    // iterate over the notes of the melody:

    for (int thisNote = 0; thisNote < 8; thisNote++) {
  
      // to calculate the note duration, take one second divided by the note type.
  
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
  
      int noteDuration = 1000 / noteDurations[thisNote];
  
      tone(8, melody[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
  
      // the note's duration + 30% seems to work well:
  
      int pauseBetweenNotes = noteDuration * 1.30;
  
      delay(pauseBetweenNotes);
  
      // stop the tone playing:
  
      noTone(8);
      }
  }
  else {
    digitalWrite(led, LOW);
    Serial.println("OFF");
    }  
  

}
