#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
int fatorial(int fat, int num, int aux)
{
    int fat, num, aux;

    printf("Digite o numero que deseja fazer o fatorial:");
    scanf("%d", &num);

    fat = num;

    while(num>1){

        aux = num - 1;
        fat = fat * aux;
        num = num - 1;

    }

    return fat;
}  