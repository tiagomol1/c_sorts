/*
5. Construa um programa que gere um vetor 1000 números aleatórios mostre os números em tela e 
depois usando o método de ordenação quick sort ordene este vetor.
R.:
*/

#include <stdio.h>
#include <stdlib.h>

// prototipo das funções
void quicksort(int vet[], int ini, int fim);
int partition(int vet[], int ini, int fim);

int main (void){
	int vet[1000], i;
	
	// entrada de dados
	for (i=0;i<1000;i++){
		vet[i]=(int) (rand()%1000); 
	}
	printf("Desordenado:\n\n");
	for(i=0;i<1000;i++){
		printf("%i, ",vet[i]);
		if((i+1)%15==0){
			printf("\n");
		}
	}
	
	// processamento dos dados
	quicksort(vet, 0, 999);
	
	// saída de dados
	printf("\n\nOrdenado:\n\n");
	for(i=0;i<1000;i++){
		printf("%i, ",vet[i]);
		if((i+1)%15==0){
			printf("\n");
		}
	}
	
	return 0;
}

void quicksort(int vet[], int ini, int fim) {
    int meio;
	static int acessos;

    if (ini < fim) {
        meio = partition(vet, ini, fim);
        quicksort(vet, ini, meio);
        quicksort(vet, meio + 1, fim);
    }
}

int partition(int vet[], int ini, int fim) {
    int pivo, topo, i;
    pivo = vet[ini];
    topo = ini;

    for (i = ini + 1; i <= fim; i++) {
        if (vet[i] < pivo) {
            vet[topo] = vet[i];
            vet[i] = vet[topo + 1];
            topo++;
        }
    }
    if(topo == 1000){
    	
	}
    vet[topo] = pivo;
    return topo;
}
