#include <stdio.h>
#include <stdlib.h>

main(){

    int num, inverso = 0, aux;

    printf( "Digite um numero:\n" );
    scanf( "%d", &num );
    
    while(num>0){

        aux = num % 10;
        inverso = inverso * 10 + aux;
        num = num/10;
    }

    printf( "O numero inverso eh = %d\n", inverso);

    getch();
}
