#ifndef INIT_AUTOMAT_H
#define INIT_AUTOMAT_H

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"

void refresh_automat(queue_t *q1, queue_t *q2, automat *a);
automat* init_auto();
float randfrom(int min, int max);

#endif // INIT_AUTOMAT_H