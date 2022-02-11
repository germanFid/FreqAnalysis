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

    printf("\nИспользование: Lab2 -i [filename]\n");
}

void printCompare(float* iFreq, wchar_t* iCharset, float* cFreq, wchar_t* cCharset)
{
    printf("Исходный текст\t | \tШифр\n---------------------------------\n");
    for (int i = 0; i < 32; i++)
    {
        wprintf(L"%f\t%lc %lc\t%f\n", iFreq[i], iCharset[i], cCharset[i], cFreq[i]);
    }
}

void printMenu()
{
    printf("Выберите действие:\n1. Отобразить текущее состояние криптограммы\n2. Показать предполагаемые замены\n0. Выход\n");
}