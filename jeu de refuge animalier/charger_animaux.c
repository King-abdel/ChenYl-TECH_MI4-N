#include "FichierStructure.h"
#include "FichierSource.h"

// Fonction pour charger les animaux depuis un fichier
void charger_animaux(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Fichier introuvable ou erreur d'ouverture");
        return;
    }

    // Utilisation de nb_animal pour charger les animaux du fichier
    while (fscanf(file, "%d;%99[^;];%d;%d;%f;%199[^\n]\n", 
                  &refuge[nb_animal].id,
                  refuge[nb_animal].nom,
                  &refuge[nb_animal].espece,
                  &refuge[nb_animal].annee,
                  &refuge[nb_animal].poids,
                  refuge[nb_animal].descrip) == 6) {
        nb_animal++;  // Incrémentation du nombre d'animaux chargés
        if (nb_animal >= NbAnimal) break;  // Stop si on atteint la capacité maximale
    }

    fclose(file);
}
