#include <stdio.h>
#include <windows.h>

void scan_int(int *num)
{
    int rc;
    char tmp;

    while(((rc = scanf("%d%c", num, &tmp)) != 2 && rc != EOF) || tmp != '\n')
    {
    printf("�訡�� �����, �������� ������ 楫�� �᫮: ");
    do
        {
            rc = scanf("%c", &tmp);
        }
        while(rc != EOF && tmp != '\n');
    }
    printf("�� �����: %d.\n", *num);
}

void scan_float(float *num)
{
    int rc;
    char tmp;

    while(((rc = scanf("%f%c", num, &tmp)) != 2 && rc != EOF) || tmp != '\n')
    {
        printf("�訡�� �����, �������� ������ ����⢥���� �᫮: ");
        do
        {
            rc = scanf("%c", &tmp);
        }
        while(rc != EOF && tmp != '\n');
    }
    printf("�� �����: %.2f.\n", *num);
}
