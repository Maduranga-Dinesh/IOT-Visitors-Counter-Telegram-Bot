
#include <Wire.h> 

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 

#define sensorPin1 7
#define sensorPin2 8
//#define relay 3

int sensorState1 = 0;
int sensorState2 = 0;
int count=0;
int button = 0;
int pinup = 5;

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  Serial.begin(9600);
  pinMode (sensorPin1,INPUT_PULLUP);
  pinMode (sensorPin2,INPUT_PULLUP);
  pinMode(pinup,INPUT);
//  pinMode(relay, OUTPUT);
  
 // lcd.begin(16,2);
lcd.backlight();
 lcd.setCursor(0,0);
 lcd.print("Set Visitors");
 button = digitalRead(pinup);

 //lcd.print("COUNTER");
 Serial.print("COUNTER");
  lcd.setCursor(0,1);
  lcd.print("No Visitors     ");
  Serial.print("No Visitors     ");
  delay(200);
}

void loop()
{  

  button = digitalRead(pinup);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
 if(button == HIGH){
  count = count+1;
  lcd.setCursor(12,0);
  lcd.print(count);
  Serial.print(count);
  }
  
  sensorState1 = digitalRead(sensorPin1);
  sensorState2 = digitalRead(sensorPin2);

  if(sensorState1 == LOW){
    count++; 
    delay(500);
  }

  if(sensorState2 == LOW){
    count--; 
    delay(500);
  }
  

   if(count<=0)
  {
   // digitalWrite(relay, LOW); 
    lcd.setCursor(0,1);
    lcd.print("No visitors    ");
   Serial.println("No visitors    ");
  }
  else if (count>0 && count<10){
  //  digitalWrite(relay, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Visitors:   ");
   Serial.println("Visitors:");
    lcd.setCursor(12,1);
    lcd.print(count);
   Serial.println(count);
    lcd.setCursor(13,1);
    lcd.print("  "); 
    
  }
  else {
//    digitalWrite(relay, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Visitors:   ");
   Serial.println("Visitors:");
    lcd.setCursor(12,1);
    lcd.print(count);  
   Serial.println(count);
  }
 
}
