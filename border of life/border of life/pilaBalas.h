#include "balas.h"
#include <stdio.h>
typedef struct BALAS{
	struct BALAS *next;
	balas *bala;
}Balas;


void pushBala(balas b, Balas *p);
balas popBala(Balas *p);

void pushBala(balas b,Balas *p){
	if(p!=NULL){
	Balas temp;
	temp.bala = new balas(b);
	temp.next=p;
	p=&temp;
	}
	else{

	}
}