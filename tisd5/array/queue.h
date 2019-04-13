#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

queue_t *new_queue(int max_size, enum req_type t);
int add_elem(queue_t *queue, float item, enum req_type t);
void queue_free(queue_t* queue);
float delete_elem(queue_t *queue);
void queue_print(queue_t* q);

#endif // QUEUE_H