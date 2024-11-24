#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 4;

Servo doorServo;

void setup() {

  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  doorServo.attach(servoPin);


  doorServo.write(0);
}

void loop() {

  long duration, distance;
  

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);


  distance = (duration / 2) / 29.1;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  if (distance < 20) {
    doorServo.write(0); 
    Serial.println("Door opened!");
    digitalWrite(6, HIGH);
  } else {
    doorServo.write(180); 
    Serial.println("Door closed!");
    digitalWrite(6, LOW);
  }

  
  delay(500);
}
