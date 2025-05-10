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
            (*j)++;
        } else {
            senior[*s] = &refuge[i];
            (*s)++;
        }
    }
}



    int RechercheAnimal(){
        char n[50];
        Espece e;
        int critere_nom , critere_espece, critere_age;
        int i, age_type, naissance;
        int a, b, c;
        int annee_courante = AnneeCourante();
        Animal *enfant[NbAnimal];  
        Animal *jeune[NbAnimal];
        Animal *senior[NbAnimal];
        
        
    printf("Rechercher par nom ? (1:Oui / 0:Non) : ");
    scanf("%d", &critere_nom);
    while (getchar() != '\n');
    if (critere_nom == 1) {
        printf("Entrez le nom : ");
        fgets(n, 50,stdin);
        n[strcspn(n, "\n")] = '\0';
    }

    printf("Rechercher par espèce ? (1:Oui / 0:Non) : ");
    scanf("%d", &critere_espece);
    while (getchar() != '\n');
    if (critere_espece == 1) {
        e = ChoisirEspece();
        while (getchar() != '\n');
    }

    printf("Rechercher par type d'âge ? (1:Oui / 0:Non) : ");
    scanf("%d", &critere_age);
    while (getchar() != '\n');
    if (critere_age == 1) {
        printf("1: Enfant (<2 ans), 2: Senior (>10 ans), 3: Jeune (>2 ans && <10 ans)  ");
        scanf("%d", &age_type);
        while (getchar() != '\n');
    }

    DecoupageTabAge(enfant, jeune, senior, &a, &b, &c);

    if(critere_age == 0){
        for(i = 0; i< nb_animal; i++){
            if(critere_nom == 1 && strcmp(refuge[i].nom, n) == 0){
                    if(critere_espece == 1 && refuge[i].espece == e ){
                        afficheAnimale(refuge[i]);
                        return 0;
                    }
                    else if(critere_espece == 0){
                        afficheAnimale(refuge[i]);
                        return 0;
                    }
            }
            else if(critere_nom == 0 && critere_espece == 1 ){
                if(refuge[i].espece == e){
                    afficheAnimale(refuge[i]);
                    return 0;
                }
            }
        }
        printf("Aucan animal trouvé !");
        return 1;
    }
        
    else if(critere_age == 1){
        if(age_type == 1){
            printf("l'animal est un enfant \n ");
            for(i = 0; i < a; i++){
                if(critere_nom == 1 && strcmp(enfant[i]->nom, n) == 0){
                    if(critere_espece == 1 && enfant[i]->espece == e ){
                        afficheAnimale(*enfant[i]);
                        return 0;
                    }
                    else if(critere_espece == 0){
                        afficheAnimale(*enfant[i]);
                        return 0;
                    }
                }
                else if(critere_nom == 0 && critere_espece == 1 ){
                    if(enfant[i]->espece == e){
                        afficheAnimale(*enfant[i]);
                        return 0;
                    }
                }
            }
            printf("ces informations ne correspondent à aucun animal\n");
        }
    
    else if(age_type == 2){
        printf("l'animal est un sénior \n");
        for(i = 0; i < c; i++){
            if(critere_nom == 1 && strcmp(senior[i]->nom, n) == 0){
                if(critere_espece == 1 && senior[i]->espece == e ){
                    afficheAnimale(*senior[i]);
                    return 0;
                }
                else if(critere_espece == 0){
                    afficheAnimale(*senior[i]);
                    return 0;
                }
            }
            else if(critere_nom == 0 && critere_espece == 1 ){
                if(senior[i]->espece == e){
                    afficheAnimale(*senior[i]);
                    return 0;
                }
            }
        }
        printf("ces informations ne correspondent à aucun animal\n");
    }
    
        else if(age_type == 3){
            printf("l'animal est un jeune \n");
            for(i = 0; i < b; i++){
                if(critere_nom == 1 && strcmp(jeune[i]->nom, n) == 0){
                    if(critere_espece == 1 && jeune[i]->espece == e ){
                        afficheAnimale(*jeune[i]);
                        return 0;
                    }
                    else if(critere_espece == 0){
                        afficheAnimale(*jeune[i]);
                        return 0;
                    }
                }
                else if(critere_nom == 0 && critere_espece == 1 ){
                    if(jeune[i]->espece == e){
                        afficheAnimale(*jeune[i]);
                        return 0;
                    }
                }
            }
            printf("ces informations ne correspondent à aucun animal\n");
        }   
         return 1;
    }	
}