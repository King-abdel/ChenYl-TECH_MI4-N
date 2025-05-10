
#ifndef FICHIERSTRUCTURE_H
#include <sys/stat.h>
#include <sys/types.h>


int sauvegarder_animaux() {
    mkdir("refuge", 0777);
    mkdir("refuge/sauvegarde", 0777);

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char filename[200];
    sprintf(filename, "refuge/sauvegarde/animaux_%04d-%02d-%02d.txt",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("❌ Erreur : impossible d’ouvrir %s\n", filename);
        return 1;
    }

    for (int i = 0; i < nb_animal; i++) {
        Animal a = refuge[i];
        fprintf(f, "%d;%d;%f;%d;%s;%s\n", a.id, a.annee, a.poids, a.espece, a.nom, a.descrip);
    }

    fclose(f);
    printf("💾 Sauvegarde réussie dans %s\n", filename);
    return 0;
}
