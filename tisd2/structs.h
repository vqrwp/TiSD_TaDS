/*адрес, общую площадь,
        количество комнат, стоимость квадратного метра, первичное
        жилье или нет (первичное – с отделкой или без нее; вторичное –
время постройки, количество предыдущих собственников,
        количество последних жильцов, были ли животные). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CHAR_SIZE 35
#define M_SIZE 100

typedef struct
{
    int finished_or_not;
} primary;

typedef struct
{
    int date;
    int owners;
    int tenants;
    int animals;
} secondary;

typedef union
{
    primary primary1;
    secondary secondary1;
} inverse_type;

typedef struct
{
    char address[CHAR_SIZE];
    int area;
    int rooms;
    int for_meter;
    char housing[CHAR_SIZE];
    inverse_type type;
} flats;

typedef struct
{
    int index;
    int for_meter;
} key;


int filling_table_from_file(flats *table);
void show(flats *table_flats, int amount);
void bubble_sort(flats *table, int amount);
void insert_sort(flats *table, int amount);
int add_flat(flats *table, int *amount);
void fill_str(char *pString, char *string);
void delete_string(int amount);
void renew(flats *table1, flats *table2, int amount);
void fill_num(int *num, char *string, int fl);
int read_int(int *value, const char *prompt, int size);