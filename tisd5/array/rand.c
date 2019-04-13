#include "rand.h"
#include "constants.h"
#include <stdlib.h>

float randfrom(int min, int max)
{
    int range = max - min;
    int div = RAND_MAX / range;
    return  min + ((float) rand() / div);
}