#include <EEPROM.h>

int LED=13;

void setup() 
{
  Serial.begin(9600);
  //Initial Setup
  int value=EEPROM.read(0);
  digitalWrite(LED,value);
}

void loop() 
{
  if(Serial.available()>0)
  {

    char Re=Serial.read();
    Serial.println(Re);
    //if the Read is 0 then Off
    if(Re=='0')
    {
      digitalWrite(LED,0);
      EEPROM.write(0,0);
    }
    //if its on make it On
    else if(Re=='1')
    {
      digitalWrite(LED,1);
      EEPROM.write(0,1);
    }
  } 
  //Delay Sleep()
  delay(500);
}
