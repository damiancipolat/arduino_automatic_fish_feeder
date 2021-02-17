#include <Arduino.h>

//Led pins.
int BLUE_LED=2;
int RED_LED=3;

//Setup ligths.
void setupLigths(){
  pinMode(BLUE_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
}

//Active info ligth.
void ledInfo(boolean statusLed){
  if (statusLed==true)
    digitalWrite(BLUE_LED,HIGH);
  else  
    digitalWrite(BLUE_LED,LOW);
}

//Active alarm ligth.
void ledAlarm(boolean statusLed){
  if (statusLed==true)
    digitalWrite(RED_LED,HIGH);
  else  
    digitalWrite(RED_LED,LOW);
}

//Alarm animation.
void alarmShow(){
  digitalWrite(RED_LED,HIGH);
  digitalWrite(BLUE_LED,HIGH);
  delay(500);
  digitalWrite(RED_LED,LOW);
  digitalWrite(BLUE_LED,LOW);
  delay(500);  
}
