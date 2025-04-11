#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../lib/inout.h"
#include "../lib/connexe.h"
#include "../lib/disjoint.h"

int TAILLE = 5;

int main(){

    disjoint * ed = init_disjoint(TAILLE);

    affiche_disjoint(ed, TAILLE);



    return 0;
}