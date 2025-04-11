#ifndef DISJOINT_H
#define DISJOINT_H
#include "graphe.h"
# include "inout.h"


typedef struct disjoint //ensemble disjoint
{	int num, rang;
	struct disjoint* rep; //representant
}enrdisjoint, *disjoint;

disjoint * init_disjoint(int n);
void free_disjoint(disjoint * ed, int taille);

graphe disjoint_to_graph(disjoint * ed, int taille);

void affiche_disjoint(disjoint * ed, int taille);

disjoint singleton(int);

disjoint representant(disjoint r);

void reunion(disjoint p,disjoint q);

#endif
