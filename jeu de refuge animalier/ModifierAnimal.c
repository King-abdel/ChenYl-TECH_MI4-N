#include "FichierStructure.h"
#include "FichierSource.h"
void modifierAnimal() {
    int id;
    int trouve = 0;

    do {
        printf("ID de l'animal à modifier : ");
        scanf("%d", &id);
        while (getchar() != '\n');
    } while (id <= 0);

    for (int i = 0; i < nb_animal; i++) {
        if (refuge[i].id == id) {
            trouve = 1;
            afficheAnimale(refuge[i], 1);  // Avant modification

            int modif;
            do {
                printf("Modifier: 1 le nom | 2 l'année de naissance | 3 l'espèce | 4 le poids | 5 la description\n");
                scanf("%d", &modif);
                while (getchar() != '\n');
            } while (modif < 1 || modif > 5);

            switch (modif) {
                case 1:
                    printf("Nouveau nom : ");
                    fgets(refuge[i].nom, MAX, stdin);
                    refuge[i].nom[strcspn(refuge[i].nom, "\n")] = '\0';
                    break;

                case 2:
                    do {
                        printf("Nouvelle année de naissance : ");
                        scanf("%d", &refuge[i].annee);
                        while (getchar() != '\n');
                    } while (refuge[i].annee < 0);
                    break;

                case 3:
                    do {
                        printf("Nouvelle espèce (1=chien, 2=chat, 3=hamster, 4=autruche) : ");
                        scanf("%d", (int*)&refuge[i].espece);
                        while (getchar() != '\n');
                    } while (refuge[i].espece < 1 || refuge[i].espece > 4);
                    break;

                case 4:
                    do {
                        printf("Nouveau poids : ");
                        scanf("%f", &refuge[i].poids);
                        while (getchar() != '\n');
                    } while (refuge[i].poids < 0);
                    break;

                case 5:
                    printf("Nouvelle description : ");
                    fgets(refuge[i].descrip, MAX, stdin);
                    refuge[i].descrip[strcspn(refuge[i].descrip, "\n")] = '\0';
                    break;
            }

            printf("✅ Animal modifié avec succès !\n");
            afficheAnimale(refuge[i], 1);  // Après modification
            break;
        }
    }

    if (trouve ==0) {
        printf("❌ Aucun animal trouvé avec l'ID %d.\n", id);
    }
    sauvegarder_animaux();
}
