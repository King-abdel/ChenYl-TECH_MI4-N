#include "FichierStructure.h"
#include "FichierSource.h"

void ajouter_animal(){ 
    if (nb_animal >= NbAnimal) {
    	printf("Capacité maximale atteinte.\n");
	}
else{	
	Animal a;
	a.id = prochain_id++;		//génèrer l'id automatiquement
		
	printf("Nom : \n");
	fgets(a.nom, MAX,stdin);                 // lire avec possibilté de mettre des espaces
	a.nom[strcspn(a.nom, "\n")] = '\0';    					 // enlever le \n de la chaîne nom 

do{
	printf("Espèce (1:Chien, 2:Chat, 3:Hamster, 4:Autruche) : \n");
	scanf("%d", &a.espece);
	while (getchar() != '\n');            			// supprimer le \n dans le tampon
} while(a.espece<1 || a.espece>4);

do{
	printf("Année de naissance : \n");
	scanf("%d", &a.annee);
	while (getchar() != '\n');
} while(a.annee<0);
	
do{
	printf("Poids (kg) : \n");
	scanf("%f", &a.poids);
	while (getchar() != '\n');
} while(a.poids<=0);   

int choix;
do{
	printf("Voulez-vous ajouter une description : 1 oui 2 non \n");
	scanf("%d", &choix);
	while (getchar() != '\n');
} while(choix!=1 && choix!=2);
	if (choix == 1){
    		printf("Description : \n");
    		fgets(a.descrip, MAX,stdin);
            	a.descrip[strcspn(a.descrip, "\n")] = '\0';
	}
refuge[nb_animal++] = a;    // incrémenter le nombre d'animal 
afficheAnimale(a, choix);

printf("✅ Animal ajouté avec succès.\n");  
sauvegarder_animaux();  // sauvegarder l'ajout
}
}


