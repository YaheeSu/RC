#include <Wire.h>
#include "rgb_lcd.h"
#include <Ultrasonic.h>//垃圾高度檢測

long duration, dist, average;
long aver[3];
Ultrasonic ultrasonic(5, 6);

rgb_lcd lcd;
const int colorR = 255;
const int colorG = 165;
const int colorB = 0;


int sound = 11;
const int interval=200;

int gas_sensor= A0; 


void setup()    
{   
  Serial.begin(9600);
  pinMode(gas_sensor,INPUT); 

  pinMode(sound,OUTPUT);
  pinMode(2,INPUT);  //臭味檢測宣告


  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setRGB(colorR , colorG , colorB);
} 

void loop(){
  gas_detection();//臭味檢測
  Height();
}
      
void gas_detection()  
{    
  int val=analogRead(gas_sensor); 
  Serial.println(val); 
  // delay(100);
 if(val>300){
    tone(sound,330,interval);
    delay(interval);
    tone(sound,311,interval);
    delay(interval);
    tone(sound,330,interval);
    delay(interval);
    tone(sound,311,interval);
    delay(interval);
    tone(sound,330,interval);
    delay(interval);
    tone(sound,247,interval);
    delay(interval);
    tone(sound,294,interval);
    delay(interval);
    tone(sound,262,interval);
    delay(interval);
    tone(sound,220,interval*4);
    delay(interval*3);
    tone(sound,262,interval);
    delay(interval);
    tone(sound,165,interval);
    delay(interval-1);
    tone(sound,220,interval);
    delay(interval);
    tone(sound,247,interval*4);
    delay(interval*3);
    tone(sound,165,interval);
    delay(interval);
    tone(sound,208,interval);
    delay(interval);
    tone(sound,247,interval);
    delay(interval);
    tone(sound,262,interval*4);
    delay(interval*5);
 
    tone(sound,330,interval);
    delay(interval);
    tone(sound,311,interval);
    delay(interval);
    tone(sound,330,interval);
    delay(interval);
    tone(sound,311,interval);
    delay(interval);
    tone(sound,330,interval);
    delay(interval);
    tone(sound,247,interval);
    delay(interval);
    tone(sound,294,interval);
    delay(interval);
    tone(sound,262,interval);
    delay(interval);
    tone(sound,220,interval*4);
    delay(interval*3);
    tone(sound,262,interval);
    delay(interval);
    tone(sound,165,interval);
    delay(interval-1);
    tone(sound,220,interval);
    delay(interval);
    tone(sound,247,interval*4);
    delay(interval*3);
    tone(sound,165,interval);
    delay(interval);
    tone(sound,262,interval);
    delay(interval);
    tone(sound,247,interval);
    delay(interval);
    tone(sound,220,interval*4);
    delay(interval*8);
 }
   

} 

void Height(){
  for (int i = 0; i <= 2; i++) {
    measure();
    aver[i] = dist;
    delay(10);
  }
  dist = (aver[0] + aver[1] + aver[2]) / 3;

  if ( dist > 30 )
  {
    lcd.clear();
    lcd.setRGB(800 , 500 , 300);
    lcd.print(dist);
    lcd.print(" EMPTY :)");
    delay(1000);
  }
  else if ( dist < 10 )
  {
    lcd.clear();
    lcd.setRGB(255 , 0 , 166);
    lcd.print(dist);
    lcd.print(" FULL!!CLEAR IT!\n");
    delay(1000);
  }
  else
  {
    lcd.clear();
    lcd.setRGB(500 , 165 , 0);
    lcd.print(dist);
    lcd.print("  ......");
    delay(1000);
  }
}

void measure() {
  dist = ultrasonic.read();

  Serial.print("Distance in CM: ");
  Serial.println(dist);
}
