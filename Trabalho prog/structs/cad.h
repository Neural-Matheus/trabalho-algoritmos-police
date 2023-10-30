#pragma once
#include <bits/stdc++.h>
#define MAX 50

struct nodo {
    void *item;
    struct nodo *prox;
};

typedef struct nodo Nodo;

struct policiais {
    char nome[MAX];
    char CPF[MAX];
    char nomeGuerra[MAX];
    char cidade[MAX];
    int idade;
    char cargo[MAX];
    char senha[MAX];
    struct policiais *prox;
};

typedef struct policiais Policiais;

struct pessoas {
    char nome[MAX];
    char CPF[MAX];
    char cidade[MAX];
    int idade;
    int passagens;
    int quantInadi;
    char nomeIndadi[MAX];
    struct pessoas *prox;
};

typedef struct pessoas Pessoas;

struct viatura {
    int codigo;
    char tipoViatura[MAX];
    struct viatura *prox;
};

typedef struct viatura Viaturas;
