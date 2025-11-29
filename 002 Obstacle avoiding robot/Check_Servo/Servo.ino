#include <Servo.h>  // Include the Servo library

Servo myServo;      // Create a Servo object

void setup() {
  Serial.begin(9600);          // Initialize serial communication at 9600 baud rate
  myServo.attach(10);          // Attach the servo to pin 10
  Serial.println("Enter an angle between 0 and 180:");  // Prompt the user
}

void loop() {
  if (Serial.available()) {    // Check if data is available in the serial buffer
    int angle = Serial.parseInt();  // Read the integer value from the serial input

    // Ensure the angle is within the valid range (0 to 180)
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);    // Set the servo to the specified angle
      Serial.print("Servo moved to: ");
      Serial.println(angle);   // Confirm the angle in the Serial Monitor
    } else {
      Serial.println("Invalid angle! Please enter a value between 0 and 180.");
    }
  }
}
