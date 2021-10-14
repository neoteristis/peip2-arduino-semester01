const int led_red = 3;
const int led_orange = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("--- Début du programme ---");

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);

  digitalWrite(led_red, LOW);
  digitalWrite(led_orange, LOW);
  delay(1000);
  digitalWrite(led_red, HIGH);
  digitalWrite(led_orange, HIGH);
  delay(1000);
  digitalWrite(led_red, LOW);
  digitalWrite(led_orange, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i=0; i < 255; i++) {
    Serial.print("i : ");
    Serial.println(i);
    analogWrite(led_red, i);
    analogWrite(led_orange, i);
    delay(10);
    }

  for (int i=255; i > 0; i--) {
    Serial.print("i : ");
    Serial.println(i);
    analogWrite(led_red, i);
    analogWrite(led_orange, i);
    delay(10);
    }

}
