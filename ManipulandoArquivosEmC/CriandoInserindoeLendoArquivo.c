#include <stdio.h>
#include <conio.h>
int main()
{
  FILE *arq;
  int i;
  int result;
  char Linha[100];
 // clrscr();
  arq = fopen("c:/2020/ads/inf006/ArqGrav2.txt", "wt");  // Cria um arquivo texto para gravação
  if (arq == NULL) // Se nào conseguiu criar
  {
     printf("Problemas na CRIACAO do arquivo\n");
     return;
  }
  for (i = 0; i<10;i++)
  {
// A funcao 'fprintf' devolve o número de bytes gravados 
// ou EOF se houve erro na gravação
      result = fprintf(arq,"Linha %d\n",i);  					  
      if (result == EOF)		    
	  printf("Erro na Gravacao\n");
  }
  for (i = 0; i<10;i++)
  {
	result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (result)  // Se foi possível ler
	  printf("Linha %d : %s\n",i,Linha);
  }
  fclose(arq);
  return 1;
}