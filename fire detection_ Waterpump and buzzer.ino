#define waterpump 7
#define buzzer 6
char receivedChar;
void setup() {
  Serial.begin(9600);
  pinMode(waterpump,OUTPUT);
  pinMode(buzzer,OUTPUT);


}

void loop() {
if (Serial.available()>0) {
  receivedChar = Serial.read();
  if (receivedChar== '1') {
    digitalWrite(waterpump,1);
    digitalWrite(buzzer,1);
  } else {
    digitalWrite(waterpump,0);
    digitalWrite(buzzer,0);

  }
}
delay (500);

}
