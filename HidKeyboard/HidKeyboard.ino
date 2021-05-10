/*
  HID Keyboard example


  created 2020
  by Deqing Sun for use with CH55xduino

  This example code is in the public domain.

*/
//键位定义
//#define KeyPad1 KEY_F1
//#define KeyPad2 KEY_F2
//#define KeyPad3 KEY_F3
//#define KeyPad4 KEY_F4
//#define KeyPad5 KEY_F5
//#define KeyPad6 KEY_F6
//#define KeyPad7 KEY_F7
//#define KeyPad8 KEY_UP_ARROW
//#define KeyPad9 KEY_DOWN_ARROW

#define KeyPad1 KEY_F13
#define KeyPad2 KEY_F14
#define KeyPad3 KEY_F15
#define KeyPad4 KEY_F16
#define KeyPad5 KEY_F17
#define KeyPad6 KEY_F18
#define KeyPad7 KEY_F19
#define KeyPad8 KEY_F20
#define KeyPad9 KEY_F21

//#define KeyPad1 KEY_RIGHT_ARROW
//#define KeyPad2 KEY_LEFT_ARROW
//#define KeyPad3 KEY_END
//#define KeyPad4 'o'
//#define KeyPad5 'i'
//#define KeyPad6 KEY_HOME
//#define KeyPad7 'k'
//#define KeyPad8 'j'
//#define KeyPad9 'l'

//For windows user, if you ever played with other HID device with the same PID C55D
//You may need to uninstall the previous driver completely        


#define TX(LedColor) {\
  if (((LedColor)&0x80)==0) {\
       XdigitalWriteFast(3,4,HIGH);\
       (LedColor)=(LedColor)<<1;\
       XdigitalWriteFast(3,4,LOW);\
       XdigitalWriteFast(3,4,LOW);\
       XdigitalWriteFast(3,4,LOW);\
   }else{\
       XdigitalWriteFast(3,4,HIGH);\
       XdigitalWriteFast(3,4,HIGH);\
       XdigitalWriteFast(3,4,HIGH);\
       XdigitalWriteFast(3,4,HIGH);\
       XdigitalWriteFast(3,4,HIGH);\
       XdigitalWriteFast(3,4,HIGH);\
       XdigitalWriteFast(3,4,HIGH);\                       
       (LedColor)=(LedColor)<<1;\
       XdigitalWriteFast(3,4,LOW);\
       XdigitalWriteFast(3,4,LOW);\
       XdigitalWriteFast(3,4,LOW);\
       XdigitalWriteFast(3,4,LOW);\
       XdigitalWriteFast(3,4,LOW);\
       }\
  }
byte RValue,GValue,BValue;

#ifndef USER_USB_RAM
#error "This example needs to be compiled with a USER USB setting"
#endif

#include "USBHIDKeyboard.h"


//键盘引脚对应
#define BUTTON1_PIN 32
#define BUTTON2_PIN 14
#define BUTTON3_PIN 15
#define BUTTON4_PIN 16
#define BUTTON5_PIN 17
#define BUTTON6_PIN 11
#define EC11D_PIN 33
#define EC11A_PIN 31
#define EC11B_PIN 30

//#define BUTTON1_PIN 14
//#define BUTTON2_PIN 15
//#define BUTTON3_PIN 16
//#define BUTTON4_PIN 32
//#define BUTTON5_PIN 33
//#define BUTTON6_PIN 34
//#define EC11D_PIN 17
//#define EC11A_PIN 31
//#define EC11B_PIN 30
#define LEDPIN 34
volatile int     mRotaryEncoderPulse        = 0;
volatile uint8_t mLastestRotaryEncoderPinAB = 0; // last last pin value of A and B
volatile uint8_t mLastRotaryEncoderPinAB    = 0; // last pin value of A and B

bool button1PressPrev = false;
bool button2PressPrev = false;
bool button3PressPrev = false;
bool button4PressPrev = false;
bool button5PressPrev = false;
bool button6PressPrev = false;
bool button7PressPrev = false;
bool button8PressPrev = false;
bool button9PressPrev = false;

void setup() {
  USBInit();
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  pinMode(BUTTON4_PIN, INPUT_PULLUP);
  pinMode(BUTTON5_PIN, INPUT_PULLUP);
  pinMode(BUTTON6_PIN, INPUT_PULLUP);
  pinMode(EC11D_PIN, INPUT_PULLUP);
  pinMode(EC11A_PIN, INPUT_PULLUP);
  pinMode(EC11B_PIN, INPUT_PULLUP);

  pinMode(LEDPIN,OUTPUT);
  digitalWrite(LEDPIN,LOW); 
}

void loop() {
  bool button1Press = !digitalRead(BUTTON1_PIN);
  if (button1PressPrev != button1Press) {
    button1PressPrev = button1Press;
    if (button1Press) {
      Keyboard_press(KeyPad1);
    } else {
      Keyboard_release(KeyPad1);
    }
    delay(50);  //naive debouncing
  }

  bool button2Press = !digitalRead(BUTTON2_PIN);
  if (button2PressPrev != button2Press) {
    button2PressPrev = button2Press;
    if (button2Press) {
      Keyboard_press(KeyPad2);
    } else {
      Keyboard_release(KeyPad2);
    }
    delay(50);  //naive debouncing
  }

  bool button3Press = !digitalRead(BUTTON3_PIN);
  if (button3PressPrev != button3Press) {
    button3PressPrev = button3Press;
    if (button3Press) {
      Keyboard_press(KeyPad3);
    } else {
      Keyboard_release(KeyPad3);
    }
    delay(50);  //naive debouncing
  }

  bool button4Press = !digitalRead(BUTTON4_PIN);
  if (button4PressPrev != button4Press) {
    button4PressPrev = button4Press;
    if (button4Press) {
      Keyboard_press(KeyPad4);
    } else {
      Keyboard_release(KeyPad4);
    }
    delay(50);  //naive debouncing
  }

  bool button5Press = !digitalRead(BUTTON5_PIN);
  if (button5PressPrev != button5Press) {
    button5PressPrev = button5Press;
    if (button5Press) {
      Keyboard_press(KeyPad5);
    } else {
      Keyboard_release(KeyPad5);
    }
    delay(50);  //naive debouncing
  }

  bool button6Press = !digitalRead(BUTTON6_PIN);
  if (button6PressPrev != button6Press) {
    button6PressPrev = button6Press;
    if (button6Press) {
      Keyboard_press(KeyPad6);
    } else {
      Keyboard_release(KeyPad6);
    }
    delay(50);  //naive debouncing
  }

  bool button7Press = !digitalRead(EC11D_PIN);
  if (button7PressPrev != button7Press) {
    button7PressPrev = button7Press;
    if (button7Press) {
      Keyboard_press(KeyPad7);
    } else {
      Keyboard_release(KeyPad7);
    }
    delay(50);  //naive debouncing
  }

  uint8_t currentPin = digitalRead(EC11A_PIN) * 10 + digitalRead(EC11B_PIN);
  if (currentPin == mLastRotaryEncoderPinAB) {
      return;
    } 
  else {
        // (A<=>B) 表示旋转编码器的A脚和B脚的电平值
        // ---------------------------------------------------------------------------------------------------
        // (1<=>1) 是旋转编码的选择一个刻度的起始点
        // (1<=>0) 是旋转编码顺时针旋转的起始标识, (0<=>1) 是旋转编码逆时针旋转的起始标识
        // (0<=>0) 是旋转编码旋转一个刻度的中位点
        // (0<=>1) 是旋转编码顺时针旋转的终止标识, (0<=>1) 是旋转编码逆时针旋转的终止标识
        // (1<=>1) 是旋转编码的选择一个刻度的终止点，也是下一个刻度的起始点
        if (mLastRotaryEncoderPinAB == 00) {
          if (mLastestRotaryEncoderPinAB == 10 && currentPin == 01) {
            Keyboard_press(KeyPad8);
            delay(10);
            Keyboard_release(KeyPad8);
          }
          else if (mLastestRotaryEncoderPinAB == 01 && currentPin == 10) {
            Keyboard_press(KeyPad9);
            delay(10);
            Keyboard_release(KeyPad9);
          }
        }
        mLastestRotaryEncoderPinAB = mLastRotaryEncoderPinAB;
        mLastRotaryEncoderPinAB = currentPin;       
  }
  delay(5);  //naive debouncing
  
//    GValue=0x07;
//    RValue=0x00;
//    BValue=0x10;
//    //Send Green value from Bit7 to 0
//    TX(GValue);TX(GValue);TX(GValue);TX(GValue);TX(GValue);TX(GValue);TX(GValue);TX(GValue);
//    //Send Red value from Bit7 to 0
//    TX(RValue);TX(RValue);TX(RValue);TX(RValue);TX(RValue);TX(RValue);TX(RValue);TX(RValue);
//    //Send Blue value from Bit7 to 0
//    TX(BValue);TX(BValue);TX(BValue);TX(BValue);TX(BValue);TX(BValue);TX(BValue);TX(BValue);  
    
}
