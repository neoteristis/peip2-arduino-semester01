const int led=2;
const int button=4;
int val=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);

  Serial.begin(9600);

  Serial.println("--- Program Started ---");
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(button);
  Serial.print(val);
  Serial.print(" ");

  if (val==LOW) {
    digitalWrite(led, LOW);
    Serial.println("Button is pushed");
    
    }
   else if (val==HIGH) {
    digitalWrite(led, HIGH);
    Serial.println("Button isn't pushed");
    }
  

}
