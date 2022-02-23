#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11;
int aux=0,aux2=0;
int verif1=0,verif2=0;
int opc, cpf;
char conv[20];

do{

		printf("\n\n------GERADOR DE VERIFICADORES PARA CPF------\n\n");	
		printf("Digite 1 para informar o CPF.\n\n");
		printf("Digite 2 para descorir o primeiro digito verificador do CPF.\n\n");
		printf("Digite 3 para descorir o segundo digito verificador do CPF.\n\n");
		printf("Digite 4 para descorir o CPF completo.\n\n");
		printf("Digite 0 para encerrar o programa.\n\n");
		scanf("%d", &opc);

		if(opc == 1){

			printf("Informe o CPF sem os digitos verificadores:\n\n");
			scanf ("%d", &cpf);
			fflush(stdin);

			if(cpf > 999999999){
				printf("Digitos do cpf excedido, informe um cpf valido\n\n");
			}

		}

		if(opc == 2){

			d1 = cpf/100000000;
			d2 = cpf%100000000 / 10000000;
			d3 = cpf%100000000 % 10000000 / 1000000;
			d4 = cpf%100000000 % 10000000 % 1000000 / 100000;
			d5 = cpf%100000000 % 10000000 % 1000000 % 100000 / 10000;
			d6 = cpf%100000000 % 10000000 % 1000000 % 100000 % 10000 / 1000;
			d7 = cpf%100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 / 100;
			d8 = cpf%100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 / 10;
			d9 = cpf%100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 % 10 / 1;

			aux = ((d1*10) + (d2*9) + (d3*8) + (d4*7) + (d5*6) + (d6*5) + (d7*4) + (d8*3) + (d9*2));
			
			verif1 = aux/11;

			if(aux%11<2)
			verif1 = 0;
    		else
			verif1 = 11 - aux%11;

			d10 = verif1;

			printf("o primeiro digito verificador eh: %d \n", d10);
		}

		if(opc == 3){

			d1 = cpf/100000000;
			d2 = cpf%100000000 / 10000000;
			d3 = cpf%100000000 % 10000000 / 1000000;
			d4 = cpf%100000000 % 10000000 % 1000000 / 100000;
			d5 = cpf%100000000 % 10000000 % 1000000 % 100000 / 10000;
			d6 = cpf%100000000 % 10000000 % 1000000 % 100000 % 10000 / 1000;
			d7 = cpf%100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 / 100;
			d8 = cpf%100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 / 10;
			d9 = cpf%100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 % 10 / 1;

			aux2= ((d1*11) + (d2*10) + (d3*9) + (d4*8) + (d5*7) + (d6*6) + (d7*5) + (d8*4) + (d9*3) + (d10*2));

			if(aux2%11 < 2)
			verif2 = 0;
			else
			verif2 = 11 - aux2%11;

			d11=verif2;
	
			printf("O segundo digito verificador eh: %d \n", d11);
		}

		if(opc == 4){

			itoa (cpf,conv,10);
			puts(conv);

		}

		}while((opc >=1 ) && (opc <=4) && (opc != 0));
		return 0;
	}