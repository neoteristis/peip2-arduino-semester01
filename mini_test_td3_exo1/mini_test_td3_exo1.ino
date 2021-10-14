const int led = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("--- Début du programme ---");

  pinMode(3, OUTPUT);

  digitalWrite(led, LOW);
  delay(1000);
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i=0; i < 255; i++) {
    Serial.print("i : ");
    Serial.println(i);
    analogWrite(led, i);
    delay(10);
    }

  for (int i=255; i > 0; i--) {
    Serial.print("i : ");
    Serial.println(i);
    analogWrite(led, i);
    delay(10);
    }

}
