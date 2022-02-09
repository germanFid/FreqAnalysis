/*
UI interaction library
*/

#include <stdio.h>

void printError(int code)
{
    switch (code)
    {
    case 1:
        printf("(!!!) Incorrect filename!\n");
        break;

    case 2:
        printf("(!!!) Incorrect argument(s) format!\n");
        break;
    
    case 3:
        printf("(!!!) Error on reading file!\n");
        break;
    
    default:
        printf("(!!!) Undefined Error!\n");
        break;
    }

    printf("\nUsage: Lab2 -f [filename]\n");
}