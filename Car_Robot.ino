#include <NewPing.h>
#include <Servo.h> 

#define TRIG_PIN A3 
#define ECHO_PIN A5 
#define MAX_DISTANCE 200 
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 
Servo car;   
int distance = 100;


const int motorPin1  = 11;  
const int motorPin2  = 10;  
// Motor B
const int motorPin3  = 7; 
const int motorPin4  = 6;  

void setup() {
  Serial.begin(9600);
  car.attach(5);  
  car.write(115); 
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);

}

void loop() {
 
  int distanceR = 0;
  int distanceL = 0;
  delay(40);
  Serial.println(distanceL);
 
  if (distance <= 20) {
    moveStop();
    delay(100);
    moveBackward();
    delay(600);
    moveStop();
    delay(200);
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);

    if (distanceR >= distanceL) {
      turnRight();
      moveStop();
    } else {
      turnLeft();
      moveStop();
    }
  } else {
    moveForward();
  
  }

  distance = readPing();

  delay(100);
}

int lookRight() {
  car.write(50); 
  delay(500);
  int distance = readPing();
  delay(100);
  car.write(115); 
  return distance;
}

int lookLeft() {
  car.write(170); 
  delay(500);
  int distance = readPing();
  delay(100);
  car.write(115); 
  return distance;
  delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}

void moveStop() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
} 
  
void moveForward() {
  analogWrite(motorPin1, 180);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 180);
  analogWrite(motorPin4, 0);  
}

void moveBackward() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 180);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 180);   
}  

void turnRight() {
  analogWrite(motorPin1, 180);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 180);    
  delay(300);
  moveForward();      
} 
 
void turnLeft() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 180);   
  analogWrite(motorPin3, 180);
  analogWrite(motorPin4, 0);     
  delay(300);
  moveForward();
}