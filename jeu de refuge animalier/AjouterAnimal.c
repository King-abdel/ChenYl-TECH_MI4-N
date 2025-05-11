#include "FichierStructure.h"
#include "FichierSource.h"

void ajouter_animal() { 		// Fonction pour ajouter un animal au refuge
   
    if (nb_animal >= NbAnimal) {	 // Vérifie si la capacité maximale est atteinte
        printf("Capacité maximale atteinte.\n");
    } else {	
        Animal a;                        // Déclare une variable de type Animal
        a.id = prochain_id++;           // génère un identifiant unique automatiquement

        // Saisie du nom de l'animal
        printf("Nom : \n");
        fgets(a.nom, MAX, stdin);       // lire une chaîne avec espaces
        a.nom[strcspn(a.nom, "\n")] = '\0';  // enlève le '\n' de la chaîne du nom

        // Saisie du type d'espèce 
        do {
            printf("Espèce (1:Chien, 2:Chat, 3:Hamster, 4:Autruche) : \n");
            scanf("%d", (int*)&a.espece);
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
            printf("Description : \n");
            fgets(a.descrip, MAX, stdin);                    
            a.descrip[strcspn(a.descrip, "\n")] = '\0';      
        }

        // Ajout de l'animal au tableau refuge 
        refuge[nb_animal++] = a;

        // Affichage des caractéristique de l’animal ajouté
        afficheAnimal(a, choix);

        printf("✅ Animal ajouté avec succès.\n");

        // Sauvegarde dans le fichier 
        sauvegarder_animaux();  
    }
}

