#include "inout.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


graphe lireGraphe(char *nom){
	FILE *source;
	source = fopen(nom,"r");
	
	if (source == NULL)
	{	perror("nom");
		exit(1);
	}
	
	graphe G;
	int n,i,j;
	
	//pour la matrice d'adjacence
	char buffer[1024];
	while (fgets(buffer,1024,source))
	{	switch (buffer[0])
		{	case 'n': sscanf(buffer,"nbs=%d",&n);
					 G = initGraphe(n);
						break;

			case '#' : break;
		}
		if (sscanf(buffer,"%d %d",&i,&j)==2)
			G.mat[i][j] = G.mat[j][i] = 1;
	}
	fclose(source);
	return G;
}

void afficheGraphe(graphe g, int opt){
 	int i,j;
	//struct liste * it;
	
	if (opt==0){
		for(i=0;i<g.nbs;i++)
		{	for (j=0;j<g.nbs;j++)
				printf("%d ",g.mat[i][j]);
			printf("\n");
		}
	}

	else{
		for(i=0;i<g.nbs;i++){
			printf("%d : ", i);
			for (j=0;j<g.nbs;j++){
				if ((i!=j) && (g.mat[i][j]))
					printf("%d ", j);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void creerDotGraphe(graphe G, char * radical){
	if (radical != NULL){
		// Allouer la memoire pour nom_fichier

		//size_t: comme unsigned int mais adapté pour representer la taille des objets en octets
		size_t radical_len = strlen(radical);
		const char *extension = ".dot";
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
		
		fprintf(fichier, "graph {\n");
		for (int i=0; i<G.nbs; i++)
			fprintf(fichier,"\t%d [color=lightgreen];\n",i);
			
		
		for (int i=0; i<G.nbs; i++)
		{	for (int j=i+1; j<G.nbs; j++)
			{	if (G.mat[i][j] == 1)
					fprintf(fichier,"\t%d -- %d;\n",i,j);
			}	
		}
		fprintf(fichier, "}");
		fclose(fichier);
		free(nom_fichier);
	}
}

void dessinerGraphe(graphe g, char* radical){
	creerDotGraphe(g, radical);

	char cmd[128];
	sprintf(cmd,"fdp -Tpng %s.dot -o %s.png", radical, radical);
	system(cmd);
}
