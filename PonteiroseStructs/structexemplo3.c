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
	struct paciente p;
	struct paciente *ap;
	
	ap = &p;
	
	printf("digite a idade");
	scanf ("%d", &p.idade);
	printf("digite o peso");
	scanf ("%f", &p.peso);
	
	p.complemento.altura = 1.83;
	
	printf("%d\n", p.idade);
	printf("%f\n", ap->peso);
	printf("%f\n", p.complemento.altura);
	return 0;
	
}