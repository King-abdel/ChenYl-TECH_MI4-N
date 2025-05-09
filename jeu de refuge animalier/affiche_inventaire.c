void afficherInventaireNbDesc() {
    int compteur[4] = {0}; 
    int indices[4] = {0, 1, 2, 3}; 

   
    for (int i = 0; i < nb_animal; i++) {
        if (refuge[i].espece >= chien && refuge[i].espece <= autruche) {
            compteur[refuge[i].espece - 1]++;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (compteur[i] < compteur[j]) {
                
                int tmp = compteur[i];
                compteur[i] = compteur[j];
                compteur[j] = tmp;
                
                int tmpIdx = indices[i];
                indices[i] = indices[j];
                indices[j] = tmpIdx;
            }
        }
    }


    const char *nomsEspeces[4] = { "Chien 🐶", "Chat 🐱", "Hamster 🐹", "Autruche 🐦" };

    printf("\n📦 Nombre total d'animaux : %d\n", nb_animal);
    printf("📊 Détail par espèce (ordre décroissant) :\n");

    for (int i = 0; i < 4; i++) {
        if (compteur[i] > 0) {
            printf("   - %s : %d\n", nomsEspeces[indices[i]], compteur[i]);
        }
    }
}
