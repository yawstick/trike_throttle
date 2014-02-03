#include <Servo.h> 
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  // initialize the library with the numbers of thepins interface 
Servo myservo;  // create servo object to control a servo 
 
int pot_pin = 3;  // analog pin used to connect the potentiometer
int spd;    // variable to read the value from the analog pin 
int curr_pin = 5;
int curr;
int set_spd;
int anl_0;
int anl_1;
int anl_2;
int anl_3;
int anl_4;
int anl_5;
int myset=5;
int myscr =0;
float volts = 0;
long previousMillis = 0; 
long interval = 500;
float curr2 = 0;
float curr3 = 0;

void setup() 
{ 
Serial.begin(9600);
myservo.attach(3);  // attaches the servo on pin 9 to the servo object 
lcd.begin(20, 4);
pinMode(myset, INPUT_PULLUP);
}
 
void loop() {
  
curr = analogRead(curr_pin);
curr2 = curr - 122;
curr3 = curr2 / 10.00;

set_spd = analogRead(pot_pin);            // reads the value of the potentiometer (value between 0 and 1023) 
spd = map(set_spd, 200, 800, 60, 120);     // scale it to use it with the servo (value between 50 and 130) 

anl_0 = analogRead(0);
anl_0 = analogRead(1);
anl_2 = analogRead(2);
anl_3 = analogRead(3);
anl_4 = analogRead(4);
anl_5 = analogRead(5);

if (digitalRead(myset) == 0)  myscr = myscr + 1; 

if (myscr < 0) myscr = 3;
if (myscr > 3) myscr = 0;

volts = (anl_4/34.53);

myservo.write(spd);                  // sets the servo position according to the scaled value 
//delay(100);   
unsigned long currentMillis = millis();
if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;   
    switch (myscr) {
    case 1: write_data1();
    break;
    case 2: write_data2();
    break;
    case 3: write_data3();
    break;
    default: write_data();
        }}}

void write_data() {
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Raw Inputs Spd ");
lcd.print(set_spd);
lcd.setCursor(0, 1);
lcd.print("Set Speed  ");
lcd.print(spd);
lcd.setCursor(0, 2);
lcd.print("Volts  ");
lcd.print(volts);
lcd.setCursor(13, 2);
lcd.print("Raw ");
lcd.print(anl_0);
lcd.setCursor(0, 3);
lcd.print("Curr ");
lcd.print(curr3);
}

void write_data1() {
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Analog 3 Input  ");
lcd.print(set_spd);
lcd.setCursor(0, 1);
lcd.print("Set Speed  ");
lcd.print(spd);
lcd.setCursor(0, 2);
lcd.print("Volts  ");
lcd.print(anl_3);
lcd.setCursor(0, 3);
lcd.print("MPH ");
lcd.print(set_spd);
lcd.setCursor(11, 3);
lcd.print("Curr ");
lcd.print(anl_0);
}

void write_data2() {
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Analog 4 Input  ");
lcd.print(set_spd);
lcd.setCursor(0, 1);
lcd.print("Set Speed  ");
lcd.print(spd);
lcd.setCursor(0, 2);
lcd.print("Volts  ");
lcd.print(anl_3);
lcd.setCursor(0, 3);
lcd.print("MPH ");
lcd.print(set_spd);
lcd.setCursor(11, 3);
lcd.print("Curr ");
lcd.print(anl_0);
}

void write_data3() {
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Analog 4 Input  ");
lcd.print(set_spd);
lcd.setCursor(0, 1);
lcd.print("Set Speed  ");
lcd.print(spd);
lcd.setCursor(0, 2);
lcd.print("Volts  ");
lcd.print(anl_3);
lcd.setCursor(0, 3);
lcd.print("MPH ");
lcd.print(set_spd);
lcd.setCursor(11, 3);
lcd.print("Curr ");
lcd.print(anl_0);
}










