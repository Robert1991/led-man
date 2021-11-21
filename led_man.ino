#include "ledMan.h"
#include "lightshow.h"

// D0 blue
// D1 green
// D2 yellow
const int NUMBER_OF_LEDS_SHIFT_REGISTER_1 = 7;
const Led LEDS_ON_SHIFT_REGISTER_1[NUMBER_OF_LEDS_SHIFT_REGISTER_1] = {Led(1, 4), Led(2, 5), Led(3, 6), Led(4, 3), Led(5, 2), Led(6, 1), Led(7, 0)};
LedShiftRegisterPins PINS_SHIFT_REGISTER_1 = {D1, D2, D0};
LedShiftRegister *shiftRegister1 = new LedShiftRegister(PINS_SHIFT_REGISTER_1, LEDS_ON_SHIFT_REGISTER_1, NUMBER_OF_LEDS_SHIFT_REGISTER_1);

// D5 blue
// D6 white
// D7 yellow
const int NUMBER_OF_LEDS_SHIFT_REGISTER_2 = 8;
const Led LEDS_ON_SHIFT_REGISTER_2[NUMBER_OF_LEDS_SHIFT_REGISTER_2] = {Led(1, 7), Led(2, 6), Led(3, 5), Led(4, 4), Led(5, 3), Led(6, 2), Led(7, 1), Led(7, 0)};
LedShiftRegisterPins PINS_SHIFT_REGISTER_2 = {D6, D7, D5};
LedShiftRegister *shiftRegister2 = new LedShiftRegister(PINS_SHIFT_REGISTER_2, LEDS_ON_SHIFT_REGISTER_2, NUMBER_OF_LEDS_SHIFT_REGISTER_2);

LedMan *ledMan = new LedMan(shiftRegister1, shiftRegister2);

void setup()
{
  //Serial.begin(9600);
  ledMan->initialize();
}

int currentLightShowIndex = 0;
void loop()
{
  ledMan->apply(LIGHT_SHOW[currentLightShowIndex].bits);
  for (int delayIteration = 0; delayIteration < LIGHT_SHOW[currentLightShowIndex].numberOfExecutions; delayIteration++) {
      delay(40);
  }

  currentLightShowIndex++;
  if (currentLightShowIndex == TOTAL_STEPS) {
    currentLightShowIndex = 0;
  }
}
