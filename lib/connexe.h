#ifndef CONNEXE_H
#define CONNEXE_H
#include "graphe.h"

//Retourne le nb de composantes connexes
int connexe(graphe g, int* max);
int giant(graphe g, int *max, int **sommets);

#endif