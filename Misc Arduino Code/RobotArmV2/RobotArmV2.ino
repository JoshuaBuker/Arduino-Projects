
#include <Servo.h>

Servo SecondPivot;
Servo WristFlex;
Servo MainPivot;
Servo Grabber;
Servo WristTwist;
Servo BaseTwist;


int secondPivotPin = 11;
int wristFlexPin = 10;
int mainPivotPin = 9;
int grabberPin = 3;
int wristTwistPin = 5;
int baseTwistPin = 6;

int Joystick_1 = A0;    // select the input pin for the potentiometer
int Joystick_1_Val = 0;  // variable to store the value coming from the sensor
int Joystick_2 = A1;    // select the input pin for the potentiometer
int Joystick_2_Val = 0;  // variable to store the value coming from the sensor
int Joystick_3 = A2;    // select the input pin for the potentiometer
int Joystick_3_Val = 0;  // variable to store the value coming from the sensor
int Joystick_4 = A3;    // select the input pin for the potentiometer
int Joystick_4_Val = 0;  // variable to store the value coming from the sensor
int Joystick_5 = A4;    // select the input pin for the potentiometer
int Joystick_5_Val = 0;  // variable to store the value coming from the sensor
int Joystick_6 = A5;    // select the input pin for the potentiometer
int Joystick_6_Val = 0;  // variable to store the value coming from the sensor


void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  SecondPivot.attach(secondPivotPin);
  WristFlex.attach(wristFlexPin);
  MainPivot.attach(mainPivotPin);
  Grabber.attach(grabberPin);
  WristTwist.attach(wristTwistPin);
  BaseTwist.attach(baseTwistPin);
}

void loop() {
  // read the value from the sensor:
  Joystick_1_Val = analogRead(Joystick_1);
  Joystick_2_Val = analogRead(Joystick_2);
  Joystick_3_Val = analogRead(Joystick_3);
  Joystick_4_Val = analogRead(Joystick_4);
  Joystick_5_Val = analogRead(Joystick_5);
  Joystick_6_Val = analogRead(Joystick_6);


  Joystick_1_Val = map(Joystick_1_Val, 0, 1023, 0, 180);
  Joystick_2_Val = map(Joystick_2_Val, 0, 1023, 0, 180);
  Joystick_3_Val = map(Joystick_3_Val, 0, 1023, 0, 180);
  Joystick_4_Val = map(Joystick_4_Val, 0, 1023, 0, 180);
  Joystick_5_Val = map(Joystick_5_Val, 0, 1023, 0, 180);
  Joystick_6_Val = map(Joystick_6_Val, 0, 1023, 0, 180);
  
  SecondPivot.write(Joystick_1_Val);
  WristFlex.write(Joystick_2_Val);
  MainPivot.write(Joystick_3_Val);
  Grabber.write(Joystick_4_Val);
  WristTwist.write(Joystick_6_Val);
  BaseTwist.write(Joystick_5_Val);


  delay(50);
  
}
