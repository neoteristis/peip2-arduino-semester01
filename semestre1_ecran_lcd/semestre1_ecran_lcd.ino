#include <LiquidCrystal.h>
LiquidCrystal lcd_screen(4, 5, 6, 7, 8, 9);

const int potentio = 19;
const int led = 2;
const int selection_type_msg = 4; // HIGH envoie de donnee - LOW envoie instruction
const int ecran_on_off = 5; // Prend en compte lorsque HIGH => LOW
const int ecran_input_0 = 6;
const int ecran_input_1 = 7;
const int ecran_input_2 = 8;
const int ecran_input_3 = 9;
const int ecran_input_4 = 10;
const int ecran_input_5 = 11;
const int ecran_input_6 = 12;
const int ecran_input_7 = 13;

void setup() {
  // put your setup code here, to run once:

  lcd_screen.begin(16, 2);
  lcd_screen.print("Bonjour");
  
  Serial.begin(9600);

   pinMode(led, OUTPUT);
   pinMode(selection_type_msg, OUTPUT);
   pinMode(ecran_on_off, OUTPUT);
   pinMode(ecran_input_0, OUTPUT);
   pinMode(ecran_input_1, OUTPUT);
   pinMode(ecran_input_2, OUTPUT);
   pinMode(ecran_input_3, OUTPUT);
   pinMode(ecran_input_4, OUTPUT);
   pinMode(ecran_input_5, OUTPUT);
   pinMode(ecran_input_6, OUTPUT);
   pinMode(ecran_input_7, OUTPUT);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  double val_potentio = analogRead(potentio) * 5.0 /1023.0;
  digitalWrite(led, val_potentio);
  
}
