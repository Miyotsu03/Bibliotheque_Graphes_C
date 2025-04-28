#include "disjoint.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//var globale pour la fonction recup_aretes : taille du tableau de retour
int cpt;

/*
Génère un ensemble disjoint de taille n
*/
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

/*
Retour : le représentant de r
*/
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

/*
Tire des arêtes aléatoires dans l'ensemble disjoint.
Retour : Nombre d'arête tirées pour rendre l'ed connexe
*/
int ar_aleat_connexe(int n){
	int res = 0, p = n;//p = # de comp connexes
	disjoint * ed = init_disjoint(n);
    
    int i,j;
    while (p>1){
        i = random() % n;
        j = random() % n;
        disjoint ri = representant(ed[i]);//representant de i
        disjoint rj = representant(ed[j]);//representant de j

        if (ri != rj){
            reunion(ri, rj);
            p = p-1;
        }
        res += 1;
    }
    free_disjoint(ed, n);
    return res;
}


/*
Expérience : tirer des aretes aleatoirement dans un ensemble(graphe) disjoint jusqu'à le rendre connexe
Retour : fichier gnuplot representant l'expérience pour nMax graphes (n en fonction du # d'arêtes)*/
void creerPlotExp(int nMax, char *radical){
    if (radical != NULL){
		// Allouer la memoire pour nom_fichier

		//size_t: comme unsigned int mais adapté pour representer la taille des objets en octets
		size_t radical_len = strlen(radical);
		const char *extension = ".txt";
		size_t extension_len = strlen(extension);
	
		
	
		// Allouer assez de memoire pour le nom du fichier
		char *nom_fichier = malloc(radical_len + extension_len + 1); // +1 for the null terminator
	
		if (nom_fichier == NULL) {
			perror("Failed to allocate memory");
			return;
		}
	
	
		// Creer le nom du fichier
		strcpy(nom_fichier, radical);
		strcat(nom_fichier, extension);

		FILE* fichier = fopen(nom_fichier,"w");
		if (fichier == NULL) {
			perror("Error opening file");
			free(nom_fichier); // Liberer la memoire allouee
			return;
	
		}
		
		fprintf(fichier, "# x y log(x)\n");

        for (int it=0; it<nMax; it++){
            int res = ar_aleat_connexe(it);
            fprintf(fichier, "%d %d %f\n", it, res, it*log(it));
            printf("(%d, %d)\n", it, res);
        }
        
        fprintf(fichier, "}");
        fclose(fichier);
        free(nom_fichier);
    }

}

void dessinerPlot(int nMax, char* radical){
	creerPlotExp(nMax, radical);

	char cmd[128];
	sprintf(cmd,"gnuplot %s.gp", radical);
    system(cmd);
}

/*
Retourne -1 si p1 < p2, 0 ou plus sinon
*/
static int cmp_arc(const void *p1, const void *p2){
	arc *arc1 = (arc *)p1;
    arc *arc2 = (arc *)p2;
    if (arc1->w < arc2->w) return -1;
    if (arc1->w > arc2->w) return 1;
    return 0;
}

/*retourne un tableau des arêtes de G*/
arc *recup_arc(graphe g){
    int taille_tab = 10; // Taille initiale
    cpt = 0;
    arc *tab_aretes = malloc(taille_tab * sizeof(arc)); // Utilisez malloc pour une taille initiale

    if (tab_aretes == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        return NULL; // Gestion de l'erreur
    }

    for (int i = 0; i < g.nbs; i++) {
        for (int j = i + 1; j < g.nbs; j++) {
            if (g.mat[i][j]) {
                if (cpt >= taille_tab) { // Vérifiez si vous devez redimensionner
                    taille_tab += 2; // Doublez la taille
                    arc *new_tab = realloc(tab_aretes, taille_tab * sizeof(arc));
                    if (new_tab == NULL) {
                        free(tab_aretes); // Libérez l'ancienne mémoire
                        fprintf(stderr, "Erreur de réallocation de mémoire.\n");
                        return NULL; // Gestion de l'erreur
                    }
                    tab_aretes = new_tab; // Mettez à jour le pointeur
                }
                arc tmp;
                tmp.x = i;
                tmp.y = j;
                tmp.w = g.mat[i][j];
                tab_aretes[cpt++] = tmp;
            }
        }
    }
    // Redimensionner le tableau à la taille exacte
    arc *final_tab = realloc(tab_aretes, cpt * sizeof(arc));
    if (final_tab != NULL) {
        tab_aretes = final_tab; // Mettez à jour le pointeur si la réallocation a réussi
    }

    return tab_aretes; // Retournez le tableau d'arêtes
}

arc* Kruskal(graphe g, int *result_size) {
    // Initialisation des ensembles disjoints
    disjoint *ed = init_disjoint(g.nbs);
    arc *res = malloc((g.nbs - 1) * sizeof(arc)); // Pour stocker l'arbre couvrant
    int e = 0; // Compteur pour les arêtes de l'arbre couvrant

    //Création du tableau d'arêtes et Màj de cpt (taille )
    arc *arcs = recup_arc(g);
    // Tri des arêtes par poids
    qsort(arcs, cpt, sizeof(arc), cmp_arc);

    for (int i = 0; i < cpt; i++) {
        arc current_arc = arcs[i];
        disjoint rep_x = representant(ed[current_arc.x]);
        disjoint rep_y = representant(ed[current_arc.y]);

        // Si les représentants sont différents, on ajoute l'arête à l'arbre couvrant
        if (rep_x != rep_y) {
            res[e++] = current_arc; // Ajouter l'arête à l'arbre couvrant
            reunion(rep_x, rep_y); // Union des deux ensembles
        }
    }
    *result_size = e; // Taille de l'arbre couvrant
    free_disjoint(ed, g.nbs); // Libération de la mémoire
    return res; // Retourne l'arbre couvrant
}