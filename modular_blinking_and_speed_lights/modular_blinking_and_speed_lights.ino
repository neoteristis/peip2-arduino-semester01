const int color_controler=18;
const int speed_controler=19;

const int led_green=4;
const int led_orange=3;
const int led_red=2;

int val_color_controler;
float val_color_controler_volt;

int val_speed_controler;
float val_speed_controler_volt;

void setup() {
  // Setup
  pinMode(color_controler, INPUT);
  pinMode(speed_controler, INPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_orange, OUTPUT);
  pinMode(led_red, OUTPUT);
  
  Serial.begin(9600);
  
  Serial.println("--- Program started ---");

}

void loop() {
  // Main loop

  val_color_controler = analogRead(color_controler);
  val_color_controler_volt = ((val_color_controler * 5.0) / 1023.0);

  val_speed_controler = analogRead(speed_controler);
  val_speed_controler_volt = ((val_speed_controler * 5.0) / 1023.0) + 1;
  
  Serial.println(val_color_controler_volt);
  Serial.println(val_speed_controler_volt);
  Serial.println("-----------------------");

  if (val_color_controler_volt < 1.7) {
     digitalWrite(led_red, LOW);
     digitalWrite(led_orange, LOW);
     digitalWrite(led_green, HIGH);
     delay(1000/val_speed_controler_volt);
     digitalWrite(led_red, LOW);
     digitalWrite(led_orange, LOW);
     digitalWrite(led_green, LOW);
     delay(int(1000/val_speed_controler_volt));
     }

  else if (val_color_controler_volt >= 1.7 and val_color_controler_volt < 3.4) {
     digitalWrite(led_red, LOW);
     digitalWrite(led_orange, HIGH);
     digitalWrite(led_green, HIGH);
     delay(1000/val_speed_controler_volt);
     digitalWrite(led_red, LOW);
     digitalWrite(led_orange, LOW);
     digitalWrite(led_green, LOW);
     delay(int(1000/val_speed_controler_volt));
     }

  else if (val_color_controler_volt >= 3.4) {
    digitalWrite(led_red, HIGH);
    digitalWrite(led_orange, HIGH);
    digitalWrite(led_green, HIGH);
    Serial.println(1000/val_speed_controler_volt);
    delay(int(1000/val_speed_controler_volt));
    digitalWrite(led_red, LOW);
    digitalWrite(led_orange, LOW);
    digitalWrite(led_green, LOW);
    delay(int(1000/val_speed_controler_volt));
     }

}
