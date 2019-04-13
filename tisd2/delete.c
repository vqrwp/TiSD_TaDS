#include "structs.h"

void delete_string(int amount)
{
    FILE * f = fopen ("table.txt", "r+");
    int num, rc;
    char tmp;
    printf("Enter the number of the string you want to delete: ");
    while (((rc = scanf("%d%c", &num, &tmp)) != 2 && rc != EOF) || tmp != '\n' || num > amount || num <= 0)
    {
        printf("Input error. Please, enter a positive integer under current number of flats (%d): ", amount);
        while (rc != EOF && tmp != '\n');
    }
    if (f)
    {
        const int size = 1024;
        char pattern [size];

        fseek (f, 0, SEEK_END);
        char storyData[1024 * 100] = "";
        char *ptr = storyData;
        *ptr = 0;
        fseek(f, 0, SEEK_SET);

        int i = 1;
        while (fgets(pattern, size, f))
        {
            if (i != num)
            {
                strcat(ptr, pattern);
                ptr += strlen(pattern);
            }
            else
            {
                printf("This is a string you want to delete:\n");
                puts(pattern);
            }
            i++;
        }
        for (int j = 0, k = 0; k < amount - 1; j++)
        {
            if (storyData[j] == '\n')
            {
                k++;
            }
            if (k == amount - 1)
            {
                storyData[j] = '\0';
            }
        }
        fclose (f);
        f = fopen("table.txt", "w+");
        fputs(storyData, f);
        fclose (f);
    }

}