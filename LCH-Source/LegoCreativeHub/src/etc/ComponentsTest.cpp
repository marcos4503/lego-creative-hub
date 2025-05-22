//Include dependency files
#include <Arduino.h>
#include "../libraries/Button2/src/Button2.h"

//Private variables
unsigned long lastTestRunTimeOf_voltageSensor = 0;
bool alreadyDefinedRButtonCallback = false;
unsigned long lastTestRunTimeOf_potentiometer = 0;
bool alreadyDefinedLButtonCallback = false;
unsigned long lastTestRunTimeOf_pf1Port = 0;

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

void LButtonTapped(Button2& btn){
  Serial.println("L Button tapped!");
}

void LButtonPressed(Button2& btn){
  Serial.println("L Button pressed!");
}

void LButtonReleased(Button2& btn){
  Serial.print("L Button released! (Pressed during ");
  Serial.print(btn.wasPressedFor());
  Serial.println(" ms)");
}

void LButtonDoubleTapped(Button2& btn){
  Serial.println("L Button was double tapped!");
}

void LButtonTripleTapped(Button2& btn){
  Serial.println("L Button was triple tapped!");
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

void RButtonTest(int pin_rButton, Button2& rButtonRef){
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

  //Reading in raw mode
  //if (digitalRead(pin_rButton) == HIGH){
  //  digitalWrite(pin_output, HIGH);
  //}
  //if (digitalRead(pin_rButton) == LOW){
  //  digitalWrite(pin_output, LOW);
  //}
}

void PotentiometerTest(int pin_potentiometer){
  //Get current milliseconds time
  int currentMillis = millis();

  //If can run the test, run it
  if ((currentMillis - lastTestRunTimeOf_potentiometer) >= 1000){
    //Read the current analog voltage value of potentiometer
    int potentiometerValue = analogRead(pin_potentiometer);

    //With a standard 9mm Shaft Potentiometer, with recommended LCH connections
    //In fully rotated potentiometer, the "potentiometerValue" value is 4095
    //In fully zero potentiometer, the "potentiometerValue" value is 0

    //Convert the potentiometer value to a percent value
    float percentValue = ((map(potentiometerValue, 0, 4095, 0, 100) / 100.0) * 100.0);

    //Print the result to Serial Monitor
    Serial.print("Potentiometer Result: ");
    Serial.println(percentValue, 2);

    //Update the last run time
    lastTestRunTimeOf_potentiometer = currentMillis;
  }
}

void LButtonTest(int pin_lButton, Button2& lButtonRef){
  //If not defined the L Button callback yet, define it
  if (alreadyDefinedLButtonCallback == false){
    //Define callbacks of L Button
    lButtonRef.setTapHandler(LButtonTapped);
    lButtonRef.setPressedHandler(LButtonPressed);
    lButtonRef.setReleasedHandler(LButtonReleased);
    lButtonRef.setDoubleClickHandler(LButtonDoubleTapped);
    lButtonRef.setTripleClickHandler(LButtonTripleTapped);

    //Inform that the L Button callback was defined
    alreadyDefinedLButtonCallback = true;
  }

  //Reading in raw mode
  //if (digitalRead(pin_lButton) == HIGH){
  //  digitalWrite(pin_output, HIGH);
  //}
  //if (digitalRead(pin_lButton) == LOW){
  //  digitalWrite(pin_output, LOW);
  //}
}

void PF1PortTest(int pin_pfPort1_c1, int pin_pfPort1_c2){
  //Get current milliseconds time
  int currentMillis = millis();
  if ((currentMillis - lastTestRunTimeOf_pf1Port) >= 13000){
    //Update the last run time
    lastTestRunTimeOf_pf1Port = currentMillis;
  }
    

  //This will run in Power Function Port 1...

  //Stop the Power Function Port 1...
  if ((currentMillis - lastTestRunTimeOf_pf1Port) >= 0 && (currentMillis - lastTestRunTimeOf_pf1Port) < 500){
    //Send signal to Stop
    analogWrite(pin_pfPort1_c1, 0);
    analogWrite(pin_pfPort1_c2, 0);
  }

  //Rotate in Speed Min to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_pf1Port) >= 500 && (currentMillis - lastTestRunTimeOf_pf1Port) < 3500){
    //Send signal to Right
    digitalWrite(pin_pfPort1_c1, LOW);
    analogWrite(pin_pfPort1_c2, 130);
  }

  //Rotate in Speed Max to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_pf1Port) >= 3500 && (currentMillis - lastTestRunTimeOf_pf1Port) < 6500){
    //Send signal to Right
    digitalWrite(pin_pfPort1_c1, LOW);
    analogWrite(pin_pfPort1_c2, 255);
  }

  //Stop the Power Function Port 1...
  if ((currentMillis - lastTestRunTimeOf_pf1Port) >= 6500 && (currentMillis - lastTestRunTimeOf_pf1Port) < 7000){
    //Send signal to Stop
    analogWrite(pin_pfPort1_c1, 0);
    analogWrite(pin_pfPort1_c2, 0);
  }

  //Rotate in Speed Min to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_pf1Port) >= 7000 && (currentMillis - lastTestRunTimeOf_pf1Port) < 10000){
    //Send signal to Left
    analogWrite(pin_pfPort1_c1, 130);
    digitalWrite(pin_pfPort1_c2, LOW);
  }

  //Rotate in Speed Max to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_pf1Port) >= 10000 && (currentMillis - lastTestRunTimeOf_pf1Port) < 13000){
    //Send signal to Left
    analogWrite(pin_pfPort1_c1, 255);
    digitalWrite(pin_pfPort1_c2, LOW);
  }
}
