//210322 fujigaya2 PsCon2Switch

#include "SwitchControlLibrary.h"
#include "Psx.h"                                          // Includes the Psx Library 
                                                          // Any pins can be used since it is done in software
#define dataPin A3 //8
#define cmndPin A2 //9
#define attPin A1 //11
#define clockPin A0 //10

//USB SERIAL DEBUGをする場合はコメントアウトを取る
//#define USB_SERIAL_ENABLE

Psx Psx;                                                  // Initializes the library

unsigned int data = 0;                                    // data stores the controller response

void setup()
{
  Psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10);
#if defined(USB_SERIAL_ENABLE)
  Serial.begin(112500);
#endif
  SwitchControlLibrary();
  button_release();
  SwitchControlLibrary().moveLeftStick(128, 128);
  SwitchControlLibrary().moveRightStick(128, 128);
}

void loop()
{
  data = Psx.read();                                      
#if defined(USB_SERIAL_ENABLE)                            
  Serial.print(data,HEX);                                 
  Serial.print(",");
  Serial.print(Psx.getRightLR(),HEX);
  Serial.print(",");
  Serial.print(Psx.getRightUD(),HEX);
  Serial.print(",");
  Serial.print(Psx.getLeftLR(),HEX);
  Serial.print(",");
  Serial.print(Psx.getLeftUD(),HEX);
  Serial.println("");
#endif
  
  button_release();
  if (data & psxLeft){SwitchControlLibrary().pressHatButton(HatButton::LEFT);}
  if (data & psxDown){SwitchControlLibrary().pressHatButton(HatButton::DOWN);}
  if (data & psxRight){SwitchControlLibrary().pressHatButton(HatButton::RIGHT);}
  if (data & psxUp){SwitchControlLibrary().pressHatButton(HatButton::UP);}
  if (data & psxStrt){SwitchControlLibrary().pressButton(Button::HOME);}
  if (data & psxSlct){SwitchControlLibrary().pressButton(Button::PLUS);}
  if (data & psxSqu){SwitchControlLibrary().pressButton(Button::Y);}
  if (data & psxX){SwitchControlLibrary().pressButton(Button::B);}
  if (data & psxO){SwitchControlLibrary().pressButton(Button::A);}
  if (data & psxTri){SwitchControlLibrary().pressButton(Button::X);}
  if (data & psxR1){SwitchControlLibrary().pressButton(Button::R);}
  if (data & psxL1){SwitchControlLibrary().pressButton(Button::L);}
  if (data & psxR2){SwitchControlLibrary().pressButton(Button::ZR);}
  if (data & psxL2){SwitchControlLibrary().pressButton(Button::ZL);}
  if (data & psxJoyR){SwitchControlLibrary().pressButton(Button::RCLICK);}
  if (data & psxJoyL){SwitchControlLibrary().pressButton(Button::LCLICK);}
  //ボタン系を送信
  SwitchControlLibrary().sendReport();

  SwitchControlLibrary().moveLeftStick(Psx.getLeftLR(),Psx.getLeftUD());
  SwitchControlLibrary().moveRightStick(Psx.getRightLR(),Psx.getRightUD());
  //ボタン系を送信
  SwitchControlLibrary().sendReport();
  
  //delay(1);
}

void button_release()
{
  //全ボタンリリース(Left_Stick以外）
  SwitchControlLibrary().releaseButton(Button::Y);
  SwitchControlLibrary().releaseButton(Button::B);
  SwitchControlLibrary().releaseButton(Button::A);
  SwitchControlLibrary().releaseButton(Button::X);
  SwitchControlLibrary().releaseButton(Button::L);
  SwitchControlLibrary().releaseButton(Button::R);
  SwitchControlLibrary().releaseButton(Button::ZL);
  SwitchControlLibrary().releaseButton(Button::ZR);
  SwitchControlLibrary().releaseButton(Button::MINUS);
  SwitchControlLibrary().releaseButton(Button::PLUS);
  SwitchControlLibrary().releaseButton(Button::LCLICK);
  SwitchControlLibrary().releaseButton(Button::RCLICK);
  SwitchControlLibrary().releaseButton(Button::HOME);
  SwitchControlLibrary().releaseButton(Button::CAPTURE);
  SwitchControlLibrary().releaseHatButton(HatButton::UP);
  SwitchControlLibrary().releaseHatButton(HatButton::RIGHT);
  SwitchControlLibrary().releaseHatButton(HatButton::DOWN);
  SwitchControlLibrary().releaseHatButton(HatButton::LEFT);
}
