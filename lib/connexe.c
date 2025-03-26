#include "connexe.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*Parcours en profondeur recursif du graphe*/
void PPR(int sommet, graphe g, bool v[], int * taille){
    v[sommet] = true;
    *taille = *taille+1;

    for (int j=0; j<g.nbs; j++)
        if (!v[j] && g.mat[sommet][j])
            PPR(j, g, v, taille); 
}


/*
Retourne le nombre de composantes connexes du graphe
*/
int connexe(graphe g, int *max){
    int res = 0;
    int taille;
    *max = 0;

    //Initialisation de la liste de visite de sommets
    bool *visit = malloc(g.nbs * sizeof(bool));
    memset(visit, false, g.nbs*sizeof(bool)); 
    
    for (int s=0; s<g.nbs; s++)
        if (!visit[s]){
            taille = 0;
            PPR(s, g, visit, &taille);
            res += 1;
            if (taille > *max) *max = taille;
        }
    free(visit);
    return res;
}

void PPRG(int sommet, graphe g, int **v, int * taille){
    v[sommet] += 1;
    *taille = *taille+1;

    for (int j=0; j<g.nbs; j++)
        if (v[sommet] == 0 && g.mat[sommet][j])
            PPRG(j, g, v, taille);  
}

int giant(graphe g, int *max, int ** visit){
    int res = 0;
    int taille;
    *max = 0;

    //Initialisation de la liste de visite de sommets
    *visit = realloc(*visit, g.nbs * sizeof(int));
    memset(*visit, 0, g.nbs * sizeof(int));

    
    for (int s=0; s<g.nbs; s++){
        if ((*visit)[s] > 0){
            taille = 0;
            PPRG(s, g, visit, &taille);
            res += 1;
            if (taille > *max) *max = taille;
        }
    }
    return res;
}

