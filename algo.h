#include <stdio.h>

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