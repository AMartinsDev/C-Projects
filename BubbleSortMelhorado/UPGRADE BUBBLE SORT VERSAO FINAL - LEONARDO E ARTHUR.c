#include <stdio.h>
#include <stdlib.h>
#define TAM 40

//Alunos: Leonardo Reis e Arthur Silva Martins
// Disciplina: Estrutura de Dados
// Professor: Marcelo
//Data : 02/12/2019 (Neste dia foi enviado o rascunho deste codigo)
//Data : 06/12/2019 as 23:45 foi enviado o codigo definitivo para o professor.
//Inicialmente, algumas funções basicas para o funcionamento do codigo sao declaradas.
//1-Pegavetor (Preenche o vetor declarado na main).
//2-medirvet (essa funcao implementa o algoritmo de bubble sort, para organizar o vetor preenchido na funcao anterior).
//3-imprimirvetor( essa funcao apenas imprimi o vetor da funcao main de forma ja organizada).


// DECLARACAO DOS PROTOTIPOS
void pegarvetor(int vet[TAM]);
void organizarvet(int vet[TAM]);
void imprimirvetororganizado(int vet[TAM]);


// PREENCHIMENTO DO VETOR DE TAMANHO DEFINIDO
void pegarvetor(int vet[TAM]){

    int i;

    printf("Informe os numeros a serem preenchidos no vetor de %d posicoes:\n", TAM);

    for(i = 0; i < TAM; i++)

    scanf("%d", &vet[i]);
    fflush(stdin);
}

// ORDENACAO COM BUBBLE SORT OTIMIZADO
void organizarvet(int vet[TAM]){

    int j, i, sinalizador;

    for(i = TAM-1 ; i >= 0 ; i--){   //optamos por fazer o percorrimento do vetor de "trás para frente", em nossa concepção, a quantidade de passos pode vir a ser diminuida.

        sinalizador = 0;          //sinalizador inicializado com 0, para caso o vetor percorrido ja esteja ordenado, o sinalizador sera alterado para "1", assim, percorrimentos desnecessarios serão barrados.

        for(j = TAM ; j >= 0 ; j--){
        
            if( vet[i] > vet[j] ){         // A troca que ocorre nessa etapa aqui, foi retirada a variavel "aux", consideramos isso como uma das melhorias do nosso codigo.

                vet[i] = vet[i] + vet [j]; 
                vet[j] = vet[i] - vet [j]; 
                vet[i] = vet[i] - vet [j]; 

                sinalizador = 1;
            }
        }

    if(sinalizador == 0)         //caso o sinalizador seja = 0, significa que o algoritmo ja esta ordenado ou ja foi ordenado, entao ele entra na condicao e para a repeticao.
    break;                      // o loop é parado, não necessita mais de ordenação.

    }
}


void imprimirvetororganizado(int vet[TAM]){  // impressao do vetor ja ordenado

    int i;

    for(i=0;i<TAM;i++)

        printf("OS VALORES SAO : %d\n",vet[i]);

}


int main(){

    int vetor[TAM];

    pegarvetor(vetor);

    organizarvet(vetor);

    imprimirvetororganizado(vetor);

    return 0;
}
