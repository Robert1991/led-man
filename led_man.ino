#include "pt.h"
#include "protothreads.h"
#include "ledMan.h"
#include "lightshow.h"
#include "floatingAverage.h"

#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.39370

const int ULTRA_SONIC_SENSOR_TRIGGER_PIN = D3;
const int ULTRA_SONIC_SENSOR_ECHO_PIN = D4;

// D0 blue
// D1 yellow
// D2 green
const int NUMBER_OF_LEDS_SHIFT_REGISTER_1 = 7;
const Led LEDS_ON_SHIFT_REGISTER_1[NUMBER_OF_LEDS_SHIFT_REGISTER_1] = {Led(1, 4), Led(2, 5), Led(3, 6), Led(4, 3),
                                                                       Led(5, 2), Led(6, 1), Led(7, 0)};
LedShiftRegisterPins PINS_SHIFT_REGISTER_1 = {D1, D2, D0};
LedShiftRegister *shiftRegister1 = new LedShiftRegister(PINS_SHIFT_REGISTER_1, LEDS_ON_SHIFT_REGISTER_1,
                                                        NUMBER_OF_LEDS_SHIFT_REGISTER_1);

// D5 blue
// D6 yellow
// D7 green
const int NUMBER_OF_LEDS_SHIFT_REGISTER_2 = 8;
const Led LEDS_ON_SHIFT_REGISTER_2[NUMBER_OF_LEDS_SHIFT_REGISTER_2] = {Led(1, 7), Led(2, 6), Led(3, 5), Led(4, 4),
                                                                       Led(5, 3), Led(6, 2), Led(7, 1), Led(7, 0)};
LedShiftRegisterPins PINS_SHIFT_REGISTER_2 = {D6, D7, D5};
LedShiftRegister *shiftRegister2 = new LedShiftRegister(PINS_SHIFT_REGISTER_2, LEDS_ON_SHIFT_REGISTER_2,
                                                        NUMBER_OF_LEDS_SHIFT_REGISTER_2);

LedMan *ledMan = new LedMan(shiftRegister1, shiftRegister2);

pt lightShowThread;
pt speedCalculationThread;

static int lightShowDelay = 50;
static int currentLightShowIndex = 0;

void setup()
{
  Serial.begin(115200);

  PT_INIT(&lightShowThread);
  PT_INIT(&speedCalculationThread);

  ledMan->initialize();

  pinMode(ULTRA_SONIC_SENSOR_TRIGGER_PIN, OUTPUT);
  pinMode(ULTRA_SONIC_SENSOR_ECHO_PIN, INPUT);
}

void loop()
{
  PT_SCHEDULE(calculateLightShowSpeed(&speedCalculationThread));
  PT_SCHEDULE(iterateLightShow(&lightShowThread));
}

int calculateLightShowSpeed(struct pt *thread)
{
  PT_BEGIN(thread);
  while (true)
  {
    float distanceCm = measureDistance(thread);
    // Serial.print("Distance (cm): ");
    // Serial.println(distanceCm);

    int lightShowSpeedRatio = calculateLightShowSpeedRatio(distanceCm);
    // Serial.print("Ratio: ");
    // Serial.println(lightShowSpeedRatio);

    int smoothendLightShowSpeedRatio = floatingAverage(lightShowSpeedRatio);
    Serial.print("Ratio Smooth: ");
    Serial.println(smoothendLightShowSpeedRatio);

    lightShowDelay = (int)(300.0 * (smoothendLightShowSpeedRatio / 100.0));

    PT_YIELD(thread);
  }
  PT_END(thread);
}

int iterateLightShow(struct pt *thread)
{
  PT_BEGIN(thread);
  Serial.println("Begin Light Show");

  while (true)
  {
    ledMan->apply(LIGHT_SHOW[currentLightShowIndex].bits);
    for (int delayIteration = 0; delayIteration < LIGHT_SHOW[currentLightShowIndex].numberOfExecutions; delayIteration++)
    {
      PT_SLEEP(thread, lightShowDelay);
    }

    // Serial.print("currentLightShowSpeedDelay: ");
    // Serial.println(lightShowDelay);

    // Serial.print("light show index: ");
    // Serial.println(currentLightShowIndex);

    currentLightShowIndex++;
    if (currentLightShowIndex == TOTAL_STEPS)
    {
      currentLightShowIndex = 0;
    }
  }
  PT_END(thread);
}

float measureDistance(struct pt *thread)
{
  digitalWrite(ULTRA_SONIC_SENSOR_TRIGGER_PIN, LOW);
  delay(2);
  digitalWrite(ULTRA_SONIC_SENSOR_TRIGGER_PIN, HIGH);
  delay(10);
  digitalWrite(ULTRA_SONIC_SENSOR_TRIGGER_PIN, LOW);

  long duration = pulseIn(ULTRA_SONIC_SENSOR_ECHO_PIN, HIGH);
  return duration * SOUND_VELOCITY / 2;
}

int calculateLightShowSpeedRatio(float distanceToNextObject)
{
  if (distanceToNextObject >= 250.0)
  {
    return 150;
  }
  int ratio = (int)((distanceToNextObject / 250.0) * 100.0);
  if (ratio <= 20)
  {
    return 10;
  }
  if (ratio <= 10)
  {
    return 5;
  }
  return ratio;
}
