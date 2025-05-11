#include "FichierStructure.h"
#include "FichierSource.h"

// Fonction pour sauvegarder la liste des animaux dans un fichier texte
int sauvegarder_animaux() {
    // Crée le dossier "refuge" s'il n'existe pas (0777 = permissions maximales)
    mkdir("refuge", 0777);
    // Crée le sous-dossier "refuge/sauvegarde"
    mkdir("refuge/sauvegarde", 0777);

    // Récupère la date et l'heure actuelles
    time_t now = time(NULL);
    struct tm *t = localtime(&now);  // Convertit en structure de date lisible

    // Génère un nom de fichier avec la date : animaux_YYYY-MM-DD.txt
    char filename[200];
    sprintf(filename, "animaux.txt");

    // Ouvre le fichier en écriture
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        // Affiche un message d'erreur si le fichier ne peut pas être ouvert
        printf(" Erreur : impossible d’ouvrir %s\n", filename);
        return 1;
    }

    // Parcourt la liste des animaux et écrit chaque animal dans le fichier
    for (int i = 0; i < nb_animal; i++) {
        Animal a = refuge[i];
        // Écrit les infos de l’animal séparées par des points-virgules
        fprintf(f, "%d;%d;%f;%d;%s;%s\n", a.id, a.annee, a.poids, a.espece, a.nom, a.descrip);
    }

    // Ferme le fichier après écriture
    fclose(f);

    // Confirme que la sauvegarde s’est bien passée
    printf("💾 Sauvegarde réussie dans %s\n", filename);
    return 0;  // Retourne 0 pour indiquer que tout s'est bien passé
}

