#include <Servo.h> // Include servo library

const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 7;
const int IN4 = 6;

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 3;

float duration, distance;
Servo servo;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo.attach(servoPin);
  servo.write(90); // Center position
  delay(500);

  Serial.begin(9600);
}

void loop() {
  servo.write(90); // Look forward
  delay(300);
  distance = getDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 10) {
    forward();
  } else {
    stop();
    delay(500);

    // Look right
    servo.write(30);
    delay(500);
    float rightDist = getDistance();

    // Look left
    servo.write(150);
    delay(500);
    float leftDist = getDistance();

    // Recenter servo
    servo.write(90);
    delay(300);

    // Compare distances
    if (rightDist > leftDist) {
      right();
      delay(500);
    } else {
      left();
      delay(500);
    }
  }
}

// Distance measurement function
float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  if (duration == 0) return 1000; // If no echo, assume far

  return (duration * 0.0343) / 2;
}

// Motor movement functions
void forward() {
  Serial.println("Moving Forward");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  Serial.println("Turning Right");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  Serial.println("Turning Left");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stop() {
  Serial.println("Stopping");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
