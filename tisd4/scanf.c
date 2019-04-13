#include <stdio.h>
#include <windows.h>

void scan_char(char *num)
{
    int rc;
    char tmp;

    while(((rc = scanf("%c%c", num, &tmp)) != 2 && rc != EOF) || tmp != '\n')
    {
        printf("�訡�� �����, �������� ������ ���� ᨬ���: ");
        do
        {
            rc = scanf("%c", &tmp);
        }
        while(rc != EOF && tmp != '\n');
    }
    printf("�� �����: %c.\n", *num);
}

void scan_int(int *num)
{
    int rc;
    char tmp;

    while(((rc = scanf("%d%c", num, &tmp)) != 2 && rc != EOF) || tmp != '\n')
    {
        printf("�訡�� �����, �������� ������ ����⢥���� �᫮: ");
        do
        {
            rc = scanf("%c", &tmp);
        }
        while(rc != EOF && tmp != '\n');
    }
    printf("�� �����: %d.\n", *num);
}