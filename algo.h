#include <stdio.h>
#include "structure.h"

int strToLowerCase(wchar_t* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if (str[i] >= 1040 && str[i] <= 1103) // if the letter is cyrylic
        {
            if(str[i] > 1071)
            {
                str[i] -= 32;
            }
        }
        i++;
    }
    
    return 0;
}

int freqCount(wchar_t* str, float* freq)
{
    long count[32]; // letter quantity in source text
    for (int i = 0; i < 32; i++)
    {
        count[i] = 0;
    }
    
    int i = 0;
    while(str[i] != '\0')
    {
        if (str[i] >= 1040 && str[i] <= 1103)
        {
            count[str[i] - 1040]++;
        }
        i++;
    }

    int c = 0;
    for (int j = 0; j < 32; j++)
        c += count[j];

    for (int j = 0; j < 32; j++)
    {
        freq[j] = (float) count[j] / (float) c;;
    }
    
    return 0;
}

void generateCharArrRU(int* charArr)
{
    for (int i = 0; i < 32; i++)
    {
        charArr[i] = i + 1040;
    }
    
}

void bubbleSort(float* freqArr, int n, int* charArr) // sorts freqArr and applying same changes for charArr
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (freqArr[j] < freqArr[j + 1])
            {
                float tf = freqArr[j];
                int cf = charArr[j];

                freqArr[j] = freqArr[j + 1];
                freqArr[j + 1] = tf;

                charArr[j] = charArr[j + 1];
                charArr[j + 1] = cf;
            }
        }
        
    }
}

int strReplace(wchar_t* str, wchar_t og, wchar_t to, int mode)
{
    if (og >= 1040 && og <= 1103 && to >= 1040 && to <= 1103)
    {
        if (mode)
        {
            if (og > 1071) // protects og symbol from being lowercase
            {
                og -= 32;
            }

            if (to <= 1071) // protects 'to' symbol from being uppercase
            {
                to += 32;
            }
        }

        else // for rewind
        {
             if (og <= 1071) // protects og symbol from being uppercase
            {
                og += 32;
            }

            if (to > 1071) // protects 'to' symbol from being lowercase
            {
                to -= 32;
            }
        }

        int i = 0;
        while (str[i] != '\0')
        {
            if (str[i] == og)
            {
                str[i] = to;
            }

            i++;
        }
    }

    else
        return -1;

    return 0;
}

void historyRewind(wchar_t* str, struct stack *pt , int step, int nSteps)
{
    for (int i = nSteps / 2; i >= step-1; i -= 2)
    {
        // wprintf(L"%lc %lc\n", pt->items[i], pt->items[i-1]);
        // strReplace(str, pt->items[i], pt->items[i-1], 0);
        wchar_t og;
        wchar_t to;

        pop(pt, &og, &to);

        strReplace(str, to, og, 0);
    }
}

long maxLexemeLen(wchar_t* str)
{
    long maxLen = 0;
    long curLen = 0;

    int i = 0;
    while (str[i] != L'\0')
    {
        if (str[i] == L' ')
        {
            if (curLen > maxLen)
            {
                maxLen = curLen;
            }
            curLen = 0;
        }

        else 
            curLen++;

        i++;
    }

    if (curLen > maxLen)
    {
        maxLen = curLen;
    }

    return maxLen;
}

void sortNPrint(wchar_t* str, int decryptedMode)
{
    wchar_t * pwc;
    wchar_t * pt;

    long maxLen = maxLexemeLen(str);

    for (long i = 0; i <= maxLen; i++)
    {
        wchar_t* newStr = malloc(sizeof(*str));
        wcpcpy(newStr, str);

        int flag_printed = 0; // if printed at least one word

        pwc = wcstok(newStr, L" ,.", &pt);
        while (pwc != NULL)
        {
            long l = 0;
            if (!decryptedMode) 
                l = wcslen(pwc);

            else
            {
                int j = 0;
                while (pwc[j] != L'\0')
                {
                    if (pwc[j] >= 1040 && pwc[j] <= 1071)
                        l++;

                    j++;
                }
            }

            if (l == i)
            {
                if (!flag_printed)
                    printf("%ld:\n", i);

                wprintf(L"%ls\n", pwc);
                flag_printed = 1;
            }

            pwc = wcstok(NULL, L" ,.-", &pt);
        }

        free(newStr); 

        if (flag_printed)
            printf("\n"); // print for 'groupig'
    }
}
