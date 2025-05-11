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
 

// Fonction qui affiche le menu principal et gère les choix de l'utilisateur
int afficherMenu() {
    // Affichage du menu  
    printf("\n\033[1;3m"); // Activation du style italique et gras dans le terminal 
    printf("                              ======================== MENU PRINCIPAL ========================\n");
    printf("                              |                                                              |\n");
    printf("                              |   1. ➕ Ajouter un animal                                    |\n");
    printf("                              |   2. 🔍 Rechercher un animal                                 |\n");
    printf("                              |   3. 🏠 Adopter un animal                                    |\n");
    printf("                              |   4. 📦 Afficher l'inventaire                                |\n");
    printf("                              |   5. 🧽 Afficher la charge de nettoyage hebdomadaire         |\n");
    printf("                              |   6. 🍽️ Afficher la quantité de nourriture quotidienne        |\n");
    printf("                              |   7. 📝 Modifier les informations d’un animal                |\n");                  
    printf("                              |   8. ❌ Quitter le programme                                 |\n");
    printf("                              |______________________________________________________________|\n");
    printf("\033[0m\n"); 
   
    printf("\n✅ Veuillez Sélectionner Une Action (Tapez 8 Pour Quitter ❌) : ");
	
    int choix;

    scanf("%d", &choix); // Lecture du choix utilisateur
    while (getchar() != '\n'); // Enlève les caractères restants (comme "Entrée") après scanf


    // Traitement du choix via un switch
    switch (choix) {
        case 1:
            printf("→ [Ajouter un animal] 🐶\n");
            ajouter_animal(); // Appel à la fonction pour ajouter un animal
            break;

        case 2:
            printf("→ [Rechercher un animal] 🔍\n");
            rechercher_animaux(); // Appel à la fonction de recherche
            break;

        case 3:
            printf("→ [Retirer un animal] 🚪\n");
            adopter_animal(); // Appel à la fonction pour adopter (retirer) un animal
            break;

        case 4:
            printf("→ [Afficher l'inventaire] 📋\n");
            afficherInventaireNbDesc(); // Appel à la fonction d'affichage de l'inventaire
            break;

        case 5:
            printf("→ [Afficher charge de travail] 🧳\n");
            {
                // Calcul de la charge de nettoyage hebdomadaire
                int total_minutes = day_clean();
                int heures = total_minutes / 60;
                int minutes = total_minutes % 60;

                // Affichage du résultat sous forme "hh:mm"
                printf("⏱️ Charge totale de nettoyage hebdomadaire : %02dh %02dmin\n", heures, minutes);
            }
            break;

        case 6:
            printf("→ [Afficher la quantité de croquettes] 🍽️\n");
            day_food(); // Appel à la fonction pour afficher la nourriture quotidienne
            break;

        case 7:
            printf("→ [Modifier un animal] 📝\n");
            modifierAnimal(); // Appel à la fonction de modification d’un animal
            break;

        case 8:
            printf("Au revoir ! 👋\n"); // Fin du programme
            break;

        default:
            printf("Choix invalide, réessaie ! ❌\n"); // Gestion des entrées incorrectes
            break;
    }

    return choix; 
}

int main(){
    int a = 0;
    afficherBanniere();
    charger_animaux();
    prochain_id = 1;
    for (int i = 0; i < nb_animal; i++) {
        if (refuge[i].id >= prochain_id){
            prochain_id = refuge[i].id + 1;
        }
}
    while(a != 8){
	a = afficherMenu();
    }
return 0;
}
