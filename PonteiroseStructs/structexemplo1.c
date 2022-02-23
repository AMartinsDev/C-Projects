#include <stdio.h>

struct paciente
{
	int idade;
	float peso;
	float altura;
	
};

int main ()
{
	struct paciente p;
	
	printf("digite a idade");
	scanf ("%d", &p.idade);
	printf("digite o peso");
	scanf ("%f", &p.peso);
	
	printf("%d\n", p.idade);
	printf("%f\n", p.peso);
	return 0;
	
}