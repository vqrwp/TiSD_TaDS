#include "structs.h"
#include <stdio.h>
#include <string.h>

int add_flat(flats *table, int *amount)
{
    char string[35] = "";
    FILE *f = fopen("table.txt", "r+");
    int flag = 1, count = 0;
    if (*amount + 1 > M_SIZE)
    {
        printf("The table is full!\n");
    } else
        {
        printf("Firstly, enter an address. Latin symbols, comas, dots and numbers only.\n"
               "Max size is 35 symbols! The program will ask to enter the address until\n"
               "it is correctly entered.\n");
        while (flag)
        {
            if (count)
            {
                printf("Enter the address: \n");
            }
            gets(string);
            for (int i = 0; i < strlen(string); i++)
            {
                if (string[i] == '.' || string[i] == ',' || (string[i] > 47 && string[i] < 58) ||
                    (string[i] > 64 && string[i] < 91) || (string[i] > 96 && string[i] < 123) ||
                        string[i] == ' ')
                {
                    flag = 0;
                } else
                    {
                    flag = 1;
                    break;
                }
            }
            count++;
        }
        strcpy(table[*amount + 1].address, string);

        while (0 != read_int(&table[*amount + 1].area, "Enter the area of the flat: ", 4))
        {
            printf("Try again!\n");
        }

        while (0 != read_int(&table[*amount + 1].rooms, "Enter the number of rooms: ", 5))
        {
            printf("Try again!\n");
        }

        while (0 != read_int(&table[*amount + 1].for_meter, "Enter the price for meter: ", 9))
        {
            printf("Try again!\n");
        }

        flag = 1;
        printf("Enter a type of housing. Can be only secondary or primary.\n");
        while (flag)
        {
            gets(string);
            if (strcmp(string, "primary") == 0 || strcmp(string, "secondary") == 0)
            {
                flag = 0;
            } else
                {
                flag = 1;
                printf("Wrong input! Try again!\n");
            }
        }
        strcpy(table[*amount + 1].housing, string);
        puts(table[*amount + 1].housing);
        if (strcmp(string, "primary") == 0)
        {
            table[*amount + 1].type.primary1.finished_or_not = -99999;
            while (0 != read_int(&table[*amount + 1].type.primary1.finished_or_not,
                     "Enter 0 if the flat is not finished, otherwise enter 1: ", 1)
                     || (table[*amount + 1].type.primary1.finished_or_not != 0 &&
                     table[*amount + 1].type.primary1.finished_or_not != 1))
            {
                printf("Try again!\n");
            }
        }
        else
        {
            while (0 != read_int(&table[*amount + 1].type.secondary1.date, "Enter the building date: ", 4))
            {
                printf("Try again!\n");
            }

            while (0 != read_int(&table[*amount + 1].type.secondary1.owners, "Enter the number of previous owners: ", 4))
            {
                printf("Try again!\n");
            }
            while (0 != read_int(&table[*amount + 1].type.secondary1.tenants, "Enter the number of tenants: ", 4))
            {
                printf("Try again!\n");
            }
            table[*amount + 1].type.secondary1.animals = -99999;
            while (0 != read_int(&table[*amount + 1].type.secondary1.animals,
                                 "Enter 0 if the were no pets, otherwise enter 1: ", 1)
                   || (table[*amount + 1].type.secondary1.animals != 0 &&
                       table[*amount + 1].type.secondary1.animals != 1))
            {
                printf("Try again!\n");
            }
        }
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s; %d; %d; %d; %s; ", table[*amount + 1].address,
                table[*amount + 1].area,
                table[*amount + 1].rooms,
                table[*amount + 1].for_meter,
                table[*amount + 1].housing);
        if (strcmp(table[*amount + 1].housing, "primary") == 0)
        {
            fprintf(f, "%d", table[*amount + 1].type.primary1.finished_or_not);
        }
        else
        {
            fprintf(f, "%d; %d; %d; %d;", table[*amount + 1].type.secondary1.date,
                    table[*amount + 1].type.secondary1.owners,
                    table[*amount + 1].type.secondary1.tenants,
                    table[*amount + 1].type.secondary1.animals);
        }
        *amount += 1;
    }
    fclose(f);
    return *amount;
}