#include "FichierStructure.h"
#include "FichierSource.h"

Espece ChoisirEspece(){
    int a;
    printf("Espèce (1:Chien, 2:Chat, 3:Hamster, 4:Autruche) : ");
    scanf("%d", &a);
    while (getchar() != '\n');
    while(a < 1 || a > 4){
        scanf("%d", &a);
        while (getchar() != '\n');
    }
    return (Espece)a;  
}

int AnneeCourante(){
    int annee_actuel;
    time_t ts = time(NULL);    //time_t permet de déclarer une variable en seconde depuis 1970. time(NULL) c'est une fonction qui sert à obtenir le temps actuel en seconde. 
    annee_actuel = 1970 + (ts/(60*60*24*365));   // on fait la conversion de ts en année puis on ajoute 1970.
    return annee_actuel;
 } 

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

int Verification(Animal *tab[], char nom[], int critere_n, int critere_e, int critere_a, int taille, Espece espece){
    int i;
    for(i = 0; i< taille; i++){
        if(critere_n == 1 || critere_e == 1 ){
            if(strcmp(tab[i]->nom, nom) == 0 && tab[i]->espece == espece ){
                afficheAnimal(*tab[i]);
                return 0;
            }
            else if(critere_e == 0 && strcmp(tab[i]->nom, nom) == 0){
                afficheAnimal(*tab[i]);
                return 0;
            }
             else if(critere_n == 0 && tab[i]->espece == espece){
                afficheAnimal(*tab[i]);
                return 0;
            }
        }
        else if(critere_a == 1){
            afficheAnimal(*tab[i]);
            return 0;
        }
    }
    printf("Aucan animal trouvé !\n");
    return 1;
}

int Validation(int critere){
    while(critere != 0 && critere != 1){
        printf("Choix invalide !");
        scanf("%d", &critere);
        while (getchar() != '\n');
    }
    return critere;
}

int rechercher_animaux(){
    char n[MAX];
    Espece e;
    int critere_nom , critere_espece, critere_age, age_type;
    int i, a, b, c;
    Animal *enfant[NbAnimal];  
    Animal *jeune[NbAnimal];
    Animal *senior[NbAnimal];
        
    printf("Rechercher par nom ? (1:Oui / 0:Non) : ");
    scanf("%d", &critere_nom);
    while (getchar() != '\n');
    critere_nom = Validation(critere_nom);
    if (critere_nom == 1) {
        printf("Entrez le nom : ");
        fgets(n, MAX, stdin);                     // lire une chaîne avec des espaces
        n[strcspn(n, "\n")] = '\0';             // enlève du \n dans la chaîne
    }

    // Demande si l'utilisateur veut filtrer par espèce
    printf("Rechercher par espèce ? (1:Oui / 0:Non) : ");
    scanf("%d", &critere_espece);
    while (getchar() != '\n');
    critere_espece = Validation(critere_espece);
    if (critere_espece == 1) {
        e = ChoisirEspece();
    }

    // Demande si l'utilisateur veut filtrer par âge
    printf("Rechercher par type d'âge ? (1:Oui / 0:Non) : ");
    scanf("%d", &critere_age);
    while (getchar() != '\n');
    critere_age = Validation(critere_age);
    if (critere_age == 1) {
        do{
        printf("1: Enfant (<2 ans), 2: Jeune (2-10 ans), 3: Sénior (>10 ans) : ");
        scanf("%d", &age_type);
        while (getchar() != '\n');
        }while( age_type < 1 || age_type > 3);
    }

    DecoupageTabAge(enfant, jeune, senior, &a, &b, &c);

    if(critere_age == 0){
        if(critere_espece == 1 || critere_nom == 1){
            Animal *ptrRefuge[NbAnimal];
            for (int i = 0; i < nb_animal; i++) {
                ptrRefuge[i] = &refuge[i];
            }
        Verification(ptrRefuge, n, critere_nom, critere_espece, critere_age, nb_animal, e);
        }
        else{
            printf("Aucun critère de recherche sélectionné. Recherche impossible.\n");
        }
    }
        
    else if(critere_age == 1){
        if(age_type == 1){
            Verification(enfant, n, critere_nom, critere_espece, critere_age, a, e);
        }
        else if(age_type == 2){
            Verification(jeune, n, critere_nom, critere_espece, critere_age,b, e);
        }
        else if(age_type == 3){
            Verification(senior, n, critere_nom, critere_espece, critere_age,c, e);
        }
    }	
    return 1;
}
