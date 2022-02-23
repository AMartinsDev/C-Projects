#include <stdio.h>
#include <conio.h>

int main()
{
 
  int numero = 10;
  
  //declaração do ponteiro
  int *ponteiro;
  
  //atribuindo o endereço da variável valor ao ponteiro
  ponteiro = &numero;
  
  //Explicação	
  printf("Valores passados para o ponteiro, a prova de que nao existe uma passagem por referencia, tendo em vista que o conteudo da variavel ponteiro nao muda, mas faz uma copia do endereco da variavel numero\n\n");
  printf ("Conteudo da variavel numero: %d\n", numero);
  printf ("Endereço da variavel numero: %x \n", &numero);
  printf ("Conteudo da variavel ponteiro : %x", ponteiro);
  

  return(0);
}