#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ){
    long long int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, dig1, dig2, cpf, a;

    printf("\nDigite o CPF: ");
    scanf("%lli",&cpf);

    d1 =  cpf/10000000000;
    d2 = (cpf/1000000000)%10;
    d3 = (cpf/100000000)%10;
    d4 = (cpf/10000000)%10;
    d5 = (cpf/1000000)%10;
    d6 = (cpf/100000)%10;
    d7 = (cpf/10000)%10;
    d8 = (cpf/1000)%10;
    d9 = (cpf/100)%10;
    d10= (cpf/10)%10;
    d11=  cpf%10;

    dig1 = ((d1*10)+(d2*9)+(d3*8)+(d4*7)+(d5*6)+(d6*5)+(d7*4)+(d8*3)+(d9*2));

    dig1%11;

    if(dig1%11<2){
        dig1 = 0;
    }
    else{
        dig1 = 11 - (dig1%11);
    }

    dig2 = ((d1*11)+(d2*10)+(d3*9)+(d4*8)+(d5*7)+(d6*6)+(d7*5)+(d8*4)+(d9*3)+(d10*2));

    dig2%11;

    if(dig2%11<2){
        dig2=0;
    }
    else{
        dig2= 11 - (dig2%11);
    }

    if((dig1 == d10) && (dig2 == d11)) {
        printf("CPF Valido\n");
    }
    else {
        printf("\nCPF INVALIDO\n\n");
    }

    printf("Aperte 0 para encerrar o programa\n");
    scanf("%d",&a);

	if( a == 0){
		printf("Programa encerrado\n");
	}

return 0;
}