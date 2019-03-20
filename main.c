#include "Graphe.h"
#include "Proprietes.h"
#include "Export.h"

#include <string.h>

int main ( int argc , char *argv[] )
{
	struct timeval trecv;
	
	gettimeofday(&trecv, NULL);
	srandom(trecv.tv_usec);
	
	int degre[N];
	
	Graphe *g = NULL;
	g = init_Graphe();

	if(strcmp(argv[1], "ErdosRenyi") == 0) {
		gen_modele_un(g);
	}
	else if(strcmp(argv[1], "BenderCanfield") == 0) {
		gen_modele_deux(g, degre);
	}
	else {
		gen_modele_trois(g);
	}
	
	char nom_degre[256];
	char nom_graph[256];
	strcpy(nom_degre, "degre");
	strcpy(nom_graph, "graph");
	
	strcat(nom_degre, argv[1]);
	strcat(nom_graph, argv[1]);
	
	gnu(g->degres, g->degreMax, nom_degre);
	dessine_graph(g, nom_graph);
	
	suppression_graphe(g);
	
    return 0;
} 
