#ifndef LISTASEDOMINO_H
#define LISTASEDOMINO_H

#include <stdio.h>
#include <stdlib.h>


typedef struct tp_no{
	tp_pedra pedra;
	struct tp_no *prox;
}tp_listase;

tp_listase * inicializa_listase(){
	return NULL;
}

int listase_vazia(tp_listase *lista) {
	if(lista == NULL) return 1;
	return 0;
}

tp_listase * aloca_listase () {
	tp_listase *novo_no;
	novo_no = (tp_listase*) malloc(sizeof(tp_listase));
	return novo_no;
}

int insere_listase_no_fim(tp_listase **l, tp_pedra e) {
	tp_listase *novo_no, *atu;
	novo_no = aloca_listase();
	if(novo_no == NULL) return 0;
	novo_no->pedra = e;
	novo_no->prox = NULL;
	
	if(listase_vazia(*l)) {
		*l = novo_no;
	} else{
		atu = *l;
		while(atu->prox!=NULL){
			atu= atu->prox;
		}
		atu->prox = novo_no;
	}
	return 1;
}

void imprime_listase(tp_listase *lista){
	tp_listase *atu;
	atu = lista;
	while(atu != NULL){
		printf(" [ %d | %d ] ",atu->pedra.esquerda, atu->pedra.direita);
		atu = atu->prox;
	}
}

int tamanho_listase(tp_listase *lista) {
	int cont = 0;
	tp_listase *atu;
	atu = lista;
	while(atu != NULL) {
		cont++;
		atu = atu->prox;
	}
	return cont;
}

int remove_listase(tp_listase **lista, tp_pedra e){
tp_listase *ant, *atu;
atu = *lista;
ant = NULL;
while((atu != NULL) && (atu->pedra.direita != e.direita) && (atu->pedra.esquerda != e.esquerda)){
	ant = atu;
	atu = atu->prox;
}
if (atu == NULL) return 0;
if (ant == NULL) {
	*lista= atu->prox;
}
else{
	ant->prox = atu->prox;
}
free(atu);
atu = NULL;
return 1;
}

tp_listase *busca_listase(tp_listase *lista, tp_pedra e){
	tp_listase *atu;
	atu = lista;
	while((atu != NULL) && (atu->pedra.direita != e.direita) && (atu->pedra.esquerda != e.esquerda)){
		atu= atu->prox;
	}
	if(atu == NULL) return NULL;
	return atu;
}

int insere_listase_no_inicio(tp_listase **l, tp_pedra e) {
	tp_listase *novo_no;
	novo_no = aloca_listase();
	if(novo_no == NULL) return 0;
	novo_no->pedra = e;
	if(listase_vazia(*l)) {
		novo_no->prox = NULL;
	} else{
		novo_no->prox = *l;
	}
	*l = novo_no;
	
	return 1;
}

#endif
