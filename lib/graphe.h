#ifndef GRAPHE_H
#define GRAPHE_H
#include <math.h>
#define MAXRAND pow(2,31)-1

typedef unsigned char uchar;

typedef struct {
    int nbs;
    int ** mat;
} graphe;

typedef struct liste
{	int num_sommet;
	struct liste *suivant;
} enrliste, *liste;


graphe initGraphe(int n);
void freeGraphe(graphe g);

int degre(int sommet, graphe g);
graphe hypercube(int m);
graphe complement(graphe G);

graphe aleatoire(int n, float p);

#endif
