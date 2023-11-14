#pragma once
#include "viaturaFunctions\adicionarViatura.cpp"
#include "structs\cad.h"
#include "viaturaFunctions\viaturasEmUso.cpp"
#include "pessoaFunctions\pessoasAtuais.cpp"
#include "loginFunction\loginMain.cpp"
#include "policiaisFunctions\policiaisAtuais.cpp"


void viaturaLogin(Nodo* &listViaturas, Nodo* &listViaturasFull, Nodo* &pPrioritaria, Nodo* &qPrioritaria, Nodo* &pNormal, Nodo* &qNormal, Nodo* &listPessoas, Nodo* &listOcorrencias, Nodo* &pOcorrencia, Nodo* &qOcorrencia, Nodo* &pRegistros, Nodo* &qRegistros, Nodo* &listViaturasFinalizadas);

void viaturaEmUso(Nodo* &listViaturas, Nodo* &listPessoas, Nodo* &listPessoasFull, Nodo* &listViaturasEmUso, Nodo* &listOcorrencias, Nodo* &pOcorrencia, Nodo* &qOcorrencia, Nodo* &pRegistros, Nodo* &qRegistros);

void lerArquivoPessoas(Nodo* &listPessoas);

void viaturaOcorrencia(Nodo* &listPessoas, Nodo* &listViaturas, Nodo* &pOcorrencias, Nodo* &qOcorrencias, Nodo* &pLogRegistro, Nodo* &qLogRegistro, Nodo* &listViaturasFinalizadas);

int loginInit(Nodo *listPoliciais, char patente[][20], int numPatentes);

void lerPoliciaisDoArquivo(Nodo* &listaPoliciais);

void enqueueOcorrencias(Nodo* &pOcorrencia, Nodo* &qOcorrencia, void* item);

void enqueuePrioritaria(Nodo* &pPrioritaria, Nodo* &qPrioritaria, void* item);

void enqueueNormal(Nodo* &pNormal, Nodo* &qNormal, void* item);