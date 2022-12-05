
#define ENABLE 5
#define DIRA 3
#define DIRB 4

 
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
 
  pinMode(DIRA,OUTPUT);
  digitalWrite(DIRA, HIGH);
  pinMode(DIRB,OUTPUT);
  digitalWrite(DIRB, LOW);}

void loop() {
   analogWrite(ENABLE, 255);
   delay(2000);
   analogWrite(ENABLE, 0);
   delay(2000);
}
