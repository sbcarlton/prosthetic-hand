//Combination of sweep and read analog voltage

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int sensorValue;
float voltage;


int pos = 0;    // variable to store the servo position
void setup() {
  // put your setup code here, to run once:
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  if (voltage >= 0) {
    while (voltage >= .55) {
      sensorValue = analogRead(A0);
      voltage = sensorValue * (5.0 / 1023.0);
      // print out the value you read:
      Serial.println(voltage);
      if (myservo.read() != 140) {
        for (pos = 0; pos <= 140; pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }
      }
    }
    sensorValue = analogRead(A0);
    voltage = sensorValue * (5.0 / 1023.0);
     // print out the value you read:
     Serial.println(voltage);
     while (voltage < .35) {
      sensorValue = analogRead(A0);
      voltage = sensorValue * (5.0 / 1023.0);
      // print out the value you read:
      Serial.println(voltage);
      if (myservo.read() != 0) {
        for (pos = 140; pos >= 0; pos -= 1) { /// goes from 180 degrees to 0 degrees
          // in steps of 1 degree
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }
      }
    }
  } else {
    delay (150);
  }

}
