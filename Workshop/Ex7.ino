#include <IRremote.h>
#define IR_RECEIVE_PIN 12
#include <Servo.h>
Servo myservo;

String data;

void setup() 
{
  Serial.begin(9600);  
  IrReceiver.begin(IR_RECEIVE_PIN);
  myservo.attach(9);  
}
void loop() {
  if (IrReceiver.decode()) 
  {
    IrReceiver.resume();
    data=IrReceiver.decodedIRData.command;
    Serial.println(data);
    if(data=="28")
    {
      myservo.write(0); 
    }
    else if(data=="24")
    {
      myservo.write(45); 
    }
    else if(data=="90")
    {
      myservo.write(90); 
    }
    else if(data=="82")
    {
      myservo.write(135); 
    }
    else if(data=="8")
    {
      myservo.write(180); 
    }
  }
}