#include <stdio.h>
#include <windows.h>

void scan_int(int *num)
{
    int rc;
    char tmp;

    while(((rc = scanf("%d%c", num, &tmp)) != 2 && rc != EOF) || tmp != '\n')
    {
    printf("Ошибка ввода, пожалуйста введите целое число: ");
    do
        {
            rc = scanf("%c", &tmp);
        }
        while(rc != EOF && tmp != '\n');
    }
    printf("Вы ввели: %d.\n", *num);
}

void scan_float(float *num)
{
    int rc;
    char tmp;

    while(((rc = scanf("%f%c", num, &tmp)) != 2 && rc != EOF) || tmp != '\n')
    {
        printf("Ошибка ввода, пожалуйста введите вещественное число: ");
        do
        {
            rc = scanf("%c", &tmp);
        }
        while(rc != EOF && tmp != '\n');
    }
    printf("Вы ввели: %.2f.\n", *num);
}
