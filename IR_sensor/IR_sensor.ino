//IR sensor setting
int IRR = A0;
int IRL = A1;

void setup() {
  Serial.begin(9600);
  //IR sensor pinmode
  pinMode(IRR, INPUT);
  pinMode(IRL, INPUT);
}

void loop() {
  IRValue();
}

void IRValue(){
  //read the IR sensor value
  delay(1000);
  Serial.print("IRR value:");
  Serial.println(analogRead(IRR));
  Serial.print("IRL value:");
  Serial.println(analogRead(IRL));
  Serial.println(" ");
  
  delay(500);
}
