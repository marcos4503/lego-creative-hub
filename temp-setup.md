# Preparing Arduino IDE for ESP32

Before uploading codes to ESP32, it is necessary to prepare the Arduino IDE for this. In this topic you will see how to do this in a simple way. Follow the steps below to perform this procedure.

1. Download and install Arduino IDE (recommended version is 2.X.X). You can click <a href="https://downloads.arduino.cc/arduino-ide/arduino-ide_2.3.4_Windows_64bit.exe">this link</a> to download.
2. With the Arduino IDE open, click the "File" tab and then "Preferences...".
3. In the field of "Additional boards manager URLs", paste the value "https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json" (without quotes).
4. Still in the "Preferences" window, click "OK" to save.
5. Now click on the "Tools" tab, then "Board" and then "Boards Manager...".
6. In the window that opens, search for "ESP32 (by Espressif Systems)" and click "Install".
7. Wait for the end of downloading and installing of packages.

To test the board and the code uploading, we will prepare and load a simple code. This will also be useful for showing you the board configuration process and code uploading. Follow the steps below to perform the test.

1. First, we need to install the ESP32 driver on the computer. It is a driver for the "CP2102 USB to Uart Bridge Controller" which is the Chip responsible for connecting the ESP32 Chip and the USB interface used by computers. The driver is the "CP210X Windows Drivers" that can be downloaded <a href="https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads">here</a> (or alternatively <a href="https://github.com/marcos4503/lego-creative-hub/tree/main/This-Repository">here</a>). After downloading it, simply unzip it and execute the "CP210xvcpinstaller_x64.exe" file to perform the installation.
2. Connect your ESP32 board to your computer, using a USB Cable.
3. At Arduino IDE, click the "Tools" tab, then click "Board", then "ESP32", finally select "ESP32 Dev Module".
4. Again, go to the "Tools" tab, then click "Port" and select some port such as "COMX", which is the Windows port for your ESP32 device.
5. Now, let's get a small demonstration code, ready. This code will cause ESP32 to inform the chip data to the Arduino IDE when executed. To do this, click "File", then "Examples", then "ESP32", then click "ChipID" and finally click "GetChipID". A new Arduino IDE window, with a new project will open, with the example code present there.
6. Now, to compile the source code and upload it to the ESP32, click the "Sketch" tab and then click "Upload".
7. To view what ESP32 may be returning to the Arduino IDE, click "Tools" then "Serial Monitor". Serial Monitor displays all the text that ESP32 may be returning to your computer.

If in the end, you are seeing a text similar to the text below, being returned by your ESP32, then the whole process has ran as expected and you are ready to load your codes to ESP32.

```
ESP32 Chip model = ESP32-D0WD-V3 Rev 301
This chip has 2 cores
Chip ID: 11202528
```

If you are not seeing anything returned by ESP32, try uploading the code again. If you still don't see anything, try to review all the steps shown above.