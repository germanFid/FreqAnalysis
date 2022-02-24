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

    if (argc != 7 || strcmp(argv[1], "-s") != 0 || strcmp(argv[3], "-i") != 0 || strcmp(argv[5], "-n") != 0) // check if arguments are correct
    {
        printError(2);
        exit(0);
    }

    char* end;
    long strSize = strtol(argv[6], &end, 10);

    wchar_t source[strSize];
    wfRead(source, argv[2]);

    clear();
    printInfo();

    strToLowerCase(source);

    float iFreq[32]; // frequency of russian letters in source text
    freqCount(source, iFreq);

    int iCharset[32];
    generateCharArrRU(iCharset);
    bubbleSort(iFreq, 32, iCharset);
    
    wchar_t cypher[strSize];
    wfRead(cypher, argv[4]);
    strToLowerCase(cypher);

    float cFreq[32];
    int cCharset[32];
    
    generateCharArrRU(cCharset);
    freqCount(cypher, cFreq);
    bubbleSort(cFreq, 32, cCharset);

    wchar_t changeHistory[5000][2];
    int nChanges = 0;

    printMenu();
    int choice;

    while(1)
    {
        printf("> ");
        scanf("%1d", &choice);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }

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

        case 3:
            letterChangeOption();
            
            wchar_t og;
            wchar_t to;

            wscanf(L"%lc %lc", &og, &to);

            int res = strReplace(cypher, og, to, 1);
            
            if (!res)
            {
                changeHistory[nChanges][0] = og;
                changeHistory[nChanges][1] = to;

                nChanges++;
            }
            break;

        case 4:
            displayHistory(changeHistory, nChanges);
            scanf("%d", &choice);

            if (choice == 0)
            {
                break;
            }

            choice--;
            historyRewind(cypher, changeHistory, choice, nChanges-1);
            nChanges = choice + 1;
            break;

        case 5:
            sortNPrint(cypher, 0);
            break;
        
        case 6:
            sortNPrint(cypher, 1);
            break;
        
        default:
            printf("Некорректный ввод!\n");
            break;
        }
    }

    return 0;
}
