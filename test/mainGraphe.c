#include <stdio.h>
#include <math.h>
#include "../lib/graphe.h"
#include "../lib/inout.h"
#include "../lib/connexe.h"

int main(int argc, char* argv[]){

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
    graphe g_aleat, g_aleat2, G2 = lireGraphe("../data/maison.txt");
    creerDotGraphe(G2, "maison");


    int nb_comp = connexe(G2);
    printf("Le graphe maison a %d composantes connexes\n", nb_comp);

    g_aleat=aleatoire(9, 1.7);
    dessinerGraphe(g_aleat, "graphe_aleatoire");

    g_aleat2=aleatoire(9, 1.7);
    dessinerGraphe(g_aleat2, "graphe_aleatoire2");

    return 0;
}