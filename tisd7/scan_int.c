//
// Created by Margo on 23.12.2018.
//

#include "scan_int.h"

int scan_int()
{
    int rc, num;
    char tmp;
    while(((rc = scanf("%d%c", &num, &tmp)) != 2 && rc != EOF) || tmp != '\n')
    {
        do
        {
            rc = scanf("%c", &tmp);
        }
        while(rc != EOF && tmp != '\n');
    }
    return num;
}