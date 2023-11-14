#include <bits/stdc++.h>
#include "../structs/cad.h"
#include "../arqV2.h"


void viaturaEmUso(Nodo* &listViaturas, Nodo* &listPessoas, Nodo* &listPessoasFull, Nodo* &listViaturasEmUso, Nodo* &listOcorrencias, Nodo* &pOcorrencia, Nodo* &qOcorrencia, Nodo* &pRegistros, Nodo* &qRegistros, Nodo* &listViaturasFinalizadas) {
    char codeViatura[50];
    printf("SPM - Viatura Em Uso\n");
    printf("Identificador da viatura: ");
    scanf(" %[^\n]", codeViatura);

    Nodo *aux = listViaturas;

    while (aux != NULL) {
        Viaturas* verifi = (Viaturas*)aux->item;

        if (verifi->usoAtual == false && (strcmp(verifi->estadoAtual, "neutro") == 0  || strcpy(verifi->estadoAtual, "finalizada"))) {
            printf("\nSPM - Viatura em Uso\n");
            printf("Viatura: %s\n", verifi->codigo);
            printf("Estado atual: %s\n", verifi->estadoAtual);
        }

        if (verifi->usoAtual == true && strcmp(verifi->codigo, codeViatura) == 0) {
            strcpy(verifi->ocorrendo, "ocorrendo");
            printf("\nSPM - Viatura Chamada Policial\n");
            printf("Descrição: %s\n", verifi->descricao);
            printf("Localização: %s\n", verifi->localiza);
            printf("Confirmada ação policial - 1  Ação Policial Dispensada - 2\n");
            int op; scanf("%d", &op);
            
            if (op == 1) {
                viaturaOcorrencia(listPessoas, listViaturas, pOcorrencia, qOcorrencia, pRegistros, qRegistros, listViaturasFinalizadas);
            } 
            return;  
        }

        aux = aux->prox;
    }
}


    




