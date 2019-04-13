#ifndef TIME_H
#define TIME_H

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "init_automat.h"
#include "structs.h"

float get_time(queue_t *q1, queue_t *q2, automat *a);

#endif // TIME_H