int inPin = 7;    
int BzPin = 8;
void setup() 
{
  Serial.begin(9600);
  pinMode(inPin, INPUT);    
  pinMode(BzPin, OUTPUT);    
}

void loop() {
  int val = digitalRead(inPin);  
  Serial.println(val);  
  if(val)
  {
    digitalWrite(BzPin,LOW);
  }
  else
  {
    digitalWrite(BzPin,HIGH);
  }
}