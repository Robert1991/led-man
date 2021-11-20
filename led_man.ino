#include "ledMan.h"

#ifdef __arm__
// should use uinstd.h to define sbrk but Due causes a conflict
extern "C" char* sbrk(int incr);
#else  // __ARM__
extern char *__brkval;
#endif  // __arm__

int freeMemory() {
  char top;
#ifdef __arm__
  return &top - reinterpret_cast<char*>(sbrk(0));
#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
  return &top - __brkval;
#else  // __arm__
  return __brkval ? &top - __brkval : &top - __malloc_heap_start;
#endif  // __arm__
}


// LED heart actor initialization
const Led ledsOnShiftRegister1[7] = {Led(1, 4), Led(2, 5), Led(3, 6), Led(4, 3), Led(5, 2), Led(6, 1), Led(7, 0)};
const Led ledsOnShiftRegister2[8] = {Led(1, 7), Led(2, 6), Led(3, 5), Led(4, 4), Led(5, 3), Led(6, 2), Led(7, 1), Led(7, 0)};

// D0 Blau
// D1 Grün
// D2 Gelb

// D5 Blau
// D6 Weiß
// D7 Gelb

LedShiftRegisterPins shiftRegister1Pins = {D1, D2, D0};
LedShiftRegisterPins shiftRegister2Pins = {D6, D7, D5};

const int numberOfLedsShiftRegister1 = 7;
LedShiftRegister *shiftRegister1 = new LedShiftRegister(shiftRegister1Pins, ledsOnShiftRegister1, numberOfLedsShiftRegister1);

const int numberOfLedsShiftRegister2 = 8;
LedShiftRegister *shiftRegister2 = new LedShiftRegister(shiftRegister2Pins, ledsOnShiftRegister2, numberOfLedsShiftRegister2);

LedMan *ledMan = new LedMan(shiftRegister1, shiftRegister2);

int testArray[41][15] = {
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};

void setup()
{
  Serial.begin(9600);

  shiftRegister1->initializePins();
  shiftRegister2->initializePins();
}

void loop()
{
  Serial.print("used memory: ");
  Serial.println(sizeof(testArray));

  for (int i = 0; i < 41; i++)
  {
    ledMan->apply(testArray[i]);
    delay(100);
  }

  //  ledMan->turnOnAll();
  //  delay(1000);
  //  ledMan->turnOffAll();
  //  delay(1000);
  //  ledMan->turnOnAll();
  //  delay(1000);
  //  ledMan->turnOffAll();
  //  delay(1000);
  //
  //  for (int i = 0; i < LED_COUNT; i++) {
  //    ledMan->turnOn(i);
  //    delay(100);
  //  }
  //
  //  for (int i = 0; i < LED_COUNT; i++) {
  //    ledMan->turnOff(i);
  //    delay(100);
  //  }
  //
  //  delay(1000);
  //
  //  for (int i = 0; i < 1000; i++) {
  //    ledMan->turnOnRandomly(2);
  //    delay(10);
  //  }
}
