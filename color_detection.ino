void setup() {
  pinMode(3, OUTPUT);  // RED
  pinMode(4, OUTPUT);  // GREEN
  pinMode(5, OUTPUT);  // BLUE
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    digitalWrite(3, c == 'R');  // RED LED
    digitalWrite(4, c == 'G');  // GREEN LED
    digitalWrite(5, c == 'B');  // BLUE LED
  }
}
