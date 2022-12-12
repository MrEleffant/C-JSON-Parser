#include <stdio.h>
#include "parsef.h"

int main(int argc, char *argv[])
{
    printf("C Project");
    for (int i = 1; i < argc; i++)
    {
        // print all argv
        printf("\nargv[%d] = %s", i, argv[i]);
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("\nError: cannot open file %s", argv[i]);
            return 1;
        }

        // checking the file
        // checking for first and last char to be '[' and ']'
        char lastC, firstC, pc, c;
        int firstT = 1, stringParity = 0;

        int virgCount = 0;
        while ((c = fgetc(fp)) != EOF)
        {
            if(c == ',') {
                virgCount++;
                printf("\n");
            } else {
                printf("%c", c);
            }

            if (c == 34 && pc != 92) // check for string issues
            {
                stringParity++;
            }

            if (firstT == 1)
            {
                firstC = c;
            }
            firstT = 0;
            lastC = c;

            pc = c;
        }
        if (firstC != '[' || lastC != ']')
        {
            printf("\nError: file %s is not a valid JSON file", argv[i]);
            return 1;
        }
        if (stringParity % 2 != 0)
        {
            printf("\nError: file %s is not a valid JSON file\nString issue", argv[i]);
            return 1;
        }

        


        fclose(fp);
    }

    return 0;
}