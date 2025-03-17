#include "connexe.h"
#include <stdbool.h>

#include <string.h>

/*Parcours en profondeur recursif du graphe*/
void PPR(int sommet, graphe g, bool v[]){
    v[sommet] = true;

    for (int j=0; j<g.nbs; j++)
        if (!v[j] && g.mat[sommet][j])
            PPR(j, g, v); 
}


/*
Retourne le nombre de composantes connesxes du graphe
*/
int connexe(graphe g){
    int res = 0;

    //Initialisation de la liste de visite de sommets
    bool visit[g.nbs];
    memset(visit, false, sizeof(visit)); 
    
    for (int s=0; s<g.nbs; s++)
        if (!visit[s]){
            PPR(s, g, visit);
            res += 1;
        }
    return res;
}