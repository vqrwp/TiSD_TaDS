#include "headers.h"
#include <stdlib.h>
#include <stdio.h>

int mult_sparse_mtr(list_t *lines_mtr, const int *columns_mtr, const float *values_mtr,
                    const int *columns_str, const float *values_str,
                    list_t **lines_res, int *columns_res, float *values_res,
                    int elems, int elems_str, int column, int not_null_lines)
{
    list_t *key = lines_mtr;
    float res[10000];
    int count = 0, count_2 = 0, k = 0;
    int i = elems - 1, c_res[10000];
    for (int j; count_2 < not_null_lines; count_2++)
    {
        if (count_2 != 0)
        {
            key = key->next;
        }
        if (key->next)
        {
            j = key->num_line;
            count = key->first_in_line;
        }
        else
        {
            j = key->num_line;
            count = 0;
        }
        while (i >= count)
        {
            if (rounding(fabs((double)(values_mtr[i] * values_str[j])), 6) != 0.000000)
            {
                res[columns_mtr[i]] += values_mtr[i] * values_str[columns_str[j]];
                c_res[columns_mtr[i]] = columns_mtr[i];
            }
            i--;
        }
    }
    int j = 0;
    for (i = 0; i <= column; i++)
    {
        if (rounding(fabs((double)res[i]), 6) != 0.000000)
        {
            values_res[j] = res[i];
            columns_res[j] = c_res[i];
            j++;
        }
    }
    if (j != 0)
    {
        push(lines_res, 0, 0);
    }
    return j;
}

float *mult_ord_mtr(float **mtr, const float *str, int line, int column, float *str_res)
{
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < line; j++)
        {
            str_res[i] += mtr[j][i] * str[j];
        }
    }
    return str_res;
}

