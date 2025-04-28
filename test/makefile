#Compilateur et options
CC = gcc
OPTIONS = -Wall -g -I$(GRAPHE)/lib -L$(GRAPHE)/lib

# CIBLES
EXECUTABLES = mainGraphe.exe mainDisjoint.exe mainKruskal.exe
LIB = libgraphe.a

#OBJETS
OBJS = mainGraphe.o mainDisjoint.o mainKruskal.o

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

#Compiler le fichier mainKruskal.exe
mainKruskal.exe : mainKruskal.o
	$(CC) $(OPTIONS) $^ -o $@ -lgraphe -lm

mainKruskal.o : mainKruskal.c
	$(CC) $(OPTIONS) -c $< -o $@

#Construire la librairie statique
$(LIB):
	make -C ../lib

# Clean
clean:
	rm -f $(OBJS) $(EXECUTABLES)
	rm -f *.dot
	rm -f *.png
	rm -f *.o

#Run l'executable
runGraphe: mainGraphe.exe
	./$<

runDisjoint: mainDisjoint.exe
	./$<

#cibles PHONY
.PHONY: all clean runGraphe runDisjoint