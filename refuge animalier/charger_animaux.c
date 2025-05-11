#include "FichierStructure.h"
#include "FichierSource.h"

// Fonction pour charger les animaux depuis un fichier
void charger_animaux() {
    const char* fichier = "animaux.txt";
    FILE* F = fopen(fichier, "r");
    if (F==NULL) {
        perror("Fichier introuvable ou erreur d'ouverture");
        return;
    }

    nb_animal = 0;  // Réinitialise le compteur avant chargement

    while (nb_animal < NbAnimal &&
           fscanf(F, "%d;%999[^;];%d;%d;%f;%999[^\n]\n",
                  &refuge[nb_animal].id,
                  refuge[nb_animal].nom,
                  (int*)&refuge[nb_animal].espece,
                  &refuge[nb_animal].annee,
                  &refuge[nb_animal].poids,
                  refuge[nb_animal].descrip) == 6) {
        nb_animal++;
    }

    fclose(F);
}

