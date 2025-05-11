#include "FichierStructure.h"
#include "FichierSource.h"

// Fonction permettant de rechercher des animaux selon plusieurs critères (nom, espèce, âge)
void rechercher_animaux() {
    Animal a;                      // Variable  pour parcourir le tableau
    char nom[MAX];                // Nom à saisir
    int filtre_espece, age_type;  // Variables pour filtrer espèce et type d’âge
    int critere_nom = 0, critere_espece = 0, critere_age = 0; // Variable pour savoir les filtres saisir

    // Demande si l'utilisateur veut filtrer par nom
    do{
    printf("Rechercher par nom ? (1:Oui / 0:Non) : ");
    scanf("%d", &critere_nom);
    while (getchar() != '\n');  // supprime '\n' du tampon
    }while(critere_nom!=0 && critere_nom!=1);
    if (critere_nom == 1) {
        printf("Entrez le nom : ");
        fgets(nom, MAX, stdin);                     // lire une chaîne avec des espaces
        nom[strcspn(nom, "\n")] = '\0';             // enlève du \n dans la chaîne
    }

    // Demande si l'utilisateur veut filtrer par espèce
    do{
        printf("Rechercher par espèce ? (1:Oui / 0:Non) : ");
        scanf("%d", &critere_espece);
        while (getchar() != '\n');
    }while(critere_espece!=0 && critere_espece!=1);
    if (critere_espece == 1) {
        do{
            printf("Espèce (1:Chien, 2:Chat, 3:Hamster, 4:Autruche) : ");
            scanf("%d", &filtre_espece);
            while (getchar() != '\n');
        }while(filtre_espece<1 || filtre_espece>4);
    }

    // Demande si l'utilisateur veut filtrer par âge
    do{
    printf("Rechercher par type d'âge ? (1:Oui / 0:Non) : ");
    scanf("%d", &critere_age);
    while (getchar() != '\n');
    }while(critere_age!=0 && critere_age!=1);
    if (critere_age == 1) {
        do{
        printf("1: Jeune (<2 ans), 2: Senior (>10 ans) : ");
        scanf("%d", &age_type);
        while (getchar() != '\n');
        }while(age_type !=1 && age_type!=2);
    }

    int trouve = 0;                // Marqueur pour savoir si un animal a été trouvé
    int annee_courante = 2025;     // Année actuelle pour le calcul de l’âge

    // Parcours de tous les animaux du refuge
    for (int i = 0; i < nb_animal; i++) {
        a = refuge[i];
        int age = annee_courante - a.annee;  // Calcul de l’âge de l’animal

        int repere = 1;  //vérifie si l’animal correspond à tous les filtres

        // Filtre par nom 
        if (critere_nom == 1 && strcmp(a.nom, nom) != 0){
            repere = 0;
        }
        // Filtre par espèce
        if (critere_espece == 1 && a.espece != filtre_espece){
            repere = 0;
        }
        // Filtre par type d’âge 
        if (critere_age == 1) {
            if ((age_type == 1 && age >= 2) || (age_type == 2 && age <= 10))
                repere = 0;
        }

        // Si l’animal vérifie les filtres, on l’affiche
        if (repere == 1) {
            afficheAnimale(a, 1);  // Affichage des caractéristiques de l'animal
            trouve = 1;
        }
    }

    // le cas où aucun animal n’a été trouvé
    if (trouve == 0){
        printf("Aucun animal ne correspond aux critères.\n");
    }
}
