#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista * next;
};

typedef struct lista Lista;

Lista * inicializaLista(){	//Como L � um ponteiro para uma lista,
 	return NULL;			//ou ele retorna um endere�o para uma lista ou retorna vazio
 
}
// Insere valores no come�o da lista
Lista * inserir(Lista * pL, int elemento){			//Fun��o criar um novo n� (lista)
	Lista * novo = (Lista *) malloc(sizeof(Lista));	//Novo aponta para area alocada, retorna uma tipagem gen�rica, que e convertida
	if(novo != NULL){								//if novo!=NULL entao esta criado o n�
		novo->info = elemento;
		novo->next = pL;
	//	printf("Novo->Info: [%d]->",novo->info);
		return novo;								//Precisa retornar, para nao perder o Elo de liga��o
	}
}

void imprime(Lista *pL){	//passa o come�o da lista
	while(pL != NULL){
		printf("[%d]->",pL->info);
		pL = pL->next;		//vai para pr�ximo n�
	}
}

int main(int argc, char *argv[]) {
	
	Lista *L; 				//Elo inicial (vari�vel est�tica)
	L = inicializaLista();  //iniciar lista vazia
	
	L = inserir(L,1000);		//Passado como par�metro o come�o da lista e valor a ser inserido
	L = inserir(L,100);
	L = inserir(L,10);
	L = inserir(L,1);
	
	imprime(L);
	
	return 0;
}
