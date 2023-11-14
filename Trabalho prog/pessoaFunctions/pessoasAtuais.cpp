#include <bits/stdc++.h>
#include "../structs/cad.h"

#ifdef _WIN32
#define PATH_PESSOAS "bancoDados\\pessoas.txt"
#else
#define PATH_PESSOAS "bancoDados/pessoas.txt"
#endif

int preencherPessoa(FILE *arquivo, Pessoa *pessoa) {
    if (fscanf(arquivo, " %[^\n]", pessoa->nome) != 1) return 0;
    if (fscanf(arquivo, " %s", pessoa->CPF) != 1) return 0;
    if (fscanf(arquivo, " %[^\n]", pessoa->cidade) != 1) return 0;
    if (fscanf(arquivo, "%d", &pessoa->idade) != 1) return 0;
    if (fscanf(arquivo, "%d", &pessoa->passagensPolicia) != 1) return 0;

    for (int i = 0; i < pessoa->passagensPolicia; i++) {
        if (fscanf(arquivo, " %[^\n]", pessoa->passagens[i]) != 1) return 0;
    }

    if (fscanf(arquivo, "%d", &pessoa->nInadimplencias) != 1) return 0;

    for (int i = 0; i < pessoa->nInadimplencias; i++) {
        if (fscanf(arquivo, " %[^\n]", pessoa->inadimplencias[i]) != 1) return 0;
    }

    return 1;
}

void adicionarPessoa(Nodo **lista, Pessoa *pessoa) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    novo->item = pessoa;
    novo->prox = *lista;
    *lista = novo;
}

void lerArquivoPessoas(Nodo* &listPessoas) {
    FILE *arquivo = fopen(PATH_PESSOAS, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Pessoa *novaPessoa = (Pessoa *)malloc(sizeof(Pessoa));
    while (preencherPessoa(arquivo, novaPessoa) == 1) {
        adicionarPessoa(&listPessoas, novaPessoa);
        novaPessoa = (Pessoa *)malloc(sizeof(Pessoa));
    }
    free(novaPessoa);  // Libera a memória alocada para a última pessoa que não foi adicionada à lista

    fclose(arquivo);
}