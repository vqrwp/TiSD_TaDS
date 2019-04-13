#include "structs.h"

void insert_sort(flats *table, int amount)
{
    flats newElement;
    int location;

    for (int i = 1; i < amount; i++) 
    {
        newElement = table[i];
        location = i - 1;
        while (location >= 0 && table[location].for_meter > newElement.for_meter) 
        {
            table[location + 1] = table[location];
            location = location - 1;
        }
        table[location + 1] = newElement;
    }
}