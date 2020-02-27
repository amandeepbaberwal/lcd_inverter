
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int lightPin = 9;
int motionPin = 13;
int seconds = 0;
bool lightOn;
int timer = 0.0;
int maxTimeToLcdLightOn = 5;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(1, 0);
  lcd.print("TSR");
  pinMode(lightPin,OUTPUT);
  pinMode(motionPin, INPUT);
  lightOn = true;
  Serial.begin(9600);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // print the number of seconds since reset:
  int motionValue = digitalRead(motionPin);
  Serial.println(motionValue);
  if(motionValue){
    lightOn = true;
    lcd.setCursor(1, 0);
    lcd.print("Intruder alert alert");
    lcd.setCursor(1, 1);
    lcd.print("system engaged");
  }else{
    lightOn = true;
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("kya apko khatra h");
    lcd.setCursor(1, 1);
    lcd.print(seconds);
  }
  delay(1000);
  seconds = millis()/1000;
  lcd.setCursor(1, 1);
  lcd.print(seconds);
  if(lightOn){
    digitalWrite(lightPin, HIGH);
    timer = maxTimeToLcdLightOn - seconds;
    if(timer == 0){
      lightOn = false;
    }
  }
  else{
    digitalWrite(lightPin, LOW);
  }
  
}

