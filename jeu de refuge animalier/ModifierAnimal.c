#include "FichierStructure.h"  
#include "FichierSource.h" 

// Fonction pour modifier les informations d'un animal à partir de son ID
void modifierAnimal() {
    int id;           // ID saisi par l'utilisateur
    int trouve = 0;   // marqeur pour savoir si l'animal a été trouvé

    // Demande un ID valide (> 0)
    do {
        printf("ID de l'animal à modifier : ");        // Identifier l'animal par son id
        scanf("%d", &id);
        while (getchar() != '\n'); // Nettoie le buffer clavier
    } while (id <= 0);

    // Parcours de tous les animaux pour trouver celui avec l'ID saisi
    for (int i = 0; i < nb_animal; i++) {
        if (refuge[i].id == id) { // Si l'animal est trouvé
            trouve = 1;
            afficheAnimale(refuge[i], 1);  // Affiche l'animal avant modification

            int modif;
            // Demande à l'utilisateur quelle information il souhaite modifier
            do {
                printf("Modifier: 1 le nom | 2 l'année de naissance | 3 l'espèce | 4 le poids | 5 la description\n");
                scanf("%d", &modif);
                while (getchar() != '\n'); // Nettoie le buffer
            } while (modif < 1 || modif > 5);

            // En fonction du choix, demande la nouvelle valeur
            switch (modif) {
                case 1:
                    printf("Nouveau nom : ");
                    fgets(refuge[i].nom, MAX, stdin); // Lit le nouveau nom
                    refuge[i].nom[strcspn(refuge[i].nom, "\n")] = '\0'; // Enlève le '\n'
                    break;

                case 2:
                    do {
                        printf("Nouvelle année de naissance : ");
                        scanf("%d", &refuge[i].annee); // Met à jour l’année
                        while (getchar() != '\n');
                    } while (refuge[i].annee < 0); // Vérifie la validité
                    break;

                case 3:
                    do {
                        printf("Nouvelle espèce (1=chien, 2=chat, 3=hamster, 4=autruche) : ");
                        scanf("%d", (int*)&refuge[i].espece); // Met à jour l’espèce
                        while (getchar() != '\n');
                    } while (refuge[i].espece < 1 || refuge[i].espece > 4);
                    break;

                case 4:
                    do {
                        printf("Nouveau poids : ");
                        scanf("%f", &refuge[i].poids); // Met à jour le poids
                        while (getchar() != '\n');
                    } while (refuge[i].poids < 0); // Le poids doit être positif
                    break;

                case 5:
                    printf("Nouvelle description : ");
                    fgets(refuge[i].descrip, MAX, stdin); // Lit la nouvelle description
                    refuge[i].descrip[strcspn(refuge[i].descrip, "\n")] = '\0';
                    break;
            }

            printf(" Animal modifié avec succès !\n");
            afficheAnimale(refuge[i], 1);  // Affiche l’animal après modification
            break; // Sort de la boucle car l’animal a été trouvé et modifié
        }
    }

    // Si aucun animal ne correspond à l'ID saisi
    if (trouve == 0) {
        printf(" Aucun animal trouvé avec l'ID %d.\n", id);
    }

    // Sauvegarde les modifications dans le fichier
    sauvegarder_animaux(); // Sauvegarde tous les animaux, y compris le modifié
}

