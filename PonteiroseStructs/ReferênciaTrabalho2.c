#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#include "EstruturaVetores.h"

typedef struct vetores{
  int *vetor;
  int quant;
  int tam;
  int aux;
}vetorPrincipal;

No *lista = NULL;

vetorPrincipal vetores[TAM];

int todososvetores(){
  int retorno, i, k = 0;
  for(i=0; i<TAM; i++){
    if(vetores[i].quant > 1){
        k++;
    }
  }
  return k;
}

int getQuantidadeTotal(){
  int i, qtdt = 0;
  for(i=0; i<10; i++){
    qtdt = qtdt + vetores[i].quant;
  }

  return qtdt;
}

void inicializar(){
  int i;
  for(i=0; i<10; i++)
    vetores[i].aux = 0;
    vetores[i].quant = 0;
    vetores[i].tam = 0;
    vetores[i].aux = 0;
}
void dobrar(int *x){

    *x = *x * 2;

}
int criarEstruturaAuxiliar(int tamanho, int posicao){

    int retorno = 0;

    if(posicao < 1 || posicao > 10){
      // se posição é um valor válido {entre 1 e 10}
      retorno = POSICAO_INVALIDA;
    }else if(vetores[posicao].aux == 1){
      // a posicao pode já existir estrutura auxiliar
      retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }else if(tamanho < 1){
      // o tamanho nao pode ser menor que 1
      retorno = TAMANHO_INVALIDO;// o tamanho nao pode ser menor que 1
    }else{
      vetores[posicao].vetor = (int*)malloc(sizeof(int)*tamanho);
      if(!vetores[posicao].vetor){
        // o tamanho ser muito grande
        retorno = SEM_ESPACO_DE_MEMORIA;
      }
      vetores[posicao].tam = tamanho;
      vetores[posicao].quant = 0;
      vetores[posicao].aux = 1;
      // deu tudo certo, crie
      retorno = SUCESSO;
    }

    return retorno;
}
int inserirNumeroEmEstrutura(int valor, int posicao){

    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if (posicao < 1 || posicao > 10){
      retorno = POSICAO_INVALIDA;
    }else{

        //printf("%i   \n", vetorPrincipal[posicao]);
        // testar se existe a estrutura auxiliar
        if (vetores[posicao].aux == 1){
          if (vetores[posicao].quant < vetores[posicao].tam){
            vetores[posicao].vetor[vetores[posicao].quant] = valor;
            //printf("%i quant %i vetor\n", vetores[posicao].quant, vetores[posicao].vetor[vetores[posicao].quant]);
            vetores[posicao].quant++;
              //insere
              retorno = SUCESSO;
          }else{
              retorno = SEM_ESPACO;
          }
        }else{
          retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;

}
int excluirNumeroDoFinaldaEstrutura(int posicao){
  int retorno = 0;


  if(posicao < 1 || posicao > 10){
    retorno = POSICAO_INVALIDA;
  }else if(vetores[posicao].aux == 0){
    retorno = SEM_ESTRUTURA_AUXILIAR;
  }else if(vetores[posicao].quant == 0){
    retorno = ESTRUTURA_AUXILIAR_VAZIA;
  }else{
    vetores[posicao].quant--;
    retorno = SUCESSO;
  }

  return retorno;
}
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){

  int retorno = 0;
  int i, j, aux = 0;

  if(posicao < 1 || posicao > 10){
    retorno = POSICAO_INVALIDA;
  }else if(vetores[posicao].aux == 0){
    retorno = SEM_ESTRUTURA_AUXILIAR;
  }else if(vetores[posicao].quant <= 0){
    retorno = ESTRUTURA_AUXILIAR_VAZIA;
  }else{
    for(i = 0; i < vetores[posicao].quant; i++){
      if(vetores[posicao].vetor[i] == valor){
        for(j = i; j <vetores[posicao].quant; j++){
          vetores[posicao].vetor[j] = vetores[posicao].vetor[j + 1];
        }
          retorno = SUCESSO;
      }
    }
      vetores[posicao].quant--;
      for(i = 0; i<vetores[posicao].quant; i++){
        // printf("vetor ex %i\n", vetores[posicao].vetor[i]);
      }
  }


  if(retorno == NUMERO_INEXISTENTE){
    retorno = NUMERO_INEXISTENTE;
  }
  return retorno;
}

int ehPosicaoValida(int posicao){

    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0;
    int i;
    int qtd;
    int k;

    qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);
    if(posicao < 1 || posicao > 10){
      retorno = POSICAO_INVALIDA;
    }else if(vetores[posicao].aux == 0){
      retorno = SEM_ESTRUTURA_AUXILIAR;
      k = todososvetores();
      if(k == 0){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
      }
    }else{
      for(i = 0; i<qtd; i++){
        vetorAux[i] = vetores[posicao].vetor[i];
      }
      retorno = SUCESSO;
    }
  return retorno;
}
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0;
    int i, k;
    int qtd;

    qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);

    if(posicao < 1 || posicao > 10){
      retorno = POSICAO_INVALIDA;
    }else if(vetores[posicao].aux == 0){
      retorno = SEM_ESTRUTURA_AUXILIAR;
      k = todososvetores();
      if(k == 0){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
      }
    }else{
      for(i = 0; i<qtd; i++){
        vetorAux[i] = vetores[posicao].vetor[i];
      }
      retorno = OrdenacaoDeVetores(posicao, vetorAux);
    }

    return retorno;
}
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0, i, j, aux = 0, x = 0, k;
    for(i = 0; i < 10; i++){
      if(vetores[i].aux == 0){
        x++;
      }
    }
    k = todososvetores();
    if(k == 0){
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    if(x == 10){
      retorno = SEM_ESTRUTURA_AUXILIAR;
      }
    }else{
    for(i= 0; i < 10; i++){
      for(j = 0; j < vetores[i].quant; j++){
          vetorAux[aux] = vetores[i].vetor[j];
          aux++;
      }
    }
    retorno = SUCESSO;
  }

    return retorno;
}
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

  int retorno = 0, qtdt = 0, k;
  k = todososvetores();
  retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
  if(k == 0){
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }else if(retorno == SUCESSO){
    qtdt = getQuantidadeTotal();
    OrdenacaoDeTodosVetores(qtdt, vetorAux);
  }else{
    retorno = SEM_ESTRUTURA_AUXILIAR;
  }
  return retorno;
}
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){

    int retorno = 0;

    if(posicao < 1 || posicao > 10){
      retorno = POSICAO_INVALIDA;
    }else if(vetores[posicao].aux == 0){
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }else if(novoTamanho < -90){
      retorno = NOVO_TAMANHO_INVALIDO;
    }else{
      novoTamanho = vetores[posicao].tam + novoTamanho;
      vetores[posicao].vetor = (int *) realloc(vetores[posicao].vetor, novoTamanho * sizeof(int));
      vetores[posicao].tam = novoTamanho;
      if(vetores[posicao].quant > novoTamanho){
        vetores[posicao].quant = novoTamanho;
      }
      retorno = SUCESSO;
    }

    if(!vetores[posicao].vetor){
      retorno = SEM_ESPACO_DE_MEMORIA;
    }

    return retorno;

}
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
  int qtd;

  qtd = vetores[posicao].quant;

  return qtd;
}

int OrdenacaoDeVetores(int posicao, int vetorAux[]){

  int i, retorno, qtd, j, troca, menor;

  qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);

  for(i=0; i < qtd-1; i++){
     menor = i;
     for (j=i+1; j < qtd; j++){
         if (vetorAux[j] < vetorAux[menor]){
             menor = j;
         }
     }
     if (menor != i){
         troca = vetorAux[i];
         vetorAux[i] = vetorAux[menor];
         vetorAux[menor] = troca;
     }
 }

  retorno = SUCESSO;

  return retorno;
}
No *montarListaEncadeadaComCabecote(){
  int qtd, i;
  qtd = getQuantidadeTotal();
  if(qtd == 0){
    return NULL;
  }
  int vetorAux[qtd];
  getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux);
  for(i=0; i<qtd; i++){
    No *novo =(No*)malloc(sizeof(No));
    novo->conteudo = vetorAux[i];
    // printf("vetor = %i\n", novo->conteudo);
    novo->prox = lista;
    lista = novo;
  }
  return lista;
}
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]){
  int i = 0;
  inicio = montarListaEncadeadaComCabecote();
  while(inicio!=NULL){
    vetorAux[i] = inicio->conteudo;
    // printf("vetor = %i\n", inicio->conteudo);
    i++;
    inicio = inicio->prox;
  }

}
void destruirListaEncadeadaComCabecote(No *inicio){

  if(inicio != NULL){
		No *aux;
		while(inicio != NULL){
			aux = inicio;
			inicio = inicio->prox;
			free(aux);
		}
		free(inicio);
	}
}
void OrdenacaoDeTodosVetores(int qtdt, int vetorAux[]){

  int i, retorno, j, troca, menor;

  for(i=0; i < qtdt-1; i++){
     menor = i;
     for (j=i+1; j < qtdt; j++){
         if (vetorAux[j] < vetorAux[menor]){
             menor = j;
         }
     }
     if (menor != i){
         troca = vetorAux[i];
         vetorAux[i] = vetorAux[menor];
         vetorAux[menor] = troca;
   }
 }
}

void finalizar(){
  int i = 10;
  while (i > 0){
    free (vetores[i].vetor);
    i--;
  }
}