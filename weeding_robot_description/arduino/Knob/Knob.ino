/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo1;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(8);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = 1500;            // reads the value of the potentiometer (value between 0 and 1023)     // scale it to use it with the servo (value between 0 and 180)
  myservo.writeMicroseconds(val);                  // sets the servo position according to the scaled value
  myservo1.writeMicroseconds(1500);
  delay(15);                           // waits for the servo to get there
}
