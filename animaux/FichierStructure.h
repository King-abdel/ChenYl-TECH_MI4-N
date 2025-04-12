#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define Max 1000

typedef enum{
    chiens, 
    chats, 
    hamsters,
    autruche
}Espece;

typedef struct{
    int numero_iden;
    int annee;
    int poids;
    char nom[Max];
    char descrip[Max];
    Espece espece;
}Animale;

