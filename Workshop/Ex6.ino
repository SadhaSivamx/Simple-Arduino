int inPin = 7;    // pushbutton connected to digital pin 7
int led=13;
void setup() 
{
  Serial.begin(9600);
  pinMode(inPin, INPUT);
  pinMode(led, OUTPUT); 
}

void loop() {
  int val = digitalRead(inPin);   
  Serial.println(val);
  if(val)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
}