#include <iostream>
#include "../structs/cad.h"

void enqueuePrioritaria(Nodo* &pPrioritaria, Nodo* &qPrioritaria, void* item) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->item = item;
    novo->prox = NULL;

    if (pPrioritaria == NULL) {
        pPrioritaria = novo;
        qPrioritaria = novo;
    } else {
        qPrioritaria->prox = novo;
        qPrioritaria = novo;
    }
    printf("Ação adicionada na fila de prioridade!\n");
}

void enqueueNormal(Nodo* &pNormal, Nodo* &qNormal, void* item) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->item = item;
    novo->prox = NULL;

    if (pNormal == NULL) {
        pNormal = novo;
        qNormal = novo;
    } else {
        qNormal->prox = novo;
        qNormal = novo;
    }
    printf("Ação adicionada na fila normal!\n");
}

void push(Nodo* &stackTop, void* item) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    novo->item = item;
    novo->prox = stackTop;
    stackTop = novo;
}

void pop(Nodo* &stackTop, void* &item) {
    if (stackTop == NULL) {
        item = NULL;
    } else {
        Nodo *temp = stackTop;
        stackTop = stackTop->prox;
        item = temp->item;
        free(temp);
    }
}