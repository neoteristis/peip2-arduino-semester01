#include <NewPing.h>

const int led_red_pin = 3;
const int led_orange_pin = 4;
const int led_green_pin = 5;
const int input_emetteur_pin = 8;
const int output_emetteur_pin = 9;

double distance = 0;
int lecture_echo = 0;

NewPing sonar(input_emetteur_pin, output_emetteur_pin, 500);

void setup() {

  pinMode(led_red_pin, OUTPUT);
  pinMode(led_orange_pin, OUTPUT);
  pinMode(led_green_pin, OUTPUT);
  pinMode(input_emetteur_pin, OUTPUT);
  pinMode(output_emetteur_pin, INPUT);

  Serial.begin(9600);
  
  Serial.println("--- Test Allumage Led ---");

  digitalWrite(led_red_pin, HIGH);
  digitalWrite(led_orange_pin, HIGH);
  digitalWrite(led_green_pin, HIGH);
  delay(1000);
  digitalWrite(led_red_pin, LOW);
  digitalWrite(led_orange_pin, LOW);
  digitalWrite(led_green_pin, LOW);
  delay(1000);
  digitalWrite(led_red_pin, HIGH);
  digitalWrite(led_orange_pin, HIGH);
  digitalWrite(led_green_pin, HIGH);

  Serial.println("--- Fin Test Allumage Led ---");
  delay(100);

  Serial.println("--- Début du programme ---");
}

void loop() {

  // Faire la mesure
  distance = sonar.ping_cm();
  delay(60);

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Utiliser la mesure

  if (distance <= 5) {
    digitalWrite(led_green_pin, LOW);
    digitalWrite(led_orange_pin, LOW);
    digitalWrite(led_red_pin, LOW);
    }

  else if (distance > 5 and distance <= 10) {
    digitalWrite(led_green_pin, LOW);
    digitalWrite(led_orange_pin, LOW);
    digitalWrite(led_red_pin, HIGH);
    }

  else if (distance > 10) {
    digitalWrite(led_green_pin, LOW);
    digitalWrite(led_orange_pin, HIGH);
    digitalWrite(led_red_pin, HIGH);
    }
}
