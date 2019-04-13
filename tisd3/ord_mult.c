//
// Created by Margo on 10.11.2018.
//
#include "headers.h"
#include <stdio.h>
#include <stdlib.h>

void ord_mult()
{
    int line = 0, column = 0, type_input = 0;
    printf("����� ࠧ��� �� ��� ������ �����?\n"
           "��������: ����� � �����, �᫨ �ணࠬ�� ����୮ �뢮��� ᮮ�饭�� � ⮬,\n"
           "�� �ॡ���� ����� �᫮, � �।��騩 ���� ���� �����४��!!\n");
    while (line == 0 || line > 10000)
    {
        printf("������ �᫮ �� 1 �� 10000 - ������⢮ ��ப:\n ");
        scan_int(&line);
    }
    while (column == 0 || column > 10000)
    {
        printf("������ �᫮ �� 1 �� 10000 - ������⢮ �⮫�殢:\n ");
        scan_int(&column);
    }


    float *values = malloc((column * line + 1) * sizeof(float));
    int *columns= malloc((column * line + 1) * sizeof(int)), num_elems = 0, not_null_lines = 0;
    list_t *lines = NULL;

    float *values_str = malloc((line + 1) * sizeof(float));
    int *columns_str = malloc((line + 1) * sizeof(int)), num_elems_str = 0;
    list_t *lines_str = NULL;

    while (type_input != 1 && type_input != 2)
    {
        printf("��� �� ��� ����� ������? ������ 1, �᫨ ��⮬���᪨, 2 �᫨ ������.\n");
        scan_int(&type_input);
    }
    if (type_input == 1)
    {
        float proc = -1;

        while (proc > 1 || proc < 0.1)
        {
            printf("�� ᪮�쪮 ��業⮢ ����室��� ��������� ������? ������ 楫�� �᫮\n"
                   "�� 0.1 �� 1 - �� �㤥� ��業� ������������ ������: \n");
            scan_float(&proc);
        }
        num_elems = auto_input(values, columns, &lines, line, column, proc, &not_null_lines);
    }
    else
    {
        num_elems = hand_input_mtr(values, columns, &lines, line, column, &not_null_lines);
    }

    type_input = 0;
    printf("����� ����室��� ����� �����-��ப�, �� ������ �㤥� 㬭������� ��� �����.\n"
           "������ ��࠭�� �����⥭, ⠪ ��� 㬭����� ��ப�-����� �� ������ ����� ⮫쪮 ⮣��, \n"
           "����� � ��ப� �⮫쪮 ����⮢, ᪮�쪮 � ����� ��ப.\n");
    while (type_input != 1 && type_input != 2)
    {
        printf("��� �� ��� ����� �����-��ப�? ������ 1, �᫨ ��⮬���᪨, 2 �᫨ ������.\n");
        scan_int(&type_input);
    }
    if (type_input == 1)
    {
        float proc = -1;

        while (proc > 1 || proc < 0.1)
        {
            printf("�� ᪮�쪮 ��業⮢ ����室��� ��������� ������? ������ 楫�� �᫮\n"
                   "�� 0.1 �� 1 - �� �㤥� ��業� ������������ ������: \n");
            scan_float(&proc);
        }
        int extra = 0;
        num_elems_str = auto_input(values_str, columns_str, &lines_str, 1, line, proc, &extra);
    }
    else
    {
        num_elems_str = hand_input_str(values_str, columns_str, &lines_str, 1, line);
    }

    printf("\n\n");
    float **mtr = calloc((size_t) (line * column + 1), sizeof(float));
    for (int i = 0; i < line; i++)
    {
        mtr[i] = calloc((size_t) (column + 1), sizeof(float));
    }
    mtr = making_ord_mtr(mtr, lines, columns, values, num_elems, line, column, not_null_lines);
    //print_mtr(mtr, line, column);
    printf("\n\n");

    float *str = calloc((size_t) (line + 1), sizeof(float));
    str = making_ord_vec(str, columns_str, values_str, num_elems_str);
    //print_array_f(str, line);

    printf("\n\nANSWER:\n");

    float *str_res = calloc((size_t)(column + 1), sizeof(float));
    str_res = mult_ord_mtr(mtr, str, line, column, str_res);
    if (column == 0)
    {
        printf("����������� ����� �����!\n");
    }
    else if (column * line < 20)
    {
        print_array_f(str_res, column);
    }
    else
    {
        int first, count = 0, not_null_line = 0, elems = 0;
        int *columnss = malloc(column * sizeof(int));
        float *valuess = malloc(column * sizeof(float));
        list_t *liines = NULL;
        for (int i = 0; i < column; i++)
        {
            if (rounding(str_res[i], 6) != 0.000000)
            {
                elems++;
                columnss[count] = i;
                valuess[count] = str_res[i];
                count++;
            }
        }
        push(&liines, 0, 0);
        if (count == 0)
        {
            printf("����������� ����� �����!\n");
        }
        else
        {
            printf("\n\nValues:\n");
            print_array_f(valuess, count);
            printf("\nColumns:\n");
            print_array_i(columnss, count);
            printf("\nLines: \n");
            print_from_tail(liines);
        }
    }


    for (int i = 0; i < line; i++)
    {
        free(mtr[i]);
    }
    free(mtr);
    free(str);
    free(values);
    free(values_str);
    free(columns);
    free(columns_str);
}

