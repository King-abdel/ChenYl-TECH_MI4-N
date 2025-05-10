#include "FichierStructure.h"

// Fonction qui calcule la charge de nettoyage hebdomadaire totale du refuge

// Le calcul dépend du type d’animal et inclut aussi les cages vides
int calculer_charge_nettoyage_hebdomadaire() {
    int total_minutes = 0; // Initialisation du temps total en minutes

    // Parcours de tous les animaux actuellement dans le refuge
    for (int i = 0; i < nb_animal; i++) {
        switch (refuge[i].espece) {
            // Pour chaque espèce, on ajoute le temps de nettoyage correspondant

            case hamsters:
                // 10 minutes par jour * 7 jours + 20 minutes de nettoyage hebdo
                total_minutes += (10 * 7) + 20;
                break;

            case chats:
                // 10 minutes par jour * 7 jours + 20 minutes de nettoyage hebdo
                total_minutes += (10 * 7) + 20;
                break;

            case autruche:
                // 20 minutes par jour * 7 jours + 45 minutes de nettoyage hebdo
                total_minutes += (20 * 7) + 45;
                break;

            case chien:
                // 5 minutes par jour * 7 jours + 20 minutes de nettoyage hebdo
                total_minutes += (5 * 7) + 20;
                break;

            default:
                //  En Cas de sécurité 
                break;
        }
    }

    // Calcul du nombre de cages vides (sur les 50 places disponibles)
    int nb_vides = NbAnimal - nb_animal;

    // On ajoute 2 minutes par jour de nettoyage pour chaque cage vide, pendant 7 jours
    // Donc 2 min/jour * 7 jours = 14 minutes par cage vide sur la semaine
    total_minutes += nb_vides * 14;

    // Retourne le temps total estimé de nettoyage 
    return total_minutes;
}
