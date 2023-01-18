#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parsef.h"

#define MAX_LENGTH 250

int main(int argc, char *argv[])
{
    printf("C Project");

    // 
    for (int i = 1; i < argc; i++)
    {
        // print all argv
        printf("\nargv[%d] = %s", i, argv[i]);
    }

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

        dataStruct *head = NULL;
        dataStruct *current = NULL;

        // Variables pour stocker les informations de chaque élément
        char buffer[MAX_LENGTH];
        int index = 0;
        int c;

        while ((c = fgetc(fp)) != EOF)
        {
            if (c == '[')
            {
                // Début de liste, on ignore
                continue;
            }
            else if (c == ',' || c == ']')
            {
                // Fin d'un élément, on l'analyse
                buffer[index] = '\0';
                index = 0;

                // Allouer de la mémoire pour l'élément
                dataStruct *element = (dataStruct *)malloc(sizeof(dataStruct));

                // Déterminer le type de l'élément

                char *p = buffer;
                while (*p == ' ')
                {
                    p++;
                }

                memmove(buffer, p, strlen(p) + 1);

                if (strcmp(buffer, "true") == 0)
                {
                    element->type = 0;
                    element->data = "true";
                }
                else if (strcmp(buffer, "false") == 0)
                {
                    element->type = 0;
                    element->data = "false";
                }
                else if (strspn(buffer, "0123456789") == strlen(buffer))
                {
                    element->type = 1;
                    element->data = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
                    strcpy(element->data, buffer);
                }
                else if (strspn(buffer, "0123456789.") == strlen(buffer))
                {
                    element->type = 2;
                    element->data = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
                    strcpy(element->data, buffer);
                }
                else
                {
                    element->type = 3;
                    element->data = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
                    strcpy(element->data, buffer);
                }

                element->next = NULL;

                if (head == NULL)
                {
                    // Premier élément de la liste
                    head = element;
                    current = element;
                }
                else
                {
                    // Ajouter l'élément à la fin de la liste
                    current->next = element;
                    current = element;
                }
            }
            else
            {
                // Ajouter le caractère lu au buffer
                buffer[index] = c;
                index++;
            }
        }
        // Fermer le fichier
        fclose(fp);

        // Afficher les éléments
        print_elements(head);
    }
    return 0;
}

void print_elements(dataStruct *head)
{
    char *types[] = {"boolean", "integer", "float", "string"};

    dataStruct *current = head;
    int i = 0;
    while (current != NULL)
    {
        printf("\n");
        printf("%d:\n", i);
        printf("type: %s\n", types[current->type]);
        printf("content: %s\n", current->data);
        current = current->next;
        i++;
    }

    // libérer la mémoire
    current = head;
    while (current != NULL)
    {
        dataStruct *next = current->next;
        free(current);
        current = next;
    }
}