#ifndef FICHIER_SOURCE_H
#define FICHIER_SOURCE_H
#include "FichierStructure.h"
#include <sys/stat.h>
#include <sys/types.h>

void afficherBanniere();
int afficherMenu();
void ajouter_animal();
int RechercheAnimal();
void adopter_animal();
void afficheAnimale (Animal a);
int Dayclean();
void day_food();
void afficherInventaireNbDesc();
void modifierAnimal();
void charger_animaux();
int sauvegarder_animaux();
#endif 


