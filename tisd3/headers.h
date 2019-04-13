#include <math.h>


typedef struct line
{
    int first_in_line;
    int num_line;
    struct line *next;
}list_t;

typedef struct timee
{
    double time_ord;
    double time_sparse;
}tm;

float rounding(double num, long count);
void scan_int(int *num);
int auto_input(float *values, int *columns, list_t **lines, int line, int column, float proc, int *not_null_lines);
void scan_float(float *num);
int hand_input_mtr(float *values, int *columns, list_t **lines, int line, int column, int *not_null_lines);
int hand_input_str(float *values, int *columns, list_t **lines, int line, int column);
void print_from_tail(const list_t *list) ;
void print_from_head(const list_t *list) ;
void push(list_t** list, int nk, int i);
float **making_ord_mtr1(float **mtr, list_t *lines_mtr, const int *columns_mtr, const float *values_mtr,
                        int elems, int line, int column, int not_null_lines);
void print_mtr(float **mtr, int line, int column);
void print_array_i(int *array, int num);
void print_array_f(float *array, int num);
int mult_sparse_mtr(list_t *lines_mtr, const int *columns_mtr, const float *values_mtr,
                    const int *columns_str, const float *values_str,
                    list_t **lines_res, int *c_res, float *res,
                    int elems, int elems_str, int column, int not_null_lines);

float **making_ord_mtr(float **mtr, list_t *lines_mtr, const int *columns_mtr, const float *values_mtr,
                       int elems, int line, int column, int not_null_lines);
float *making_ord_vec(float *vec,const int *columns_vec, const float *values_vec, int elems);
float *mult_ord_mtr(float **mtr, const float *str, int line, int column, float *str_res);
void sparse_mult();
void ord_mult();
void check_efficiency();
