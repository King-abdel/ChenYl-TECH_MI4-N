#include "FichierStructure.h"
#include "FichierSource.h"

// Déclaration du tableau principal contenant les animaux du refuge
Animal refuge[NbAnimal]; // Tableau contenant tous les animaux enregistrés
int nb_animal;           // Nombre actuel d'animaux enregistrés
int prochain_id = 1;     // ID automatique attribué au prochain animal ajouté

// Fonction qui affiche une bannière (en bleu) à l'écran
void afficherBanniere() {
    printf("\033[1;34m"); // Code couleur bleu clair
    printf("\n");
    printf("                 ****   **    **  ********  **       **  **     **        *********  ********    ****   **    **\n");
    printf("                **  **  **    **  **        ** **    **   **   **             **     **         **  **  **    **\n");
    printf("               **       **    **  **        **  **   **    ** **              **     **        **       **    **\n");
    printf("               **       ********  ******    **   **  **     ***               **     ********  **       ********\n");
    printf("               **       **    **  **        **    ** **     ***    ******     **     **        **       **    **\n");
    printf("                **  **  **    **  **        **     ****     ***               **     **         **   ** **    **\n");
    printf("                 ****   **    **  ********  **      ***     ***               **     ********    ****   **    **\n");
    printf("\033[0m"); // Réinitialise la couleur du texte
}

// Fonction principale d'affichage du menu et de gestion des choix utilisateur
void afficherMenu() {
    // Affichage stylisé du menu principal
    printf("\n\033[1;3m"); // Italique
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

    // Message d'invite pour l'utilisateur
    printf("\n✅ Veuillez Sélectionner Une Action (Tapez 7 Pour Quitter ❌) : ");

    int choix;
    do {
        scanf("%d", &choix);

        // Traitement selon le choix de l'utilisateur
        switch (choix) {
            case 1:
                printf("→ [Ajouter un animal] 🐶\n");
                ajouter_animal();     // Appel de la fonction d'ajout
                afficherMenu();       // Affiche à nouveau le menu après action
                break;

            case 2:
                printf("→ [Rechercher un animal] 🔍\n");
                // Fonction manquante : à implémenter si nécessaire
                afficherMenu();
                break;

            case 3:
                printf("→ [Retirer un animal] 🚪\n");
                adopter_animal();     // Appel de la fonction d’adoption
                afficherMenu();
                break;

            case 4:
                printf("→ [Afficher l'inventaire] 📋\n");
                afficherInventaireNbDesc(); // Affiche tous les animaux
                afficherMenu();
                break;

            case 5:
                printf("→ [Afficher charge de travail] 🧳\n");
                {
                    // Appel à la fonction de calcul du temps de nettoyage
                    int total_minutes = calculer_charge_nettoyage_hebdomadaire();
                    int heures = total_minutes / 60;
                    int minutes = total_minutes % 60;

                    // Affichage du temps au format h:min
                    printf("⏱️ Charge totale de nettoyage hebdomadaire : %02dh %02dmin\n", heures, minutes);
                }
                afficherMenu();
                break;

            case 6:
                printf("→ [Afficher la quantité de croquettes] 🍽️\n");
                DAY_FOOD();          // Appel de la fonction pour calcul nourriture
                afficherMenu();
                break;

            case 7:
                printf("Au revoir ! 👋\n"); // Quitte proprement le programme
                break;

            default:
                printf("Choix invalide, réessaie ! ❌\n");
                break;
        }
    } while (choix != 7); // 
}

// Fonction principale : lance le programme
int main() {
	afficherBanniere(); // Affiche la bannière 
    	afficherMenu();     // Affiche le menu au démarrage
    
    return 0;
}
