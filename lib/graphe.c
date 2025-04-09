#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>

/* Initialise un graphe d'ordre n */
graphe initGraphe(int n){

    graphe res;
    res.nbs = n;
    res.mat = calloc(n,sizeof(int*));
    for(int i =0; i<res.nbs; i++)
        res.mat[i] = calloc(n, sizeof(int));

    return res;
}

void freeGraphe(graphe g){

    for(int i=0; i<g.nbs; i++)
        free(g.mat[i]);
    free(g.mat);
}

/* Genere un hypercube de dimension m */
graphe hypercube(int m){
    
	graphe R = initGraphe(1<<m);
	for (int k=0; k<R.nbs;k++)
	{	for (int l=0; l< R.nbs; l++)
		{	if ((k^l) > 0)
				R.mat[k][l] = 1;
		}
	}
	return R;
}

/* Retourne le degre d'un sommet du graphe G */
int degre(int sommet, graphe g){

    int deg=0;
    
    for(int i=0; i<g.nbs; i++){
        if ((i != sommet) && (g.mat[sommet][i]))
            deg += 1;
    }
    return deg;
}

graphe complement(graphe G){
	graphe R = initGraphe(G.nbs);
	
	for (int i=0; i<R.nbs; i++)
	{	for (int j=0; j<R.nbs; j++)
		{	if (G.mat[i][j])
				R.mat[i][j] = 0;
			else
				R.mat[i][j] = 1;
		}
	}
	return R;
}


int test(int n, float p){
	float s = (MAXRAND*p)/n;
	return (random() < s);
}


/*Genere un graphe aleatoire :
	chaque arete a une probabilite p/n d'exister*/
graphe aleatoire(int n, float p){
	graphe res = initGraphe(n);

	for (int i=0; i<n;i++){
		for (int j=0; j<n; j++){
			if (test(n,p))
				res.mat[i][j] = res.mat[j][i] = 1;
		}
	}
	return res;
}