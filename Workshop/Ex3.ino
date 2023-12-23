#include <IRremote.h>
#define IR_RECEIVE_PIN 12
String data;
int led=13;
void setup() 
{
  Serial.begin(9600);  
  IrReceiver.begin(IR_RECEIVE_PIN);
  pinMode(led,OUTPUT);
}
void loop() {
  if (IrReceiver.decode()) 
  {
    IrReceiver.resume();
    data=IrReceiver.decodedIRData.command;
    Serial.println(data);
    if(data=="69")
    {digitalWrite(led,HIGH);}
    else if(data=="70")
    {digitalWrite(led,LOW);}
  }
}