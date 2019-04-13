#include "structs.h"

void show(flats *table_flats, int amount)
{
    printf("\nTOTAL: %d\n\n", amount);
    printf("# |             Address               |Area|Rooms|  Price  |  Housing |Finished/not|Building date|"
           "Owners|Tenants|Animals");
    printf("------------------------------------------------------------"
           "------------------------------------------------------------");
    for (int i = 0; i < amount; i++)
    {
        printf("%2d|%35s|%4d|%5d|%9d|%10s|", i + 1, table_flats[i].address, table_flats[i].area,
               table_flats[i].rooms, table_flats[i].for_meter, table_flats[i].housing);
        if (strcmp(table_flats[i].housing, "primary") == 0)
        {
            if (table_flats[i].type.primary1.finished_or_not == 0)
            {
                printf("Finished    |-------------|------|-------|-------");
            }
            else
            {
                printf("Not finished|-------------|------|-------|-------");
            }
        }
        else
        {
            printf("------------|"
                   "%13d|%6d|%7d|%7d", table_flats[i].type.secondary1.date, table_flats[i].type.secondary1.owners,
                   table_flats[i].type.secondary1.tenants, table_flats[i].type.secondary1.animals);
        }
    }
    printf("------------------------------------------------------------"
           "------------------------------------------------------------");
}