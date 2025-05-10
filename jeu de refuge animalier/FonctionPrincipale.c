#include "FichierStructure.h"
#include "FichierSource.h"

Animal refuge[NbAnimal];
int nb_animal;
int prochain_id = 1;

int afficherMenu() {
    printf("🐾 === ChenYl-Tech - Menu Principal === 🐾\n");
    printf("1. Ajouter un animal\n");
    printf("2. Rechercher un animal\n");
    printf("3. Supprimer un animal (adoption)\n");
    printf("4. Afficher l'inventaire\n");
    printf("5. Afficher  charge travail\n");
    printf("6. Quitter\n");
    printf("Choix : ");

    int choix;
    scanf("%d\n", &choix);
        
        switch (choix) {
            case 1:
                printf("→ [Ajouter un animal] 🐶\n");
                ajouter_animal();
                break;
            case 2:
                printf("→ [Rechercher un animal] 🔍\n");
                RechercheAnimal();
                break;
            case 3:
                printf("→ [Supprimer un animal] 🚪\n");
                adopter_animal();
                break;
            case 4:
                printf("→ [Afficher l'inventaire] 📋\n");
                afficherInventaireNbDesc();
                break;
            case 5:
                printf("→ [Afficher  charge travail] 🧳\n");
                printf("le temps totale de nettoyage est %d min \n",calculer_charge_nettoyage_hebdomadaire());
                break;
            case 6:
                printf("Au revoir ! 👋\n");
                return choix;
            default:
                printf("Choix invalide, réessaie ! ❌\n");
                break;
    }
    return choix;
}

int main(){
    int a = 0;
    while(a != 6){
	    a = afficherMenu();
    }
	
return 0;
}