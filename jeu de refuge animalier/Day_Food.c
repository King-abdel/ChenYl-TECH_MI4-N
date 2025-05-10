#include "FichierStructure.h"

void DAY_FOOD() {
    int annee_courante;
    printf("\n Entrez l'année actuelle : ");
    scanf("%d", &annee_courante);

    float total_croquettes_kg = 0.0;

    for (int i = 0; i < nb_animal; i++) {
        Animal a = refuge[i];
        int age = annee_courante - a.annee;

        switch (a.espece) {
            case hamsters:
                total_croquettes_kg += 0.02; // 20g
                break;
            case autruche:
                total_croquettes_kg += 2.5;   // 2.5kg
                break;
            case chats:
            case chien:
                if (age < 2) {
                    total_croquettes_kg += 0.5; // 500g
                } else {
                    total_croquettes_kg += a.poids * 0.10; // 10% du poids
                }
                break;
        }
    }

    printf("\n🍽️  Quantité totale de croquettes nécessaire aujourd'hui : %.2f kg\n", total_croquettes_kg);
