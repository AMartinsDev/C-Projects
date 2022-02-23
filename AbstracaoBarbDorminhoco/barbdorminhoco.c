#include <stdio.h>
#include <stdlib.h>

int semaforo (int cadeiras);
int semaforo1(int cadeiraBarbeiro);
void barbeiroCochila();
void aguardar();
void corta();
void vaiEmbora();
void chegaCliente();

int main(){
    
    int cadeiras = 5;
    int cadeiraBarbeiro = 1;
    chegaCliente();
    if(cadeiras >= 1 && cadeiras <= 5){
    cadeiras --;  //entra na fila de espera
    }


    if((semaforo1(cadeiraBarbeiro) == 1)){ //verifica se a cadeira do barbeiro está disponível 
        corta();                           // usando o semaforo
        cadeiraBarbeiro --; //ocupa cadeira do barbeiro o cliente
        cadeiras++; //desocupa uma cadeira da fila de espera
        printf("\nCliente está cortando\n");
        return 0;

    }
    else if((semaforo(cadeiras) == 0) && (semaforo1(cadeiraBarbeiro) == 0)){ //se não tiver vagas nem na cadeira do barbeiro
        vaiEmbora();                                        // nem na fila de espera
        printf("\nCliente foi embora\n");            // o cliente vai embora;
        return 0;
    }


    if((semaforo(cadeiras) >=1 && (semaforo(cadeiras) <= 5) && (semaforo1(cadeiraBarbeiro) == 0))){ //se a cadeira do barbeiro estiver ocupada
        void aguardar();                                                     //mas a fila de espera não, o cliente aguarda e
        cadeiras--;     // diminui uma vaga da fila de espera
        printf("\nCliente está aguardando\n");
        return 0;
    }
    else if(semaforo(cadeiras) == 5 && semaforo1(cadeiraBarbeiro) == 1){ // se estiver tudo vago, o barbeiro cochila;
        void barbeiroCochila();
        printf("\nBarbeiro está dormindo\n");
        return 0; 
    }
}

    
    
