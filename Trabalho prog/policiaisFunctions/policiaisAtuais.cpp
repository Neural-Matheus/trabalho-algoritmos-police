#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../structs/cad.h"

#ifdef _WIN32
#define PATH_POLICIAIS "bancoDados\\policiais.txt"
#else
#define PATH_POLICIAIS "bancoDados/policiais.txt"
#endif

void adicionarPolicial(Policiais **head, const char nome[], const char CPF[], const char nomeGuerra[], const char cidade[], int idade, const char cargo[], const char senha[]) {
    Policiais *novoPolicial = (Policiais*)malloc(sizeof(Policiais));
    strncpy(novoPolicial->nome, nome, MAX);
    strncpy(novoPolicial->CPF, CPF, MAX);
    strncpy(novoPolicial->nomeGuerra, nomeGuerra, MAX);
    strncpy(novoPolicial->cidade, cidade, MAX);
    novoPolicial->idade = idade;
    strncpy(novoPolicial->cargo, cargo, MAX);
    strncpy(novoPolicial->senha, senha, MAX);
    novoPolicial->prox = *head;
    *head = novoPolicial;
}

void lerPoliciaisDoArquivo(Nodo* &listPoliciais) {
    FILE *file = fopen(PATH_POLICIAIS, "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de policiais.\n");
        return;
    }

    char line[MAX * 7 + 6];

    while (fgets(line, sizeof(line), file) != NULL) {
        char nome[MAX + 1];
        char CPF[MAX + 1];
        char nomeGuerra[100];
        char cidade[MAX + 1];
        int idade;
        char cargo[MAX + 1];
        char senha[MAX + 1];

        sscanf(line, "%s", nome);
        fgets(line, sizeof(line), file);
        sscanf(line, "%s", CPF);
        fgets(line, sizeof(line), file);
        sscanf(line, "%s", nomeGuerra);
        fgets(line, sizeof(line), file);
        sscanf(line, "%s", cidade);
        fgets(line, sizeof(line), file);
        sscanf(line, "%d", &idade);
        fgets(line, sizeof(line), file);
        sscanf(line, "%s", cargo);
        fgets(line, sizeof(line), file);
        sscanf(line, "%s", senha);

        Policiais *novoPolicial = (Policiais *)malloc(sizeof(Policiais));
        strncpy(novoPolicial->nome, nome, MAX);
        strncpy(novoPolicial->CPF, CPF, MAX);
        strncpy(novoPolicial->nomeGuerra, nomeGuerra, MAX);
        strncpy(novoPolicial->cidade, cidade, MAX);
        novoPolicial->idade = idade;
        strncpy(novoPolicial->cargo, cargo, MAX);
        strncpy(novoPolicial->senha, senha, MAX);

        Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));
        novoNodo->item = novoPolicial;
        novoNodo->prox = listPoliciais;
        listPoliciais = novoNodo;
    }

    fclose(file);
}