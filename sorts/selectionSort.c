/*
PROCESSO AVALIATIVO N2 – ESTRUTURA DE DADOS

INTEGRANTES EQUIPE:
	- TIAGO MURILO OCHOA DA lUZ
	- RODRIGO C.
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
	
    geraNumero(vet, 1);
	selectionSort(vet);
	
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
void selectionSort(int *x){
	int i, j, eleito, menor, pos;
	int trocaComp = 0;
	int comparacoes = 0; 
	float tempo_inicial = clock();
	
	for (i = 0; i < TAMANHO-1; i++) {
		trocaComp++;
        eleito = x[i];
        menor = x[i + 1];
        pos = i + 1;
        for (j = i + 2; j <= TAMANHO; j++) {
            comparacoes++;
            if (x[j] < menor) {
                menor = x[j];
                pos = j;
            }
        }
        if (menor < eleito) {
			trocaComp++;
            x[i] = x[pos];
            x[pos] = eleito;
        }
    }

    float tempo_final = clock() - tempo_inicial;
    printf("Tempo de execucao do algoritmo: %.3f",tempo_final/1000);
    printf("\nQuantidade de comparacoes: %i\n",comparacoes);
    printf("Quantidade de trocas: %i\n",trocaComp);
}

