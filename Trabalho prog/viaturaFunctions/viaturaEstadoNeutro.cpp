#include <bits/stdc++.h>
#include "../structs/cad.h"

void veriNeutro(Nodo* &listViaturas) {
    Nodo* current = listViaturas;
    Viaturas* viatura = (Viaturas*)current->item;
    strcpy(viatura->estadoAtual, "neutro");
    viatura->usoAtual = false;

    int op;
    printf("\nViatura - Estado Neutro\n");
    printf("1 - Voltar para o menu\n");

    scanf("%d", &op);
    if (op == 1) {
        return;
    }
}