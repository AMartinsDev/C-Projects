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
	struct paciente *ap2;

		
	ap = (struct paciente*)malloc(sizeof(struct paciente));
	
	printf("digite a idade");
	scanf ("%d", &ap->idade);
	printf("digite o peso");
	scanf ("%f", &ap->peso);
	
	ap2 = (struct paciente*)malloc(sizeof(struct paciente));
	
//	p.complemento.altura = 1.83;
	
	ap2->idade = ap->idade+2;
	ap2->peso = ap->peso+2;
	
	printf("%d\n", ap->idade);
	printf("%f\n", ap->peso);
	
	printf("%d\n", ap2->idade);
	printf("%f\n", ap2->peso);
//	printf("%f\n", p.complemento.altura);
	return 0;
	
}