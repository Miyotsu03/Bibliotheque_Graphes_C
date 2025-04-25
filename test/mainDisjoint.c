#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/inout.h"
#include "../lib/connexe.h"
#include "../lib/disjoint.h"

int NB_TESTS = 10000;

int main(){
    srand(time(NULL));

    int n = 12, nb_aretes, som=0;

    printf("nb_aretes tirées, nlog(n)");
    for (int x=0; x<NB_TESTS; x++){
        nb_aretes = ar_aleat_connexe(n);
        printf("(%d , %f)\n", nb_aretes, n*log(n));
        som += nb_aretes;
    }
    printf("nb_aretes tirées en moyenne : %d", som/NB_TESTS);
	
	return 0;
}