const int potentiometre=19;
const int led_green=4;
const int led_orange=3;
const int led_red=2;

int val_potentio;
float val_potentio_volt;

void setup() {
  // put your setup code here, to run once:
  pinMode(potentiometre, INPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_orange, OUTPUT);
  pinMode(led_red, OUTPUT);
  
  Serial.begin(9600);
  
  Serial.println("--- Program started ---");

}

void loop() {
  // put your main code here, to run repeatedly:

  val_potentio = analogRead(potentiometre);
  val_potentio_volt = ((val_potentio * 5.0) / 1023.0);
  Serial.println(val_potentio_volt);

  if (val_potentio_volt < 2.4) {
     digitalWrite(led_red, LOW);
     digitalWrite(led_orange, HIGH);
     digitalWrite(led_green, LOW);
  }

  else if (val_potentio_volt >= 2.4 and val_potentio_volt < 2.6) {
     digitalWrite(led_red, LOW);
     digitalWrite(led_orange, LOW);
     digitalWrite(led_green, HIGH);
     }

  else if (val_potentio_volt >= 2.6) {
    digitalWrite(led_red, HIGH);
    digitalWrite(led_orange, LOW);
    digitalWrite(led_green, LOW);
    }
}
