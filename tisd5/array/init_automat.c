#include "init_automat.h"
#include "constants.h"
#include "structs.h"

automat* init_auto()
{
    automat * my_auto = malloc(sizeof(automat));
    if (my_auto == NULL)
    {
        return NULL;
    }
    else
        {
        my_auto->prev = NONE;
        my_auto->now_t = NONE;
        my_auto->now = -1;
        my_auto->work_time = 0;
        my_auto->left1 = 0;
        my_auto->left2 = 0;
        my_auto->downtime = 0;
        my_auto->work = 0;
        return my_auto;
    }

}





