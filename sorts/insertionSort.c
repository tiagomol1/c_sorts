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
#include <time.h>
 
#define TAMANHO 10000
 
void insertion_sort(int *a);
void geraNumero(int *vet, int op);
 
int main(){
	int i, vet[TAMANHO];
	
    geraNumero(vet, 2);
	insertion_sort(vet);
	
	system("pause");
	return 0;
}
 

// Função geração de números
void geraNumero(int *vet, int op) {
    int i, j;

    switch (op) {
        case 1: // Ordenados
            for (i = 0; i < TAMANHO; i++) {
                vet[i] = i + 1;
            }
            break;
        case 2: //Invertidos
            for (i = 0; i < TAMANHO; i++) {
               vet[i] = TAMANHO-i;
            }
            break;
        case 3: // Aleatórios
            for (i = 0; i < TAMANHO; i++) {
                vet[i] = (int) (rand() % TAMANHO);
            }
            break;
    }
}
 
// Insertion sort function
void insertion_sort(int *arr){
	int comparacoes = 0;
	int trocaComp = 0;
	int trocaCompDois = 0;
	float tempo_inicial = clock();
    int i, key, j;
    
    for (i = 1; i < TAMANHO; i++) {
		trocaCompDois++;
    	comparacoes++;
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
			comparacoes++;
        	trocaComp++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
    	arr[j + 1] = key;
    	
    	if(i == 9999){
    		trocaCompDois = trocaCompDois *2;
		}
	}
	trocaComp = trocaComp + trocaCompDois;
    float tempo_final = clock() - tempo_inicial;
    printf("Tempo de execucao do algoritmo: %.3f",tempo_final/1000);
    printf("\nQuantidade de comparacoes: %i\n",comparacoes);
    printf("Quantidade de trocas: %i\n",trocaComp);
}
