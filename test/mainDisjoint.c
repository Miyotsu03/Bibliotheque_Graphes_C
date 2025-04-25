#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/inout.h"
#include "../lib/connexe.h"
#include "../lib/disjoint.h"

int main(){
    srand(time(NULL));

    int NB_TESTS = 5000;

    dessinerPlot(NB_TESTS, "expDisjoint");
	
	return 0;
}