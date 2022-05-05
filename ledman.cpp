#include "ledman.h"

LedMan::LedMan(LedShiftRegister *leftShiftRegister, LedShiftRegister *rightShiftRegister)
{
  this->firstShiftRegister = leftShiftRegister;
  this->secondShiftRegister = rightShiftRegister;
}

void LedMan::initialize()
{
  firstShiftRegister->initializePins();
  secondShiftRegister->initializePins();
}

void LedMan::apply(int bitArray[])
{
  turnOffAll();
  for (int i = 0; i < LED_COUNT; i++)
  {
    if (bitArray[i] == 1)
    {
      turnOn(i);
    }
    else
    {
      turnOff(i);
    }
  }
}

void LedMan::turnOnAll()
{
  firstShiftRegister->turnOnAll();
  secondShiftRegister->turnOnAll();
}

void LedMan::turnOffAll()
{
  firstShiftRegister->turnOffAll();
  secondShiftRegister->turnOffAll();
}

void LedMan::turnOn(int ledIndex)
{
  void (LedShiftRegister::*ledShiftRegisterTurnLedOn)(int) = &LedShiftRegister::turnOn;
  doForLed(ledIndex, ledShiftRegisterTurnLedOn);
}

void LedMan::turnOff(int ledIndex)
{
  void (LedShiftRegister::*ledShiftRegisterTurnLedOff)(int) = &LedShiftRegister::turnOff;
  doForLed(ledIndex, ledShiftRegisterTurnLedOff);
}

void LedMan::turnOnRandomly(int minLedsTurnedOn)
{
  if (minLedsTurnedOn > 0 && minLedsTurnedOn <= LED_COUNT)
  {
    int numberOfLedsTurnedOn = nextRandomIntInBounds(minLedsTurnedOn, LED_COUNT);
    int turnedOnLeds[numberOfLedsTurnedOn];

    for (int i = 0; i < numberOfLedsTurnedOn; i++)
    {
      int nextLed = nextRandomIntInBounds(0, LED_COUNT);
      while (alreadyTurnedOn(turnedOnLeds, numberOfLedsTurnedOn, nextLed))
      {
        nextLed = nextRandomIntInBounds(0, LED_COUNT);
      }
      turnedOnLeds[i] = nextLed;
    }

    turnOffAll();
    for (int i = 0; i < numberOfLedsTurnedOn; i++)
    {
      turnOn(turnedOnLeds[i]);
    }
  }
}

int LedMan::nextRandomIntInBounds(int lower, int upper)
{
  return lower + rand() % (upper - lower + 1);
}

bool LedMan::alreadyTurnedOn(int *turnedOn, int arrayLength, int ledIndex)
{
  for (int i = 0; i < arrayLength; i++)
  {
    if (turnedOn[i] == ledIndex)
    {
      return true;
    }
  }

  return false;
}

void LedMan::doForLed(int ledIndex, void (LedShiftRegister::*shiftRegisterFunctionPointer)(int))
{
  if (ledIndex >= 0 && ledIndex < LED_COUNT)
  {
    switch (ledIndex)
    {
    case 0:
    case 1:
    case 2:
      (firstShiftRegister->*shiftRegisterFunctionPointer)(ledIndex);
      break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      (secondShiftRegister->*shiftRegisterFunctionPointer)(ledIndex - 3);
      break;
    case 11:
    case 12:
    case 13:
    case 14:
      (firstShiftRegister->*shiftRegisterFunctionPointer)(ledIndex - 8);
      break;
    }
  }
}
