# Compilateur
CC = gcc

# compilation
CFLAGS = -Wall -Wextra -std=c99

# Fichiers sources
SRC = FonctionPrincipale.c AjouterAnimal.c AdopterAnimal.c affiche_inventaire.c charger_animaux.c Day_clean.c Day_Food.c ModifierAnimal.c RechercheAnimal.c sauvegarde.c 

# Fichiers d'en-tête
HEADERS = FichierStructure.h FichierSource.h

# Objets générés
OBJ = $(SRC:.c=.o)

# Nom de l'exécutable
EXEC = maker

# Cible par défaut
all: $(EXEC)

# Edition de liens
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation de chaque .c en .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f *.o $(EXEC)

# Suprrimer exécutable
rebuild: clean all
