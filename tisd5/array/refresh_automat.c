#include "refresh_automat.h"
#include "structs.h"
#include "constants.h"
#include "queue.h"
#include "structs.h"
#include "rand.h"

void refresh_automat(queue_t *q1, queue_t *q2, automat *a)
{
    if (a->now != -1)
    {
        if (a->now_t == T1)
        {
            delete_elem(q1);
            a->now = -1;
            a->prev = T1;
        }
        else
            if (a->now_t == T2)
            {
                delete_elem(q2);
                a->now = -1;
                a->prev = T2;
            }
        if (a->prev == T1 && q1->num_of_elems > 0)
        {
            a->now = q1->data_store[0];
            a->now_t = T1;
        }
        else if (a->prev == T1 && q1->num_of_elems == 0 && q2->num_of_elems > 0)
        {
            a->now = q2->data_store[0];
            a->now_t = T2;
        }
        else if (a->prev == T2 && q2->num_of_elems > 0)
        {
            a->now = q2->data_store[0];
            a->now_t = T2;
        }
        else if (a->prev == T2 && q2->num_of_elems == 0 && q1->num_of_elems > 0)
        {
            a->now = q1->data_store[0];
            a->now_t = T1;
        }
        else
            return;

        if (a->now_t == T1)
        {
            a->left1++;
            a->work_time = randfrom(T3_MIN, T3_MAX);
            a->work += a->work_time;
        }
        else if (a->now_t == T2)
        {
            a->left2++;
            a->work_time = randfrom(T4_MIN, T4_MAX);
            a->work += a->work_time;
        }
    }
    else

        if (q1->num_of_elems == 0 && q2->num_of_elems == 0)
        {
            a->downtime += a->work_time;
            return;
        }
        else if (q1->num_of_elems > 0 && q2->num_of_elems == 0)
        {
            a->now = q1->data_store[0];
            a->now_t = T1;
            a->left1++;
            a->work_time = randfrom(T3_MIN, T3_MAX);
            a->work += a->work_time;
        }
        else if (q1->num_of_elems == 0 && q2->num_of_elems > 0)
        {
            a->now = q2->data_store[0];
            a->now_t = T2;
            a->left2++;
            a->work_time = randfrom(T4_MIN, T4_MAX);
            a->work += a->work_time;
        }
        else
        {
            if (q1->num_of_elems > 0 && q2->num_of_elems > 0)
            {
                if (a->prev == T1)
                {
                    a->now = q1->data_store[0];
                    a->now_t = T1;
                    a->left1++;
                    a->work_time = randfrom(T3_MIN, T3_MAX);
                    a->work += a->work_time;
                }
                if (a->prev == T2)
                {
                    a->now = q2->data_store[0];
                    a->now_t = T2;
                    a->left2++;
                    a->work_time = randfrom(T4_MIN, T4_MAX);
                    a->work += a->work_time;
                }
            }
        }
}