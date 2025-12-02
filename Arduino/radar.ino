#include <Servo.h>

// Ultrasonic Pins
const int trigPin = 10;
const int echoPin = 11;

long duration;
int distance;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  myServo.attach(12);
}

void loop() {

  // Scan Left → Right (slow)
  for (int i = 15; i <= 165; i += 2) {
    myServo.write(i);
    delay(40);      // slower movement

    distance = calculateDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }

  // Scan Right → Left (slow)
  for (int i = 165; i >= 15; i -= 2) {
    myServo.write(i);
    delay(40);      // slower movement

    distance = calculateDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 20000);

  distance = duration * 0.034 / 2;
  return distance;
}
