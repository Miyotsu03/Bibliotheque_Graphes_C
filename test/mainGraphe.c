#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../lib/graphe.h"
#include "../lib/inout.h"
#include "../lib/connexe.h"
#include <time.h>

int main(int argc, char* argv[]){
    srand(time(NULL));
    /*
    graphe G1 = hypercube(3);

    afficheGraphe(G1, 1);
    printf("degré g : %d", degre(1, G1));
    creerDotGraphe(G1, "hypercube3.dot");

    graphe G2 = lireGraphe("../data/maison.txt");
    creerDotGraphe(G2, "maison.dot");
    afficheGraphe(G2, 0);

    graphe G1_comp = complement(G1);
    afficheGraphe( G1_comp, 1);

    freeGraphe(G1);
    freeGraphe(G2);
    freeGraphe(G1_comp);

    */
    
    graphe g_aleat = aleatoire(9, 1.7), G2 = lireGraphe("../data/maison.txt");
    creerDotGraphe(G2, "maison");
    dessinerGraphe(G2, "maison");

    int * maximum = malloc(sizeof(int));
    int * num_giant = malloc(sizeof(int));
    int * sommets_giant = giant(G2, maximum, num_giant);

    //(G2, maximum, sommets_comp);
    //printf("Le graphe maison a %d composantes connexes\nSa composante géante est de %d sommets\n", nb_comp, *maximum);
    printf("Sommets graphe Maison :[");
    for (int it=0; it<G2.nbs-1; it++)
        printf("%d, ", sommets_giant[it]);
    printf("%d]\n", sommets_giant[G2.nbs-1]);

    printf("La composante géante est d'ordre %d\nC'est la composante numéro %d \n", *maximum, *num_giant);

    sommets_giant = giant(g_aleat, maximum, num_giant);
    dessinerGraphe(g_aleat, "graphe_aleatoire");
    //printf("Le graphe aleatoire a %d composantes connexes\nSa composante géante est de %d sommets\n", nb_comp, *maximum);
    printf("Sommets graphe_aleatoire : [");
    for (int it=0; it<g_aleat.nbs-1; it++)
        printf("%d, ", sommets_giant[it]);
    printf("%d]\n", sommets_giant[g_aleat.nbs-1]);

    printf("La composante géante est d'ordre %d\nC'est la composante numéro %d \n", *maximum, *num_giant);

    //freeGraphe(G2);
    freeGraphe(g_aleat);
    freeGraphe(G2);
    free(maximum);
    free(num_giant);
    free(sommets_giant);
    

    return 0;
}