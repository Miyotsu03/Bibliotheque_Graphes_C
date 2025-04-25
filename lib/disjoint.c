#include "disjoint.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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