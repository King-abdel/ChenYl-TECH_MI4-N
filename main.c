#include "FichierStructure.h"
#include "FichierSource.h"

int main(){
    int a=0;
    afficherBanniere();
    charger_animaux();
    while(a != 8){
	   a= afficherMenu();
    }
	
return 0;
}
