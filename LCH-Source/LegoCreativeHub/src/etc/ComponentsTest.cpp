//Include dependency files
#include <Arduino.h>
#include "../libraries/Button2/src/Button2.h"
#include "../libraries/ezBuzzer/src/ezBuzzer.h"
#include "../libraries/ESP32Servo/src/ESP32Servo.h"

//Private variables
unsigned long lastTestRunTimeOf_voltageSensor = 0;
bool alreadyDefinedRButtonCallback = false;
unsigned long lastTestRunTimeOf_potentiometer = 0;
bool alreadyDefinedLButtonCallback = false;
unsigned long lastTestRunTimeOf_pf1Port = 0;
unsigned long lastTestRunTimeOf_pf2Port = 0;
unsigned long lastTestRunTimeOf_pf3Port = 0;
unsigned long lastTestRunTimeOf_pf4Port = 0;
unsigned long lastTestRunTimeOf_em1Port = 0;
bool status_em1Port = false;
unsigned long lastTestRunTimeOf_em2Port = 0;
bool status_em2Port = false;
unsigned long lastTestRunTimeOf_em3Port = 0;
bool status_em3Port = false;
unsigned long lastTestRunTimeOf_em4Port = 0;
bool status_em4Port = false;
unsigned long lastTestRunTimeOf_em5Port = 0;
bool status_em5Port = false;
unsigned long lastTestRunTimeOf_em6Port = 0;
bool status_em6Port = false;
unsigned long lastTestRunTimeOf_em7Port = 0;
bool status_em7Port = false;
unsigned long lastTestRunTimeOf_em8Port = 0;
bool status_em8Port = false;
unsigned long lastTestRunTimeOf_buzzer = 0;
bool runnedStage1_buzzer = false;
bool runnedStage2_buzzer = false;
int melodieNotes_buzzer[] = {     NOTE_B0, NOTE_E1, NOTE_A1, NOTE_D2, NOTE_G2, NOTE_C3, NOTE_F3, NOTE_B3, NOTE_F4, NOTE_B4, NOTE_F5, NOTE_A5, NOTE_D6, NOTE_G6, NOTE_C7, NOTE_F7, NOTE_B7, NOTE_DS8 };  //<- Notes in Melody
int melodieNotesDurations_buzzer[] = {  4,       4,       4,       4,       4,       4,       4,       4,       4,       4,       4,       4,       4,       4,       4,       4,       4,        4 };  //<- Notes Tempo, 1 = full, 2 = half note, 4 = quarter note, 8 = eighth note
unsigned long lastTestRunTimeOf_gs1Port = 0;
unsigned long lastTestRunTimeOf_gs2Port = 0;

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

void PF2PortTest(int pin_pfPort2_c1, int pin_pfPort2_c2){
  //Get current milliseconds time
  int currentMillis = millis();
  if ((currentMillis - lastTestRunTimeOf_pf2Port) >= 13000){
    //Update the last run time
    lastTestRunTimeOf_pf2Port = currentMillis;
  }
    

  //This will run in Power Function Port 1...

  //Stop the Power Function Port 1...
  if ((currentMillis - lastTestRunTimeOf_pf2Port) >= 0 && (currentMillis - lastTestRunTimeOf_pf2Port) < 500){
    //Send signal to Stop
    analogWrite(pin_pfPort2_c1, 0);
    analogWrite(pin_pfPort2_c2, 0);
  }

  //Rotate in Speed Min to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_pf2Port) >= 500 && (currentMillis - lastTestRunTimeOf_pf2Port) < 3500){
    //Send signal to Right
    digitalWrite(pin_pfPort2_c1, LOW);
    analogWrite(pin_pfPort2_c2, 130);
  }

  //Rotate in Speed Max to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_pf2Port) >= 3500 && (currentMillis - lastTestRunTimeOf_pf2Port) < 6500){
    //Send signal to Right
    digitalWrite(pin_pfPort2_c1, LOW);
    analogWrite(pin_pfPort2_c2, 255);
  }

  //Stop the Power Function Port 1...
  if ((currentMillis - lastTestRunTimeOf_pf2Port) >= 6500 && (currentMillis - lastTestRunTimeOf_pf2Port) < 7000){
    //Send signal to Stop
    analogWrite(pin_pfPort2_c1, 0);
    analogWrite(pin_pfPort2_c2, 0);
  }

  //Rotate in Speed Min to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_pf2Port) >= 7000 && (currentMillis - lastTestRunTimeOf_pf2Port) < 10000){
    //Send signal to Left
    analogWrite(pin_pfPort2_c1, 130);
    digitalWrite(pin_pfPort2_c2, LOW);
  }

  //Rotate in Speed Max to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_pf2Port) >= 10000 && (currentMillis - lastTestRunTimeOf_pf2Port) < 13000){
    //Send signal to Left
    analogWrite(pin_pfPort2_c1, 255);
    digitalWrite(pin_pfPort2_c2, LOW);
  }
}

void PF3PortTest(int pin_pfPort3_c1, int pin_pfPort3_c2){
  //Get current milliseconds time
  int currentMillis = millis();
  if ((currentMillis - lastTestRunTimeOf_pf3Port) >= 13000){
    //Update the last run time
    lastTestRunTimeOf_pf3Port = currentMillis;
  }
    

  //This will run in Power Function Port 1...

  //Stop the Power Function Port 1...
  if ((currentMillis - lastTestRunTimeOf_pf3Port) >= 0 && (currentMillis - lastTestRunTimeOf_pf3Port) < 500){
    //Send signal to Stop
    analogWrite(pin_pfPort3_c1, 0);
    analogWrite(pin_pfPort3_c2, 0);
  }

  //Rotate in Speed Min to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_pf3Port) >= 500 && (currentMillis - lastTestRunTimeOf_pf3Port) < 3500){
    //Send signal to Right
    digitalWrite(pin_pfPort3_c1, LOW);
    analogWrite(pin_pfPort3_c2, 130);
  }

  //Rotate in Speed Max to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_pf3Port) >= 3500 && (currentMillis - lastTestRunTimeOf_pf3Port) < 6500){
    //Send signal to Right
    digitalWrite(pin_pfPort3_c1, LOW);
    analogWrite(pin_pfPort3_c2, 255);
  }

  //Stop the Power Function Port 1...
  if ((currentMillis - lastTestRunTimeOf_pf3Port) >= 6500 && (currentMillis - lastTestRunTimeOf_pf3Port) < 7000){
    //Send signal to Stop
    analogWrite(pin_pfPort3_c1, 0);
    analogWrite(pin_pfPort3_c2, 0);
  }

  //Rotate in Speed Min to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_pf3Port) >= 7000 && (currentMillis - lastTestRunTimeOf_pf3Port) < 10000){
    //Send signal to Left
    analogWrite(pin_pfPort3_c1, 130);
    digitalWrite(pin_pfPort3_c2, LOW);
  }

  //Rotate in Speed Max to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_pf3Port) >= 10000 && (currentMillis - lastTestRunTimeOf_pf3Port) < 13000){
    //Send signal to Left
    analogWrite(pin_pfPort3_c1, 255);
    digitalWrite(pin_pfPort3_c2, LOW);
  }
}

void PF4PortTest(int pin_pfPort4_c1, int pin_pfPort4_c2){
  //Get current milliseconds time
  int currentMillis = millis();
  if ((currentMillis - lastTestRunTimeOf_pf4Port) >= 13000){
    //Update the last run time
    lastTestRunTimeOf_pf4Port = currentMillis;
  }
    

  //This will run in Power Function Port 1...

  //Stop the Power Function Port 1...
  if ((currentMillis - lastTestRunTimeOf_pf4Port) >= 0 && (currentMillis - lastTestRunTimeOf_pf4Port) < 500){
    //Send signal to Stop
    analogWrite(pin_pfPort4_c1, 0);
    analogWrite(pin_pfPort4_c2, 0);
  }

  //Rotate in Speed Min to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_pf4Port) >= 500 && (currentMillis - lastTestRunTimeOf_pf4Port) < 3500){
    //Send signal to Right
    digitalWrite(pin_pfPort4_c1, LOW);
    analogWrite(pin_pfPort4_c2, 130);
  }

  //Rotate in Speed Max to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_pf4Port) >= 3500 && (currentMillis - lastTestRunTimeOf_pf4Port) < 6500){
    //Send signal to Right
    digitalWrite(pin_pfPort4_c1, LOW);
    analogWrite(pin_pfPort4_c2, 255);
  }

  //Stop the Power Function Port 1...
  if ((currentMillis - lastTestRunTimeOf_pf4Port) >= 6500 && (currentMillis - lastTestRunTimeOf_pf4Port) < 7000){
    //Send signal to Stop
    analogWrite(pin_pfPort4_c1, 0);
    analogWrite(pin_pfPort4_c2, 0);
  }

  //Rotate in Speed Min to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_pf4Port) >= 7000 && (currentMillis - lastTestRunTimeOf_pf4Port) < 10000){
    //Send signal to Left
    analogWrite(pin_pfPort4_c1, 130);
    digitalWrite(pin_pfPort4_c2, LOW);
  }

  //Rotate in Speed Max to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_pf4Port) >= 10000 && (currentMillis - lastTestRunTimeOf_pf4Port) < 13000){
    //Send signal to Left
    analogWrite(pin_pfPort4_c1, 255);
    digitalWrite(pin_pfPort4_c2, LOW);
  }
}

void EMPort1Test(int pin_emPort1){
  //Get current milliseconds time
  int currentMillis = millis();

  //If can run the test, run it
  if ((currentMillis - lastTestRunTimeOf_em1Port) >= 150){
    //Update the last run time
    lastTestRunTimeOf_em1Port = currentMillis;

    //Send a blink signal in Extra Module Port 1
    if (status_em1Port == false){
      pinMode(pin_emPort1, OUTPUT);
      digitalWrite(pin_emPort1, LOW);
      status_em1Port = true;
      return;
    }
    if (status_em1Port == true){
      pinMode(pin_emPort1, OUTPUT);
      digitalWrite(pin_emPort1, HIGH);
      status_em1Port = false;
      return;
    }
  }
}

void EMPort2Test(int pin_emPort2){
  //Get current milliseconds time
  int currentMillis = millis();

  //If can run the test, run it
  if ((currentMillis - lastTestRunTimeOf_em2Port) >= 150){
    //Update the last run time
    lastTestRunTimeOf_em2Port = currentMillis;

    //Send a blink signal in Extra Module Port 2
    if (status_em2Port == false){
      pinMode(pin_emPort2, OUTPUT);
      digitalWrite(pin_emPort2, LOW);
      status_em2Port = true;
      return;
    }
    if (status_em2Port == true){
      pinMode(pin_emPort2, OUTPUT);
      digitalWrite(pin_emPort2, HIGH);
      status_em2Port = false;
      return;
    }
  }
}

void EMPort3Test(int pin_emPort3){
  //Get current milliseconds time
  int currentMillis = millis();

  //If can run the test, run it
  if ((currentMillis - lastTestRunTimeOf_em3Port) >= 150){
    //Update the last run time
    lastTestRunTimeOf_em3Port = currentMillis;

    //Send a blink signal in Extra Module Port 3
    if (status_em3Port == false){
      pinMode(pin_emPort3, OUTPUT);
      digitalWrite(pin_emPort3, LOW);
      status_em3Port = true;
      return;
    }
    if (status_em3Port == true){
      pinMode(pin_emPort3, OUTPUT);
      digitalWrite(pin_emPort3, HIGH);
      status_em3Port = false;
      return;
    }
  }
}

void EMPort4Test(int pin_emPort4){
  //Get current milliseconds time
  int currentMillis = millis();

  //If can run the test, run it
  if ((currentMillis - lastTestRunTimeOf_em4Port) >= 150){
    //Update the last run time
    lastTestRunTimeOf_em4Port = currentMillis;

    //Send a blink signal in Extra Module Port 4
    if (status_em4Port == false){
      pinMode(pin_emPort4, OUTPUT);
      digitalWrite(pin_emPort4, LOW);
      status_em4Port = true;
      return;
    }
    if (status_em4Port == true){
      pinMode(pin_emPort4, OUTPUT);
      digitalWrite(pin_emPort4, HIGH);
      status_em4Port = false;
      return;
    }
  }
}

void EMPort5Test(int pin_emPort5){
  //Get current milliseconds time
  int currentMillis = millis();

  //If can run the test, run it
  if ((currentMillis - lastTestRunTimeOf_em5Port) >= 150){
    //Update the last run time
    lastTestRunTimeOf_em5Port = currentMillis;

    //Send a blink signal in Extra Module Port 5
    if (status_em5Port == false){
      pinMode(pin_emPort5, OUTPUT);
      digitalWrite(pin_emPort5, LOW);
      status_em5Port = true;
      return;
    }
    if (status_em5Port == true){
      pinMode(pin_emPort5, OUTPUT);
      digitalWrite(pin_emPort5, HIGH);
      status_em5Port = false;
      return;
    }
  }
}

void EMPort6Test(int pin_emPort6){
  //Get current milliseconds time
  int currentMillis = millis();

  //If can run the test, run it
  if ((currentMillis - lastTestRunTimeOf_em6Port) >= 150){
    //Update the last run time
    lastTestRunTimeOf_em6Port = currentMillis;

    //Send a blink signal in Extra Module Port 6
    if (status_em6Port == false){
      pinMode(pin_emPort6, OUTPUT);
      digitalWrite(pin_emPort6, LOW);
      status_em6Port = true;
      return;
    }
    if (status_em6Port == true){
      pinMode(pin_emPort6, OUTPUT);
      digitalWrite(pin_emPort6, HIGH);
      status_em6Port = false;
      return;
    }
  }
}

void EMPort7Test(int pin_emPort7){
  //Get current milliseconds time
  int currentMillis = millis();

  //If can run the test, run it
  if ((currentMillis - lastTestRunTimeOf_em7Port) >= 150){
    //Update the last run time
    lastTestRunTimeOf_em7Port = currentMillis;

    //Send a blink signal in Extra Module Port 7
    if (status_em7Port == false){
      pinMode(pin_emPort7, OUTPUT);
      digitalWrite(pin_emPort7, LOW);
      status_em7Port = true;
      return;
    }
    if (status_em7Port == true){
      pinMode(pin_emPort7, OUTPUT);
      digitalWrite(pin_emPort7, HIGH);
      status_em7Port = false;
      return;
    }
  }
}

void EMPort8Test(int pin_emPort8){
  //Get current milliseconds time
  int currentMillis = millis();

  //If can run the test, run it
  if ((currentMillis - lastTestRunTimeOf_em8Port) >= 150){
    //Update the last run time
    lastTestRunTimeOf_em8Port = currentMillis;

    //Send a blink signal in Extra Module Port 8
    if (status_em8Port == false){
      pinMode(pin_emPort8, OUTPUT);
      digitalWrite(pin_emPort8, LOW);
      status_em8Port = true;
      return;
    }
    if (status_em8Port == true){
      pinMode(pin_emPort8, OUTPUT);
      digitalWrite(pin_emPort8, HIGH);
      status_em8Port = false;
      return;
    }
  }
}

void BuzzerTest(int pin_buzzer, ezBuzzer& buzzerRef){
  //Get current milliseconds time
  int currentMillis = millis();
  if ((currentMillis - lastTestRunTimeOf_buzzer) >= 8000){
    //Update the last run time
    lastTestRunTimeOf_buzzer = currentMillis;
    runnedStage1_buzzer = false;
    runnedStage2_buzzer = false;
  }
    

  //This will play the Buzzer in test mode

  //Buzzer status
  //0 - BUZZER_IDLE       - Buzzer is not playing anything.
  //1 - BUZZER_BEEP_DELAY - Buzzer is playing a beep, but is in the delay part.
  //2 - BUZZER_BEEPING    - Buzzer is playing a beep.
  //3 - BUZZER_MELODY     - Buzzer is playing a melody.

  //Run stage 1 of test
  if ((currentMillis - lastTestRunTimeOf_buzzer) >= 0 && (currentMillis - lastTestRunTimeOf_buzzer) < 1000){
    if (runnedStage1_buzzer == false){
      //Show the current status of the Buzzer
      Serial.println("Buzzer Stopped.");
      Serial.print("Buzzer Current State: ");
      Serial.println(buzzerRef.getState());

      //Play a beep
      Serial.println("Playing a Beep...");
      if (buzzerRef.getState() != 0)
        buzzerRef.stop();
      if (buzzerRef.getState() == 0)
        buzzerRef.beep(100);   //<-- Generates a 100ms beep
      Serial.print("Buzzer Current State: ");
      Serial.println(buzzerRef.getState());

      //Inform that was runned
      runnedStage1_buzzer = true;
    }
  }

  //Run stage 2 of test
  if ((currentMillis - lastTestRunTimeOf_buzzer) >= 3000 && (currentMillis - lastTestRunTimeOf_buzzer) < 7000){
    if (runnedStage2_buzzer == false){
      //Show the current status of the Buzzer
      Serial.println("Buzzer Stopped.");
      Serial.print("Buzzer Current State: ");
      Serial.println(buzzerRef.getState());

      //Play a melody
      Serial.println("Playing a Melody...");
      if (buzzerRef.getState() != 0)
        buzzerRef.stop();
      if (buzzerRef.getState() == 0)
        buzzerRef.playMelody(melodieNotes_buzzer, melodieNotesDurations_buzzer, (sizeof(melodieNotesDurations_buzzer) / sizeof(int)));   //<- Play the Melody, duration varies according to quantity of Notes
      Serial.print("Buzzer Current State: ");
      Serial.println(buzzerRef.getState());

      //Inform that was runned
      runnedStage2_buzzer = true;
    }
  }

  //Run stage 3 of test
  if ((currentMillis - lastTestRunTimeOf_buzzer) >= 7000 && (currentMillis - lastTestRunTimeOf_buzzer) < 8000){ }
}

void GS1PortTest(int pin_gsPort1, Servo& servoRef){
  //Get current milliseconds time
  int currentMillis = millis();
  if ((currentMillis - lastTestRunTimeOf_gs1Port) >= 21500){
    //Update the last run time
    lastTestRunTimeOf_gs1Port = currentMillis;
  }
    

  //This will run in GeekServo Port 1...

  //GeekServos can rotate until 360°, so, to use a GeekServo in -90°~90° the degrees is different...
  //-90° is 45°  on GeekServo
  //0°   is 90°  on GeekServo
  //90°  is 135° on GeekServo

  //Reset the GeekServo Port 1...
  if ((currentMillis - lastTestRunTimeOf_gs1Port) >= 0 && (currentMillis - lastTestRunTimeOf_gs1Port) < 500){
    //Send signal to 0°
    servoRef.write(90);
  }

  //Rotate to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_gs1Port) >= 500 && (currentMillis - lastTestRunTimeOf_gs1Port) < 3500){
    //Send signal to 30°
    servoRef.write(105);
  }

  //Rotate to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_gs1Port) >= 3500 && (currentMillis - lastTestRunTimeOf_gs1Port) < 6500){
    //Send signal to 60°
    servoRef.write(120);
  }

  //Rotate to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_gs1Port) >= 6500 && (currentMillis - lastTestRunTimeOf_gs1Port) < 9500){
    //Send signal to 90°
    servoRef.write(135);
  }

  //Reset the GeekServo Port 1...
  if ((currentMillis - lastTestRunTimeOf_gs1Port) >= 9500 && (currentMillis - lastTestRunTimeOf_gs1Port) < 12500){
    //Send signal to 0°
    servoRef.write(90);
  }

  //Rotate to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_gs1Port) >= 12500 && (currentMillis - lastTestRunTimeOf_gs1Port) < 15500){
    //Send signal to -30°
    servoRef.write(75);
  }

  //Rotate to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_gs1Port) >= 15500 && (currentMillis - lastTestRunTimeOf_gs1Port) < 18500){
    //Send signal to -60°
    servoRef.write(60);
  }

  //Rotate to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_gs1Port) >= 18500 && (currentMillis - lastTestRunTimeOf_gs1Port) < 21500){
    //Send signal to -90°
    servoRef.write(45);
  }
}

void GS2PortTest(int pin_gsPort2, Servo& servoRef){
  //Get current milliseconds time
  int currentMillis = millis();
  if ((currentMillis - lastTestRunTimeOf_gs2Port) >= 21500){
    //Update the last run time
    lastTestRunTimeOf_gs2Port = currentMillis;
  }
    

  //This will run in GeekServo Port 2...

  //GeekServos can rotate until 360°, so, to use a GeekServo in -90°~90° the degrees is different...
  //-90° is 45°  on GeekServo
  //0°   is 90°  on GeekServo
  //90°  is 135° on GeekServo

  //Reset the GeekServo Port 2...
  if ((currentMillis - lastTestRunTimeOf_gs2Port) >= 0 && (currentMillis - lastTestRunTimeOf_gs2Port) < 500){
    //Send signal to 0°
    servoRef.write(90);
  }

  //Rotate to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_gs2Port) >= 500 && (currentMillis - lastTestRunTimeOf_gs2Port) < 3500){
    //Send signal to 30°
    servoRef.write(105);
  }

  //Rotate to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_gs2Port) >= 3500 && (currentMillis - lastTestRunTimeOf_gs2Port) < 6500){
    //Send signal to 60°
    servoRef.write(120);
  }

  //Rotate to RIGHT>>>
  if ((currentMillis - lastTestRunTimeOf_gs2Port) >= 6500 && (currentMillis - lastTestRunTimeOf_gs2Port) < 9500){
    //Send signal to 90°
    servoRef.write(135);
  }

  //Reset the GeekServo Port 2...
  if ((currentMillis - lastTestRunTimeOf_gs2Port) >= 9500 && (currentMillis - lastTestRunTimeOf_gs2Port) < 12500){
    //Send signal to 0°
    servoRef.write(90);
  }

  //Rotate to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_gs2Port) >= 12500 && (currentMillis - lastTestRunTimeOf_gs2Port) < 15500){
    //Send signal to -30°
    servoRef.write(75);
  }

  //Rotate to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_gs2Port) >= 15500 && (currentMillis - lastTestRunTimeOf_gs2Port) < 18500){
    //Send signal to -60°
    servoRef.write(60);
  }

  //Rotate to LEFT<<<
  if ((currentMillis - lastTestRunTimeOf_gs2Port) >= 18500 && (currentMillis - lastTestRunTimeOf_gs2Port) < 21500){
    //Send signal to -90°
    servoRef.write(45);
  }
}