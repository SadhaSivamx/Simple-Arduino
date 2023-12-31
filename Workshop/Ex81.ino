#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
void setup() 
{
  Serial.begin(9600);
  mySwitch.enableTransmit(10);
}
void loop() 
{
  mySwitch.send(1000, 24);
  delay(3000);
  mySwitch.send(2000, 24);
  delay(3000);  
} 
