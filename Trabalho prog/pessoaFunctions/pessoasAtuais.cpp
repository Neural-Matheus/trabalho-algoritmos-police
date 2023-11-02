#include <bits/stdc++.h>
#include "../structs/cad.h"

#ifdef _WIN32
#define PATH_PESSOAS "bancoDados\\pessoas.txt"
#else
#define PATH_PESSOAS "bancoDados/pessoas.txt"
#endif

void addNewPessoaNode(Nodo* &listPessoas, Pessoa* pessoa) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    novo->item = pessoa;
    novo->prox = listPessoas;
    listPessoas = novo;
}

void lerPessoasDoArquivo(Nodo* &listPessoas) {
    FILE* file = fopen(PATH_PESSOAS, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo de pessoas");
        return;
    }

    Pessoa pessoa;
    int x = 0;

    while (fscanf(file, " %[^\n]", pessoa.nome) != EOF) {
        fgetc(file);
        fscanf(file, " %s", pessoa.CPF);
        fgetc(file);
        fscanf(file, " %[^\n]", pessoa.cidade);
        fgetc(file);
        fscanf(file, "%d", &pessoa.passagensPolicia);
        fgetc(file);

        for (int j = 0; j < 2; j++) {
            int ni;
            fscanf(file, "%d", &ni);

            for(int i = 0; i < ni; i++) {
                fscanf(file, " %[^\n]", pessoa.inadimplencias[i]);
                x++;
            }
        }

        addNewPessoaNode(listPessoas, &pessoa);
    }

    fclose(file);
}
