
/*
A program to automatically move the debris dispensor slider at the push of a button. 

step one pulse, you apply a digitalWrite hi/lo to the cw or ccw pin.

*/





#include <Wire.h>
#include "nunchuck_funcs.h"
#define pulsePin 3  //pulse tone
#define motorPin 6   //high to turn ccw
#define pulsePinGas 9
#define motorPinGas 11
#define delaytime 800
#define delaytimeGas 200

static int current_position=0, step_position;
static int current_positionGas=0, step_positionGas;


void setup() {                
  
  pinMode(motorPin, OUTPUT);  
  pinMode(pulsePin, OUTPUT);
  pinMode(motorPinGas, OUTPUT);  
  pinMode(pulsePinGas, OUTPUT);
  
  Serial.begin(9600);
  nunchuck_init();
  digitalWrite(pulsePin, HIGH);
  digitalWrite(pulsePinGas,LOW); //zzz
}

// the loop routine runs over and over again forever:
void loop() 
{   
  nunchuck_get_data();
  if (nunchuck_joyy() < 127)
  {
    constrain(nunchuck_joyy(),30,125);
  step_position=map(nunchuck_joyy(),30,125,0,260); //30,120,0,250
  int needtomove = step_position - current_position;
  Serial.println(nunchuck_joyy(),DEC);
  if (needtomove > 0)
  {
  digitalWrite(motorPin, LOW);
  }
  if (needtomove < 0) 
  {
    digitalWrite(motorPin,HIGH);
  }
  else
  {
    digitalWrite(pulsePin, HIGH);
  }
  
  current_position = step_position;
  
  for (int counter = 0; counter < abs(needtomove); counter++)
  {
    
   digitalWrite(pulsePin, LOW);  // turn the stepper motor forward direction 
   delayMicroseconds(delaytime);
   
   digitalWrite(pulsePin, HIGH);
   delayMicroseconds(delaytime);
   
  }
  }
  
  
  
  
  if (nunchuck_joyy() > 124)
  {
    constrain(nunchuck_joyy(),125,225);
  step_positionGas=map(nunchuck_joyy(),125,225,0,1800); //125,225,0,1800
  int needtomove = step_positionGas - current_positionGas;
  if (needtomove > 0)
  {
  digitalWrite(motorPinGas, LOW);
  }
  if (needtomove < 0) 
  {
    digitalWrite(motorPinGas,HIGH);
  }
  else
  {
    digitalWrite(pulsePinGas, HIGH);
  }
  
  current_positionGas = step_positionGas;
  
  for (int counter = 0; counter < abs(needtomove); counter++)
  {
    
   digitalWrite(pulsePinGas, LOW);  // turn the stepper motor forward direction 
   delayMicroseconds(delaytimeGas);
   
   digitalWrite(pulsePinGas, HIGH);
   delayMicroseconds(delaytimeGas);
   
  }
  }
  
}




