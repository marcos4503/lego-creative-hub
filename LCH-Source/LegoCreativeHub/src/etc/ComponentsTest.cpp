//Include dependency files
#include <Arduino.h>

//Private variables
unsigned long lastTestRunTimeOf_voltageSensor = 0;

//Initialization methods

void InitializeComponentTest(){
  //This method should be called on "setup()" of main "ino" file, to initialize the Serial Communiction to do the tests
  Serial.begin(115200);
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