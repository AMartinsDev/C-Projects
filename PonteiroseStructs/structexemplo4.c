#include <stdio.h>


struct taltura
{
	float altura;
};

struct paciente
{
	int idade;
	float peso;
	struct taltura complemento;
	
};


int main ()
{
	struct paciente *ap;
	
	ap = (struct paciente*)malloc(sizeof(struct paciente));
	
	printf("digite a idade");
	scanf ("%d", &ap->idade);
	printf("digite o peso");
	scanf ("%f", &ap->peso);
	
//	p.complemento.altura = 1.83;
	
	printf("%d\n", ap->idade);
	printf("%f\n", ap->peso);
//	printf("%f\n", p.complemento.altura);
	return 0;
	
}