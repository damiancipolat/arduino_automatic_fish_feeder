#include <Arduino.h>

int BUZZER_PIN=8;

//Setup sound.
void setupSound(){
  pinMode(BUZZER_PIN,OUTPUT);
}

//Make sonud..
void makeSound(int freq){
  tone(BUZZER_PIN, freq);
}

//Disable buzzer.
void disableSound(){
  noTone(BUZZER_PIN);
}

//This sound emit on food moment.
void alarmSound(){
  tone(BUZZER_PIN, 500);
  delay(200);
  noTone(BUZZER_PIN);
  delay(200);
  tone(BUZZER_PIN, 1500);
  delay(200);
  noTone(BUZZER_PIN);
}

//Food finish.
void finishSound(){
  tone(BUZZER_PIN, 2000);
  delay(200);
  noTone(BUZZER_PIN);
  delay(200);
  tone(BUZZER_PIN, 100);
  delay(200);
  noTone(BUZZER_PIN);
}
