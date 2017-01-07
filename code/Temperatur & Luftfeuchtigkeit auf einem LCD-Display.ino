#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);   //Hier wird festgelegt um was für einen Display es sich handelt. In diesem Fall einer mit 16 Zeichen in 2 Zeilen.
 
 
#define DHTPIN 8
#define DHTTYPE DHT11
 
// DHT sensor
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
lcd.begin(); //Im Setup wird der LCD gestartet
dht.begin(); //Im Setup wird der DHT11 gestartet
delay(500);
}
 
void loop() {
  // put your main code here, to run repeatedly:
int humidity_data = (int)dht.readHumidity();
int temperature_data = (int)dht.readTemperature();
lcd.setCursor(0,0); //Ab hier kann das I2C LCD Modul genau wie das einfache LCD Modul programmiert werden.
lcd.print("Temp.: ");
lcd.print(temperature_data); // lcd.print um etwas auf dem Display anzeigen zu lassen
lcd.print("\337C");
lcd.setCursor(0,1);  // lcd.setCursor um Zeichen und Zeile anzugeben
lcd.print("Feuchte: ");
lcd.print(humidity_data);
lcd.print("%");
delay(500);
 
}
