#ifndef _COMPONENTS_TEST_HEADER_
#define _COMPONENTS_TEST_HEADER_

//Include dependency files
#include <Arduino.h>
#include "../libraries/Button2/src/Button2.h"

//Define the methods

void InitializeComponentTest();
void VoltageSensorTest(int pin_voltageSensor);
void RButtonTest(int pin_rButton, Button2& rButtonRef);
void RButtonTapped(Button2& btn);
void RButtonPressed(Button2& btn);
void RButtonReleased(Button2& btn);
void RButtonDoubleTapped(Button2& btn);
void RButtonTripleTapped(Button2& btn);
void PotentiometerTest(int pin_potentiometer);
void LButtonTest(int pin_rButton, Button2& rButtonRef);
void LButtonTapped(Button2& btn);
void LButtonPressed(Button2& btn);
void LButtonReleased(Button2& btn);
void LButtonDoubleTapped(Button2& btn);
void LButtonTripleTapped(Button2& btn);
void PF1PortTest(int pin_pfPort1_c1, int pin_pfPort1_c2);
void PF2PortTest(int pin_pfPort2_c1, int pin_pfPort2_c2);
void PF3PortTest(int pin_pfPort3_c1, int pin_pfPort3_c2);
void PF4PortTest(int pin_pfPort4_c1, int pin_pfPort4_c2);
void EMPort1Test(int pin_emPort1);
void EMPort2Test(int pin_emPort2);
void EMPort3Test(int pin_emPort3);
void EMPort4Test(int pin_emPort4);
void EMPort5Test(int pin_emPort5);
void EMPort6Test(int pin_emPort6);
void EMPort7Test(int pin_emPort7);
void EMPort8Test(int pin_emPort8);

#endif