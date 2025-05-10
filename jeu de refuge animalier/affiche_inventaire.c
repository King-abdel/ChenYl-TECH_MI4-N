#include "FichierStructure.h"

// Les espèces sont affichées par ordre décroissant de leur nombre
void afficherInventaireNbDesc() {
    int compteur[4] = {0};    // Tableau pour compter le nombre d'animaux par espèce
                              // Indices : 0 = chien, 1 = chat, 2 = hamster, 3 = autruche

    int indices[4] = {0, 1, 2, 3}; // Tableau des indices servant à trier les espèces sans perdre le lien avec leur nom

    // Étape 1 : Comptage des animaux par espèce
    for (int i = 0; i < nb_animal; i++) {
        if (refuge[i].espece >= chien && refuge[i].espece <= autruche) {
            compteur[refuge[i].espece - 1]++; // On utilise l’énumération (débutant à 1)
        }
    }

    // Étape 2 : Tri des espèces en fonction du nombre d'animaux (ordre décroissant)
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (compteur[i] < compteur[j]) {
                // Échange des valeurs de compteur
                int tmp = compteur[i];
                compteur[i] = compteur[j];
                compteur[j] = tmp;

                // Échange également des indices associés (pour garder les noms cohérents)
                int tmpIdx = indices[i];
                indices[i] = indices[j];
                indices[j] = tmpIdx;
            }
        }
    }

    // Tableau des noms des espèces (dans l’ordre d'origine)
    const char *nomsEspeces[4] = { "Chien 🐶", "Chat 🐱", "Hamster 🐹", "Autruche 🐦" };

    // Affichage global
    printf("\n📦 Nombre total d'animaux : %d\n", nb_animal);
    printf("📊 Détail par espèce (ordre décroissant) :\n");

    // Affichage des espèces présentes avec leur nombre, triées par ordre décroissant
    for (int i = 0; i < 4; i++) {
        if (compteur[i] > 0) { // On affiche seulement les espèces présentes
            printf("   - %s : %d\n", nomsEspeces[indices[i]], compteur[i]);
        }
    }
}

