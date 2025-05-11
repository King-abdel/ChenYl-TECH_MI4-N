#include "FichierStructure.h"
#include "FichierSource.h"

 // Fonction pour sauvegarder la liste des animaux dans deux fichiers (un horodaté + un fixe)
int sauvegarder_animaux() {
    // Crée les dossiers s'ils n'existent pas
    mkdir("refuge", 0777);
    mkdir("refuge/sauvegarde", 0777);

    // Date actuelle pour nom du fichier horodaté
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char filename[200];
    sprintf(filename, "refuge/sauvegarde/animaux_%04d-%02d-%02d.txt",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

    // Sauvegarde 1 : fichier horodaté 
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf(" Erreur : impossible d’ouvrir %s\n", filename);
        return 1;
    }

    for (int i = 0; i < nb_animal; i++) {
        Animal a = refuge[i];
        fprintf(f, "%d;%d;%f;%d;%s;%s\n", a.id, a.annee, a.poids, a.espece, a.nom, a.descrip);
    }
    fclose(f);
    printf(" Sauvegarde horodatée réussie dans %s\n", filename);

    // Sauvegarde 2 : fichier fixe pour rechargement
    FILE *f2 = fopen("animaux.txt", "w");
    if (f2 != NULL) {
        for (int i = 0; i < nb_animal; i++) {
            Animal a = refuge[i];
            fprintf(f2, "%d;%d;%f;%d;%s;%s\n", a.id, a.annee, a.poids, a.espece, a.nom, a.descrip);
        }
        fclose(f2);
        printf(" Sauvegarde pour chargement automatique réussie dans animaux.txt\n");
    } else {
        printf(" Erreur : impossible d’écrire dans animaux.txt\n");
    }

    return 0;
}
