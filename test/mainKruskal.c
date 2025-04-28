#include "disjoint.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    graphe g = initGraphe(5);
    for (int i=0; i<g.nbs; i++)
        for (int j=i+1; j<g.nbs; j++){
            int tmp = random() % 10;
            g.mat[i][j] = tmp;
            printf("%d - %d = %d\n", i, j, tmp);
        }
    int result_size;
    
    
    // Appel de la fonction Kruskal
    arc *mst = Kruskal(g, &result_size);

    // Affichage des arêtes de l'arbre couvrant
    printf("Les arêtes de l'arbre couvrant de poids minimum sont :\n");
    for (int i = 0; i < result_size; i++) {
        printf("%d - %d : %.2f\n", mst[i].x, mst[i].y, mst[i].w);
    }

    free(mst); // Libération de la mémoire
    return 0;
}