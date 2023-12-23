#include <DHT.h>
#define DHTPIN 7     
#define DHTTYPE DHT11   
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin();
  lcd.clear();         
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();
}

void loop() 
{
  float humidity = dht.readHumidity();   
  float temperature = dht.readTemperature(); 
  lcd.setCursor(0,0);
  lcd.print("Temp : "+String(temperature)+" C");
  lcd.setCursor(0,1);
  lcd.print("Humi : "+String(humidity)+" %");
  lcd.clear();
  delay(2000);
}