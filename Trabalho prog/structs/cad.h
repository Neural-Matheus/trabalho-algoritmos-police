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

struct pessoa {
    char nome[50];
    char CPF[12];
    char cidade[50];
    int passagensPolicia;
    int ni;
    char inadimplencias[100][50];
    struct pessoa *prox;
};

typedef struct pessoa Pessoa;

struct viatura {
    int codigo;
    char tipoViatura[MAX];
    struct viatura *prox;
};

typedef struct viatura Viaturas;