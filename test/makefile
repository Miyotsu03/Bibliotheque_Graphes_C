#Compilateur et options
CC = gcc
OPTIONS = -Wall -g -I$(GRAPHE)/lib -L$(GRAPHE)/lib

# CIBLES
EXECUTABLES = mainGraphe.exe mainDisjoint.exe
LIB = libgraphe.a

#OBJETS
OBJS = mainGraphe.o mainDisjoint.o

#CIBLE par defaut
all: $(LIB) $(EXECUTABLES)

#Construire la cible (executable)
mainGraphe.exe: mainGraphe.o
	$(CC) $(OPTIONS) $^ -o $@ -lgraphe -lm

#Compiler le fichier objet mainGraphe.o
mainGraphe.o: mainGraphe.c
	$(CC) $(OPTIONS) -c $< -o $@

mainDisjoint.exe : mainDisjoint.o
	$(CC) $(OPTIONS) $^ -o $@ -lgraphe -lm

#Compiler le fichier objet mainDisjoint.o
mainDisjoint.o : mainDisjoint.c
	$(CC) $(OPTIONS) -c $< -o $@
#Construire la librairie statique
$(LIB):
	make -C ../lib

# Clean
clean:
	rm -f $(OBJS) $(EXECUTABLES)
	rm -f *.dot
	rm -f *.png

#Run l'executable
run: $(EXECUTABLES)
	./$(EXECUTABLES)

#cibles PHONY
.PHONY: all clean run