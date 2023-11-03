#pragma once
#include "viaturaFunctions\adicionarViatura.cpp"
#include "structs\cad.h"
#include "viaturaFunctions\viaturasEmUso.cpp"
#include "pessoaFunctions\pessoasAtuais.cpp"
#include "COPOM\COPOMFunc.cpp"
#include "loginFunction\loginMain.cpp"
#include "policiaisFunctions\policiaisAtuais.cpp"


void viaturaLogin(Nodo* &listViaturas, Nodo* &listViaturasFull);

void viaturaEmUso(Nodo* &listViaturas, Nodo* &listViaturasFull, Nodo* &listPessoasFull, Nodo* &listViaturasEmUso);

void lerPessoasDoArquivo(Nodo* &listPessoas);

void viaturaOcorrencia(Nodo *listPessoas);

void copomFun();

void loginInit(Nodo *listPoliciais, char patente[][20], int numPatentes);

void lerPoliciaisDoArquivo(Nodo* &listaPoliciais);