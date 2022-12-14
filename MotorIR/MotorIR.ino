//IR sensor setting
int IRR = A0;
int IRL = A1;
int IRRVal = 0;
int IRLVal = 0;

// Motor L
int INL1 = 7; 
int INL2 = 6; 
int ENAL = 11;

// Motor R
int INR1 = 5; 
int INR2 = 4; 
int ENAR = 3; 

//pwm speed
int PWMspeedHalf = 75;
int PWMspeedQuator = 50;

void setup(){
  //setting 
  Serial.begin(9600);

  //IR sensor pinmode
  pinMode(IRR, INPUT);
  pinMode(IRL, INPUT);
  
  //INL
  pinMode(INL1, OUTPUT);
  pinMode(INL2, OUTPUT);
  pinMode(ENAL, OUTPUT);
  
  //INR
  pinMode(INR1, OUTPUT);
  pinMode(INR2, OUTPUT);
  pinMode(ENAR, OUTPUT);
}

void loop(){
  IRValue();

  if (IRLVal>100 && IRRVal>100)
  {
    digitalWrite(INL1, HIGH);
    digitalWrite(INL2, LOW);
    digitalWrite(INR1, HIGH);
    digitalWrite(INR2, LOW);
    analogWrite (ENAL, PWMspeedHalf);
    analogWrite (ENAR, PWMspeedHalf);
    Serial.println("Forward");
  }
  else if (IRLVal<100 && IRRVal>100)
  {
    digitalWrite(INL1, HIGH);
    digitalWrite(INL2, LOW);
    digitalWrite(INR1, HIGH);
    digitalWrite(INR2, LOW);
    analogWrite (ENAL, PWMspeedQuator);
    analogWrite (ENAR, PWMspeedHalf);
    Serial.println("Left");
  }
  else if (IRLVal>100 && IRRVal<100)
  {
    digitalWrite(INL1, HIGH);
    digitalWrite(INL2, LOW);
    digitalWrite(INR1, HIGH);
    digitalWrite(INR2, LOW);
    analogWrite (ENAL, PWMspeedHalf);
    analogWrite (ENAR, PWMspeedQuator);
    Serial.println("Right");
  }
  
}

void IRValue(){
  //read the IR sensor value
  delay(1000);
  Serial.print("IRR value:");
  IRRVal = analogRead(IRR);
  Serial.println(IRRVal);
  Serial.print("IRL value:");
  IRLVal = analogRead(IRL);
  Serial.println(IRLVal);
  Serial.println(" ");
  
  delay(500);
} 
