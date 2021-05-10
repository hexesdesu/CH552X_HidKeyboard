/*
  HID Keyboard example


  created 2020
  by Deqing Sun for use with CH55xduino

  This example code is in the public domain.

*/
//键位定义
#define KeyPad1 KEY_F13
#define KeyPad2 KEY_F14
#define KeyPad3 KEY_F15
#define KeyPad4 KEY_F16
#define KeyPad5 KEY_F17
#define KeyPad6 KEY_F18
#define KeyPad7 KEY_F19
#define KeyPad8 KEY_F20

////键盘引脚对应v1
//#define BUTTON1_PIN 15
//#define BUTTON2_PIN 10
//#define BUTTON3_PIN 17
//#define BUTTON4_PIN 31
//#define LED1_PIN 14
//#define LED2_PIN 11
//#define LED3_PIN 16
//#define LED4_PIN 30

//键盘引脚对应v2
#define BUTTON1_PIN 31
#define BUTTON2_PIN 14
#define BUTTON3_PIN 10
#define BUTTON4_PIN 17
#define LED1_PIN 30
#define LED2_PIN 32
#define LED3_PIN 11
#define LED4_PIN 16

//For windows user, if you ever played with other HID device with the same PID C55D
//You may need to uninstall the previous driver completely        

#ifndef USER_USB_RAM
#error "This example needs to be compiled with a USER USB setting"
#endif

#include "USBHIDKeyboard.h"

volatile int     mRotaryEncoderPulse        = 0;
volatile uint8_t mLastestRotaryEncoderPinAB = 0; // last last pin value of A and B
volatile uint8_t mLastRotaryEncoderPinAB    = 0; // last pin value of A and B

bool button1PressPrev = false;
bool button2PressPrev = false;
bool button3PressPrev = false;
bool button4PressPrev = false;

bool button1Layer = false;
bool button2Layer = false;
bool button3Layer = false;
bool button4Layer = false;

void setup() {
  USBInit();
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  pinMode(BUTTON4_PIN, INPUT_PULLUP);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
}

void loop() {
  bool button1Press = !digitalRead(BUTTON1_PIN);
  if (button1PressPrev != button1Press) {
    button1PressPrev = button1Press;
    if (button1Press) {
      if (button1Layer){
        Keyboard_press(KeyPad1);
        digitalWrite(LED1_PIN,1);
        button1Layer=false;
        }
      else{
        Keyboard_press(KeyPad5);
        digitalWrite(LED1_PIN,0);
        button1Layer=true;
        }
    } else {
      Keyboard_releaseAll();
    }
    delay(50);  //naive debouncing
  }

  bool button2Press = !digitalRead(BUTTON2_PIN);
  if (button2PressPrev != button2Press) {
    button2PressPrev = button2Press;
    if (button2Press) {
      if (button2Layer){
        Keyboard_press(KeyPad2);
        digitalWrite(LED2_PIN,1);
        button2Layer=false;
        }
      else{
        Keyboard_press(KeyPad6);
        digitalWrite(LED2_PIN,0);
        button2Layer=true;
        }
    } else {
      Keyboard_releaseAll();
    }
    delay(50);  //naive debouncing
  }

  bool button3Press = !digitalRead(BUTTON3_PIN);
  if (button3PressPrev != button3Press) {
    button3PressPrev = button3Press;
    if (button3Press) {
      if (button3Layer){
        Keyboard_press(KeyPad3);
        digitalWrite(LED3_PIN,1);
        button3Layer=false;
        }
      else{
        Keyboard_press(KeyPad7);
        digitalWrite(LED3_PIN,0);
        button3Layer=true;
        }
    } else {
      Keyboard_releaseAll();
    }
    delay(50);  //naive debouncing
  }

  bool button4Press = !digitalRead(BUTTON4_PIN);
  if (button4PressPrev != button4Press) {
    button4PressPrev = button4Press;
    if (button4Press) {
      if (button4Layer){
        Keyboard_press(KeyPad4);
        digitalWrite(LED4_PIN,1);
        button4Layer=false;
        }
      else{
        Keyboard_press(KeyPad8);
        digitalWrite(LED4_PIN,0);
        button4Layer=true;
        }
    } else {
      Keyboard_releaseAll();
    }
    delay(50);  //naive debouncing
  }
}
