#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
void setup() 
{
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}
void loop() 
{
  if (mySwitch.available()) 
  {    
    int value = mySwitch.getReceivedValue();
    if (value == 0) 
    {
      Serial.print("Unknown encoding");
    } 
    else 
    {
      Serial.println("Received "+String(mySwitch.getReceivedValue()));
    }
    mySwitch.resetAvailable();
  }
}
