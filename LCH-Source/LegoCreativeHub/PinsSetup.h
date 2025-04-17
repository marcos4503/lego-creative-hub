#ifndef _PINS_SETUP_
#define _PINS_SETUP_

/*
 * This file contains references for each Pin (or component) of ESP32, regarding the components required
 * for the Lego Creative Hub mini-computer. All Lego Creative Hub software uses this file to get these references.
 *
 * If in the mini-computer that you have assembled, have some component linked to a different Pin than expected,
 * you can change the Pin ID here.
*/

// ------------------------------------ ESP32-WROOM-32 DOIT DEVKIT EXPECTED GPIO PINS TABLE ----------------------------------- //
//Pin EN  - ID XX - None         - None                    ! > Disable or Enable the ESP32 Chip.
//Pin VP  - ID 36 - Input        - Voltage Sensor 
//Pin VN  - ID 39 - Input        - R Button
//Pin D34 - ID 34 - Input        - Potentiometer
//Pin D35 - ID 35 - Input        - L Button
//Pin D32 - ID 32 - Input/Output - PF Port 4 C2
//Pin D33 - ID 33 - Input/Output - PF Port 4 C1
//Pin D25 - ID 25 - Input/Output - PF Port 3 C2
//Pin D26 - ID 26 - Input/Output - PF Port 3 C1
//Pin D27 - ID 27 - Input/Output - PF Port 2 C2
//Pin D14 - ID 14 - Input/Output - PF Port 2 C1
//Pin D12 - ID 12 - Input/Output - PF Port 1 C2            ! > Used during BOOT. Should be defined as LOW by default after boot
//Pin D13 - ID 13 - Input/Output - PF Port 1 C1 
//Pin GND - ID XX - None         - None                    ! > Used for complete circuits. Is the Ground connection, a.k.a as (-)
//Pin VIN - ID XX - None         - None                    ! > Can be used to direct power the ESP32 with 5v, a.k.a Voltage Input
//Pin D23 - ID 23 - Input/Output - Extra Module Port 8
//Pin D22 - ID 22 - Input/Output - Display SCK/SCL
//Pin TX0 - ID  1 - Input/Output - Extra Module Port 7     ! > Used by UART Chip. Don't use "Serial.begin()" if using this Pin
//Pin RX0 - ID  3 - Input/Output - Extra Module Port 6     ! > Used by UART Chip. Don't use "Serial.begin()" if using this Pin
//Pin D21 - ID 21 - Input/Output - Display SDA
//Pin D19 - ID 19 - Input/Output - Extra Module Port 5
//Pin D18 - ID 18 - Input/Output - Extra Module Port 4
//Pin  D5 - ID  5 - Input/Output - Extra Module Port 3     ! > Used during BOOT. Should be defined as HIGH by default after boot
//Pin TX2 - ID 17 - Input/Output - Extra Module Port 2
//Pin RX2 - ID 16 - Input/Output - Extra Module Port 1
//Pin  D4 - ID  4 - Input/Output - GeekServo Port 2
//Pin  D2 - ID  2 - Input/Output - Buzzer                  ! > Used by On-Board LED. Should be defined as LOW by def. after boot
//Pin D15 - ID 15 - Input/Output - GeekServo Port 1        ! > Used during BOOT. Should be defined as HIGH by default after boot
//Pin GND - ID XX - None         - None                    ! > Used for complete circuits. Is the Ground connection, a.k.a as (-)
//Pin 3V3 - ID XX - None         - None                    ! > Can dir. power the ESP32 with 3.3v OR provides 3.3v/600mA as Output
// ---------------------------------------------------------------------------------------------------------------------------- //

//Pins references

int pin_voltageSensor = 36;
int pin_rButton = 39;
int pin_lButton = 35;
int pin_potentiometer = 34;
int pin_pfPort1_c1 = 13;
int pin_pfPort1_c2 = 12;
int pin_pfPort2_c1 = 14;
int pin_pfPort2_c2 = 27;
int pin_pfPort3_c1 = 26;
int pin_pfPort3_c2 = 25;
int pin_pfPort4_c1 = 33;
int pin_pfPort4_c2 = 32;
int pin_displaySCK = 22;
int pin_displaySDA = 21;
int pin_emPort1 = 16;
int pin_emPort2 = 17;
int pin_emPort3 = 5;
int pin_emPort4 = 18;
int pin_emPort5 = 19;
int pin_emPort6 = 3;
int pin_emPort7 = 1;
int pin_emPort8 = 23;
int pin_buzzer = 2;
int pin_gsPort1 = 15;
int pin_gsPort2 = 4;

#endif