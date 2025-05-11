# 🐾 Projet Refuge Animalier — Application Console en C

## 📋 Description
Ce programme en langage C permet de gérer un refuge animalier. Il offre un menu interactif en console pour réaliser plusieurs opérations : ajouter, modifier, adopter ou rechercher des animaux, calculer la quantité de nourriture nécessaire, afficher l'inventaire par espèce, et estimer la charge de nettoyage hebdomadaire.

## 🔧 Fonctionnalités principales

### ➕ Ajouter un animal
- Saisie du nom, de l'espèce, de l'année de naissance, du poids, et description facultative.
- L’animal est automatiquement attribué à un ID unique.
- Les données sont enregistrées dans un fichier `animaux.txt`.

### 🔍 Rechercher un animal
- Recherches combinables selon : le nom, l'espèce, ou le type d’âge (jeune < 2 ans / senior > 10 ans).
- Affichage détaillé des animaux correspondant aux critères.

### 🏠 Adopter un animal
- Supprime un animal de la liste en fonction de son ID.

### 📦 Afficher l'inventaire
- Affiche le nombre d’animaux par espèce dans un ordre décroissant.
- Présente un récapitulatif du nombre total d’animaux présents.

### 🧽 Calcul de la charge de nettoyage hebdomadaire
- Basé sur l’espèce de l’animal.
- Convertit la durée en heures et minutes.
- Prend aussi en compte les cages vides.

### 🍽️ Calcul de la quantité de nourriture quotidienne
- Prend en compte l'espèce et l'âge.
- Les jeunes ou légers consomment moins, les adultes consomment 10 % de leur poids pour certaines espèces.

### 📝 Modifier un animal
- Permet de modifier le nom, l’année de naissance, l’espèce, le poids ou la description d’un animal en fonction de son ID.

### 💾 Sauvegarde & chargement automatique
- Les animaux sont enregistrés dans `animaux.txt` et rechargés automatiquement au démarrage.

## 💻 Utilisation

### ✅ Compilation
```bash
make
````

### ▶️ Exécution
```bash
./maker
```

## 🗃️ Fichier `animaux.txt`
Les animaux sont sauvegardés sous la forme :
```
id;annee;poids;espece;nom;description
```

Exemple :
```
1;2021;5;1;Rex;Chien; très joueur
```

## 📌 Limites
- Maximum 50 animaux (modifiable via #define NbAnimal).
- Interface 100 % en ligne de commande.

## ✨ Améliorations possibles
- Ajouter un système de tri par âge ou nom.
- Interface graphique 

