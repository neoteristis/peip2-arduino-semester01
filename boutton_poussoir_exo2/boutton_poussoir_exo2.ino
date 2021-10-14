const int led=2;
const int button=4;
int val=1;
int ancien_val=1;
int etat=1;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);

  Serial.begin(9600);

  Serial.println("--- Program Started ---");
  digitalWrite(led, HIGH);
  delay(2000);
  digitalWrite(led, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(button);
  
  if ((val==LOW) && (ancien_val==HIGH)) {
    etat=1-etat;
    delay(200);
    }

  if (etat==0) {
    digitalWrite(led, HIGH);
    Serial.println("ON");
    }
  else {
    digitalWrite(led, LOW);
    Serial.println("OFF");
    }  
  

}
