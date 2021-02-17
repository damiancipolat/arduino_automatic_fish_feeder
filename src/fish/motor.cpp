#include <Arduino.h>
#include <Stepper.h>

//Stepper motor pins.
int MOTOR_INT_1=9;
int MOTOR_INT_2=10;
int MOTOR_INT_3=11;
int MOTOR_INT_4=12;
int MOTOR_STEPS_AMMOUNT=2048;
int MOTOR_STEP=256;

//Define motor.
Stepper motor1(MOTOR_STEPS_AMMOUNT, MOTOR_INT_1, MOTOR_INT_2, MOTOR_INT_3, MOTOR_INT_4);

//Setup motor and speed.
void setupMotor(){
  motor1.setSpeed(10);
}

//Move step in motor.
void motorStep(){
  //motor1.step(MOTOR_STEP);
  Serial.println("Mover motor");
}
