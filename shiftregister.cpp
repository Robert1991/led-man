#include "shiftregister.h"

Led::Led() {
  this->ledNumber = -1;
  this->shiftRegisterPosition = -1;
}


Led::Led(int ledNum, int shiftRegisterPosition) {
  this->ledNumber = ledNum;
  this->shiftRegisterPosition = shiftRegisterPosition;
}

void Led::turnOn() { on = true; }

void Led::turnOff() { on = false; }

LedShiftRegister::LedShiftRegister(LedShiftRegisterPins pins, const Led *ledsOnShiftRegister, int totalLedCount) {
  this->pins = pins;
  this->shiftRegisterByte = 0;
  this-> totalLedCount = totalLedCount;
  for (int i = 0; i < totalLedCount; i++) {
    this->leds[i] = ledsOnShiftRegister[i];
  }
}


void LedShiftRegister::updateShiftRegister() {
  updateShiftRegisterByte();
   
  digitalWrite(pins.latchPin, LOW);
  shiftOut(pins.dataPin, pins.clockPin, LSBFIRST, shiftRegisterByte);
  digitalWrite(pins.latchPin, HIGH);
}

void LedShiftRegister::updateShiftRegisterByte() {
  shiftRegisterByte = 0;

  for (int i = 0; i < totalLedCount; i++) {
    Led led = leds[i];
    if (led.on) {
      bitSet(shiftRegisterByte, led.shiftRegisterPosition);
    } else {
      bitClear(shiftRegisterByte, led.shiftRegisterPosition);
    }
  }
}

void LedShiftRegister::turnOn(int ledIndex) {
  if (ledIndex >= 0 && ledIndex < totalLedCount) {
    leds[ledIndex].turnOn();
    updateShiftRegister();
  }
}

void LedShiftRegister::turnOff(int ledIndex) {
  if (ledIndex >= 0 && ledIndex < totalLedCount) {
    leds[ledIndex].turnOff();
    updateShiftRegister();
  }
}

void LedShiftRegister::turnOffAll() {
  for (int i = 0; i < totalLedCount; i++) {
    leds[i].turnOff();
  }

  updateShiftRegister();
}

void LedShiftRegister::turnOnAll() {
  for (int i = 0; i < totalLedCount; i++) {
    leds[i].turnOn();
  }

  updateShiftRegister();
}

void LedShiftRegister::initializePins() {
  pinMode(pins.latchPin, OUTPUT);
  pinMode(pins.dataPin, OUTPUT);
  pinMode(pins.clockPin, OUTPUT);
}
