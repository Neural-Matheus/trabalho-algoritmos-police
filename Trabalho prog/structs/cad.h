#pragma once
#include <bits/stdc++.h>
#define MAX 50

struct nodo {
    void *item;
    struct nodo *prox;
};

typedef struct nodo Nodo;

struct policiais {
    char nome[MAX+1];
    char CPF[MAX+1];
    char nomeGuerra[MAX+1];
    char cidade[MAX+1];
    int idade;
    char cargo[MAX+1];
    char senha[MAX+1];
    struct policiais *prox;
};

typedef struct policiais Policiais;

struct pessoa {
    char nome[50+1];
    char CPF[12+1];
    char cidade[50+1];
    int passagensPolicia;
    int ni;
    char inadimplencias[100+1][50+1];
    struct pessoa *prox;
};

typedef struct pessoa Pessoa;

struct viatura {
    int codigo;
    char tipoViatura[MAX];
    struct viatura *prox;
};

typedef struct viatura Viaturas;


struct viaturaEmUso {
    char descricao[50+1];
    char localizacao[50+1];
    struct viaturaEmUso* prox; 
};

typedef struct viaturaEmUso ViaturaEmUso;


struct ocorrenciaDP {
    int quant;
    char CPFs[100+1][12+1];
};