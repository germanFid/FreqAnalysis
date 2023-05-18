/*
UI interaction library
*/

#include <stdio.h>

#define clear() wprintf(L"\033[H\033[J") // Очищает весь экран
#define gotoxy(x,y) wprintf(L"\033[%d;%dH", (y), (x)) // Устанавливает курсор в положение (x, y)

void printInfo()
{
    wprintf(L"--- Инструмент криптоаналитика ---\n\n");
}

void printError(int code)
{
    switch (code)
    {
    case 1:
        wprintf(L"(!!!) Неправильное имя файла!\n");
        break;

    case 2:
        wprintf(L"(!!!) Неправильный формат аргумента(ов)!\n");
        break;
    
    case 3:
        wprintf(L"(!!!) Ошибка чтения файла!\n");
        break;
    
    default:
        wprintf(L"(!!!) Неопределенная ошибка\n");
        break;
    }

    wprintf(L"\nИcпoльзoвaниe: Lab2 -s [файл для анализа] -i [файл c криптограммой] -n [максимальный размер строки]\n");
}

void printCompare(float* iFreq, wchar_t* iCharset, float* cFreq, wchar_t* cCharset)
{
    wprintf(L"Исходный текст\t | \tШифp\n---------------------------------\n");
    for (int i = 0; i < 32; i++)
    {
        wprintf(L"%f\t%lc %lc\t%f\n", iFreq[i], iCharset[i], cCharset[i], cFreq[i]);
    }
}

void printMenu()
{
    wprintf(L"Выберите действие:\n1. Отобразить текущее состояние криптограммы\n2. Показать предполагаемые замены\n3. Заменить букву\n4. История замен\n5. Вывод слов с группировкой по длине\n6. Вывод слов с группировкой по количеству нерасшифрованных символов\n0. Выход\n");
}

void letterChangeOption()
{
    wprintf(L"Введите две буквы в формате X<ПРОБЕЛ>Y,\nгдe X - это заменяемая буква, Y - заменяющая\n> ");
}

void displayHistory(wchar_t (*history)[2], int n)
{
    wprintf(L"История замен:\n");

    for (int i = 0; i < n; i++)
    {
        wprintf(L"%d: %lc -> %lc\n", i+1, history[i][0], history[i][1]);
    }

    wprintf(L"Введите номер шага для отката к нему, \'0\' для выхода\n> ");
}
