#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NbAnimale 50
#define MAX 1000

typedef enum{
    chien = 1, 
    chats, 
    hamsters,
    autruche
}Espece;

typedef struct{
    int numero_iden;
    int annee;
    float poids;
    char nom[MAX];
    char descrip[MAX];
    Espece espece;
}Animale;

