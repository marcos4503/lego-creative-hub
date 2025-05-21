//Include dependency files
#include <Arduino.h>
#include "../libraries/Button2/src/Button2.h"

//Private variables
unsigned long lastTestRunTimeOf_voltageSensor = 0;
bool alreadyDefinedRButtonCallback = false;

//Initialization methods

void InitializeComponentTest(){
  //This method should be called on "setup()" of main "ino" file, to initialize the Serial Communiction to do the tests
  Serial.begin(115200);

  //Warn that the test module was setuped
  Serial.println("The LCH Components Test was prepared!");
}

//Auxiliar methods

void RButtonTapped(Button2& btn){
  Serial.println("R Button tapped!");
}

void RButtonPressed(Button2& btn){
  Serial.println("R Button pressed!");
}

void RButtonReleased(Button2& btn){
  Serial.print("R Button released! (Pressed during ");
  Serial.print(btn.wasPressedFor());
  Serial.println(" ms)");
}

void RButtonDoubleTapped(Button2& btn){
  Serial.println("R Button was double tapped!");
}

void RButtonTripleTapped(Button2& btn){
  Serial.println("R Button was triple tapped!");
}

//Components test methods

void VoltageSensorTest(int pin_voltageSensor){
  //Get current milliseconds time
  int currentMillis = millis();

  //If can run the test, run it
  if ((currentMillis - lastTestRunTimeOf_voltageSensor) >= 1000){
    //Read the current analog voltage value of voltage sensor
    int voltageAnalogValue = analogRead(pin_voltageSensor);

    //In a Battery of 7.4v (two Lithium Cells of 3.7v) with a Voltage Sensor based in Voltage Divider of 47kΩ
    //In fully charged the "voltageAnalogValue" value is 1760 (7.5v)
    //In very close to discharged the "voltageAnalogValue" value is 1170 (5.2v)

    //Convert the analog voltage into voltage value
    float realVoltage = ((map(voltageAnalogValue, 0, 1760, 0, 75) / 75.0) * 7.5);
    if (realVoltage > 7.5)
        realVoltage = 7.5;
    if (realVoltage < 0.0)
        realVoltage = 0.0;

    //Print the result to Serial Monitor
    Serial.print("Voltage Sensor Result: ");
    Serial.println(realVoltage, 2);

    //Update the last run time
    lastTestRunTimeOf_voltageSensor = currentMillis;
  }
}

void RButtonTest(Button2& rButtonRef){
  //If not defined the R Button callback yet, define it
  if (alreadyDefinedRButtonCallback == false){
    //Define callbacks of R Button
    rButtonRef.setTapHandler(RButtonTapped);
    rButtonRef.setPressedHandler(RButtonPressed);
    rButtonRef.setReleasedHandler(RButtonReleased);
    rButtonRef.setDoubleClickHandler(RButtonDoubleTapped);
    rButtonRef.setTripleClickHandler(RButtonTripleTapped);

    //Inform that the R Button callback was defined
    alreadyDefinedRButtonCallback = true;
  }
}

void LButtonTest(int pin_lButton){

}