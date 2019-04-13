#include <stdio.h>
#include <windows.h>

void scan_char(char *num)
{
    int rc;
    char tmp;

    while(((rc = scanf("%c%c", num, &tmp)) != 2 && rc != EOF) || tmp != '\n')
    {
        printf("Ошибка ввода, пожалуйста введите один символ: ");
        do
        {
            rc = scanf("%c", &tmp);
        }
        while(rc != EOF && tmp != '\n');
    }
    printf("Вы ввели: %c.\n", *num);
}

void scan_int(int *num)
{
    int rc;
    char tmp;

    while(((rc = scanf("%d%c", num, &tmp)) != 2 && rc != EOF) || tmp != '\n')
    {
        printf("Ошибка ввода, пожалуйста введите вещественное число: ");
        do
        {
            rc = scanf("%c", &tmp);
        }
        while(rc != EOF && tmp != '\n');
    }
    printf("Вы ввели: %d.\n", *num);
}