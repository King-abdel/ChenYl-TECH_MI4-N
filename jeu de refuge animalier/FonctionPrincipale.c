#include "FichierStructure.h"
#include "FichierSource.h"

Animal refuge[NbAnimal];
int nb_animal;
int prochain_id = 1;

void afficherBanniere() {
   printf("\033[1;34m"); 
    printf("\n");
    printf("                 ****   **    **  ********  **       **  **     **        *********  ********    ****   **    **\n");
    printf("                **  **  **    **  **        ** **    **   **   **             **     **         **  **  **    **\n");
    printf("               **       **    **  **        **  **   **    ** **              **     **        **       **    **\n");
    printf("               **       ********  ******    **   **  **     ***               **     ********  **       ********\n");
    printf("               **       **    **  **        **    ** **     ***    ******     **     **        **       **    **\n");
    printf("                **  **  **    **  **        **     ****     ***               **     **         **   ** **    **\n");
    printf("                 ****   **    **  ********  **      ***     ***               **     ********    ****   **    **\n");
    printf("\033[0m"); 
}

void afficherMenu() {
printf("\n\033[1;3m"); 
printf("                              ======================== MENU PRINCIPAL ========================\n");
printf("                              |                                                              |\n");
printf("                              |   1. ➕ Ajouter un animal                                    |\n");
printf("                              |   2. 🔍 Rechercher un animal                                 |\n");
printf("                              |   3. 🏠 Adopter un animal                                    |\n");
printf("                              |   4. 📦 Afficher l'inventaire                                |\n");
printf("                              |   5. 🧽 Afficher la charge de nettoyage hebdomadaire         |\n");
printf("                              |   6. 🍽️  Afficher la quantité de nourriture quotidienne       |\n");
printf("                              |   7. ❌ Quitter le programme                                 |\n");
printf("                              |______________________________________________________________|\n");
printf("\033[0m\n");
printf("\n✅ Veuillez Sélectionner Une Action (Tapez 7 Pour Quitter ❌) : ");


    int choix;
    do {
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("→ [Ajouter un animal] 🐶\n");
                ajouter_animal();
                afficherMenu();
                break;
            case 2:
                printf("→ [Rechercher un animal] 🔍\n");
                afficherMenu();
                break;
            case 3:
                printf("→ [Retirer un animal] 🚪\n");
                adopter_animal();
                afficherMenu();
                break;
            case 4:
                printf("→ [Afficher l'inventaire] 📋\n");
                afficherInventaireNbDesc();
                afficherMenu();
                break;
            case 5:
				printf("→ [Afficher charge de travail] 🧳\n");
					{
				int total_minutes = calculer_charge_nettoyage_hebdomadaire();
				int heures = total_minutes / 60;
				int minutes = total_minutes % 60;
       
				//printf("🧼 Charge totale de nettoyage hebdomadaire : %d minutes\n", total_minutes);//
				printf("⏱️ Charge totale de nettoyage hebdomadaire : %02dh %02dmin\n", heures, minutes);
				}
				afficherMenu();
				break;

            case 6:
				printf("→ [Afficher la quantité de croquettes] 🍽️\n");
				DAY_FOOD();
				afficherMenu();
				break;
            case 7:
                printf("Au revoir ! 👋\n");
                break;
            default:
                printf("Choix invalide, réessaie ! ❌\n");
                break;
        }
    } while (choix != 6);
}



int main(){
afficherMenu();
afficherBanniere();
return 0;
}
