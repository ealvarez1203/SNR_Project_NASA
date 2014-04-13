
#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(9);

//need to add the functionality if the button is pressed
  myservo.write(0);
  myservo.write(180);  // 
} 

void loop() {}





