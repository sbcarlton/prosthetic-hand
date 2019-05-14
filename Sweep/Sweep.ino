/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
//#include <Keyboard.h>
//#include "Keyboard.h"


Servo myservo;  // create servo object to control a servo
byte incomingByte; 

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    Serial.begin(9600);
    //Keyboard.begin();

}

void loop() {
  if (Serial.available() > 0) {
   // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    Serial.println(incomingByte);
    if (incomingByte == 120) {
      for (pos = 0; pos <= 140; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
    }
    if (incomingByte == 115) {
      for (pos = 140; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
    }
  } else {
    delay (150);
  }
}

