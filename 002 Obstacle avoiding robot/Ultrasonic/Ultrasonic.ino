// Define pins for the ultrasonic sensor
const int trigPin = 9;  // Trigger pin (sends the ultrasonic pulse)
const int echoPin = 8; // Echo pin (receives the reflected pulse)

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  // Set the trigger pin as OUTPUT and the echo pin as INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.println("Ultrasonic Sensor Distance Measurement");
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10-microsecond HIGH pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  // Speed of sound = 343 m/s = 29.1 microseconds per centimeter
  float distance = duration * 0.034 / 2;

  // Display the distance in the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Wait for 500 milliseconds before the next measurement
  delay(500);
}
