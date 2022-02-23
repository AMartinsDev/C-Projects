#include <stdio.h>
#include <stdlib.h>

struct ponto
{
	int numero;
	struct ponto* ponteiro;

};

typedef struct ponto Ponto;

int main ()
{
	
	   Ponto* ponto;
	   Ponto* pontofor;
	   
	   Ponto* p1 = (Ponto*)malloc(sizeof(Ponto));
// p2  ----> p1 	   
	   p1->numero = 5;
	   p1->ponteiro = NULL;
	   // ponto aponta para o ultimo ponto da fila
	   ponto = p1;
	   
	   Ponto* p2 = (Ponto*)malloc(sizeof(Ponto));
	   
	   p2->numero = 8;
	   p2->ponteiro =ponto;
	   // ponto aponta para o ultimo ponto da fila
	   ponto = p2;
	   
	   Ponto* p3 = (Ponto*)malloc(sizeof(Ponto));
	   
	   p3->numero = 15;
	   p3->ponteiro =ponto;
	   // ponto aponta para o ultimo ponto da fila
	   ponto = p3;
	   
	   //for (valor inicial; condicaocontinuar, incremento)
	   for (pontofor=ponto; pontofor!=NULL;pontofor=pontofor->ponteiro)	
		printf("%d\n", pontofor->numero);
}

//p1  p2