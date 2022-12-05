int potPin=A0;
int Low = 8;
int High = 13;

void setup() {
  // put your setup code here, to run once:
 // digitalWrite(11,LOW);
  //digitalWrite(10,LOW);
  for (int thisPin = Low; thisPin < High + 1; thisPin++){
     pinMode(thisPin,OUTPUT);
    }
  Serial.begin(9600);
  Serial.setTimeout(10);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if (analogRead(potPin) < 250) {
     goUp();
     delay(250);
     goDown();
     delay(250);
  } else {
      goDown();
     }
     
  }

void goUp() {
    for (int thisPin = Low; thisPin < High + 1; thisPin++){
     digitalWrite(thisPin,LOW);
     Serial.println(thisPin);
     delay(250);
    }
  }
void goDown() {
     for (int thisPin = High; thisPin >= Low; thisPin--){
     digitalWrite(thisPin,HIGH);
     Serial.println(thisPin);
     delay(250);
  }
}
   

  
 
