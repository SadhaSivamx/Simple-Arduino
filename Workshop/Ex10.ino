#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int val=0;
int pin1 = A0;
int Buzz = 10;
void setup() 
{
  Serial.begin(9600);
  lcd.begin();
  lcd.clear();         
  lcd.backlight();
  pinMode(pin1, INPUT);
  pinMode(Buzz, OUTPUT);
}
void BlowBuz()
{
  String text="   Buzzing   ";
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(text);
  for(int i=0;i<3;i++)
  {
    digitalWrite(Buzz,HIGH);
    delay(1000);
    digitalWrite(Buzz,LOW);
    delay(1000);
  }
}
void update()
{
  lcd.clear();
  String Head="  Arduino-Timer   ";
  String Time=" Setime : - "+String(val)+" +";
  lcd.setCursor(0,0);
  lcd.print(Head);
  lcd.setCursor(0,1);
  lcd.print(Time);
}
int SetClock(int Data)
{
  lcd.clear();
  String Timer;
  String Header;
  while(Data>=0)
  {

    delay(1000);
    Header="  Timer-Set   ";
    Timer=" Buz in "+String(Data)+" ...";
    lcd.setCursor(0,0);
    lcd.print(Header);
    lcd.setCursor(0,1);
    lcd.print(Timer);
    Data-=1;
  }
  if(Data==-1)
  {
    BlowBuz();
  }
  return 0;
}
void loop() 
{
  if((analogRead(pin1)==22 || analogRead(pin1)==21) && val<99) 
  {
    val+=1;
  }
  if((analogRead(pin1)==43 || analogRead(pin1)==42) && val>0)
  {
    val-=1;
  }
  if(analogRead(pin1)==1023)
  {
    SetClock(val);
  }
  Serial.println(analogRead(pin1));
  update();
  delay(200);
}
