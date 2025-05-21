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

#endif