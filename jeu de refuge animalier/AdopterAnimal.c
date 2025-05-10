#include "FichierStructure.h"
#include "FichierSource.h"

void adopter_animal() {
    int id;
    do{
	    printf("ID de l'animal à adopter : ");
	    scanf("%d", &id);
	    while (getchar() != '\n');
    }while(id<=0);

    int trouvé = 0;
    for (int i = 0; i < nb_animal; i++) {   // parcours tout les animaux
        if (refuge[i].id == id) {   
            trouvé = 1;                    
            printf("Animal trouvé :\n");
            afficheAnimale(refuge[i], 1);
            for (int j = i; j < nb_animal - 1; j++) {    
                refuge[j] = refuge[j + 1];                        // on réajuste les indices du tableaux 
            }
            nb_animal--;
            printf("Animal avec ID %d adopté avec succès.\n", id);
            break;
        }
    }
	
    if (trouvé==0) {
        printf("Aucun animal trouvé avec l'ID %d.\n", id);
    }
    
    sauvegarder_animaux(); // sauvegarder la suppression
}
