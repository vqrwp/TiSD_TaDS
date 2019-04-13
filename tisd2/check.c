#include "structs.h"

void check_efficiency(flats *table_flats, flats *copy, key *key_table, key *copyk, int amount)
{
    float bbsort_time = 0, insert_sort_time = 0, by_key1_time = 0, by_key2_time = 0;
    int t1, t2;

    printf("PLEASE WAIT WHILE PROGRAM IS CALCULATING THE EFFICIENCY OF SORTS\n\n");
    for (int i = 0; i < 10000; i++)
    {
        t1 = clock();
        bubble_sort(table_flats, amount);
        t2 = clock();
        renew(table_flats, copy, amount);
        bbsort_time += t2 - t1;
    }
    bbsort_time /= 10000;

    for (int i = 0; i < 10000; i++)
    {
        t1 = clock();
        insert_sort(table_flats, amount);
        t2 = clock();
        renew(table_flats, copy, amount);
        insert_sort_time += t2 - t1;
    }
    insert_sort_time /= 10000;

    for (int i = 0; i < 10000; i++)
    {
        t1 = clock();
        sort1_key(key_table, amount);
        sort_by_key(table_flats, key_table, amount, 0);
        t2 = clock();
        renew(table_flats, copy, amount);
        renewk(key_table, copyk, amount);
        by_key1_time += t2 - t1;
    }
    by_key1_time /= 10000;

    for (int i = 0; i < 10000; i++)
    {
        t1 = clock();
        sort2_key(key_table, amount);
        sort_by_key(table_flats, key_table, amount, 0);
        t2 = clock();
        renew(table_flats, copy, amount);
        renewk(key_table, copyk, amount);
        by_key2_time += t2 - t1;
    }
    by_key2_time /= 10000;

    float mem_b = sizeof(table_flats[0]) * amount;
    float mem_i = sizeof(table_flats[0]) * amount;
    float mem_k = (sizeof(table_flats[0]) + sizeof(key_table[0])) * amount;

    printf("      |Bubble Sort|BubbleSort By Key|Insert Sort|InsertSort By Key|\n");
    printf("------------------------------------------------------------------\n");
    printf(" Time |%11f|%17f|%11f|%17f|\n", bbsort_time, by_key1_time, insert_sort_time, by_key2_time);
    printf("Memory|%11.0f|%17.0f|%11.0f|%17.0f|\n", mem_b, mem_k, mem_i, mem_k);
    printf("------------------------------------------------------------------\n");
    printf("Sorting by key consumes %.0f%% more memory.\n", (mem_k / mem_b - 1) * 100);
    printf("Sorting by key is %.0f%% faster.\n", (100 * (bbsort_time / by_key1_time - 1) +
                                                 100 * (insert_sort_time / by_key2_time - 1)) / 2);
}