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
    enum type type;
    struct DATASTRUCT *next;

} typedef dataStruct;


// ajouter un élément à la liste
void ajouterElement(dataStruct *data);
void lireListe(dataStruct *data);

#endif