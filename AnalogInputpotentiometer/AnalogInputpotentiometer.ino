
#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
               // twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position 


int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);      // open the serial port at 9600 bps:
  Serial.print("Start:");
  Serial.println();
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  
}

void loop() {
  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
 {                                  // in steps of 1 degree 
   myservo.write(pos);              // tell servo to go to position in variable 'pos' 
   delay(15);                       // waits 15ms for the servo to reach the position 
  sensorValue = analogRead(sensorPin);
  Serial.print(sensorValue); // prints sensor value
  Serial.println();
 } 
 delay(3000);
  sensorValue = analogRead(sensorPin);
  Serial.print("At pos: ");
  Serial.print(pos);
  Serial.println();
  Serial.print(sensorValue); // prints sensor value
  Serial.println();
 for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
 {                                
   myservo.write(pos);              // tell servo to go to position in variable 'pos' 
   delay(15);                       // waits 15ms for the servo to reach the position 
  sensorValue = analogRead(sensorPin);
  Serial.print(sensorValue); // prints sensor value
  Serial.println();
 } 
}

