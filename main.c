#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ui.h"

char* ReadFile(char *filename)
{
   char *buffer = NULL;
   int stringSize, readSize;
   FILE *handler = fopen(filename, "r");

   if (handler)
   {
       // Seek the last byte of the file
       fseek(handler, 0, SEEK_END);
       // Offset from the first to the last byte, or in other words, filesize
       stringSize = ftell(handler);
       // go back to the start of the file
       rewind(handler);

       // Allocate a string that can hold it all
       buffer = (char*) malloc(sizeof(char) * (stringSize + 1) );

       // Read it all in one operation
       readSize = fread(buffer, sizeof(char), stringSize, handler);

       // fread doesn't set it so put a \0 in the last position
       // and buffer is now officially a string
       buffer[stringSize] = '\0';

       if (stringSize != readSize)
       {
           // Something went wrong, throw away the memory and set
           // the buffer to NULL
           free(buffer);
           buffer = NULL;
       }

       // Always remember to close the file.
       fclose(handler);
    }

    return buffer;
}

int main(int argc, char* argv[])
{
    if (argc != 3 || strcmp(argv[1], "-f") != 0) // check if arguments are correct
    {
        printError(2);
        exit(0);
    }

    char* source = ReadFile(argv[2]);

    if (source == NULL)
    {
        printError(3);
        exit(0);
    }

    puts(source);
    free(source);
    
    return 0;
}