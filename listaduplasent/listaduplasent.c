#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

typedef struct cidade {
    char nomeCidade [30];
    int temperatura;
    struct cidade *proximo;
    struct cidade *anterior;
} cidade;
typedef struct lista_dup {
    cidade *cabeca;
    cidade *cauda;
    int cont;
} lista_dup;
void inicializar (lista_dup *lista) {
    lista->cabeca = NULL;
    lista->cauda  = NULL;
}
void listarTodos(lista_dup lista) {
    cidade *auxiliar = lista.cabeca;
    while(auxiliar->proximo!=NULL){
        printf("|Cidade: %s, Temperatura: %d|\n", auxiliar->nomeCidade, auxiliar->temperatura);
        auxiliar = auxiliar->proximo;
    }
}
void limpar(lista_dup* lista) {
	
	while(lista->cabeca) {
		
		cidade * aux = lista->cabeca;
		lista->cabeca = aux->proximo;
		aux->proximo = NULL;
		aux->anterior = NULL;
		free(aux);

	}
}
void inserir_cabeca(lista_dup* lista, cidade* ci) {
	cidade * aux = lista->cabeca;
	if (aux == NULL) {
		lista->cabeca = ci;
		lista->cauda = ci;
		lista->cont++;
		return;
	}
	lista->cabeca = ci;
	ci->proximo = aux;
    lista->cont++;
	aux->anterior = ci;
}
void inserir_cauda(lista_dup* lista, cidade* ci) {
    cidade* aux = lista->cauda;
	if (aux == NULL) {
		lista->cauda = ci;
		lista->cabeca= ci;
        lista->cont++;
		return;
	}
	aux->proximo = ci;
	ci->anterior = aux;
    lista->cont++;
	lista->cauda = ci;
}
void retornaCidadeFria(lista_dup lista) {
    cidade *auxiliar, *menor;
    auxiliar= lista.cabeca;
    menor = auxiliar;
    while(auxiliar->proximo!=NULL){
        if(auxiliar->temperatura < menor->temperatura) menor = auxiliar;
        auxiliar = auxiliar->proximo;
    }
    printf("\n\nCidade: %s, Temperatura: %d\n\n", menor->nomeCidade, menor->temperatura);
}

int main (int argc, char **argv) {
    lista_dup list;
	cidade *city;
    inicializar(&list);

    while (scanf("%s %i", city->nomeCidade, &city->temperatura) != EOF){
        city = (cidade *) malloc(sizeof(cidade));
        inserir_cauda(&list, city);
        //inserir_cabeca(&list, city);
    }
    foreground(BLUE);
    printf("\nListando todas as cidades:\n");
    listarTodos(list);
    foreground(RED);
    printf("\n\nExibindo a cidade mais fria:");
    retornaCidadeFria(list);
    style(RESETALL);
    fflush(stdout);
}
