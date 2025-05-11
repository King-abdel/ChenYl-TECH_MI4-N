#include "FichierStructure.h"  
#include "FichierSource.h" 
#include <sys/stat.h>
#include <sys/types.h>

// Fonction permettant de modifier les informations d’un animal identifié par son ID
void modifierAnimal() {
    int id;         // Variable  de l’id saisi par l’utilisateur
    int trouve = 0; // Marqueur pour vérifier si l’animal a été trouvé

    //  saisir un id valide
    do {
        printf("ID de l'animal à modifier : ");
        scanf("%d", &id);
        while (getchar() != '\n'); // supprime le '\n' du tampon
    } while (id <= 0);

    // Parcours de tous les animaux du refuge pour chercher celui avec l’id correspondant
    for (int i = 0; i < nb_animal; i++) {
        if (refuge[i].id == id) { // Si l’ID correspond à celui d’un animal du tableau
            trouve = 1; // L’animal est trouvé

            // Affiche les caractéristiques de l’animal avant modification
            afficheAnimal(refuge[i], 1);

            int modif; // Variable pour le choix de l’utilisateur

            // Affiche les différentes modifications possibles
            do {
                printf("Modifier: 1.nom | 2.année de naissance | 3.espèce | 4.poids | 5.description : ");
                scanf("%d", &modif);
                while (getchar() != '\n'); 
            } while (modif < 1 || modif > 5);

            // on modifie le critère correspondant
            switch (modif) {
                case 1: // Modification du nom
                    do{
                        printf("Nouveau nom : ");
                        fgets(refuge[i].nom, MAX, stdin); // Lire une chaîne avec des espaces
                        refuge[i].nom[strcspn(refuge[i].nom, "\n")] = '\0'; // enlève le '\n' de la chaîne
                    }while(strlen(refuge[i].nom) == 0);


                    break;

                case 2: // Modification de l’année de naissance
                    do {
                        printf("Nouvelle année de naissance : ");
                        scanf("%d", &refuge[i].annee);
                        while (getchar() != '\n');
                    } while (refuge[i].annee < 0); // L’année doit être positive
                    break;

                case 3: // Modification de l’espèce
                    do {
                        printf("Nouvelle espèce (1:Chien, 2:Chat, 3:Hamster, 4:Autruche) : ");
                        scanf("%d", (int*)&refuge[i].espece); 
                        while (getchar() != '\n');
                    } while (refuge[i].espece < 1 || refuge[i].espece > 4);
                    break;

                case 4: // Modification du poids
                    do {
                        printf("Nouveau poids : ");
                        scanf("%f", &refuge[i].poids);
                        while (getchar() != '\n');
                    } while (refuge[i].poids < 0); // Le poids doit être positif
                    break;

                case 5: // Modification de la description
                    do{
                    printf("Nouvelle description : ");
                    fgets(refuge[i].descrip, MAX, stdin);
                    refuge[i].descrip[strcspn(refuge[i].descrip, "\n")] = '\0'; 
                    } while (strlen(refuge[i].descrip) == 0);
                    break;
            }

            printf("✅ Animal modifié avec succès !\n");
            afficheAnimal(refuge[i], 1); // Affiche les nouvelles informations après les modifications
            break; // Sortir de la boucle 
        }
    }

    // Si aucun animal avec l’ID saisi n’est trouvé
    if (trouve == 0) {
        printf("❌ Aucun animal trouvé avec l'ID %d.\n", id);
    }

    // Sauvegarde les changements dans le fichier
    sauvegarder_animaux(); 
}
