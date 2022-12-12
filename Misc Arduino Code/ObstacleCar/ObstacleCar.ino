#include <Servo.h>

#define FrontRightSpeed 9
#define FrontRightForward  22   
#define FrontRightBackward  24                             
#define FrontLeftForward  26   
#define FrontLeftBackward  28  
#define FrontLeftSpeed 10  

#define RearRightSpeed 11
#define RearRightForward  5   
#define RearRightBackward  6                             
#define RearLeftForward  7   
#define RearLeftBackward  8  
#define RearLeftSpeed 12  

#define SERVO_PIN     13  

#define Echo_PIN    31
#define Trig_PIN    30 

Servo ultraServo;

long duration;
long distanceRight, distanceFront, distanceLeft;
int currentAngle = 1500;
bool slideSwitch = true;


void setMotorSpeed(int frontLeft, int frontRight, int rearLeft, int rearRight){

    analogWrite(FrontRightSpeed, frontRight);
    analogWrite(FrontLeftSpeed, frontLeft);
    analogWrite(RearRightSpeed, rearRight);
    analogWrite(RearLeftSpeed, rearLeft);
  
}

void driveForward() {

  digitalWrite(RearRightBackward, LOW);
  digitalWrite(RearLeftBackward, LOW);
  digitalWrite(FrontRightBackward, LOW);
  digitalWrite(FrontLeftBackward, LOW);
  
  digitalWrite(RearRightForward, HIGH);
  digitalWrite(RearLeftForward, HIGH);
  digitalWrite(FrontRightForward, HIGH);
  digitalWrite(FrontLeftForward, HIGH);
  
  setMotorSpeed(90,90,90,90);
}

void driveBackward() {

  digitalWrite(RearRightForward, LOW);
  digitalWrite(RearLeftForward, LOW);
  digitalWrite(FrontRightForward, LOW);
  digitalWrite(FrontLeftForward, LOW);
  
  digitalWrite(RearRightBackward, HIGH);
  digitalWrite(RearLeftBackward, HIGH);
  digitalWrite(FrontRightBackward, HIGH);
  digitalWrite(FrontLeftBackward, HIGH);
  
  setMotorSpeed(90,90,90,90);
}

void stopMotor() {
  
  digitalWrite(RearRightBackward, LOW);
  digitalWrite(RearLeftBackward, LOW);
  digitalWrite(RearRightForward, LOW);
  digitalWrite(RearLeftForward, LOW);
  digitalWrite(FrontRightBackward, LOW);
  digitalWrite(FrontLeftBackward, LOW);
  digitalWrite(FrontRightForward, LOW);
  digitalWrite(FrontLeftForward, LOW);
  
  setMotorSpeed(0,0,0,0);
}

void slideRight() {

  digitalWrite(RearRightForward, HIGH);
  digitalWrite(RearLeftForward, LOW);
  digitalWrite(FrontRightForward, LOW);
  digitalWrite(FrontLeftForward, HIGH);
  
  digitalWrite(RearRightBackward, LOW);
  digitalWrite(RearLeftBackward, HIGH);
  digitalWrite(FrontRightBackward, HIGH);
  digitalWrite(FrontLeftBackward, LOW);

  setMotorSpeed(90,90,90,90);
}

void slideLeft() {

  digitalWrite(RearRightForward, LOW);
  digitalWrite(RearLeftForward, HIGH);
  digitalWrite(FrontRightForward, HIGH);
  digitalWrite(FrontLeftForward, LOW);
  
  digitalWrite(RearRightBackward, HIGH);
  digitalWrite(RearLeftBackward, LOW);
  digitalWrite(FrontRightBackward, LOW);
  digitalWrite(FrontLeftBackward, HIGH);

  setMotorSpeed(90,90,90,90);
}

void scanRight() {
 // driveForward();
 // setMotorSpeed(75,75,75,75);

while (currentAngle > 650 || currentAngle < 600) {
      if (currentAngle < 600) {
       currentAngle = currentAngle + 25;
       ultraServo.writeMicroseconds(currentAngle);
    delay(15);
    }
    else if (currentAngle > 650) {
       currentAngle = currentAngle - 25;
       ultraServo.writeMicroseconds(currentAngle);
    delay(15);
    }
}
  digitalWrite(Trig_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_PIN, LOW);
  duration = pulseIn(Echo_PIN, HIGH);
  distanceRight = duration * 0.034 / 2; 
}

void scanForward() {
  //driveForward();
  //setMotorSpeed(75,75,75,75);
  
while (currentAngle > 1550 || currentAngle < 1450) {
      if (currentAngle < 1450) {
       currentAngle = currentAngle + 25;
       ultraServo.writeMicroseconds(currentAngle);
    delay(15);
    }
    else if (currentAngle > 1550) {
       currentAngle = currentAngle - 25;
       ultraServo.writeMicroseconds(currentAngle);
    delay(15);
    }
}
  
  digitalWrite(Trig_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_PIN, LOW);
  duration = pulseIn(Echo_PIN, HIGH);
  distanceFront = duration * 0.034 / 2; 
}

void scanLeft() {
 // driveForward();
 // setMotorSpeed(75,75,75,75);
  
while (currentAngle > 2350 || currentAngle < 2300) {
      if (currentAngle < 2300) {
       currentAngle = currentAngle + 25;
       ultraServo.writeMicroseconds(currentAngle);
    delay(15);
    }
    else if (currentAngle > 2350) {
       currentAngle = currentAngle - 25;
       ultraServo.writeMicroseconds(currentAngle);
    delay(15);
    }
}

  digitalWrite(Trig_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_PIN, LOW);
  duration = pulseIn(Echo_PIN, HIGH);
  distanceLeft = duration * 0.034 / 2; 
}


void setup() {
  
  Serial.begin(9600);
  ultraServo.attach(SERVO_PIN);

  pinMode(RearRightBackward, OUTPUT);
  pinMode(RearLeftBackward, OUTPUT);
  pinMode(RearRightForward, OUTPUT);
  pinMode(RearLeftForward, OUTPUT);
  pinMode(RearRightSpeed, OUTPUT);
  pinMode(RearLeftSpeed, OUTPUT);

  
  pinMode(FrontRightBackward, OUTPUT);
  pinMode(FrontLeftBackward, OUTPUT);
  pinMode(FrontRightForward, OUTPUT);
  pinMode(FrontLeftForward, OUTPUT);
  pinMode(FrontRightSpeed, OUTPUT);
  pinMode(FrontLeftSpeed, OUTPUT);

  pinMode(Echo_PIN, INPUT);
  pinMode(Trig_PIN, OUTPUT);
  digitalWrite(Trig_PIN,LOW);

  ultraServo.writeMicroseconds(currentAngle);
  
  
  stopMotor();
}

void loop() {
  stopMotor();
  
  scanLeft();
  delay(100);
  scanForward();
  delay(100);
  scanRight();
  delay(100);

  if (distanceFront > 35) {
    setMotorSpeed(50,50,50,50);
  }
  else {
    
  setMotorSpeed(90,90,90,90);
  }
  
  
  if (distanceFront <= 35 && distanceRight <= 10 && distanceLeft <= 10) 
  {
    driveBackward();
  }
  else if (distanceFront <= 35 && distanceRight > 10 && distanceLeft <= 10) 
  {
    slideRight();
    delay(500);
  }
  else if (distanceFront <= 35 && distanceRight <= 10 && distanceLeft > 10) 
  {
    slideLeft();
  }
   else if (distanceFront <= 35 && distanceRight > 10 && distanceLeft > 10) 
  {
    if (slideSwitch == true) 
    {
      slideLeft();
      slideSwitch = false;
      delay(500);
    }
    else 
    {
      slideRight();
      slideSwitch = true;
      delay(500);
    }
  }
  else if (distanceFront > 35) 
  {
    driveForward();
  }
  delay(750);
}
