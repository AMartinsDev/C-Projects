#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    int i = 0, op = 0;
    float total1 = 0, total2 = 0, valor[5], aux, total3 = 0;

    printf("Digite os valores dos 15 produtos: \n");

    for (i = 0; i < 5; i++)
    {
        scanf("%f", &valor[i]);
        fflush(stdin);
    }

    printf("Qual a forma de pagamento?\n");
    printf("1) A vista\n");
    printf("2) A prazo\n");
    scanf("%i", &op);

    if(op == 1)
    {
        for (i = 0; i < 5; i++)
        {
            total1 = total1 + valor[i];
            fflush(stdin);
        }
            printf("COMPRA A VISTA\n");
            printf("O Valor total a vista eh %f\n", total1);
    }
    else if (op == 2)
    {
        for (i = 0; i < 5; i++)
        {
            total2 = total2 + valor[i];
            fflush(stdin);
        }
        aux = (total2 / 3);
        printf("COMPRA A PRAZO");
        printf("O valor total a prazo eh %f\n", total2);
        printf("O valor da primeira prestacao das compras a prazo eh %f\n", aux);
    }
    else if((op != 1) && (op != 2))
    {
        printf("Opçao invalida, reinicie o programa\n");
    }
    
    return 0;
}