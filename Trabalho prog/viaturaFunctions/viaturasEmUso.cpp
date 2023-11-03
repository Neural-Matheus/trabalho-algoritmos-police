#include <bits/stdc++.h>
#include "../structs/cad.h"
#include "viaturaOcorrencia.cpp"

#ifdef _WIN32
#define PATH_LOGVIATURASEMUSO "bancoDados\\logsViaturas.txt"
#else
#define PATH_LOGVIATURASEMUSO "bancoDados/logsViaturas.txt"
#endif

void addToListVi(Nodo** head, void* item) {
    Nodo* newNode = (Nodo*)malloc(sizeof(Nodo));
    if (newNode == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    newNode->item = item;
    newNode->prox = *head;
    *head = newNode;
}

void saveListToFileVi(Nodo* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        exit(1);
    }

    Nodo* current = head;
    while (current != NULL) {
        ViaturaEmUso* viatura = (ViaturaEmUso*)current->item;
        fprintf(file, "Descrição: %s\n", viatura->descricao);
        fprintf(file, "Localização: %s\n", viatura->localizacao);
        fprintf(file, "\n");

        current = current->prox;
    }

    fclose(file);
}

void viaturaEmUso(Nodo* &listViaturas, Nodo* &listViaturasFull, Nodo* &listPessoasFull, Nodo* &listViaturasEmUso) {
    int op;

    printf("SPM - Viatura Chamada Policial\n");
    ViaturaEmUso* novaViatura = (ViaturaEmUso*)malloc(sizeof(ViaturaEmUso));
    if (novaViatura == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    printf("Descrição: ");
    scanf(" %[^\n]", novaViatura->descricao);
    printf("Localização: ");
    scanf(" %[^\n]", novaViatura->localizacao);
    printf("Confirmada Ação Policial - 1    Ação Policial Dispensada - 2");
    scanf("%d", &op);

    addToListVi(&listViaturasEmUso, novaViatura);
    saveListToFileVi(listViaturasEmUso, PATH_LOGVIATURASEMUSO);

    if (op == 1) {
        viaturaOcorrencia(listPessoasFull);
    } else {
        return;
    }
}
