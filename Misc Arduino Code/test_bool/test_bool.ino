void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(9, INPUT);
}

void loop() {
  
 // Serial.println(digitalRead(9));
  Serial.println(analogRead(A2));
}
