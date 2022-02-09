/*
UI interaction library
*/

#include <stdio.h>

#define clear() printf("\033[H\033[J") // Очищает весь экран
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x)) // Устанавливает курсор в положение (x, y)

void printInfo()
{
    printf("--- Инструмент криптоаналитика ---\n\n");
}

void printError(int code)
{
    switch (code)
    {
    case 1:
        printf("(!!!) Неправильное имя файла!\n");
        break;

    case 2:
        printf("(!!!) Неправильный формат аргумента(ов)!\n");
        break;
    
    case 3:
        printf("(!!!) Ошибка чтения файла!\n");
        break;
    
    default:
        printf("(!!!) Неопределенная ошибка\n");
        break;
    }

    printf("\nИспользование: Lab2 -f [filename]\n");
}