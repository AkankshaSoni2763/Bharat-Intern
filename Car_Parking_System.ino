#include <Servo.h>

const int trigPin = 7; // Ultrasonic sensor trigger pin
const int echoPin = 6; // Ultrasonic sensor echo pin
const int servoPin = 9; // Servo motor pin
const int parkingDistance = 10; // Parking distance in centimeters
const int freeAngle = 90; // Angle for free parking spot
const int occupiedAngle = 0; // Angle for occupied parking spot

Servo parkingServo; // Create a Servo object

void setup() {
  Serial.begin(9600); // Start serial communication
  parkingServo.attach(servoPin); // Attach the servo to the pin
}

void loop() {
  long duration, distance;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delay(2000);
  digitalWrite(trigPin, HIGH);
  delay(2000);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH); // Measure the time it takes for the ultrasonic signal to bounce back
  distance = (duration / 2) / 29.1; // Calculate the distance in centimeters

  if (distance <= parkingDistance) {
    // If a car is detected in the parking spot
    parkingServo.write(occupiedAngle); // Set the servo angle to the occupied angle
    Serial.println("Parking spot occupied");
  } 
  else {
    // If the parking spot is free
    parkingServo.write(freeAngle); // Set the servo angle to the free angle
    Serial.println("Parking spot free");
  }
  delay(5000); // Wait for half a second
}
