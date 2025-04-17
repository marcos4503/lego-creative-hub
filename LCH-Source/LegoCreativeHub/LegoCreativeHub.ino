//Include dependency files
#include <PinsSetup.h>

//Include optional test files
#include "src/etc/ComponentsTest.h"

//Initialize the software

void setup() {
  //Initialize the Pins
  pinMode(pin_voltageSensor, INPUT);
  pinMode(pin_rButton, INPUT);
  pinMode(pin_lButton, INPUT);
  pinMode(pin_potentiometer, INPUT);
  pinMode(pin_pfPort1_c1, OUTPUT);
  digitalWrite(pin_pfPort1_c1, LOW);
  pinMode(pin_pfPort1_c2, OUTPUT);
  digitalWrite(pin_pfPort1_c2, LOW);
  pinMode(pin_pfPort2_c1, OUTPUT);
  digitalWrite(pin_pfPort2_c1, LOW);
  pinMode(pin_pfPort2_c2, OUTPUT);
  digitalWrite(pin_pfPort2_c2, LOW);
  pinMode(pin_pfPort3_c1, OUTPUT);
  digitalWrite(pin_pfPort3_c1, LOW);
  pinMode(pin_pfPort3_c2, OUTPUT);
  digitalWrite(pin_pfPort3_c2, LOW);
  pinMode(pin_pfPort4_c1, OUTPUT);
  digitalWrite(pin_pfPort4_c1, LOW);
  pinMode(pin_pfPort4_c2, OUTPUT);
  digitalWrite(pin_pfPort4_c2, LOW);
  //pinMode(pin_displaySCK, OUTPUT);   <- Not Necessary
  //pinMode(pin_displaySDA, OUTPUT);   <- Not Necessary
  //pinMode(pin_emPort1, OUTPUT);      <- Variable. Can change on Runtime
  //pinMode(pin_emPort2, OUTPUT);      <- Variable. Can change on Runtime
  //pinMode(pin_emPort3, OUTPUT);      <- Variable. Can change on Runtime
  //pinMode(pin_emPort4, OUTPUT);      <- Variable. Can change on Runtime
  //pinMode(pin_emPort5, OUTPUT);      <- Variable. Can change on Runtime
  //pinMode(pin_emPort6, OUTPUT);      <- Variable. Can change on Runtime
  //pinMode(pin_emPort7, OUTPUT);      <- Variable. Can change on Runtime
  //pinMode(pin_emPort8, OUTPUT);      <- Variable. Can change on Runtime
  pinMode(pin_buzzer, OUTPUT);
  digitalWrite(pin_buzzer, LOW);
  pinMode(pin_gsPort1, OUTPUT);
  digitalWrite(pin_gsPort1, LOW);
  pinMode(pin_gsPort2, OUTPUT);
  digitalWrite(pin_gsPort2, LOW);
  
  //---//
  
  //Test method. Uncomment if you need to run some Component Test. Tests can return messages on Serial Monitor.
  InitializeComponentTest();

  //---//
}

//Run the software on loop

void loop() {
  //Tests methods. Uncomment if you need to run some Component Test. Tests can return messages on Serial Monitor.
  //VoltageSensorTest(pin_voltageSensor);

  //---//


}





/*
//#include <ESP32Servo.h> 
//Servo myServo;

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); //SCK/SCL = pin22, SDA = 21

//int pinMotorC1 = 33;
//int pinMotorC2 = 32;

//int pin = 4;

void setup() {
  //myServo.attach(4);
  //myServo.write(0);

  //pinMode(pinMotorC1, OUTPUT);
  //digitalWrite(pinMotorC1, LOW);
  //pinMode(pinMotorC2, OUTPUT);
  //digitalWrite(pinMotorC2, LOW);

  //pinMode(pin, OUTPUT);

  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  //Display static text
  display.println("Hello, world!");
  display.display(); 

  //pinMode(36, INPUT);
  //pinMode(19, OUTPUT);
  //
}

void loop() {
  //digitalWrite(pin, HIGH);
  //delay(1000);
  //digitalWrite(pin, LOW);
  //delay(1000);

  //int analogValue = map(analogRead(36), 0, 4096, 0, 255);
  //Serial.println(analogValue);
  //analogWrite(19, analogValue);

  //digitalWrite(pin,HIGH);
  //delayMicroseconds(500);
  //digitalWrite(pin,LOW);
  //delayMicroseconds(500);

  //if (digitalRead(2) == HIGH){
  //  digitalWrite(4, HIGH);
  //}
  //if (digitalRead(2) == LOW){
  //  digitalWrite(4, LOW);
  //}

  //myServo.write(90);
  //delay(2500);
  //myServo.write(0);
  //delay(2500);

  //Must rotate for right >>>
  //digitalWrite(pinMotorC1, LOW); //forward
  //analogWrite(pinMotorC2, 125); //forward
  
  //digitalWrite(pinMotorC1, LOW); //forward
  //analogWrite(pinMotorC2, 130); //forward
  //delay(2500);
  //digitalWrite(pinMotorC1, LOW); //forward
  //analogWrite(pinMotorC2, 255); //forward
  //delay(2500);
  //digitalWrite(pinMotorC1, LOW); //stop
  //analogWrite(pinMotorC2, 0); //stop
  //delay(2500);
  //analogWrite(pinMotorC1, 130); //reverse
  //digitalWrite(pinMotorC2, LOW); //reverse
  //delay(2500);
  //analogWrite(pinMotorC1, 255); //reverse
  //digitalWrite(pinMotorC2, LOW); //reverse
  //delay(2500);
  //analogWrite(pinMotorC1, 0); //stop
  //digitalWrite(pinMotorC2, LOW); //stop
  //delay(2500);
}
*/