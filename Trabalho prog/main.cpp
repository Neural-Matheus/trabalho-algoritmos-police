#include <bits/stdc++.h>
#include "arq.h"

void menu(Nodo* &listViaturas, Nodo* &listViaturasFull, Nodo* &listPoliciais, Nodo* &listPessoas, Nodo* &listPessoasFull, Nodo* &listViaturasEmUso) {
    int i = -1;

    do {
        printf("\n\n");
        printf("SPM - Funcionalidades\n\n\n");
        printf("1 - Viatura Login       2 - Viatura em Uso\n");
        printf("3 - COPOM\n");
        printf("4 - Policia Militar\n");
        printf("5 - Oficial\n");
        printf("6 - Comandante Geral    0 - Encerrar Programa\n");

        scanf("%d", &i);
        
        if (i == 1) {
            viaturaLogin(listViaturas, listViaturasFull);
        }

        else if (i == 2) {
            viaturaEmUso(listViaturas, listViaturasFull, listPessoasFull, listViaturasEmUso);
        }

        else if (i == 3) {
            copomFun();
        }

        else if (i == 4) {
            char patentes[][20] = {"Soldado", "Tenente", "Sargento"};
            loginInit(listPoliciais, patentes, 3);
        } 

        else if (i == 5) {
            char patentes[][20] = {"Oficial"};
            loginInit(listPoliciais, patentes, 1);
        } 

        else if (i == 6) {
            char patentes[][20] = {"Comandante Geral"};
            loginInit(listPoliciais, patentes, 1);
        }

    } while (i != 0);
}

void imprimirListaPoliciais(Nodo* listPessoas) {
    Nodo* aux = listPessoas;

    while (aux != NULL) {
        Policiais* policia = (Policiais*)aux->item;
        printf("Nome: %s\n", policia->nomeGuerra);

        aux = aux->prox;
    }
}
int main() {
    Nodo *listViaturas = NULL;
    Nodo *listViaturasFull = NULL;
    Nodo *listViaturasEmUso = NULL;
    Nodo *listPoliciais = NULL;

    Nodo *listPessoas = NULL;
    Nodo *listPessoasFull = NULL;

    lerPessoasDoArquivo(listPessoasFull);
    lerPoliciaisDoArquivo(listPoliciais);
    imprimirListaPoliciais(listPoliciais);
    menu(listViaturas, listViaturasFull, listPoliciais, listPessoas, listPessoasFull, listViaturasEmUso); 
    return 0;
}