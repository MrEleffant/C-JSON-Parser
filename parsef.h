#ifndef PARSE_H
#define PARSE_H
#define MAX_LENGTH 2048

struct DATASTRUCT
{
    char *data;
    char type;
    struct DATASTRUCT *next;
} typedef dataStruct;

void print_elements(dataStruct *head);
void free_elements(dataStruct *head);
void makeLower(char *str);
#endif