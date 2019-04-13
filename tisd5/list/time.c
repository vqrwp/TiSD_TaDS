#include "time.h"
#include "rand.h"
#include "refresh_automat.h"
#include "constants.h"
//#define CHECK_FRAGMENTATION

static float time_now = 0;
static alarm alarm1;
static alarm alarm2;
static alarm alarm3;

float get_time(queue_t *q1, queue_t *q2, automat *a)
{
    if (!alarm1.time && !alarm2.time && !alarm3.time)
    {
        alarm1.time = rand_from(T1_MIN, T1_MAX);
        alarm2.time = rand_from(T2_MIN, T2_MAX);
        time_now = (alarm1.time < alarm2.time ? alarm1.time : alarm2.time);
        if (alarm1.time <= alarm2.time)
        {
            add_elem(q1, rand_from(T1_MIN, T1_MAX), T1);
            a->left1++;
            a->now = q1->pin;
            a->work_time = rand_from(T3_MIN, T3_MAX);
            alarm1.time = time_now + q1->pin->time;
        }
        else
            {
                add_elem(q2, rand_from(T2_MIN, T2_MAX), T2);
            a->left2++;
            a->now = q2->pin;
            a->work_time = rand_from(T4_MIN, T4_MAX);
            alarm2.time = time_now + q2->pin->time;
        }
        alarm3.time = time_now + a->work_time;
    }
    else
        {
        if (alarm1.time <= alarm2.time && alarm1.time <= alarm3.time)
        {
            time_now = alarm1.time;
#ifdef CHECK_FRAGMENTATION
            printf("\nТекущее время:  (_%.3f_)     Добавляем элемент в очередь <1> по адресу: ", time_now);
#endif
            add_elem(q1, rand_from(T1_MIN, T1_MAX), T1);
#ifdef CHECK_FRAGMENTATION
            printf("%p\n", (void*) (q1->pout));
#endif
            alarm1.time += q1->pout->time;
        }
        if (alarm2.time <= alarm1.time && alarm2.time <= alarm3.time)
        {
            time_now = alarm2.time;
#ifdef CHECK_FRAGMENTATION
            printf("\nТекущее время:  (_%.3f_)     Добавляем элемент в очередь <2> по адресу: ", time_now);
#endif
            add_elem(q2, rand_from(T2_MIN, T2_MAX), T2);
#ifdef CHECK_FRAGMENTATION
            printf("%p\n", (void*) (q2->pout));
#endif
            alarm2.time += q2->pout->time;
        }
        if (alarm3.time <= alarm2.time && alarm3.time <= alarm1.time)
        {
#ifdef CHECK_FRAGMENTATION
            printf("\nТекущее время:  (_%.3f_)     Обновляем ОА\n...", time_now);
#endif
            refresh(q1, q2, a);
            time_now = alarm3.time;
            alarm3.time += a->work_time;
        }
    }
    /*printf("STATISTIC:\n"
       "Automat:\n"
       "count q1 : %d\n"
       "count q2 : %d\n"
       "a->prev : %d\n"
       "a->work time %f\n\n", a->left1,a->left2, a->prev, a->work_time);*/


    return time_now;
}