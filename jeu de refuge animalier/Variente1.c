#include <stdio.h>
#include <string.h>

typedef struct {
    char espece[20];
} Animal;

int main() {
    Animal chenil[6]; // on réserve de la place pour 6 animaux

  
    strcpy(chenil[0].espece, "hamster");
    strcpy(chenil[1].espece, "chat");
    strcpy(chenil[2].espece, "chien");
    strcpy(chenil[3].espece, "autruche");
    strcpy(chenil[4].espece, "chien");
    strcpy(chenil[5].espece, "vide");

    int total_minutes = 0;
    int nb_animaux = 6;

    for (int i = 0; i < nb_animaux; i++) {
        if (strcmp(chenil[i].espece, "hamster") == 0 || strcmp(chenil[i].espece, "chat") == 0) {
            total_minutes += (10 * 7) + 20;
        } else if (strcmp(chenil[i].espece, "autruche") == 0) {
            total_minutes += (20 * 7) + 45;
        } else if (strcmp(chenil[i].espece, "chien") == 0) {
            total_minutes += (5 * 7) + 20;
        } else {
            total_minutes += (2 * 7); // cage vide
        }
    }

    printf("Temps total de nettoyage hebdomadaire : %d minutes\n", total_minutes);

    return 0;
}