#include "FichierStructure.h"
#include "FichierSource.h"

Espece ChoisirEspece(){
    int a;
    printf("Choisissez l'espèce de l'animal :\n");
    printf("1 : Chien\n");
    printf("2 : Chat\n");
    printf("3 : Hamster\n");
    printf("4 : Autruche\n");
    printf("choix : ");
    scanf("%d", &a);
    while(a < 1 || a > 4){
        scanf("%d", &a);
    }
    return (Espece)a;   //switch case ne marche pas avec moi.
}
/*
int AnneeCouranteBessixtille(){
    int annee_actuel;
    time_t ts = time(NULL);   
    annee_actuel = 1970 + (ts/(60*60*24*366));  // on change le nombre de jours de 365 à 366.
    return annee_actuel;
 }
*/
int AnneeCourante(){
    int annee_actuel;
    time_t ts = time(NULL);    //time_t permet de déclarer une variable en seconde depuis 1970. time(NULL) c'est une fonction qui sert à obtenir le temps actuel en seconde. 
    annee_actuel = 1970 + (ts/(60*60*24*365));   // on fait la conversion de ts en année puis on ajoute 1970.
    // annee_actuel = VerificationAnnee(annee_actuel);
    return annee_actuel;
 } 
/*
 int VerificationAnnee(int a){
    if(a%400 == 0){
       a = AnneeCouranteBessixtille();
    }
    return a;
 }
*/

void DecoupageTabAge(Animal *enfant[], Animal *jeune[], Animal *senior[], int *e, int *j, int *s) {
    int i;
    *e = *j = *s = 0;  
    int annee_courante = AnneeCourante();

    for (i = 0; i < nb_animal; i++) {  
        int age = annee_courante - refuge[i].annee;

        if (age < 2) {
            enfant[*e] = &refuge[i];
            (*e)++;
        } else if (age <= 10) {
            jeune[*j] = &refuge[i];
            (*j++);
        } else {
            senior[*s] = &refuge[i];
            (*s)++;
        }
    }
}



    int RechercheAnimal(){
        char n[50];
        Espece e;
        int i, age, naissance;
        int a, b, c;
        int annee_courante = AnneeCourante();
        Animal *enfant[NbAnimal];  
        Animal *jeune[NbAnimal];
        Animal *senior[NbAnimal];
        
        printf("Rentrer le nom de l'aniaml ?\n");
        scanf("%s", n);
        do {
            printf("Quelle est l'année de naissance de l'animal ? ");
            scanf("%d", &naissance);
            if (naissance < 1900 || naissance > annee_courante) {
                printf("Année invalide ! Réessayez.\n");
            }
        } while (naissance < 1900 || naissance > annee_courante);
    
        age = annee_courante - naissance;
        DecoupageTabAge(enfant, jeune, senior, &a, &b, &c);
        e = ChoisirEspece();
    
        // je sais pas comment faire pour que à chaque fois que le joueur entre une information. je valide.
    
        if(age < 2){
            printf("l'animal est un enfant \n ");
            for(i = 0; i < a; i++){
                if(strcmp(enfant[i]->nom, n) == 0 && enfant[i]->espece == e){      // on peut comparer les chaines de cartctére mais on peut utiliser strcmp(). Donc, c'est bon.
                        printf("l'animal existe, Voilà ses informations :\n");
                        afficheAnimale(*enfant[i]);
                        return 0;
                    }
                }
            printf("ces informations ne correspondent à aucun animale\n");
        }
    
        else if(age > 10){
            printf("l'animal est un sénior \n");
            for(i = 0; i < c; i++){
                if(strcmp(senior[i]->nom, n) == 0 && senior[i]->espece == e){      // on peut comparer les chaines de cartctére mais on peut utiliser strcmp(). Donc, c'est bon.
                        printf("l'animal existe, Voilà ses différents informations :\n");
                        afficheAnimale(*senior[i]);
                        return 0;
                    }
                }
            printf("ces informations ne correspondent à aucun animal\n");
        }
        
        else if(age >= 2 && age <= 10){
            printf("l'animal est un jeune \n");
            for(i = 0; i < b; i++){
                if(strcmp(jeune[i]->nom, n) == 0 && jeune[i]->espece == e){       // on peut comparer les chaines de cartctére mais on peut utiliser strcmp(). Donc, c'est bon.
                        printf("l'animal existe, Voilà ses différents informations :\n");
                        afficheAnimale(*jeune[i]);
                        return 0;
                    }
                }
            printf("ces informations ne correspondent à aucun animal\n");
        }   
         return 1;
    }	