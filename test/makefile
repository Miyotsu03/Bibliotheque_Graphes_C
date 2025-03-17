#Compilateur et options
CC = gcc
OPTIONS = -Wall -g -I$(GRAPHE)/lib -L$(GRAPHE)/lib

# CIBLES
CIBLE = mainGraphe.exe
LIB = libgraphe.a

#OBJETS
OBJS = mainGraphe.o

#CIBLE par defaut
all: $(LIB) $(CIBLE)

#Construire la cible (executable)
$(CIBLE): $(OBJS)
	$(CC) $(OPTIONS) $^ -o $@ -lgraphe -lm

#Compiler le fichier objet mainGraphe.o
mainGraphe.o: mainGraphe.c
	$(CC) $(OPTIONS) -c $< -o $@

#Construire la librairie statique
$(LIB):
	make -C ../lib

# Clean
clean:
	rm -f $(OBJS) $(CIBLE)
	rm -f *.dot
	rm -f *.png

#Run l'executable
run: $(CIBLE)
	./$(CIBLE)

#cibles PHONY
.PHONY: all clean run