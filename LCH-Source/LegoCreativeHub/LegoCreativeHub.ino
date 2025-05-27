//Include dependency files
#include <PinsSetup.h>
#include <SPI.h>
#include <Wire.h>
#include "src/libraries/Button2/src/Button2.h"
#include "src/libraries/Adafruit-GFX-Library/Adafruit_GFX.h"
#include "src/libraries/Adafruit_SSD1306/Adafruit_SSD1306.h"
#include "src/libraries/ezBuzzer/src/ezBuzzer.h"
#include "src/libraries/ESP32Servo/src/ESP32Servo.h"

//Initialize needed libraries
Button2 libRef_rButton;
Button2 libRef_lButton;
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 libRef_display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
ezBuzzer libRef_buzzer(pin_buzzer);
Servo libRef_geekServoPort1;
Servo libRef_geekServoPort2;

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
  libRef_geekServoPort1.attach(pin_gsPort1);
  libRef_geekServoPort1.write(90);   //<- 90° is equivalent to 0° in GeekServos
  libRef_geekServoPort2.attach(pin_gsPort2);
  libRef_geekServoPort2.write(90);   //<- 90° is equivalent to 0° in GeekServos
  if(!libRef_display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {   //<--- Address 0x3D for 128x64
    //Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  libRef_display.clearDisplay();
  libRef_display.setTextSize(1);
  libRef_display.setTextColor(WHITE);
  libRef_display.setCursor(13, 14);
  libRef_display.println("Lego Creative Hub");
  libRef_display.display();

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
  libRef_buzzer.loop();

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
  BuzzerTest(pin_buzzer, libRef_buzzer);
  //GS1PortTest(pin_gsPort1, libRef_geekServoPort1);
  //GS2PortTest(pin_gsPort2, libRef_geekServoPort2);
  
  //Required for tests methods. Uncomment if you need to run some Component Test. Tests can return messages on Serial Monitor.
  return;

  //---//

  //...
}