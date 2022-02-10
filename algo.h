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