const int potentio = 19;
const int led_green = 4;
const int led_orange = 3;
const int led_red = 2;
double val_potentio = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("----- Début du programme -----");

  pinMode(potentio, INPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_orange, OUTPUT);
  pinMode(led_red, OUTPUT);

  digitalWrite(led_green, HIGH);
  digitalWrite(led_orange, HIGH);
  digitalWrite(led_red, HIGH);

  digitalWrite(led_green, LOW); // Allumer la led verte
  delay(2000);
  digitalWrite(led_green, HIGH); // Éteindre la led verte

}

void loop() {
  // put your main code here, to run repeatedly:
  
  val_potentio = analogRead(potentio) * 5.0 / 1023.0;
  Serial.print("Valeur potentiometre (en V) : ");
  Serial.println(val_potentio);

// ########### V1 ########### 

//  if (val_potentio >= 0) {
//    digitalWrite(led_green, LOW); // Allumer la led verte
//    digitalWrite(led_orange, HIGH); // Eteindre la led orange
//    digitalWrite(led_red, HIGH); // Eteindre la led rouge
//    }
//
//  if (val_potentio >= 3) {
//    digitalWrite(led_orange, LOW); // Allumer la led orange
//    }
//
//  if (val_potentio >= 4) {
//    digitalWrite(led_red, LOW); // Allumer la led rouge
//    }


// ########### V2 ###########

  if (val_potentio <= 3) {
    digitalWrite(led_green, LOW);
    digitalWrite(led_orange, HIGH);
    digitalWrite(led_red, HIGH);
    delay(500);
    }

  if (val_potentio > 3 && val_potentio <= 4) {
    digitalWrite(led_green, LOW);
    digitalWrite(led_orange, LOW);
    digitalWrite(led_red, HIGH);
    delay(500);
    }
  
  if (val_potentio > 4) {
    digitalWrite(led_green, LOW);
    digitalWrite(led_orange, LOW);
    digitalWrite(led_red, LOW);
    delay(500);
    }

}
