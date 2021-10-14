const int led = 3;
const int mesure_pin = 17;
const int mesure_pin_2 = 19;
int x = 0;
int last_borne = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(mesure_pin, INPUT);
  pinMode(mesure_pin_2, INPUT);
  Serial.begin(9600);
  Serial.println("--- Début du programme ---");

  analogWrite(led, 0);
  delay(1000);
  analogWrite(led, 255);
  delay(1000);
  analogWrite(led, 0);

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led, x);
  Serial.print(x * 5.0 / 255.0);
  Serial.print(" || ");
  Serial.print(analogRead(mesure_pin)*5.0/1023.0);
  Serial.print(" || ");
  Serial.println(analogRead(mesure_pin_2) * 5.0 / 1023.0);
  delay(10);

  if (last_borne == 0){
    x++;
    if (x == 255) {
      last_borne = x;
      }
    }
    
  else if (last_borne == 255) {
    x--;
    if (x == 0) {
      last_borne = x;
      }
    }

  analogWrite(led, x);

}
