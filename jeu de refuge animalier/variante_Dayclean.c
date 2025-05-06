#include "FichierStructure.h"

int calculer_charge_nettoyage_hebdomadaire() {
    int total_minutes = 0;

    for (int i = 0; i < nb_animal; i++) {
        switch (refuge[i].espece) {
            case hamsters:
                 total_minutes += (10 * 7) + 20; // 10 min/jour + 20 min/semaine
                 break;
            case chats:
                total_minutes += (10 * 7) + 20; // 10 min/jour + 20 min/semaine
                break;
            case autruche:
                total_minutes += (20 * 7) + 45; // 20 min/jour + 45 min/semaine
                break;
            case chien:
                total_minutes += (5 * 7) + 20;  // 5 min/jour + 20 min/semaine
                break;
            default:
                break;
        }
    }
 int nb_vides = NbAnimal - nb_animal;
    total_minutes += nb_vides * 14;
       return total_minutes;
}
