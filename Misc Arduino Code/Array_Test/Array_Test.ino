int potPin=A0;
int Low = 8;
int High = 13;
int currentPin;

int pinArray[6] = {8,9,10,11,12,13};

void setup() {
  // put your setup code here, to run once:
 // digitalWrite(11,LOW);
  //digitalWrite(10,LOW);
  for (int thisPin = Low; thisPin < High + 1; thisPin++){
     pinMode(thisPin,OUTPUT);
     digitalWrite(thisPin, LOW);
     Serial.begin(9600);
     Serial.setTimeout(10);
    }
  

}
void loop() {
  for(int i = 0; i < 7 ; i++) {
    Serial.println(pinArray[i]);
    if(i == 6) {
     digitalWrite(High,LOW);
     digitalWrite(Low,LOW);
    // digitalWrite(High-1,HIGH);
      i = -1;
      delay(250);
      digitalWrite(High,HIGH);
   } else {
      digitalWrite(pinArray[i],LOW);
  //    digitalWrite(pinArray[i-1],LOW);
      digitalWrite(pinArray[i-2],HIGH);
      delay(500);
   }

  }
  
}
