#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista * next;
};

typedef struct lista Lista;

Lista * inicializaLista(){	//Como L é um ponteiro para uma lista,
 	return NULL;			//ou ele retorna um endereço para uma lista ou retorna vazio
 
}
// Insere valores no começo da lista
Lista * inserir(Lista * pL, int elemento){			//Função criar um novo nó (lista)
	Lista * novo = (Lista *) malloc(sizeof(Lista));	//Novo aponta para area alocada, retorna uma tipagem genérica, que e convertida
	if(novo != NULL){								//if novo!=NULL entao esta criado o nó
		novo->info = elemento;
		novo->next = pL;
	//	printf("Novo->Info: [%d]->",novo->info);
		return novo;								//Precisa retornar, para nao perder o Elo de ligação
	}
}

void imprime(Lista *pL){	//passa o começo da lista
	while(pL != NULL){
		printf("[%d]->",pL->info);
		pL = pL->next;		//vai para próximo nó
	}
}

int main(int argc, char *argv[]) {
	
	Lista *L; 				//Elo inicial (variável estática)
	L = inicializaLista();  //iniciar lista vazia
	
	L = inserir(L,1000);		//Passado como parâmetro o começo da lista e valor a ser inserido
	L = inserir(L,100);
	L = inserir(L,10);
	L = inserir(L,1);
	
	imprime(L);
	
	return 0;
}
