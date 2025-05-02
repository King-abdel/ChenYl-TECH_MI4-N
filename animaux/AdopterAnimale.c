#include "FichierStructure.h"

void adopter_animal() {
    int id;
    printf("ID de l'animal à adopter : ");
    scanf("%d", &id);

    int trouvé = 0;
    for (int i = 0; i < nb_animaux; i++) {
        if (refuge[i].id == id) {
            trouvé = 1;
            for (int j = i; j < nb_animaux - 1; j++) {
                refuge[j] = refuge[j + 1];
            }
            nb_animaux--;
            printf("Animal avec ID %d adopté avec succès.\n", id);
            break;
        }
    }

    if (!trouvé) {
        printf("Aucun animal trouvé avec l'ID %d.\n", id);
    }
}
