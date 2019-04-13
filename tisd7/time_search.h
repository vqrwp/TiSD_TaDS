#ifndef INTERFACE_INCLUDED
#define INTERFACE_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define panic(MESSAGE) 			\
do 							\
{  							\
	fprintf(stderr, MESSAGE);		\
	putc('\n',stderr);		\
}							\
while(0)

#define assert_eq(A, B) assert((A) == (B))

#define memory_check( ELEM, RET, MESS)                              \
do                                                          \
{                                                           \
    if (ELEM == NULL)                                          \
    {                                                       \
        panic(MESS);   										\
        return RET;                                 			\
    }                                                       \
} while (0)

int menu_value(void);
unsigned long long int tick(void);

#endif // INTERFACE_INCLUDED