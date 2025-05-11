#ifndef FICHIER_SOURCE_H
#define FICHIER_SOURCE_H

#include "FichierStructure.h"
#include <sys/stat.h>
#include <sys/types.h>

void ajouter_animal();
void rechercher_animaux();
void adopter_animal();
void afficheAnimal(Animal a, int choix);
int day_clean();
void day_food();
void afficherInventaireNbDesc();
void modifierAnimal();
void charger_animaux();
int sauvegarder_animaux();
#endif 


