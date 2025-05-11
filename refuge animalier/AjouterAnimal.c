#include "FichierStructure.h"
#include "FichierSource.h"

// Fonction pour afficher les informations d’un animal
void afficheAnimal(Animal a, int choix){
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

// Fonction pour ajouter un animal au refuge
void ajouter_animal() { 		
   
    if (nb_animal >= NbAnimal) {	 // Vérifie si la capacité maximale est atteinte
        printf("Capacité maximale atteinte.\n");
    } else {	
        Animal a;                        // Déclare une variable de type Animal
        a.id = prochain_id++;           // génère un identifiant unique automatiquement

        // Saisie du nom de l'animal
        do{
        printf("Nom : \n");
        fgets(a.nom, MAX, stdin);       // lire une chaîne avec espaces
        a.nom[strcspn(a.nom, "\n")] = '\0';  // enlève le '\n' de la chaîne du nom
    }while(a.nom[0]== '\0');

        // Saisie du type d'espèce 
        do {
            printf("Espèce (1:Chien, 2:Chat, 3:Hamster, 4:Autruche) : \n");
            scanf("%d", &a.espece);
            while (getchar() != '\n');  // supprimer le '\n' du tampon
        } while(a.espece < 1 || a.espece > 4);

        // Saisie de l’année de naissance
        do {
            printf("Année de naissance : \n");
            scanf("%d", &a.annee);
            while (getchar() != '\n');  
        } while(a.annee < 0);
        
        // Saisie du poids 
        do {
            printf("Poids (kg) : \n");
            scanf("%f", &a.poids);
            while (getchar() != '\n');
        } while(a.poids <= 0);   

        int choix;
        // Demande pour ajouter une description 
        do {
            printf("Voulez-vous ajouter une description : 1 oui 2 non \n");
            scanf("%d", &choix);
            while (getchar() != '\n');  // enlève le '\n'
        } while(choix != 1 && choix != 2);

        // Saisie de la description si l'utilisateur a choisi oui
        if (choix == 1) {
            do{
            printf("Description : \n");
            fgets(a.descrip, MAX, stdin);                    
            a.descrip[strcspn(a.descrip, "\n")] = '\0';
            }while(a.descrip[0]== '\0');      
        }

        // Ajout de l'animal au tableau refuge 
        refuge[nb_animal++] = a;

        // Affichage des caractéristique de l’animal ajouté
        afficheAnimale(a, choix);

        printf("✅ Animal ajouté avec succès.\n");

        // Sauvegarde dans le fichier 
        sauvegarder_animaux();  
    }
}