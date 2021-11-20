#ifndef ledMan_h
#define ledMan_h

#include "shiftregister.h"

const int LED_COUNT = 15;

class LedMan {
 private:
  LedShiftRegister *firstShiftRegister;
  LedShiftRegister *secondShiftRegister;

  bool alreadyTurnedOn(int *turnedOn, int arrayLength, int ledIndex);
  int nextRandomIntInBounds(int upper, int lower);
  void doForLed(int ledIndex, void (LedShiftRegister::*shiftRegisterFunctionPointer)(int));

 public:
  LedMan();
  LedMan(LedShiftRegister *lowerShiftRegister, LedShiftRegister *upperShiftRegister);

  void initialize();
  void apply(int bitArray[]);
  void turnOnAll();
  void turnOffAll();
  void turnOn(int ledIndex);
  void turnOff(int ledIndex);
  void turnOnRandomly(int minLedsTurnedOn = 0);
};


#endif
