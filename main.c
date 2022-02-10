#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

#include "ui.h"
#include "algo.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru_RU.UTF-8"); // setting locale to Russian UTF-8

    if (argc != 3 || strcmp(argv[1], "-f") != 0) // check if arguments are correct
    {
        printError(2);
        exit(0);
    }

    // wchar_t* source = ReadFile(argv[2]);
    wchar_t source[10000];
    FILE* pFile;

    pFile = fopen (argv[2] , "r");
    if (pFile != NULL)
    {
        if (fgetws (source , 100 , pFile) == NULL)
        {
            printError(3);
            exit(0);
        }
        fclose (pFile);
    }

    clear();
    printInfo();

    int result = strToLowerCase(source);

    printf("Исходная строка: ");
    wprintf(L"%ls\n", source);

    return 0;
}