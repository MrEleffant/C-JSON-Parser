#ifndef PARSE_H
#define PARSE_H

enum type
{
    STRING,
    INTEGER,
    FLOAT,
    BOOLEAN
};

struct DATASTRUCT
{
    char *data;
    char type;
    struct DATASTRUCT *next;
} typedef dataStruct;

void print_elements(dataStruct *head);

#endif