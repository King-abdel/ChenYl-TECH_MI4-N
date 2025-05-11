#include "FichierStructure.h"
#include "FichierSource.h"

Animal refuge[NbAnimal];
int nb_animal = 0;
int prochain_id = 1;

int main(){
    int a=0;
    afficherBanniere();
    charger_animaux();
    while(a != 8){
	   a= afficherMenu();
    }
	
return 0;
}
