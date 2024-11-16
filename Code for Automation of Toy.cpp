#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo1;  // create first servo object
Servo myservo2;  // create second servo object
Servo myservo3;

int pos1 = 0;    // variable to store the position of the first servo
int pos2 = 0;
int pos3 = 0;    // variable to store the position of the second servo

int IR_PIN = 12;   // IR sensor input pin
int LED1_PIN = 4;  // First LED pin
int LED2_PIN = 5;  // Second LED pin
int LED3_PIN = 6;  // Third LED pin


void setup() {
  myservo1.attach(8);  // attaches the first servo on pin 12 to the first servo object
  myservo2.attach(9);
  myservo3.attach(3);  // attaches the second servo on pin 13 to the second servo object

  pinMode(IR_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);

 // Set the baud rate to match your Bluetooth module
}

void loop() {
  // Check for obstacle
  if (digitalRead(IR_PIN) == HIGH) {
    // Obstacle detected, turn off all LEDs and stop servos
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, HIGH);

    // Remember current servo positions
    pos1 = myservo1.read();
    pos2 = myservo2.read();
    pos3 = myservo3.read();

    // Stop servos at current positions
    myservo1.write(pos1);
    myservo2.write(pos2);
    for (int i = -360; i <= 180; i += 1) {
      myservo3.write(i);
      // Opposite direction for the second servo
      delay(9);

    }

  } else {
    // No obstacle, sweep servos back and forth
for (int i = 90; i <= 90; i += 1) {
myservo3.write(i);
delay(10);
     // Adjust the delay as needed
}



    // Sweep both servos simultaneously in opposite directions
   for (int i = 90; i <= 180; i += 1) {
myservo1.write(i);
myservo2.write(270-i);
delay(10);
     // Adjust the delay as needed
}

// Reverse direction
for (int i = 180; i >= 90; i -= 1) {

myservo1.write(i);
myservo2.write(270-i);
delay(10); // Adjust the delay as needed
}



    // Turn off LEDs after the servos have moved
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
  }

  // Check for Bluetooth commands

}
