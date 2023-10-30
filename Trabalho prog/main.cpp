#include <bits/stdc++.h>
#include "arq.h"

void menu(Nodo* &listViaturas, Nodo* &listViaturasFull, Nodo* &listPoliciais, Nodo* &listPessoas) {
    int i = -1;

    do {
        printf("SPM - Funcionalidades\n");
        printf("1 - Viatura Login\n");
        printf("2 - Viatura em Uso\n");
        printf("3 - COPOM\n");
        printf("4 - Policia Militar\n");
        printf("5 - Oficial\n");
        printf("6 - Comandante Geral\n");
        printf("0 - Encerrar Programa\n");

        scanf("%d", &i);
        
        if (i == 1) {
            viaturaLogin(listViaturas, listViaturasFull);
        }

        if (i == 2) {
            viaturaEmUso(listViaturas, listViaturasFull);
        }
    } while (i != 0);
}

int main() {
    Nodo *listViaturas = NULL;
    Nodo *listViaturasFull = NULL;
    Nodo *listPoliciais = NULL;
    Nodo *listPessoas = NULL;

    menu(listViaturas, listViaturasFull, listPoliciais, listPessoas); 
    return 0;
}