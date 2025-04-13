#include "FichierStructure.h"


char ChoisirEspace(){
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
int AnneeCouranteBessixtille(){
    int annee_actuel;
    time_t ts = time(NULL);   
    annee_actuel = 1970 + (ts/(60*60*24*366));  // on change le nombre de jours de 365 à 366.
    return annee_actuel;
 } 

int AnneeCourante(){
    int annee_actuel;
    time_t ts = time(NULL);    //time_t permet de déclarer une variable en seconde depuis 1970. time(NULL) c'est une fonction qui sert à obtenir le temps actuel en seconde. 
    annee_actuel = 1970 + (ts/(60*60*24*365));   // on fait la conversion de ts en année puis on ajoute 1970.
    annee_actuel = VerificationAnnee(annee_actuel);
    return annee_actuel;
 } 

 int VerificationAnnee(int a){
    if(a%400 == 0){
       a = AnneeCouranteBessixtille();
    }
    return a;
 }

 void DecoupageTabAge(Animale *tab[], int a, Animale *enfant[], Animale *jeune[],Animale *senior[]){
    // On peut faire malloc mais là on connait le nombre d'espace à alloué, ça prends plus d'espace que autre chose.
    int i, j = 0;
    for(i = 0; tab[i] !='\0'; i++){
        if(a < 2 && tab[i]->annee < 2){
            enfant[j] = tab[i];
            j++;
        }
        else if((a >= 2 && tab[i]->annee >= 2) && (a <= 10 && tab[i]->annee <= 10)){
            jeune[j] = tab[i];
            j++;
        }
        else if(a > 10 && tab[i]->annee > 10){
            senior[j] = tab[i];
            j++;
        }
    }
}

int RechercheAnimale(Animale *tab[], char n[], int age, char e){
    int i;
    Animale enfant[sizeof(tab)];  
    Animale jeune[sizeof(tab)];
    Animale senior[sizeof(tab)];

    DecoupageTabAge(tab, age, enfant, jeune, senior);
    printf("Rentrer le nom de l'aniamle\n");
    scanf("%s", n);
    printf("quelle est l'âge de l'animale\n");
    scanf("%d", &age);
    e = ChoisirEspace();

    if(age < 2){
        printf("l'animale est un enfant ");
        for(i = 0; i < sizeof(enfant); i++){
            if(enfant[i].nom == n){
                printf("le nom %s existe\n", n);
                if(enfant[i].espace == e){
                   printf("l'animale existe, Voilà ses différents informations :\n");
                   
                }
                else{
                    printf("il n'existe pas d'animale qui s'appellent %s et qui appartient à l'espace %s\n", n, e);
                }
            }
            else {
                printf("il n'y a pas de jeune avec ce nom\n")
            }
        }
  
    }
     return 0;
}

