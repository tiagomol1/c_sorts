#include <stdio.h>
#define TAMANHO 10000
 
void geraNumero(int *vet, int op);
void quick_sort(int[],int,int);
int partition(int[],int,int);
int comp = 0;
int troc = 0;
int compAux = 0;
 
int main(){
	int a[TAMANHO], i;
    geraNumero(a,1);

	float tempo_inicial = clock();
	quick_sort(a,0,TAMANHO-1);
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

 
void quick_sort(int a[],int l,int u){
	int j;
	compAux++;
	if(l<u){
		j=partition(a,l,u);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,u);
	}
}
 
int partition(int a[],int l,int u){
	int v,i,j,temp;
	v=a[l];
	i=l;
	j=u+1;
	
	do{
		do{
			troc++;
			i++;
		}while(a[i]<v&&i<=u);
		
		do{
			j--;
		}while(v<a[j]);
		
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);
	a[l]=a[j];
	a[j]=v;
	
	return(j);
}
