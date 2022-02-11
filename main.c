#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

#include "ui.h"
#include "algo.h"

void wfRead(wchar_t* source, char* filename)
{
    FILE* pFile;
    pFile = fopen (filename , "r");
    if (pFile != NULL)
    {
        if (fgetws (source , 100000 , pFile) == NULL)
        {
            printError(3);
            exit(0);
        }
        fclose (pFile);
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru_RU.UTF-8"); // setting locale to Russian UTF-8

    if (argc != 3 || strcmp(argv[1], "-i") != 0) // check if arguments are correct
    {
        printError(2);
        exit(0);
    }

    wchar_t source[100000];
    wfRead(source, argv[2]);

    clear();
    printInfo();

    strToLowerCase(source);

    float iFreq[32]; // frequency of russian letters in source text
    freqCount(source, iFreq);

    int iCharset[32];
    generateCharArrRU(iCharset);
    bubbleSort(iFreq, 32, iCharset);
    
    wchar_t cypher[100000];
    wfRead(cypher, "input.txt");
    strToLowerCase(cypher);

    float cFreq[32];
    int cCharset[32];
    
    generateCharArrRU(cCharset);
    freqCount(cypher, cFreq);
    bubbleSort(cFreq, 32, cCharset);

    printMenu();
    int choice;

    while(1)
    {
        printf("> ");
        scanf("%1d", &choice);

        switch (choice)
        {
        case 0:
            exit(0);

        case 1:
            wprintf(L"%ls\n", cypher);
            break;

        case 2:
            printCompare(iFreq, iCharset, cFreq, cCharset);
            break;
        
        default:
            printf("Некорректный ввод!\n");
            break;
        }
    }

    return 0;
}