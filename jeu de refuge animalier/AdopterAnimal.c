#include "FichierStructure.h"

void adopter_animal() {
    int id;
    printf("ID de l'animal à adopter : ");
    scanf("%d", &id);

    int trouvé = 0;
    for (int i = 0; i < nb_animal; i++) {
        if (refuge[i].id == id) {
            trouvé = 1;
            for (int j = i; j < nb_animal - 1; j++) {
                refuge[j] = refuge[j + 1];
            }
            nb_animal--;
            printf("Animal avec ID %d adopté avec succès.\n", id);
            break;
        }
    }

    if (trouvé==0) {
        printf("Aucun animal trouvé avec l'ID %d.\n", id);
    }
}
