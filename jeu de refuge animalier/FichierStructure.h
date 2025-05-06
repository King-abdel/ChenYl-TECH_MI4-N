#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NbAnimal 50
#define MAX 1000

typedef enum{
    chien = 1, 
    chats, 
    hamsters,
    autruche
}Espece;

typedef struct{
    int id;
    int annee;
    float poids;
    char nom[MAX];
    char descrip[MAX];
    Espece espece;
}Animal;

Animal *refuge[NbAnimal];
int nb_animal= 0;
int prochain_id=1;