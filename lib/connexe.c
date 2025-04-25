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

void PPRG(int sommet, graphe g, int sommets[], int *taille, int p){
    sommets[sommet] = p;
    (*taille)++;

    for (int j=0; j<g.nbs; j++)
        if (sommets[j] == 0 && g.mat[sommet][j])
            PPRG(j, g, sommets, taille, p);  
}

/*
Retourne une liste d'int : l [ i ] = numero de la composante à laquelle le sommet i apprtient*/
int * giant(graphe g, int *max, int *num){
    int res = 0;
    int taille;
    *max = 0;

    //Initialisation de la liste de visite de sommets
    int *sommets = calloc(g.nbs, sizeof(int));
    
    for (int s=0; s<g.nbs; s++)
        if (sommets[s] == 0){
            taille = 0;
            res++;
            PPRG(s, g, sommets, &taille, res);
            if (taille > *max) {
                *max = taille;
                *num = res;
            }
        }
    return sommets;
}

