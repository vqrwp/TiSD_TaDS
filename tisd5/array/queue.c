#include "queue.h"
#include "constants.h"
#include "structs.h"

queue_t* new_queue(int max_size, type_t t)
{
    queue_t* queue = malloc(sizeof(queue_t));
    if (queue)
    {
        float* data_store = malloc(sizeof(float) * max_size);
        if (data_store)
        {
            queue->data_store = data_store;
            queue->front = 0;
            queue->max_size = max_size;
            queue->num_of_elems = 0;
            queue->summ_of_elems = 0;
            queue->type = t;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }

    return queue;
}

int add_elem(queue_t *queue, float item, type_t t)
{
    if (queue->num_of_elems >= queue->max_size || queue->num_of_elems >= ELEM)
    {
        return FAIL;
    }

    queue->data_store[queue->front] = item;

    queue->front++;
    queue->num_of_elems++;
    queue->summ_of_elems++;

    return SUCCESS;
}

float delete_elem(queue_t *queue)
{
    if (queue->num_of_elems < 1)
    {
        return FAIL;
    }

    float result = queue->data_store[0], buf;

    queue->num_of_elems--;
    queue->front--;

    for (int i = 0; i < queue->front; i++)
    {
        buf = queue->data_store[i + 1];
        queue->data_store[i] = buf;
        queue->data_store[i + 1] = 0;
    }
    return result;
}

void queue_free(queue_t* queue)
{
    free(queue->data_store);
    free(queue);
}


void queue_print(queue_t* q)
{
    for (int i = 0; i < q->front; i++)
    {
        printf("%d   %f  \n", i,  q->data_store[i]);
    }
}