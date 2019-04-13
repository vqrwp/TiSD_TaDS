#include "rand.h"

float rand_from(int min, int max)
{
    int range = max - min;
    int div = RAND_MAX / range;
    return  min + ((float) rand() / div);
}