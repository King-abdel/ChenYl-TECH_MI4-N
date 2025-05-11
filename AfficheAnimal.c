#include "FichierStructure.h"
#include "FichierSource.h"

// Fonction pour afficher les informations d’un animal
void afficheAnimale(Animal a, int choix){
    printf("-----\n");  
    printf("Nom : %s\n", a.nom);         // Affichage du nom de l’animal
    printf("id : %d\n", a.id);           // Affichage de l’id
    printf("annee : %d\n", a.annee);     // Affichage de l’année de naissance
    printf("poids : %.2f kg\n", a.poids); // Affichage du poids

    // Affichage de l'espèce 
    switch(a.espece){
        case 1 :
            printf("Espece : chien \n");
            break;
        case 2 :
            printf("Espece : chat \n");
            break;
        case 3 :
            printf("Espece : Hamster \n");
            break;
        case 4 :
            printf("Espece : Autruche \n");
            break;
        default:
            printf("Espece : inconnue \n"); // Sécurité si valeur inattendue
            break;
    }

    // Affichage aussi la description
    if(choix == 1){  
        printf("description : %s\n", a.descrip);
    }

    printf("-----\n");  
}
