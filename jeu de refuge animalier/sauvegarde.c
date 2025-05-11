#include "FichierStructure.h"
#include "FichierSource.h"

 // Fonction pour sauvegarder la liste des animaux dans un fichier texte
void sauvegarder_animaux(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Erreur d'ouverture du fichier de sauvegarde");
        return;
    }

    // Utilisation de nb_animal pour parcourir les animaux ajoutés dans le refuge
    for (int i = 0; i < nb_animal; i++) {
        fprintf(file, "%d;%s;%d;%d;%.2f;%s\n",
                refuge[i].id,
                refuge[i].nom,          // nom de l'animal
                refuge[i].espece,       // espèce de l'animal
                refuge[i].annee,        // année de naissance
                refuge[i].poids,        // poids de l'animal
                refuge[i].descrip);     // description de l'animal
    }

    fclose(file);
}
