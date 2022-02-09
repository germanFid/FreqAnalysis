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
    
    default:
        break;
    }

    printf("Usage:\nLab2 -f [filename]\n");
}