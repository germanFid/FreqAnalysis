/*
UI interaction library
*/

#include <stdio.h>
#include "structure.h"

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

    printf("\nИспользование: Lab2 -s [файл для анализа] -i [файл с криптограммой] -n [максимальный размер строки]\n");
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
    printf("Выберите действие:\n1. Отобразить текущее состояние криптограммы\n2. Показать предполагаемые замены\n3. Заменить букву\n4. История замен\n5. Вывод слов с группировкой по длине\n6. Вывод слов с группировкой по количеству нерасшифрованных символов\n7. Автоматическая замена\n0. Выход\n");
}

void letterChangeOption()
{
    printf("Введите две буквы в формате X<ПРОБЕЛ>Y,\nгде Х - это заменяемая буква, Y - заменяющая\n> ");
}

void displayHistory(struct stack *pt)
{
    printf("История замен:\n");
    int sz = pt->top;

    int count = 1;
    for (int i = 0; i < sz; i += 2)
    {
        wprintf(L"%d: %lc -> %lc\n", count, pt->items[i], pt->items[i+1]);
        count++;
    }

    printf("Введите номер шага для отката к нему, \'0\' для выхода\n> ");
}
