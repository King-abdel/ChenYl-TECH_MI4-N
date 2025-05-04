#include "FichierStructure.h"

void ajouter_animal(){ 
    if (nb_animal >= NbAnimal) {
    	printf("Capacité maximale atteinte.\n");
    
	}
	else{	
	Animal a;
	a.id = prochain_id++;
	
	printf("Nom : ");
	scanf("%s", a.nom);
	
	do{
	printf("Espèce (1:Chien, 2:Chat, 3:Hamster, 4:Autruche) : ");
	scanf("%d", &a.espece);
	}while(a.espece<1 || a.espece>4);

	do{
	printf("Année de naissance : ");
	scanf("%d", &a.annee);
	}while(a.annee<0);
	
	do{
	printf("Poids (kg) : ");
	scanf("%f", &a.poids);
	}while(a.poids<0);   

	int choix;
	do{
	printf("Voulez-vous ajouter une description : 1 oui 2 non \n");
	scanf("%d", &choix);
	}while(choix<1 || choix>2);
	if(choix == 1){
		printf("Description : ");
		scanf("%s", a.descrip);
	}

	/*printf("Nom : %s\n", a.nom);
	printf("id : %d\n", a.id);
	printf("annee : %d\n", a.annee);
	printf("poids : %f\n", a.poids);
	int b = a.espece;
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
	} */
	
	refuge[nb_animal++] = a;
    }
}
