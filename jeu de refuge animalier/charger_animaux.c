#include "FichierStructure.h"
#include "FichierSource.h"

void charger_animaux() {
    FILE *f = fopen("animaux.txt", "r");  // Ouvre le fichier en lecture
    if (!f) return;  // Si le fichier n'existe pas ou ne peut pas être ouvert on quitte la fonction

    Animal a;  // Variable temporaire pour stocker chaque animal lu

    // Lecture ligne par ligne des animaux depuis le fichier
    while (fscanf(f, "%d;%d;%f;%d;%[^;];%[^\n]\n",
                  &a.id, &a.annee, &a.poids, (int*)&a.espece, a.nom, a.descrip) == 6) {
        refuge[nb_animal++] = a;  // Ajoute l’animal lu dans le tableau refuge et incrémente le nombre

        // Met à jour le prochain ID si nécessaire pour éviter les doublons
        if (a.id >= prochain_id) 
            prochain_id = a.id + 1;
    }

    fclose(f);  // Ferme le fichier après avoir fini de lire
}

