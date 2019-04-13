#pragma once

#ifndef Header_h
#define Header_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define NO_ERROR 0          // ошибок нет
#define OPEN_ERROR -1       // ошибка открытия файла
#define EMPTY -2            // пустой файл
#define SYMBOL -3           // некорректный ввод
#define OUT_OF_RANGE -4     // выход за пределы чисел

#define CHAR_SIZE 32        // размер адресса
#define MAX_SIZE 50         // максимальный размер таблицы

typedef struct
{
	char street[CHAR_SIZE];
	int num_house;
	int num_flat;
}house;

typedef struct
{
	int num_comm;
	int num_room;
}comm;

typedef union
{
	house home;
	comm hostel;
}type;

typedef struct
{
	int type_home;
	char name[CHAR_SIZE];
	int sex;
	int age;
	int mark;
	char year[CHAR_SIZE];
	int index;
	type type;
}student;

typedef struct                      // структура таблицы ключей
{
	int index;                      // индекс
	int area;                       // площадь
} key_table;

int checkFile(FILE *f);
int readChar(char *s, FILE *f, int len);
int readInt(int *n, FILE *f, int min_range, int max_range);
void recFromFile(student *houses, key_table *key, int *rec_num, FILE *f, int size);
void printTable(student *stud, key_table *key, int *rec_num);
void recTable(student *stud, key_table *key, int *rec_num);
void findApartment(student *stud, key_table *key, int rec_num);
void exitMenu();


#endif /* Header_h */


