/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo handServo; 

Servo twistServo;

Servo vertServo;

int handPin = A0;
int handVal;    

int xAxisPin = A1;
int xVal; 
   
int yAxisPin = A2;
int yVal;    

void setup() {
  Serial.begin(9600);
  
  handServo.attach(9); 
  
  twistServo.attach(5); 
  
  vertServo.attach(6); 
}

void loop() {
  handVal = analogRead(handPin);          
  handVal = map(handVal, 0, 1023, 5, 175);  
  handServo.write(handVal); 
  Serial.println(handVal);

  xVal = analogRead(xAxisPin);          
  xVal = map(xVal, 0, 1023, 5, 175);  
  twistServo.write(xVal); 
  Serial.println(xVal);
  
  yVal = analogRead(yAxisPin);          
  yVal = map(yVal, 0, 1023, 5, 175);  
  vertServo.write(yVal); 
  Serial.println(yVal);
                 
  delay(15);                      
}
