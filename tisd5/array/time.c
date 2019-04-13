#include "time.h"
#include "constants.h"

static float time_now = 0;
static alarm_t al1;
static alarm_t al2;
static alarm_t al3;

float get_time(queue_t *q1, queue_t *q2, automat *a)
{
    if(!al1.time && !al2.time && !al3.time)
    {
        al1.time = randfrom(T1_MIN, T1_MAX);
        al2.time = randfrom(T2_MIN, T2_MAX);
        time_now = (al1.time < al2.time ? al1.time : al2.time);
        if (al1.time <= al2.time)
        {
            if (add_elem(q1, randfrom(T1_MIN, T1_MAX), T1) != 0)
            {
                printf("Переполнение! Измените параметр ELEM (размер массива)\n");
                return 0;
            }
            a->left1++;
            a->now = q1->data_store[0];
            a->now_t = T1;
            a->work_time = randfrom(T3_MIN, T3_MAX);
            al1.time = time_now + q1->data_store[0];
        }
        else
            {
                if (add_elem(q2, randfrom(T2_MIN, T2_MAX), T2) != 0)
                {
                    printf("Переполнение! Измените параметр ELEM (размер массива)\n");
                    return 0;
                }
            a->left2++;
            a->now = q2->data_store[0];
            a->now_t = T2;
            a->work_time = randfrom(T4_MIN, T4_MAX);
            al2.time = time_now + q2->data_store[0];
        }
        al3.time = time_now + a->work_time;
    }
    else
        {
        if(al1.time <= al2.time && al1.time <= al3.time)
        {
            time_now = al1.time;
            if (add_elem(q1, randfrom(T1_MIN, T1_MAX), T1) != 0)
            {
                printf("Переполнение! Измените параметр ELEM (размер массива)\n");
                return 0;
            }
            al1.time += q1->data_store[q1->front-1];
        }
        if(al2.time <= al1.time && al2.time <= al3.time)
        {
            time_now = al2.time;
            if (add_elem(q2, randfrom(T2_MIN, T2_MAX), T2) != 0)
            {
                printf("Переполнение! Измените параметр ELEM (размер массива)\n");
                return 0;
            }
            al2.time += q2->data_store[q2->front-1];
        }
        if(al3.time <= al2.time && al3.time <= al1.time)
        {
            refresh_automat(q1, q2, a);
            time_now = al3.time;
            al3.time += a->work_time;
        }
    }
    /*printf("STATISTIC:\n"
       "Automat:\n"
       "count q1 : %d\n"
       "count q2 : %d\n"
       "a->prev : %d\n"
       "a->work time %f\n\n", a->left1,a->left2, a->prev, a->work_time);
        printf("al1 %f\n"
           "al2 %f\n"
           "al3 %f\n\n", al1.time, al2.time, al3.time);
    queue_print(q1);
    printf("------\n");
    queue_print(q2);*/

    return time_now;

}