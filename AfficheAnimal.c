


void afficheAnimale(Animal a, int choix){
	printf("-----\n");
	printf("Nom : %s\n", a.nom);
	printf("id : %d\n", a.id);
	printf("annee : %d\n", a.annee);
	printf("poids : %.2f kg\n", a.poids);
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
	}
	if(choix==1){  
        printf("description : %s\n", a.descrip);
	}
    printf("-----\n");   
    }
