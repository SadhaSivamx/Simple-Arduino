int inPin = 7;    // pushbutton connected to digital pin 7
#include <Servo.h>
Servo myservo;

void setup() 
{
  Serial.begin(9600);
  pinMode(inPin, INPUT); 
  myservo.attach(9);
  myservo.write(90);   
}

void loop() {
  int val = digitalRead(inPin);   
  Serial.println(val);
  if(!val)
  {
    myservo.write(90);
  }
  else
  {
    myservo.write(0);
  }
}