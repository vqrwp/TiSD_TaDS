#include <stdio.h>
#include "scanf.h"
#include <stdlib.h>
#include "list_funcs.h"
#include "arr_funcs.h"
#include "is_pal.h"
#include <string.h>
#include "efficience.h"

/*
������� �ணࠬ�� ࠡ��� � �⥪��,
�믮������� ����樨 ����������,
㤠����� ����⮢ � �뢮� ⥪�饣�
���ﭨ� �⥪�. ����������� �⥪: �)
���ᨢ��; �) ᯨ᪮�. �� �⠭�����
����樨 � �⥪�� ������ ���� ��ଫ���
����ணࠬ����. �� ॠ����樨 �⥪�
ᯨ᪮� � �뢮� ⥪�饣� ���ﭨ� �⥪�
�������� ��ᬮ�� ���ᮢ ����⮢ �⥪�
� ᮧ���� ᢮� ᯨ᮪ ��� ���ᨢ ᢮������
�����⥩ (���ᮢ �᢮���������
����⮢) � �뢮��� ��� �� �࠭.

Special task:

�ᯮ���� �⥪, ��।�����, ���� �� ��ப�
������஬��.
*/

int main()
{
    int flag = 0, choise = 0, type = 0;
    list_t *list = NULL;
    del_mem *list_del = NULL;
    char *arr = calloc(MAX_SIZE_VEC, sizeof(char));
    int size = 0, size_del = 0;
    char elem = 0;
    printf("������ �ணࠬ�� �ந������ ࠡ��� � �⥪��.\n"
           "�⥪ ॠ������� ���� ᯮᮡ���: \n�) � ������� �����;\n"
           "�) � ������� �����吝��� ᯨ᪠.\n"
           "��� ������ �� ࠡ�� � ������ ������ �⥪� - char.\n"
           "����������� ���������� 㤠����� ����� �� �⥪�,\n"
           "���������� ����� � �⥪, �����뢠��� �⥪�\n"
           "(� ⮬ �᫥ ����� � ���ᠬ� ����⮢),\n"
           "����������� �뢮�� ᯨ᪠ �᢮��������� �����.\n"
           "��� �� ॠ�������� �������⥫쭮� ������� - \n"
           "��।������, ���� �� ��ப�, ��室������ � �⥪�,\n"
           "������஬��.\n"
           "������, ��� �� ��� �।�⠢���� �⥪: \n"
           "1. ��� �����;\n"
           "2. ��� �����吝� ᯨ᮪.\n");
    while (type < 1 || type > 2)
    {
        puts("(�㦭� ����� ���� 1, ���� 2)\n");
        scan_int(&type);
    }
    while (flag == 0)
    {
        if (type == 2)
        {
            printf("\n------------------����------------------\n"
                   "1. �������� ⥪�饥 ���ﭨ� �⥪�;\n"
                   "2. �������� � �⥪ �����;\n"
                   "3. ������� ����� �� �⥪�;\n"
                   "4. �������� �᢮�������� ����;\n"
                   "5. �������� ⥪�饥 ���ﭨ� �⥪� � ���ᠬ�;\n"
                   "6. ��।�����, ���� �� ��ப� ������஬��;\n"
                   "7. ��䥪⨢�����;\n"
                   "8. ��室.\n"
                   "������ �㭪�, ����� �� ��� �ᯮ�����:  ");
            while (choise < 1 || choise > 8)
            {
                puts("(�㦭� ����� �᫮ �� 1 �� 8)\n");
                scan_int(&choise);
            }
            switch (choise)
            {
                case 1:
                    print_from_head(list, size);
                    choise = 0;
                    break;
                case 2:
                    printf("������ ����� �⥪� (���� ᨬ��� ASCII): ");
                    scan_char(&elem);
                    arr_push(&arr, elem, size);
                    push(&list, elem, &size);
                    choise = 0;
                    break;
                case 3:
                    arr_pop(&arr, size);
                    pop(&list, &list_del, &size, &size_del);
                    choise = 0;
                    break;
                case 4:
                    print_from_head_mem(list_del, size_del);
                    choise = 0;
                    break;
                case 5:
                    printf("������ ��� ����\n");
                    print_from_head_with_addresses(list, size);
                    choise = 0;
                    break;
                case 6:
                    //void ispoly(list_t *list, del_mem *list_del, int size, int size_del, vec arr);
                    ispoly(list, list_del, size, size_del, arr);
                    flag = 1;
                    choise = 0;
                    break;
                case 7:
                    efficience();
                    choise = 0;
                    break;
                case 8:
                    flag = 1;
                    puts("\n�����襭�� ࠡ��� �ணࠬ��!");
                    choise = 0;
                    break;
                default:
                    break;
            }
        }
        if (type == 1)
        {
            printf("\n------------------����------------------\n"
                   "1. �������� ⥪�饥 ���ﭨ� �⥪�;\n"
                   "2. �������� � �⥪ �����;\n"
                   "3. ������� ����� �� �⥪�;\n"
                   "4. ��।�����, ���� �� ��ப� ������஬��;\n"
                   "5. ��䥪⨢�����;\n"
                   "6. ��室.\n"
                   "������ �㭪�, ����� �� ��� �ᯮ�����:  ");
            while (choise < 1 || choise > 8)
            {
                puts("(�㦭� ����� �᫮ �� 1 �� 8)\n");
                scan_int(&choise);
            }
            switch (choise)
            {
                case 1:
                    print_arr(arr, size);
                    choise = 0;
                    break;
                case 2:
                    printf("������ ����� �⥪� (���� ᨬ��� ASCII): ");
                    scan_char(&elem);
                    arr_push(&arr, elem, size);
                    push(&list, elem, &size);
                    choise = 0;
                    break;
                case 3:
                    arr_pop(&arr, size);
                    pop(&list, &list_del, &size, &size_del);
                    choise = 0;
                    break;
                case 4:
                    ispoly(list, list_del, size, size_del, arr);
                    flag = 1;
                    choise = 0;
                    break;
                case 5:
                    efficience();
                    choise = 0;
                    break;
                case 6:
                    flag = 1;
                    puts("\n�����襭�� ࠡ��� �ணࠬ��!");
                    choise = 0;
                    break;
                default:
                    break;
            }
        }
    }
    free(arr);
    return 0;
}