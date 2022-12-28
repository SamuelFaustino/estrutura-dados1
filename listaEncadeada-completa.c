// Samuel F. de Almeida - 04721064

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
	if(novo != NULL){								//if novo!=NULL entao est� criado o n�
		novo->info = elemento;
		novo->next = pL;
		printf("Novo->Info: [%d]->",novo->info);
		return novo;								//Precisa retornar, para nao perder o Elo de liga��o
	}
}

// Insere valores no fim da lista
Lista * inserirFinal(Lista * pL, int elemento){
	if(pL == NULL){
		return inserir(pL,elemento);
	}
	else{
		Lista * aux = pL;
		while(aux->next != NULL){
			aux = aux->next;
		}
		Lista * novo = (Lista *) malloc(sizeof(Lista));
		if(novo != NULL){
			novo->info = elemento;
			novo->next = aux->next;
			aux->next = novo;	//
			
			printf("[%d]->",novo->info);
		}	
		return pL;
	}
}

void imprime(Lista *pL){		//Passa o come�o da lista
	while(pL != NULL){
		printf("[%d]->", pL->info);
		pL = pL->next;			//vai para pr�ximo n�
	}
}

Lista * buscar(Lista * pL, int elemento){
	while(pL != NULL){	 //diferente de NULL, sign tem endere�os
		if(pL->info == elemento){
			return pL;
		}
		pL = pL->next;
	}
	return NULL;
}

Lista *dividir(Lista * pL, int elemento){
	Lista * divisao = buscar(pL, elemento);
	
	while (pL->next != divisao)
		pL = pL->next;
		
			pL->next = NULL;
			
	return divisao;
	
}

Lista * remover(Lista * pL, int valor){
	Lista * anterior = NULL; 
	Lista * aux = pL;
	while(pL != NULL && pL->info != valor){ 
		anterior = pL;
		pL = pL->next;
	}
	if(anterior == NULL)	// 			1. Antes de excluir o primeiro n� att com "L"
		aux = aux->next;
	else{
		if(anterior->next == NULL) // 	 2. o dado nao existe na lista
			return aux;
		else{
			anterior->next = pL->next; // 3. esta no meio da lista ou no final
		}
		
	}
	free(pL);
	return aux;
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	Lista *L; 				//Elo inicial (vari�vel est�tica)
	L = inicializaLista();  //iniciar lista vazia
	
	L = inserir(L,10);	//Passado como par�metro o come�o da lista e valor a ser inserido //ultimo n�
	L = inserir(L,8);	
	L = inserir(L,6);
	L = inserir(L,4);
	L = inserir(L,2);
	L = inserirFinal(L,1);	//
	
	printf("\nImprimindo a lista: ");
	imprime(L);
	printf("\nBuscar o valor na lista!\n");
	int valor;
	scanf("%d",&valor);
	Lista * getEnd = buscar(L,valor); //Pega o endere�o do n� da lista
	if(getEnd != NULL)
		printf("\n Valor %d existe na lista e esta no endere�o %p \n",getEnd->info, getEnd);
	
	L = remover(L,8);
	printf("\nImprimindo a lista: ");
	imprime(L);
	
	printf("\nDigite o valor para divisao: ");
	scanf("%d",&valor);
	
	Lista * divisao = dividir(L,valor);
	
	printf("\nImprimindo a lista: ");
	imprime(L);
	printf("\nSegunda parte: ");
	imprime(divisao);
	
	return 0;
	
}

