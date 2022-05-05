#ifndef floatingAverage_h
#define floatingAverage_h

const int NUMBER_OF_DATAPOINTS = 15;
int readings[NUMBER_OF_DATAPOINTS];

int currentIndex = 0;
int total = 0;

int floatingAverage(int nextValue)
{
    long average;
    total = total - readings[currentIndex];
    readings[currentIndex] = nextValue;
    total = total + readings[currentIndex];
    currentIndex = currentIndex + 1;
    if (currentIndex >= NUMBER_OF_DATAPOINTS)
    {
        currentIndex = 0;
    }
    average = total / NUMBER_OF_DATAPOINTS;
    return average;
}

#endif