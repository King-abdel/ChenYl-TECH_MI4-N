#include "FichierStructure.h"
#include "FichierSource.h"

void sauvegarder_animaux() {
    // Création du répertoire "sauvegardes" s'il n'existe pas
    mkdir("sauvegardes", 0777);

    // Génération du nom de fichier horodaté
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char filename[256];
    strftime(filename, sizeof(filename), "sauvegardes/animaux_%Y-%m-%d_%H-%M-%S.txt", t);

    // Ouverture du fichier en écriture
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Erreur d'ouverture du fichier de sauvegarde");
        return;
    }

    // Écriture des données
    for (int i = 0; i < nb_animal; i++) {
        fprintf(file, "%d;%s;%d;%d;%.2f;%s\n",
                refuge[i].id,
                refuge[i].nom,
                refuge[i].espece,
                refuge[i].annee,
                refuge[i].poids,
                refuge[i].descrip);
    }

    fclose(file);
    printf("📁 Sauvegarde c
