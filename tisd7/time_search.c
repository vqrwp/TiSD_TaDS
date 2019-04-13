#include "time_search.h"

unsigned long long int tick(void)
{
    unsigned long long int time = 0;
    __asm__ __volatile__ ("rdtsc" : "=A" (time));
    return time;
}