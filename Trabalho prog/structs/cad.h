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
    char nome[MAX];
    char CPF[MAX];
    char cidade[MAX+1];
    int idade;
    int passagensPolicia;
    char passagens[MAX][MAX];
    int nInadimplencias;
    char inadimplencias[MAX][MAX];
};


typedef struct pessoa Pessoa;

struct viatura {
    char codigo[MAX];
    char tipoViatura[MAX];
    char **nomesPoliciais;
    int numPoliciais;
    int quantUso;
    bool usoAtual;
    char ocorrendo[MAX];
    char estadoAtual[MAX];
    char descricao[100];
    char localiza[100];
    char temBoletim[100];
    Pessoa **presos;  
    int numPresos;
    struct viatura *prox;
};

typedef struct viatura Viaturas;


struct viaturaEmUso {
    char descricao[50+1];
    char localizacao[50+1];
    struct viaturaEmUso *prox; 
};

typedef struct viaturaEmUso ViaturaEmUso;

struct ocorrenciaDP {
    int quant;
    char CPFs[100+1][12+1];
};

struct ocorrenciaCOPOM {
    char tipoPolicial[MAX];
    char descricao[100+1];
    char localizacao[50+1];
    char idViatura[MAX];
    bool uso;
    bool temBoletim;
    struct ocorrenciaCOPOM *prox;

};

typedef struct ocorrenciaCOPOM ocorrenciaCOPOM;

struct viaturaLog {
    char codigo[MAX];
    char tipoViatura[MAX];
    char **nomesPoliciais;
    int numPoliciais;
    int quantUso;
    bool usoAtual;
    char ocorrendo[MAX];
    char estadoAtual[MAX];
    char descricao[100];
    char localiza[100];
    struct viaturaLog *prox;
};

typedef struct viaturaLog ViaturasLog;

struct boletim {
    char boletimOco[10000];
    struct boletim *prox;
};

typedef struct boletim Boletim;
