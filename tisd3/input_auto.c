#include "headers.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

float rounding(double num, long count)
{
    float res = (float) (round(num * pow(10, count)) / pow(10, count));
    return res;
}

int auto_input(float *values, int *columns, list_t **lines, int line, int column, float proc, int *not_null_lines)
{
    srand(time(NULL));
    int num_elems = line * column, count1 = 0, count2 = 0;
    int num_not_zero = (int)round(num_elems * proc);
    float **mtr = (float**)calloc((size_t) (line * column), sizeof(float));
    for (int i = 0; i < line; i++)
    {
        mtr[i] = (float*)calloc((size_t)column, sizeof(float));
    }
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (count1 < num_not_zero)
            {
                count1++;
                while (rounding(mtr[i][j], 6) == 0.000000)
                {
                    mtr[i][j] = -100 + rand() % 200;
                }
            }
            else
            {
                break;
            }
        }
        if (count1 == num_not_zero)
        {
            break;
        }
    }
    count1 = 0;
    for (int i = 0; i < line; i++)
    {
        int flag = 0;
        for (int j = 0; j < column; j++)
        {
            if (num_elems < 20)
            {
                printf("%f ", mtr[i][j]);
            }
            if (rounding(mtr[i][j], 6) != 0.000000)
            {
                values[count1] = mtr[i][j];
                columns[count1] = j;
                if (flag == 0)
                {
                    //printf("num_line = %d num of first in line = %d\n", i, count1);
                    push(lines, i, count1);
                    *not_null_lines += 1;
                    flag = 1;
                    count2++;
                }
                count1++;
            }
        }
        if (num_elems < 20)
        {
            printf("\n");
        }
    }
    for (int i = 0; i < count1; i++)
    {
        //printf("%f %d\n", values[i], columns[i]);
    }
    //printf("\n");
    //print_from_tail(lines);
    for (int i = 0; i < line; i++)
    {
        free(mtr[i]);
    }
    free(mtr);
    return num_not_zero;
}