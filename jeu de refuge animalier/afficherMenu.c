
int afficherMenu() {
    printf("\n\033[1;3m"); 
    printf("                              ======================== MENU PRINCIPAL ========================\n");
    printf("                              |                                                              |\n");
    printf("                              |   1. ➕ Ajouter un animal                                    |\n");
    printf("                              |   2. 🔍 Rechercher un animal                                 |\n");
    printf("                              |   3. 🏠 Adopter un animal                                    |\n");
    printf("                              |   4. 📦 Afficher l'inventaire                                |\n");
    printf("                              |   5. 🧽 Afficher la charge de nettoyage hebdomadaire         |\n");
    printf("                              |   6. 🍽️ Afficher la quantité de nourriture quotidienne       |\n");
    printf("                              |   7. 📝 Modifier les informations d’un animal                |\n");                  
    printf("                              |   8. ❌ Quitter le programme                                 |\n");
    printf("                              |______________________________________________________________|\n");
    printf("\033[0m\n");
    printf("\n✅ Veuillez Sélectionner Une Action (Tapez 8 Pour Quitter ❌) : ");
	
    int choix;

        scanf("%d", &choix);
        while (getchar() != '\n');
	    
        switch (choix) {
            case 1:
                printf("→ [Ajouter un animal] 🐶\n");
                ajouter_animal();
                break;
            case 2:
                printf("→ [Rechercher un animal] 🔍\n");
                rechercher_animaux();
                break;
            case 3:
                printf("→ [Retirer un animal] 🚪\n");
                adopter_animal();
                break;
            case 4:
                printf("→ [Afficher l'inventaire] 📋\n");
                afficherInventaireNbDesc();
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
				break;

            case 6:
				printf("→ [Afficher la quantité de croquettes] 🍽️\n");
				day_food();
				break;
            case 7:
                    printf("→ [Modifier un animal] 📝\n");
                    modifierAnimal();
                break;
            case 8:
                printf("Au revoir ! 👋\n");
                break;
            default:
                printf("Choix invalide, réessaie ! ❌\n");
                break;
    }
    return choix;
}
