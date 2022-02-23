#include <stdio.h>

int main()
{

    int op1, i, op2;
    float num1 = 0, num2 = 0, num3 = 0;

    printf("CALCULADORA\n\n");
    printf("Escolha a operacao:\n"); 
    printf("1 para soma\n");
    printf("2 para subrtracao\n");
    printf("3 para multiplicacao\n");
    printf("4 para divisao\n");
    scanf("%d", &op1);

    do
    {

        switch (op1)
        {
        case 1:
            num3 = num1 * num2;
            printf("Digite o valor 1: \n");
            scanf("%f", &num1);
            printf("Digite o valor 2: \n");
            scanf("%f", &num2);
            printf("O resultado eh %f\n\n", num3);
            break;
            
        case 2:
            num3 = num1 * num2;
            printf("Digite o valor 1: \n");
            scanf("%f", &num1);
            printf("Digite o valor 2: \n");
            scanf("%f", &num2);
            printf("O resultado eh %f\n\n", num3);
            break;

        case 3:
            num3 = num1 * num2;
            printf("Digite o valor 1: \n");
            scanf("%f", &num1);
            printf("Digite o valor 2: \n");
            scanf("%f", &num2);
            printf("O resultado eh %f\n\n", num3);
            break;

        case 4:
            num3 = num1 * num2;
            printf("Digite o valor 1: \n");
            scanf("%f", &num1);
            printf("Digite o valor 2: \n");
            scanf("%f", &num2);
            printf("O resultado eh %f\n\n", num3);
            break;

        default:
            printf("Opcao nao valida\n\n");
            break;
        }

        printf("Quer continuar calculando?");
        printf("1) = Sim");
        printf("2) = Nao");
        scanf("%i", &op2);

        if (op2 != 1)
        {
            break;
        }

    } while (i != 1);

    return 0;
}