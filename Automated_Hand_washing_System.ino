#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int ir=7;
int water=5;
#include <Servo.h>
Servo myservo;
int pos = 0;

// put your setup code here, to run once:
void setup()
{
  myservo.attach(6);
  pinMode(ir,INPUT);
  pinMode(water,OUTPUT);
  digitalWrite(water,LOW);
  delay(1000);
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  delay(1000);
  lcd.clear();
  lcd.print("Hand sanitizer");
  lcd.setCursor(0,1);
  lcd.print(" Dispenser ");
  delay(4000);
  myservo.write(0);
  delay(1000);
}

  // put your main code here, to run repeatedly:
void loop()
{

  while(1)
  {

    if(digitalRead(ir)==LOW)
    {
      lcd.clear();
      lcd.print("PERSON DETECTED");
      lcd.setCursor(0,1);
      lcd.print("SANITIZER ON");
      delay(2000);
      myservo.write(90);
      delay(1000);
      lcd.setCursor(0,1);
      lcd.print("SANITIZER OFF");
      delay(2000);
      myservo.write(0);
      delay(1000);

      for(int i=20;i>0;i--)
      {
        lcd.clear();
        lcd.print("WATER ON WITHIN");
        lcd.setCursor(5,1);
        lcd.print(i);
        lcd.print(" SEC");
        delay(1000);
      }

      digitalWrite(water,HIGH);

      for(int i=10;i>0;i--)
      {
        lcd.clear();
        lcd.print("WATER OFF WITHIN");
        lcd.setCursor(5,1);
        lcd.print(i);
        lcd.print(" SEC");
        delay(1000);
      }

      digitalWrite(water,LOW);
      delay(1000);
    }   

    if(digitalRead(ir)==HIGH)
    {
      lcd.clear();
      lcd.print("WAITING....");
      delay(100);
    }
  }
}
