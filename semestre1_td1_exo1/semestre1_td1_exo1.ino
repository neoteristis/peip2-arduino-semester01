const int potentiometre=19;

void setup() {
  // put your setup code here, to run once:
  pinMode(potentiometre, INPUT);

  Serial.begin(9600);

  Serial.println("--- Program started ---");

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(analogRead(potentiometre));

}
