#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void bublle(int vetor[]){

	int j;
	int i;
	int t;
	
	for (i = 0; i < TAM; i++){
		for (j = i+1; j < TAM; j++){
			
			if (vetor[i] > vetor[j]){
				
				t = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = t;
			}
		}
	}
}
void selection(int vetor[]){
	
	int i;
	int min;
	int j;
	int t;
	
	for (i = 0; i < TAM - 1; i++){
		min = i;
		for (j = i+1; j < TAM; j++){
			if (vetor[j] < vetor[min])
				min = j;
		}
		if (min != i){
			t = vetor[min];
			vetor[min] = vetor[i];
			vetor[i] = t;
		}
	}	
}
void insert (int vetor[]){
	
	int i;
	int escolhido;
	int j;
	
	for (i = 1; i < TAM; i++){
		
		escolhido = vetor[i];
		j = i - 1;
		while ((j >= 0) && (vetor[j] > escolhido)){
			
			vetor[j+1] = vetor[j];
			j--;
			
		}
		
		vetor[j+1] = escolhido;
	}
}

int main() {
	
	int i;
	int vetor[TAM];
	int j = 999999;
	
	for (i = 0; i < TAM; i++){
	
		vetor[i] = j;
		j--;
	}	
	
	bubble(vetor); //1°
	selection(vetor); //2°
	insert (vetor); //3°
	
	//for (i = 0; i < TAM; i++)
	//	printf ("%d\n", vetor[i]);
		
	return 0;
}