const int led_green=4;
const int led_orange=3;
const int led_red=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_green, OUTPUT);
  pinMode(led_orange, OUTPUT);
  pinMode(led_red, OUTPUT);
  
  Serial.begin(9600);
  
  digitalWrite(led_green, LOW);
  digitalWrite(led_orange, LOW);
  digitalWrite(led_red, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("--- BEGINNING OF PROGRAM ---");

  digitalWrite(led_green, HIGH);
  //Serial.println("GREEN");
  delay(1500);
  //
  Serial.print(digitalRead(led_green));
  Serial.println(": value GREEN");
  //
  digitalWrite(led_green, LOW);
  delay(100);
  
  digitalWrite(led_orange, HIGH);
  //Serial.println("ORANGE"); 
  delay(1000);
  //
  Serial.print(digitalRead(led_orange));
  Serial.println(": value ORANGE");
  //
  digitalWrite(led_orange, LOW);
  delay(100);
  
  digitalWrite(led_red, HIGH);
  //Serial.println("RED");
  delay(1500);
  //
  Serial.print(digitalRead(led_red));
  Serial.println(": value RED");
  //
  digitalWrite(led_red, LOW);
  delay(100);

  Serial.println("--- END OF PROGRAM ---");
  Serial.println("");
}








// const -> constante
// int -> entier
// delay(X) -> arrêt du prog pendant X millisecondes
// pinMode(X, Y) -> config entree sortie (X : 1,2... | Y : OUTPUT, INPUT)
// digitalWrite(X, Y) -> affecte 0 ou 1 (X : Sortie | Y : LOW, HIGH)
