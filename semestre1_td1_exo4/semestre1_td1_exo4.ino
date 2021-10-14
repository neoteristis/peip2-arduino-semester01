const int potentio = 19;
const int potentio_digital = 6;
const int led_green = 4;
double val_potentio = 0;
int val_potentio_digital = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("----- Début du programme -----");

  pinMode(potentio, INPUT);
  pinMode(led_green, OUTPUT);
  pinMode(potentio_digital, INPUT);

  digitalWrite(led_green, LOW); // Allumer la led verte
  delay(2000);
  digitalWrite(led_green, HIGH); // Éteindre la led verte

}

void loop() {
  // put your main code here, to run repeatedly:
  
  val_potentio = analogRead(potentio) * 5.0 / 1023.0;
  Serial.print("Valeur potentiometre (en V) : ");
  Serial.print(val_potentio);
  Serial.print("  |  Valeur potentiometre boolenne : ");
  val_potentio_digital = digitalRead(potentio_digital);
  Serial.println(val_potentio_digital);

}
