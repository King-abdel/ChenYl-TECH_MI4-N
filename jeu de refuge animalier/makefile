# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c99

# Fichiers sources
SRC = FonctionPrincipale.c AjouterAnimal.c AdopterAnimal.c RechercheAnimal.c affiche_inventaire.c variante_Dayclean.c

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

# Rebuild complet
rebuild: clean all
