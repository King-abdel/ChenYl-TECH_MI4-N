#include "FichierStructure.h"


Espece ChoisirEspece(){
    int a;
    printf("Choisissez l'espèce de l'animal :\n");
    printf("1 : Chien\n");
    printf("2 : Chat\n");
    printf("3 : Hamster\n");
    printf("4 : Autruche\n");
    scanf("%d", &a);
    while(a < 1 || a > 4){
        scanf("%d", &a);
    }
    switch(a){
        case 1 :
        return 'Chien';
        case 2 :
        return 'Chat';
        case 3 :
        return 'Hamster';
        case 4 :
        return 'Autruche';
    }
    return 0;
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

 int DecoupageTabAge(Animal *tab[], int a, Animal *enfant[], Animal *jeune[],Animal *senior[], int year){
    int i, age_animale, j = 0;
    age_animale = year - tab[i]->annee;
    for(i = 0; i < 50; i++){        // on doit vérifier que le tableau n'est pas null puisque c'est un pointeur. Zain dois faire ça dans sa fonction.
        if(a < 2 && age_animale < 2){
            enfant[j] = tab[i];
            j++;
        }
        else if((a >= 2 && age_animale >= 2) && (a <= 10 && age_animale <= 10)){
            jeune[j] = tab[i];
            j++;
        }
        else if(a > 10 && age_animale > 10){
            senior[j] = tab[i];
            j++;
        }
    }
    return j;
}

int RechercheAnimale(Animal *tab[], char n[], int age, char e){
    int i, b = AnneeCourante();
    int taille_decoup;
    Animal enfant[NbAnimal];  
    Animal jeune[NbAnimal];
    Animal senior[NbAnimal];

    taille_decoup = DecoupageTabAge(tab, age, enfant, jeune, senior, b);
    printf("Rentrer le nom de l'aniamle\n");
    scanf("%s", n);
    printf("quelle est l'âge de l'animale ?\n");
    scanf("%d", &age);
    while(age < 0){
        printf("l'âge doit être positif\n");
        printf("quelle est l'âge de l'animale ?\n");
        scanf("%d", &age);
    }
    e = ChoisirEspece();

    // je sais pas comment faire pour que à chaque fois que le joueur entre une information. je valide.

    if(age < 2){
        printf("l'animale est un enfant ");
        for(i = 0; i < taille_decoup; i++){
            if(strcmp(enfant[i].nom, n) == 0 && enfant[i].espece == e){      // on peut comparer les chaines de cartctére mais on peut utiliser strcmp(). Donc, c'est bon.
                    printf("l'animale existe, Voilà ses informations :\n");
                    printf("nom : %s\n", enfant[i].nom);
                    printf("espace : %s\n", enfant[i].espece);
                    printf("numéro d'identité : %d\n", enfant[i].id);
                    printf("année de naissance : %d\n", enfant[i].annee);
                    printf("poids : %f\n", enfant[i].poids);
                    printf("déscription : %s\n", enfant[i].descrip);
                    return 0;
                }
            }
        printf("ces informations ne correspondent à aucun animale\n");
    }

    else if(age > 10){
        printf("l'animale est un sénior ");
        for(i = 0; i < taille_decoup; i++){
            if(strcmp(senior[i].nom, n) == 0 && senior[i].espece == e){      // on peut comparer les chaines de cartctére mais on peut utiliser strcmp(). Donc, c'est bon.
                    printf("l'animale existe, Voilà ses différents informations :\n");
                    printf("nom : %s\n", senior[i].nom);
                    printf("espace : %s\n", senior[i].espece);
                    printf("numéro d'identité : %d\n", senior[i].id);
                    printf("année de naissance : %d\n", senior[i].annee);
                    printf("poids : %f\n", senior[i].poids);
                    printf("déscription : %s\n", senior[i].descrip);
                    return 0;
                }
            }
        printf("ces informations ne correspondent à aucun animale\n");
    }
    
    else if(age >= 2 && age <= 10){
        printf("l'animale est un jeune ");
        for(i = 0; i < taille_decoup; i++){
            if(strcmp(jeune[i].nom, n) == 0 && jeune[i].espece == e){       // on peut comparer les chaines de cartctére mais on peut utiliser strcmp(). Donc, c'est bon.
                    printf("l'animale existe, Voilà ses différents informations :\n");
                    printf("nom : %s\n", jeune[i].nom);
                    printf("espace : %s\n", jeune[i].espece);
                    printf("numéro d'identité : %d\n", jeune[i].id);
                    printf("année de naissance : %d\n", jeune[i].annee);
                    printf("poids : %f\n", jeune[i].poids);
                    printf("déscription : %s\n", jeune[i].descrip);
                    return 0;
                }
            }
        printf("ces informations ne correspondent à aucun animale\n");
    }   
     return 1;
}

