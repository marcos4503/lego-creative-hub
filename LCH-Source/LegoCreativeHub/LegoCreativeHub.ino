//Include dependency files
#include <PinsSetup.h>
#include "src/libraries/Button2/src/Button2.h"
#include <SPI.h>
#include <Wire.h>
#include "src/libraries/Adafruit-GFX-Library/Adafruit_GFX.h"
#include "src/libraries/Adafruit_SSD1306/Adafruit_SSD1306.h"

//Initialize needed libraries
Button2 libRef_rButton;
Button2 libRef_lButton;
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

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

  //Initialize methods. Needed to some libraries receive the processing setup from the ESP32.
  libRef_rButton.begin(pin_rButton, INPUT_PULLUP, false);
  libRef_lButton.begin(pin_lButton, INPUT_PULLUP, false);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {   //<--- Address 0x3D for 128x64
    //Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(13, 14);
  display.println("Lego Creative Hub");
  display.display();

  //---//

  //Wait more initialization time
  delay(1000);

  //---//
  
  //Test method. Uncomment if you need to run some Component Test. Tests can return messages on Serial Monitor.
  InitializeComponentTest();
  return;

  //---//

  //...
}

//Run the software on loop

void loop() {
  //Loop methods. Needed to some libraries receive the processing loop from the ESP32.
  libRef_rButton.loop();
  libRef_lButton.loop();

  //---//

  //Tests methods. Uncomment if you need to run some Component Test. Tests can return messages on Serial Monitor.
  //VoltageSensorTest(pin_voltageSensor);
  //RButtonTest(pin_rButton, libRef_rButton);
  //PotentiometerTest(pin_potentiometer);
  //LButtonTest(pin_lButton, libRef_lButton);
  //PF1PortTest(pin_pfPort1_c1, pin_pfPort1_c2);
  //PF2PortTest(pin_pfPort2_c1, pin_pfPort2_c2);
  //PF3PortTest(pin_pfPort3_c1, pin_pfPort3_c2);
  //PF4PortTest(pin_pfPort4_c1, pin_pfPort4_c2);
  //EMPort1Test(pin_emPort1);
  //EMPort2Test(pin_emPort2);
  //EMPort3Test(pin_emPort3);
  //EMPort4Test(pin_emPort4);
  //EMPort5Test(pin_emPort5);
  //EMPort6Test(pin_emPort6);
  //EMPort7Test(pin_emPort7);
  //EMPort8Test(pin_emPort8);
  
  //Required for tests methods. Uncomment if you need to run some Component Test. Tests can return messages on Serial Monitor.
  return;

  //---//

  //...
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