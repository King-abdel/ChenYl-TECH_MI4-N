#include "FichierStructure.h"
#include "FichierSource.h"


void rechercher_animaux() {
    Animal a;
    char nom[MAX];
    int filtre_espece, age_type;
    int critere_nom = 0, critere_espece = 0, critere_age = 0;

    printf("Rechercher par nom ? (1:Oui / 0:Non) : ");
    scanf("%d", &critere_nom);
    while (getchar() != '\n');
    if (critere_nom == 1) {
        printf("Entrez le nom : ");
        fgets(nom, MAX,stdin);
        nom[strcspn(nom, "\n")] = '\0';
    }

    printf("Rechercher par espèce ? (1:Oui / 0:Non) : ");
    scanf("%d", &critere_espece);
    while (getchar() != '\n');
    if (critere_espece == 1) {
        printf("Espèce (1:Chien, 2:Chat, 3:Hamster, 4:Autruche) : ");
        scanf("%d", &filtre_espece);
        while (getchar() != '\n');
    }

    printf("Rechercher par type d'âge ? (1:Oui / 0:Non) : ");
    scanf("%d", &critere_age);
    while (getchar() != '\n');
    if (critere_age == 1) {
        printf("1: Jeune (<2 ans), 2: Senior (>10 ans) : ");
        scanf("%d", &age_type);
        while (getchar() != '\n');
    }

    int trouve = 0;
    int annee_courante = 2025;
    for (int i = 0; i < nb_animal; i++) {
        a = refuge[i];
        int age = annee_courante - a.annee;

        int repere = 1;
        if (critere_nom == 1 && strcmp(a.nom, nom) != 0)
            repere = 0;
        if (critere_espece == 1 && a.espece != filtre_espece)
            repere = 0;
        if (critere_age == 1) {
            if ((age_type == 1 && age >= 2) || (age_type == 2 && age <= 10))
                repere = 0;
        }

        if (repere == 1) {
            afficheAnimale(a, 1);
            trouve = 1;
        }
    }
    if (trouve==0){
        printf("Aucun animal ne correspond aux critères.\n");
    }
}
