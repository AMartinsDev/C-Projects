#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int info;
	struct lista* prox;
};

typedef struct lista Lista;

Lista* criar_lista()
{
	return NULL;
}

Lista* inserir_lista(Lista* l, int i)
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info= i;
	novo->prox= l;
	return novo;
}

void consultar_lista(Lista* cabeca)
{
	Lista *referencia;
	
	for (referencia= cabeca; referencia!= NULL ; referencia = referencia->prox )
		printf("%d\n", referencia->info);
}

