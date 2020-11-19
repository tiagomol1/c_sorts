/*
4. Faça um programa que cadastre 20 palavras em um vetor, ordene-os usando o método merge sort, em 
seguida encontre as palavras que começam vogais e mostre quais são elas.
R.:
*/

#include <stdio.h>
#include <string.h>

// dado estruturado
typedef struct palavra{
	char palavra[25];
}Palavra;

// prototipo de função
void merge(Palavra x[], int inicio, int fim);
void intercala(Palavra x[], int inicio, int fim, int meio);

int main (void){
	
	// variáveis locais
	Palavra vet[20];
	int i;
	
	// entrada de dados
	for (i=0;i<20;i++){
		printf("Digite a palavra %i: ",i+1);
		gets(vet[i].palavra);
		fflush(stdin);
	}
	
	// processamento dos dados
	merge(vet,0,19);
	
	// Saída de dados
	//for(i=0;i<20;i++){
	//	printf("%s\n",vet[i].palavra);
	//}
	
	char v[]={"aeiouAEIOU"};
	for(i=0;i<20;i++){
		if(strchr(v,vet[i].palavra[0])>0){
			printf("%s\n",vet[i].palavra);
		}
	}
	
	
	return 0;
}

void merge(Palavra x[], int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        merge(x, inicio, meio);
        merge(x, meio + 1, fim);
        intercala(x, inicio, fim, meio);
    }
}

void intercala(Palavra x[], int inicio, int fim, int meio) {
    int poslivre = inicio, iniciovetor1 = inicio, iniciovetor2 = meio + 1, i;
    Palavra aux[20];
    while (iniciovetor1 <= meio && iniciovetor2 <= fim) {
        if (strcmp(x[iniciovetor1].palavra, x[iniciovetor2].palavra) < 0) {
            strcpy(aux[poslivre].palavra, x[iniciovetor1].palavra);
            iniciovetor1++;
        } else {
            strcpy(aux[poslivre].palavra, x[iniciovetor2].palavra);
            iniciovetor2++;
        }
        poslivre++;
    }
    for (i = iniciovetor1; i <= meio; i++) {
        strcpy(aux[poslivre].palavra,x[i].palavra);
        poslivre++;
    }
    for (i = iniciovetor2; i <= fim; i++) {
        strcpy(aux[poslivre].palavra,x[i].palavra);
        poslivre++;
    }
    for (i = inicio; i <= fim; i++) {
        strcpy(x[i].palavra,aux[i].palavra);
    }
}
