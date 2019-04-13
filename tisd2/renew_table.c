#include "structs.h"

void renew(flats *table1, flats *table2, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        table1[i] = table2[i];
    }
}

void renewk(key *table1, key *table2, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        table1[i] = table2[i];
    }
}