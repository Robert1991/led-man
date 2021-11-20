#ifndef shiftregister_h
#define shiftregister_h

#include "Arduino.h"

const int MAX_SHIFT_REGISTER_LED_COUNT = 8;

class Led {
 private:
  int ledNumber;

 public:
  int shiftRegisterPosition;
  bool on;

  Led(int ledNum, int shiftRegisterPosition);
  Led();
  void turnOn();
  void turnOff();
};


#ifndef LedShiftRegisterPins
typedef struct LedShiftRegisterPins {
  int latchPin;
  int clockPin;
  int dataPin;
};
#endif


class LedShiftRegister {
 private:
  byte shiftRegisterByte;
  LedShiftRegisterPins pins;
  Led leds[MAX_SHIFT_REGISTER_LED_COUNT];
  int totalLedCount;

  void updateShiftRegister();
  void updateShiftRegisterByte();

 public:
  LedShiftRegister();
  LedShiftRegister(LedShiftRegisterPins pins, const Led *ledsOnShiftRegister, int totalLedCount);

  void turnOn(int ledIndex);
  void turnOff(int ledIndex);
  void turnOffAll();
  void turnOnAll();
  void initializePins();
};

#endif