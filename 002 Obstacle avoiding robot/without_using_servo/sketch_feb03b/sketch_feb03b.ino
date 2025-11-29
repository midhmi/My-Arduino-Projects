const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 7;
const int IN4 = 6;
const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  distance = getDistance(); // Get distance from sensor
  
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 10) {
    forward(); // Move forward if no obstacle
  } else {
    stop();
    delay(500);
    right();  // Turn right when obstacle detected
    delay(500);
  }
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  if (duration == 0) return 1000; // If no echo, assume no obstacle (1000 cm)

  return (duration * 0.0343) / 2; // Convert time to distance
}

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

void stop() {
  Serial.println("Stopping");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
