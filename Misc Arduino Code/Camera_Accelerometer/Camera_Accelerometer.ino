#include <Servo.h>
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

//float timeStep = 0.001;

// Pitch, Roll and Yaw values
float pitch = 90;
float yaw = 90;
int yawAxis = 0;
int pitchAxis = 0;
int buttonState;

Servo yawServo;
Servo pitchServo;


void setup() 
{
  Serial.begin(9600);
  yawServo.attach(3);
  pitchServo.attach(5);
  mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);

  
  // Calibrate gyroscope. The calibration must be at rest.
  // If you don't want calibrate, comment this line.
  mpu.calibrateGyro();

  // Set threshold sensivty. Default 3.
  // If you don't want use threshold, comment this line or set 0.
  mpu.setThreshold(3);
  pinMode(2, INPUT);


}


void loop()
{
    int buttonState = digitalRead(2);
  if (buttonState == 1) {
    mpu.calibrateGyro();
    yaw = 90;
    pitch = 90;
  }else {
    Vector norm = mpu.readNormalizeGyro();
  pitch = pitch + norm.ZAxis;// * timeStep;
  yaw = yaw + norm.XAxis;// * timeStep;

  yawAxis = map(yaw, -2500, 2500, 500, 2250);
  pitchAxis = map(pitch, -2500, 2500, 500, 2250);

  //Serial.print("Pitch: ");
 // Serial.print(pitchAxis);
  // Serial.println("Yaw: ");
 // Serial.print(yawAxis);
  yawServo.writeMicroseconds(yawAxis);
  pitchServo.writeMicroseconds(pitchAxis);
  
  delay(35);
  }
   
  

  
  }

  
 
