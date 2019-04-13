#include <stdio.h>
#include "structs.h"
#include <malloc.h>

/*
Создать таблицу, содержащую не менее 40 записей с вариантной частью. Произвести
поиск информации по вариантному полю. Упорядочить таблицу, по возрастанию ключей
(где ключ – любое невариантное поле по выбору программиста), используя: а) исходную
таблицу; б) массив ключей, используя 2 разных алгоритма сортировки. Оценить
эффективность этих алгоритмов (по времени и по используемому объему памяти) при
различной реализации программы, то есть в случаях а) и б). Обосновать выбор алгоритма
сортировки. Оценка эффективности должна быть относительной (в %).

Ввести список квартир, содержащий адрес, общую площадь,
количество комнат, стоимость квадратного метра, первичное
жилье или нет (первичное – с отделкой или без нее; вторичное –
время постройки, количество предыдущих собственников,
количество последних жильцов, были ли животные). Найти все
вторичное 2-х комнатное жилье в указанном ценовом диапазоне
без животных.

Еще там должны быть:
 указание формата и диапазона данных при вводе и (или) добавлении записей;
 указание операций производимых программой;
 наличие пояснений при выводе результата;
 возможность добавления записей в конец таблицы и удаления записи по
значению указанного поля.
 просмотр отсортированной таблицы ключей при несортированной исходной
таблице;
 вывод упорядоченной исходной таблицы;
 вывод исходной таблицы в упорядоченном виде, используя упорядоченную
таблицу ключей
 вывод результатов сравнения эффективности работы программы при
обработке данных в исходной таблице и в таблице ключей;
 вывод результатов использования различных алгоритмов сортировок.

При тестировании программы необходимо:
 проверить правильность ввода и вывода данных (в том числе, отследить
попытки ввода неверных по типу данных в вариантную часть записи);
 обеспечить вывод сообщений при отсутствии входных данных («пустой
ввод»);
 проверить правильность выполнения операций;
 отследить переполнение таблицы.
При хранении исходных данных в файлах (что приветствуется) необходимо
также проверить наличие файла и изменения информации в нем при удалении и
добавлении данных в таблицу.
 */

int main()
{
    int amount = 0;
    flats *table_flats = (flats*)malloc(M_SIZE * sizeof(flats)),
            *copy_table  = (flats*)malloc(M_SIZE * sizeof(flats));

    puts("here\n");
    amount = filling_table_from_file(table_flats);
    puts("here\n");
    printf("This program works with table, containing information about from 40 to 100 flats. "
           "It has information about its:\naddresses (string);\nareas (int);\nnumbers of rooms (int);"
           "\nprices for the square meter (int);"
           "\nif the flat is a primary housing, here is information about whether it finished or not (int, 0 or 1);\n"
           "if it is secondary, the table keeps the build time (int), number of owners and tenants (int) and whether\n"
           "there were pets living with the last tenants (int, 0 or 1).\n"
           "You can do several things with the table entering the special key of the task.\n\n");
    for (; ;) {
        printf("\t\tLIST OF TASKS\n\n"
               "enter 1 to show the table\n"
               "press 2 to add new flat\n"
               "press 3 to delete the special flat\n"
               "enter 4 to show sorted key table\n"
               "press 5 to show sorted table\n"
               "enter 6 to show sorted by the key table (insert sort)\n"
               "enter 7 to show sorted by the key table (bubble sort)\n"
               "enter 8 to show efficiency of different sorts\n"
               "enter 9 to find secondary flat with two rooms without animals with specific price\n"
               "enter 10 to close the program\n\n");
        int s;
        scanf("%d", &s);
        switch (s) {
            case 1:
                show(table_flats, amount);
                break;
            case 2:
                //add_flat(table_flats, &amount);
                amount = filling_table_from_file(table_flats);
                show(table_flats, amount);
                break;
            case 3:
                delete_string(amount);
                amount = filling_table_from_file(table_flats);
                show(table_flats, amount);
                break;
            case 5:
                bubble_sort(table_flats, amount);
                show(table_flats, amount);
                renew(table_flats, copy_table, amount);
                break;
            case 10:
                printf("Exit");
                return 0;
            default:
                printf("Wrong input!");
                return -1;
        }
    }
    return 0;
}