#include <stdio.h>

int main(int argc, char *argv[])
{
    // print all argv
    printf("Coucou");
    for (int i = 1; i < argc; i++)
    {
        printf("\nargv[%d] = %s", i, argv[i]);
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("\nError: cannot open file %s", argv[i]);
            return 1;
        }
        char c;

        // checking the file
        // checking for first and last char to be '[' and ']'
        char lastC, firstC, bc;
        int firstT = 1, stringParity = 0;
        while ((c = fgetc(fp)) != EOF)
        {
            if (c == 34 && bc != 92) // check for string issues
            {
                stringParity++;
            }

            if (firstT == 1)
            {
                firstC = c;
            }
            firstT = 0;
            lastC = c;
        }
        if (firstC != '[' || lastC != ']')
        {
            printf("\nError: file %s is not a valid JSON file", argv[i]);
            return 1;
        }
        if (stringParity % 2 != 0)
        {
            printf("\nError: file %s is not a valid JSON file\nString issue ", argv[i]);
            return 1;
        }

        // treat file




        fclose(fp);
    }

    return 0;
}