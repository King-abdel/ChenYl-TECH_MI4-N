#include "FichierStructure.h"
#include "FichierSource.h"

// Fonction qui calcule la quantité totale de croquettes nécessaire pour nourrir tous les animaux du refuge en un jour
void day_food() {
    int annee_courante = AnneeCourante();

    float total_croquettes_kg = 0.0; // Initialisation du total de croquettes en kg

    // Parcours de tous les animaux présents dans le refuge
    for (int i = 0; i < nb_animal; i++) {
        Animal a = refuge[i]; // Récupère l'animal courant
        int age = annee_courante - a.annee; // Calcule son âge en années

        // Selon l'espèce de l'animal, on ajoute une quantité différente de croquettes
        switch (a.espece) {
            case hamsters:
                total_croquettes_kg += 0.02; // Un hamster mange environ 20g par jour
                break;
            case autruche:
                total_croquettes_kg += 2.5; // Une autruche mange environ 2.5kg par jour
                break;
            case chats:
            case chien:
                if (age < 2) {
                    // Jeunes chiens ou chats (moins de 2 ans) mangent 500g par jour
                    total_croquettes_kg += 0.5;
                } else {
                    // Sinon, ils mangent l'équivalent de 10% de leur poids
                    total_croquettes_kg += a.poids * 0.10;
                }
                break;
        }
    }

    // Affichage du résultat final
    printf("\n🍽️  Quantité totale de croquettes nécessaire aujourd'hui : %.2f kg\n", total_croquettes_kg);
}
