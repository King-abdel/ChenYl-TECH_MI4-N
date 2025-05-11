#include "FichierStructure.h"
#include "FichierSource.h"

// Fonction qui permet d’adopter (supprimer) un animal du refuge selon son identifiant
void adopter_animal() {
    int id;  // Variable de l'id de l’animal à adopter 

    // Saisir l'id de l'animal à adopter
    do {
        printf("ID de l'animal à adopter (entier positif) : ");
        scanf("%d", &id);
        while (getchar() != '\n');  // supprimer le '\n' du tampon
    } while (id <= 0);  // L’ID doit être strictement positif

    int trouvé = 0;  // Marqueur pour savoir si l’animal correspondant à l’id a été trouvé

    // Parcours du tableau des animaux
    for (int i = 0; i < nb_animal; i++) {
        if (refuge[i].id == id) {  // Si l'id de l'animal correspond à celui recherché
            trouvé = 1;            //  on a trouvé l’animal

            printf("Animal trouvé :\n");
            afficheAnimal(refuge[i], 1);  // Affiche les détails de l’animal trouvé

            // Réajustement des indices : on décale les animaux suivants d’une position vers la gauche
            for (int j = i; j < nb_animal - 1; j++) {
                refuge[j] = refuge[j + 1];  // Écrase les données de refuge[i] avec refuge[i+1]
            }

            nb_animal--;  // On retire le nombre animal car un animal a été supprimé
            printf("Animal avec ID %d adopté avec succès.\n", id);
            break;        // Sort de la boucle après adoption
        }
    }

    // le cas où aucun animal n’a été trouvé avec l’ID saisi
    if (trouvé == 0) {
        printf("Aucun animal trouvé avec l'ID %d.\n", id);
    }

    // Sauvegarde la nouvelle liste d'animaux après adoption
    sauvegarder_animaux();
}
