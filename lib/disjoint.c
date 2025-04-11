#include "disjoint.h"
#include <stdlib.h>
#include <stdio.h>

disjoint * init_disjoint(int n){
    disjoint * res = calloc(n, sizeof(disjoint));
    for (int x=0; x<n; x++)
        res[x] = singleton(x);
    return res;
}

void free_disjoint(disjoint * ed, int taille){
    for (int x=0; x<taille; x++)
        free(ed[x]);
    free(ed);
}

graphe disjoint_to_graph(disjoint * ed, int taille){
    graphe res = initGraphe(taille);
    return res;
}


void affiche_disjoint(disjoint * ed, int taille){
    graphe tmp = disjoint_to_graph(ed, taille);
    printf("ed :\n");
    afficheGraphe(tmp, 0);
}


disjoint singleton(int n){
    disjoint res = malloc(sizeof(enrdisjoint));
	res->num = n;
	res->rep = res;
    res->rang = 1;
	return res;
}

disjoint representant(disjoint r){
	disjoint res = r;
    disjoint tmp;

    while(res != res->rep) res = res->rep;
	while (r != r->rep){
        tmp = r->rep;
        r->rep = res;
        r = tmp;
    }
	return res;
}


void reunion(disjoint p,disjoint q){	
    if (p->rang == q->rang)
        p->rang++;
    if (p->rang < q->rang)
        p->rep = q;
    else
        
    
    q->rep = p;
}
