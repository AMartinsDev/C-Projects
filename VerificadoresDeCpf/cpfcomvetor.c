#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ){
    int cpf[10], i, aux1, aux2, a, b;

    b = 1;

    for(i = 0; i <= 10; i++ ){
        printf("\nDigite o digito %d do CPF:\n\n", b);
        b++;
        scanf("%i",&cpf[i]);
        fflush(stdin);
    }
    
    aux1 = ((cpf[0]*10)+(cpf[1]*9)+(cpf[2]*8)+(cpf[3]*7)+(cpf[4]*6)+(cpf[5]*5)+(cpf[6]*4)+(cpf[7]*3)+(cpf[8]*2));

    aux1%11;

    if(aux1%11<2){
        aux1 = 0;
    }
    else{
        aux1 = 11 - (aux1%11);
    }

    aux2 = ((cpf[0]*11)+(cpf[1]*10)+(cpf[2]*9)+(cpf[3]*8)+(cpf[4]*7)+(cpf[5]*6)+(cpf[6]*5)+(cpf[7]*4)+(cpf[8]*3)+(cpf[9]*2));

    aux2%11;

    if(aux2%11<2){
        aux2=0;
    }
    else{
        aux2= 11 - (aux2%11);
    }

    if((aux1 == cpf[9]) && (aux2 == cpf[10])) {
        printf("CPF Valido\n\n");
    }
    else {
        printf("\nCPF INVALIDO\n\n");
    }

    printf("Aperte 0 para encerrar o programa\n\n");
    scanf("%d",&a);

	if( a == 0){
		printf("Programa encerrado\n");
	}

return 0;
}