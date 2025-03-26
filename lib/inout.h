#ifndef INOUT_H
#define INOUT_H
#include "graphe.h"


graphe lireGraphe(char *);
void afficheGraphe(graphe g, int opt);
void creerDotGraphe(graphe G, char * radical);
void dessinerGraphe(graphe g, char * radical);

#endif