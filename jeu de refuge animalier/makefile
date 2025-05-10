# Nom de l'exécutable
EXEC = FonctionPrincipale

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c99

# Fichiers sources
SRC = FonctionPrincipale.c \
      AjouterAnimal.c \
      AdopterAnimal.c \
      RechercheAnimal.c \
      affiche_inventaire.c \
      variante_Dayclean.c 

# Fichiers d'en-tête (si tu veux une cible pour les vérifier)
HEADERS = FichierStructure.h FichierSource.h

# Objets générés automatiquement à partir des sources
OBJ = $(SRC:.c=.o)

# Cible par défaut
all: $(EXEC)

# Règle pour l'édition de liens
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation de chaque fichier .c en .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers compilés
clean:
	rm -f *.o $(EXEC)

# Forcer la reconstruction complète
rebuild: clean all
