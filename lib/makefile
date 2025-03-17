OPTIONS= -Wall -g
OBJET= graphe.o inout.o connexe.o

libgraphe.a : $(OBJET)
	ar crs libgraphe.a $(OBJET) 

graphe.o : graphe.c graphe.h
	gcc $(OPTIONS) -c $<

inout.o : inout.c inout.h graphe.h
	gcc $(OPTIONS) -c $<

connexe.o : connexe.c connexe.h graphe.h
	gcc $(OPTIONS) -c $<
	
#Ouvrir depuis le bash avec
#evince tag.pdf
tag : 
	wget -O tag.pdf https://langevin.univ-tln.fr/cours/graphe/tag.pdf
	