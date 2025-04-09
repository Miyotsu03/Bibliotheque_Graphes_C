#include "disjoint.h"
#include<stdlib.h>

disjoint * table;

void init_disjoint(int n){
    table = calloc(n, sizeof(disjoint));
    for (int x=0; x<n; x++)
        table[x] = singleton(x);
}


disjoint singleton(int n){
    disjoint res = malloc(sizeof(enrdisjoint));
	res->num = n;
	res->rep = res;
    res->rang = 1;
	return res;
}

disjoint representant(int x){
	disjoint res = table[x];
    while(res->rep != res)
		res = res->rep;
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
