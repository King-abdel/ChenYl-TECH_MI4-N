#include <stdio.h>
#include <stdlib.h>

void afficherMenu() {
    printf("🐾 === ChenYl-Tech - Menu Principal === 🐾\n");
    printf("1. Ajouter un animal\n");
    printf("2. Rechercher un animal\n");
    printf("3. Supprimer un animal (adoption)\n");
    printf("4. Afficher l'inventaire\n");
    printf("5. Quitter\n");
    printf("Choix : ");
}

int main() {
    int choix;
    do {
        afficherMenu();
        scanf("%d", &choix);
        getchar(); // pour absorber le \n

        switch (choix) {
            case 1:
                printf("→ [Ajouter un animal] 🐶\n");
                // ici tu appelles ta fonction pour ajouter
                break;
            case 2:
                printf("→ [Rechercher un animal] 🔍\n");
                // ici tu appelles ta fonction pour rechercher
                break;
            case 3:
                printf("→ [Supprimer un animal] 🚪\n");
                // ici pour l’adoption
                break;
            case 4:
                printf("→ [Afficher l'inventaire] 📋\n");
                // ici pour afficher tout
                break;
            case 5:
                printf("Au revoir ! 👋\n");
                break;
            default:
                printf("Choix invalide, réessaie ! ❌\n");
        }

        printf("\n");
    } while (choix != 5);

    return 0;
}


	
