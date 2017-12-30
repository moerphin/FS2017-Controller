#include <Joystick.h>
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  17, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

int pinz[] = {1, 2, 3, 4, 5, 11, 10, 9, 8, 7, 6, A0, A1, A2, A3, A4, A5}; //Buttons to arduino pins
const int noPinz = 17; //array length
const int ledPin =  13;
void setup() {
  // Initialize Button Pins
  for (int pindex = 0; pindex < noPinz; pindex++)
  {
    pinMode(pinz[pindex], INPUT_PULLUP);
  }
  pinMode(ledPin, OUTPUT);
  // Initialize Joystick Library
  Joystick.begin();

}

// Last state of the buttons
int lastButtonState[noPinz] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void loop() {

  // Read pin values
  for (int index = 0; index < noPinz; index++)
  {
    int currentButtonState = !digitalRead(pinz[index]);
    if (currentButtonState != lastButtonState[index])
    {
      switch (index) {
        case 0: // switch
          Joystick.setButton(0, 1);
          delay(50);
          Joystick.setButton(0, 0);
          break;
        case 1: // button
          Joystick.setButton(1, currentButtonState);
          break;
        case 2: // button
          Joystick.setButton(2, currentButtonState);
          break;
        case 3: // button
          Joystick.setButton(3, currentButtonState);
          break;
        case 4: // button
          Joystick.setButton(4, 1);
          delay(50);
          Joystick.setButton(4, 0);
          break;
        case 5: // button
          Joystick.setButton(5, currentButtonState);
          break;
        case 6: // button
          Joystick.setButton(6, currentButtonState);
          break;
        case 7: // button
          Joystick.setButton(7, currentButtonState);
          break;
        case 8: // button
          Joystick.setButton(8, currentButtonState);
          break;
        case 9: // button
          Joystick.setButton(9, currentButtonState);
          break;
        case 10: // button
          Joystick.setButton(10, currentButtonState);
          break;
        case 11: // button
          Joystick.setButton(11, currentButtonState);
          break;
        case 12: // button
          Joystick.setButton(12, currentButtonState);
          break;
        case 13: // button
          Joystick.setButton(13, currentButtonState);
          break;
        case 14: // button
          Joystick.setButton(14, currentButtonState);
          break;
        case 15: // button
          Joystick.setButton(15, currentButtonState);
          break;
        case 16: // button
          Joystick.setButton(16, currentButtonState);
          break;
      }
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(50);
}

