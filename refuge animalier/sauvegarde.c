#include "FichierStructure.h"
#include "FichierSource.h"
#include <sys/stat.h>
#include <sys/types.h>

// Fonction pour sauvegarder les animaux depuis un fichier
void sauvegarder_animaux() {
    // Création du dossier "sauvegardes" 
    mkdir("sauvegardes", 0777);

    // Nom de fichier fixe (toujours le même)
    const char* fichier = "sauvegardes/animaux.txt";

    // Ouverture du fichier en écriture (écrase l'ancien)
    FILE* F = fopen(fichier, "w");
    if (F==NULL) {
        perror("Erreur d'ouverture du fichier de sauvegarde");
        return;
    }

    // Écriture des données
    for (int i = 0; i < nb_animal; i++) {
        fprintf(F, "%d;%s;%d;%d;%.2f;%s\n",
                refuge[i].id,
                refuge[i].nom,
                refuge[i].espece,
                refuge[i].annee,
                refuge[i].poids,
                refuge[i].descrip);
    }

    fclose(F);
}