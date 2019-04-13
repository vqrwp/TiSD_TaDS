#include "structs.h"

void bubble_sort(flats *table, int amount)
{
    int i = 0;
    flats bmp;
    char swap_cnt = 0;

    while (i < amount)
    {
        if (i + 1 != amount && table[i].for_meter > table[i + 1].for_meter)
        {
            bmp = table[i];
            table[i] = table[i + 1];
            table[i + 1] = bmp;
            swap_cnt = 1;
        }
        i++;
        if (i == amount && swap_cnt == 1)
        {
            swap_cnt = 0;
            i = 0;
        }
    }
}