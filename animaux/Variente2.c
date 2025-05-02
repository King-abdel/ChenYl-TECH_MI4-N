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
	
    int choix;
    do {
        scanf("%d", &choix);
	    
        switch (choix) {
            case 1:
                printf("→ [Ajouter un animal] 🐶\n");
                break;
            case 2:
                printf("→ [Rechercher un animal] 🔍\n");
                break;
            case 3:
                printf("→ [Supprimer un animal] 🚪\n");
                break;
            case 4:
                printf("→ [Afficher l'inventaire] 📋\n");
                break;
            case 5:
                printf("Au revoir ! 👋\n");
                break;
            default:
                printf("Choix invalide, réessaie ! ❌\n");
        }
    } while (choix<=0 || choix >= 5);
}


	
