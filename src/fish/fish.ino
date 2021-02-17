#include "led.h"
#include "buzzer.h"
#include "clock.h"
#include "motor.h"

//Machine variables.
int state=0;
boolean foodReady=false;

//Time values: [0...8,9...12,...23]
clock_time current_time;

//Active
clock_time ACTIVE_START = createTime(8,1,0);
clock_time ACTIVE_END = createTime(23,0,0);

//Food
clock_time FOOD_START = createTime(9,0,0);
clock_time FOOD_END = createTime(9,10,0);

//Sleep
clock_time SLEEP_START = createTime(23,0,0);
clock_time SLEEP_END = createTime(8,0,0);

//Start mode.
void start_mode(){
  Serial.println("Starting...");
  state=1;
}

//Read variables modes.
void read_mode(){
  //clock_time current_time = read_ds1307();
  current_time = createTime(9,2,0);
  print_time(current_time);
  state=2;
}

//Control sensor value
void control_mode(){

  Serial.println("STATE:CONTROL mode");
  print_time(current_time);

  //ACTIVE MODE.
  if (inTime(current_time,ACTIVE_START,ACTIVE_END))
    state=4;

  //SLEEP MODE.
  if (inTime(current_time,SLEEP_START,SLEEP_END))
    state=5;

  //Enter in FOOD MODE.
  if ((inTime(current_time,FOOD_START,FOOD_END))&&(foodReady==false))
    state=3;    
      
}

//Food time mode.
void food_time_mode(){
  Serial.println("STATE:Food time mode");

  //Sound and ligths.
  Serial.println("ALARM - #1!");
  alarmSound();
  alarmShow();
  Serial.println("ALARM - #2!");
  alarmSound();
  alarmShow();
  Serial.println("ALARM - #3!");
  alarmSound();
  alarmShow();

  //Moving motor.
  Serial.println("MOVING MOTOR start!!");
  motorStep();
  Serial.println("MOVING finish!!");
  finishSound();

  //Change state.
  foodReady=true;
  state=1;
}

//Active mode
void active_mode(){
  Serial.println("STATE:ACTIVE mode");

  //Ligth mode.
  if (foodReady==true){
    ledInfo(true);
    ledAlarm(false);
  }else{
    ledInfo(false);
    ledAlarm(true);    
  }

  state=1;
}

//Sleep mode.
void sleep_mode(){
  Serial.println("STATE:SLEEP mode");
  ledInfo(false);
  ledAlarm(false);
  state=1;
}

//--------------------------------------

void setup(){
  Serial.begin(9600);
  setupClock();
  setupLigths();
  setupSound();
  setupMotor();
}


void loop(){

  //Main switch.
  switch (state) {
    case 0:
      start_mode();
      break;
    case 1:
      read_mode();
      break;
    case 2:
      control_mode();
      break;
    case 3:
      food_time_mode();
      break;
    case 4:
      active_mode();
      break;
    case 5:
      sleep_mode();
      break;      
  }
}
