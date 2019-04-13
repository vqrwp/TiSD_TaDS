#include "refresh_automat.h"
#include "rand.h"
#include "constants.h"
//#define CHECK_FRAGMENTATION

void refresh(queue_t* q1, queue_t* q2, automat* a)
{
    if (a->now)
    {
        a->prev = a->now->type;
        if (a->now->type == T1)
        {
#ifdef CHECK_FRAGMENTATION
            printf("Удаляет элемент из очереди <%d> по адресу: %p\n", T1, (void*) (q1->pin));
#endif
            delete_elem(q1);
            a->now = NULL;
        }
        else if(a->now->type == T2)
        {
#ifdef CHECK_FRAGMENTATION
            printf("Удаляет элемент из очереди <%d> по адресу: %p\n", T2, (void*) (q2->pin));
#endif
            delete_elem(q2);
            a->now = NULL;
        }

        if (a->prev == T1 && q1->num_of_elems > 0)
        {
            a->now = q1->pin;
        }
        else if (a->prev == T1 && q1->num_of_elems == 0 && q2->num_of_elems > 0)
        {
            a->now = q2->pin;
        }
        else if (a->prev == T2 && q2->num_of_elems > 0)
        {
            a->now = q2->pin;
        }
        else if (a->prev == T2 && q2->num_of_elems == 0 && q1->num_of_elems > 0)
        {
            a->now = q1->pin;
        }
        else
        {
            return;
        }

        if (a->now->type == T1)
        {
            a->left1++;
            a->work_time = rand_from(T3_MIN, T3_MAX);
            a->work += a->work_time;
        }
        else if (a->now->type == T2)
        {
            a->left2++;
            a->work_time = rand_from(T4_MIN, T4_MAX);
            a->work += a->work_time;
        }
    }
    else {

        if (q1->num_of_elems == 0 && q2->num_of_elems == 0)
        {
            a->downtime += a->work_time;
            return;
        }
        else if (q1->num_of_elems > 0 && q2->num_of_elems == 0)
        {
            a->now = q1->pin;
            a->left1++;
            a->work_time = rand_from(T3_MIN, T3_MAX);
            a->work += a->work_time;
        }
        else if (q1->num_of_elems == 0 && q2->num_of_elems > 0)
        {
            a->now = q2->pin;
            a->left2++;
            a->work_time = rand_from(T4_MIN, T4_MAX);
            a->work += a->work_time;
        }
        else
        {
            if (q1->num_of_elems > 0 && q2->num_of_elems > 0)
            {
                if (a->prev == T1)
                {
                    a->now = q1->pin;
                    a->left1++;
                    a->work_time = rand_from(T3_MIN, T3_MAX);
                    a->work += a->work_time;
                }
                if (a->prev == T2)
                {
                    a->now = q2->pin;
                    a->left2++;
                    a->work_time = rand_from(T4_MIN, T4_MAX);
                    a->work += a->work_time;
                }
            }

        }
    }
}