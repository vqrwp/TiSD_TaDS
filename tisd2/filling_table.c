#include "structs.h"
#include <malloc.h>

void fill_num(int *num, char *string, int fl)
{
    char *s = (char *) malloc(sizeof(char) * 250);
    *num = (int) strtoll(string, &s, 10);
    if (fl)
    {
        strcpy(string, s);
        int k = 0;
        for (; k < strlen(string) - 2; k++)
        {
            string[k] = string[k + 2];
        }
        string[k] = '\0';
    }
}

void fill_str(char *pString, char *string)
{
    int j = 0, k = 0;
    for (j = 0; string[j] != ';'; j++) {
        pString[j] = string[j];
    }
    pString[j] = '\0';
    j += 2;
    for (k = 0; k < j, k < strlen(string); k++) {
        string[k] = string[k + j];
    }
    string[k] = '\0';
}

int filling_table_from_file(flats *table)
{
    int count = 0;
    FILE *f = fopen("table.txt", "r+");
    rewind(f);
    while (1)
    {
        if (feof(f))
        {
            break;
        }
        char string[250] = "";
        fgets(string, 250, f);
        printf("-%s-", string);
        if (strcmp("end\n", string) != 0)
        {
            fill_str(table[count].address, string);
            fill_num(&(table[count].area), string, 1);
            fill_num(&(table[count].rooms), string, 1);
            fill_num(&(table[count].for_meter), string, 1);

            fill_str(table[count].housing, string);
            if (strcmp(table[count].housing, "secondary") == 0 || strcmp(table[count].housing, "primary") == 0) {
                if (strcmp(table[count].housing, "primary") == 0)
                {
                    fill_num(&(table[count].type.primary1.finished_or_not), string, 0);
                }
                if (strcmp(table[count].housing, "secondary") == 0)
                {
                    fill_num(&(table[count].type.secondary1.date), string, 1);
                    fill_num(&(table[count].type.secondary1.owners), string, 1);
                    fill_num(&(table[count].type.secondary1.tenants), string, 1);
                    fill_num(&(table[count].type.secondary1.animals), string, 0);
                }
            }
            count++;
        }
        else
        {
            puts("DONE");
        }
    }
    fclose(f);
    return count;
}