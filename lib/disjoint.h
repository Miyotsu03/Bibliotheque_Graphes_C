#ifndef DISJOINT_H
#define DISJOINT_H


typedef struct disjoint //ensemble disjoint
{	int num, rang;
	struct disjoint* rep; //representant
}enrdisjoint, *disjoint;

void init_disjoint(int n);

disjoint singleton(int);

disjoint representant(int x);

void reunion(disjoint p,disjoint q);

#endif
