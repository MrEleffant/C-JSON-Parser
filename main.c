#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "parsef.h"

int main(int argc, char *argv[])
{
    printf("C Parser\n");
    for (int i = 1; i < argc; i++)
    {
        // Affichage du nom du fichier
        printf("\nargv[%d] = %s", i, argv[i]);

        FILE *fp = fopen(argv[i], "r");

        // Vérifier si le fichier existe
        if (fp == NULL)
        {
            printf("\nError: cannot open file %s", argv[i]);
            return 1;
        }

        // Variables pour la liste chaînée
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

                // Supprimer les espaces au début du buffer
                char *p = buffer;
                while (*p == ' ')
                {
                    p++;
                }
                memmove(buffer, p, strlen(p) + 1);

                // make copy of buffer and make it lower case
                char bufferCopy[MAX_LENGTH];
                strcpy(bufferCopy, buffer);
                makeLower(bufferCopy);

                // Déterminer le type de l'élément
                if (strcmp(bufferCopy, "true") == 0) // strcmp retourne 0 si les deux chaînes sont identiques
                {
                    element->type = 0;
                    element->data = "true";
                }
                else if (strcmp(bufferCopy, "false") == 0) // strcmp retourne 0 si les deux chaînes sont identiques
                {
                    element->type = 0;
                    element->data = "false";
                }
                else if (strspn(buffer, "0123456789") == strlen(buffer)) // strspn retourne le nombre de caractères de la chaîne 1 qui sont présents dans la chaîne 2
                {
                    element->type = 1;
                    element->data = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
                    strcpy(element->data, buffer);
                }
                else if (strspn(buffer, "0123456789.") == strlen(buffer)) // strspn retourne le nombre de caractères de la chaîne 1 qui sont présents dans la chaîne 2
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

                // Ajouter l'élément à la liste
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
                // Permet d'ignorer les espaces au début de l'élément (Trim)
                if (c == ' ' && i == 0)
                {
                    continue;
                }
                else
                {
                    // Ajouter le caractère lu au buffer
                    buffer[index++] = c;
                }
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
    // Tableau de chaînes de caractères
    char *types[] = {"boolean", "integer", "float", "string"};

    dataStruct *current = head;
    int i = 1;

    // Parcourir la liste
    while (current != NULL)
    {
        int typeNbr = current->type;

        printf("\n");
        printf("%d:\n", i);
        printf("type: %s\n", types[typeNbr]);
        printf("content: %s\n", current->data);
        current = current->next;
        i++;
    }
}

void free_elements(dataStruct *head)
{
    // Parcourir la liste
    dataStruct *current = head;
    while (current != NULL)
    {
        // Libérer la mémoire allouée pour l'élément
        dataStruct *next = current->next;
        free(current);
        current = next;
    }
}

void makeLower(char *str)
{
    int i = 0;
    // Parcourir la chaîne
    while (str[i])
    {
        // Convertir en minuscule
        str[i] = tolower(str[i]);
        i++;
    }
}