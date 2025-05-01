#include "FichierStructure.h"

void ajouter_animal(){ 
    if (nb_animaux >= MAX_ANIMAUX) {
    printf("Capacité maximale atteinte.\n");
    return 1;
}
Animale a;
a.numero_iden = prochain_id++;

printf("Nom : ");
scanf("%s", a.nom);

printf("Espèce (0:Chien, 1:Chat, 2:Hamster, 3:Autruche) : ");
scanf("%d", &a.espece);

printf("Année de naissance : ");
scanf("%d", &a.annee);

printf("Poids (kg) : ");
scanf("%f", &a.poids);

refuge[nb_animaux++] = a;
printf("Animal ajouté, son id est %d.\n", a.numero_iden);
}
