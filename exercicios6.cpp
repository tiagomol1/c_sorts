/*
6. Elabore um programa que gere uma combinação de duas letras em um vetor de 100 posições, 
usando o método de ordenação quick sort ordene este vetor de letras e mostre na tela.
R.:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// dado estrutura
typedef struct letras{
	char letras[3];
}Letras;

// prototipo de função
void quicksort(Letras vet[], int ini, int fim);
int partition(Letras vet[], int ini, int fim);

int main (void){
	// variáveis
	Letras vet[100];
	int i;
	
	// entrada de dados
	for(i=0;i<100;i++){
		vet[i].letras[0]=(char) (65 + (rand() % 26));
		vet[i].letras[1]=(char) (65 + (rand() % 26));
		vet[i].letras[2]='\0';
	}
	printf("Desordenado: \n\n");
	for(i=0;i<100;i++){
		printf("%s, ",vet[i].letras);
		if(i+1%10==0){
			printf("\n");
		}
	}
	
	// processamento / saída de dados
	quicksort(vet,0,99);
	printf("\n\nOrdenado: \n\n");
	for(i=0;i<100;i++){
		printf("%s, ",vet[i].letras);
		if(i+1%10==0){
			printf("\n");
		}
	}
	return 0;
}


void quicksort(Letras vet[], int ini, int fim) {
    int meio;

    if (ini < fim) {
        meio = partition(vet, ini, fim);
        quicksort(vet, ini, meio);
        quicksort(vet, meio + 1, fim);
    }
}

int partition(Letras vet[], int ini, int fim) {
    int topo, i;
    Letras pivo;
    strcpy(pivo.letras, vet[ini].letras);
    topo = ini;

    for (i = ini + 1; i <= fim; i++) {
        if ( strcmp(vet[i].letras,pivo.letras) < 0 ) {
            strcpy(vet[topo].letras, vet[i].letras);
            strcpy(vet[i].letras, vet[topo + 1].letras);
            topo++;
        }
    }
    strcpy(vet[topo].letras, pivo.letras);
    return topo;
}
