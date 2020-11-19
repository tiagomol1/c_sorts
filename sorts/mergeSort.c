/*
PROCESSO AVALIATIVO N2 – ESTRUTURA DE DADOS

INTEGRANTES EQUIPE:
	- TIAGO MURILO OCHOA DA lUZ
	- RODRIGO CONINK
	- MAURICIO NUNES
	- LUCAS PINHO

CONSEGUIU CHEGAR NO RESULTADO?
R: SIM

SE NÃO, POR QUE NÃO CONSEGUIU CHEGAR NO RESULTADO?
R.:
*/

#include <stdio.h> 
#include <stdlib.h> 

#define TAMANHO 10000

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void geraNumero(int *vet, int op);
int comp = 0;
int troc = 0;

int main() { 
	int arr[TAMANHO]; 
    geraNumero(arr, 3);
    
	float tempo_inicial = clock();
	mergeSort(arr, 0, TAMANHO - 1); 
    float tempo_final = clock() - tempo_inicial;

    printf("Tempo de execucao do algoritmo: %.3f",tempo_final/1000);
	printf("\nQuantidade de Comparacoes: %i\n", comp);
	printf("Quantidade de Trocas: %i", troc);
	return 0; 
} 

// Função geração de números
void geraNumero(int *arr, int op) {
    int i, j;

    switch (op) {
        case 1: // Ordenados
            for (i = 0; i < TAMANHO; i++) {
                arr[i] = i + 1;
            }
            break;
        case 2: //Invertidos
            for (i = 0; i < TAMANHO; i++) {
               arr[i] = TAMANHO-i;
            }
            break;
        case 3: // Aleatórios
            for (i = 0; i < TAMANHO; i++) {
                arr[i] = (int) (rand() % TAMANHO);
            }
            break;
    }
}


void merge(int arr[], int l, int m, int r) { 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++){
		L[i] = arr[l + i]; 
	}
	for (j = 0; j < n2; j++){
		R[j] = arr[m + 1 + j]; 
	} 

	i = 0; 
	j = 0; 
	k = l;
	while (i < n1 && j < n2) { 
		troc++;
		if (L[i] <= R[j]) { 
			comp++;
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			comp++;
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) { 
		troc++;
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) { 
		troc++;
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(int arr[], int l, int r) { 
	if (l < r) { 
		int m = l + (r - l) / 2; 
		mergeSort(arr, l, m); 
		mergeSort(arr, m + 1, r); 
		merge(arr, l, m, r); 
	} 
} 


