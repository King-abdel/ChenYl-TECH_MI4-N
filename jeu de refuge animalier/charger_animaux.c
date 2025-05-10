void charger_animaux() {
    FILE *f = fopen("animaux.txt", "r");  
    if (!f) return;  
 
    Animal a;
    while (fscanf(f, "%d;%d;%f;%d;%[^;];%[^\n]\n", &a.id, &a.annee, &a.poids, (int*)&a.espece, a.nom, a.descrip) == 6) {
        refuge[nb_animal++] = a;  
        if (a.id >= prochain_id) 
            prochain_id = a.id + 1;
    }
    fclose(f);  
}
