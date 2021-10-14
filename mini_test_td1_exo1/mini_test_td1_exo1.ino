const int potentio=19;
float val_potentio=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("--- Program Started ---");
}

void loop() {
  // put your main code here, to run repeatedly:

  val_potentio = analogRead(potentio);
  Serial.print(val_potentio);
  Serial.print(" | ");
  Serial.println(val_potentio * 5 /1023);

}
