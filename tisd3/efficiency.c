//
// Created by Margo on 10.11.2018.
//
#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

tm check(int line, int column, float proc, int *num_elems_res, int *num_elems, int *num_elems_str,
int *not_null_lines)
{
    tm timee;
    srand((unsigned int)time(NULL));
    float *values = malloc((line * column + 1) * sizeof(float));
    int *columns = malloc((line * column + 1) * sizeof(float));
    list_t *lines = NULL;

    *num_elems = auto_input(values, columns, &lines, line, column, proc, not_null_lines);

    float *values_str = malloc((line + 1) * sizeof(float));
    int *columns_str = malloc((line + 1) * sizeof(float)), extra = 0;
    list_t *lines_str = NULL;

    *num_elems_str = auto_input(values_str, columns_str, &lines_str, 1, line, proc, &extra);

    float *values_res = malloc((column + 1) * sizeof(float));
    int *columns_res = malloc((column + 1) * sizeof(float));
    list_t *lines_res = NULL;

    float **mtr = calloc((size_t) (line * column + 1), sizeof(float));
    for (int i = 0; i < line; i++)
    {
        mtr[i] = calloc((size_t) (column + 1), sizeof(float));
    }
    mtr = making_ord_mtr(mtr, lines, columns, values, *num_elems, line, column, *not_null_lines);

    float *str = calloc((size_t) (line + 1), sizeof(float));
    str = making_ord_vec(str, columns_str, values_str, *num_elems_str);

    float *str_res = calloc((size_t)(column + 1), sizeof(float));

    double tiick = (double)clock()/CLOCKS_PER_SEC;
    mult_ord_mtr(mtr, str, line, column, str_res);
    double toock = (double)clock()/CLOCKS_PER_SEC;

    double tick = (double)clock()/CLOCKS_PER_SEC;
    *num_elems_res = mult_sparse_mtr(lines, columns, values, columns_str, values_str, &lines_res,
                                     columns_res, values_res, *num_elems, *num_elems_str, column, *not_null_lines);
    double tock = (double)clock()/CLOCKS_PER_SEC;

    printf("%20d|", *num_elems);
    timee.time_ord = toock - tiick;
    timee.time_sparse = tock - tick;
    free(values);
    free(values_res);
    free(values_str);
    free(columns);
    free(columns_res);
    free(columns_str);
    return timee;
}

void print_result(float proc, tm time1, int line, int column, int num_elem,
                  int not_null_lines, int num_str, int test1)
{
    printf("%7.2f|%21lf|%25lf|%23d|%19d\n\n", proc, time1.time_ord, time1.time_sparse, num_elem * sizeof(float) *
    2 + sizeof(list_t) * not_null_lines + sizeof(list_t) * 2 + num_str * sizeof(float)
    * 2 + test1 * sizeof(float), sizeof(float) * line * column);
}

void check_efficiency()
{
    int test1 = 0, num_elem = 0, num_str = 0, not_null_lines = 0;
    // 3 разных обьема памяти, 2 процентных соотношения разреженности
    tm time1;


    printf("Количество элементов|Процент|Время обыч. умножения|Время умножения для разр.|"
           "Память для разреженного|Память для обычного\n");

    time1 = check(5500, 1000, 1, &test1, &num_elem, &num_str, &not_null_lines);
    print_result(1, time1, 5500, 1000, num_elem, not_null_lines, num_str, test1);

    num_elem = 0, num_str = 0, not_null_lines = 0;
    time1 = check(5000, 1000, 1, &test1, &num_elem, &num_str, &not_null_lines);
    print_result(1, time1, 5000, 1000, num_elem, not_null_lines, num_str, test1);

    num_elem = 0, num_str = 0, not_null_lines = 0;
    time1 = check(4000, 1000, 1, &test1, &num_elem, &num_str, &not_null_lines);
    print_result(1, time1, 4000, 1000, num_elem, not_null_lines, num_str, test1);

    num_elem = 0, num_str = 0, not_null_lines = 0;
    time1 = check(5500, 1000, 0.5, &test1, &num_elem, &num_str, &not_null_lines);
    print_result(0.5, time1, 5500, 1000, num_elem, not_null_lines, num_str, test1);

    num_elem = 0, num_str = 0, not_null_lines = 0;
    time1 = check(5000, 1000, 0.5, &test1, &num_elem, &num_str, &not_null_lines);
    print_result(0.5, time1, 5000, 1000, num_elem, not_null_lines, num_str, test1);

    num_elem = 0, num_str = 0, not_null_lines = 0;
    time1 = check(4000, 1000, 0.5, &test1, &num_elem, &num_str, &not_null_lines);
    print_result(0.5, time1, 4000, 1000, num_elem, not_null_lines, num_str, test1);

    num_elem = 0, num_str = 0, not_null_lines = 0;
    time1 = check(5500, 1000, 0.25, &test1, &num_elem, &num_str, &not_null_lines);
    print_result(0.25, time1, 5500, 1000, num_elem, not_null_lines, num_str, test1);

    num_elem = 0, num_str = 0, not_null_lines = 0;
    time1 = check(5000, 1000, 0.25, &test1, &num_elem, &num_str, &not_null_lines);
    print_result(0.25, time1, 5000, 1000, num_elem, not_null_lines, num_str, test1);

    num_elem = 0, num_str = 0, not_null_lines = 0;
    time1 = check(4000, 1000, 0.25, &test1, &num_elem, &num_str, &not_null_lines);
    print_result(0.25, time1, 4000, 1000, num_elem, not_null_lines, num_str, test1);

    num_elem = 0, num_str = 0, not_null_lines = 0;
    time1 = check(5500, 1000, 0.05, &test1, &num_elem, &num_str, &not_null_lines);
    print_result(0.05, time1, 5500, 1000, num_elem, not_null_lines, num_str, test1);

    num_elem = 0, num_str = 0, not_null_lines = 0;
    time1 = check(5000, 1000, 0.05, &test1, &num_elem, &num_str, &not_null_lines);
    print_result(0.05, time1, 5000, 1000, num_elem, not_null_lines, num_str, test1);

    num_elem = 0, num_str = 0, not_null_lines = 0;
    time1 = check(4000, 1000, 0.05, &test1, &num_elem, &num_str, &not_null_lines);
    print_result(0.05, time1, 4000, 1000, num_elem, not_null_lines, num_str, test1);


}
