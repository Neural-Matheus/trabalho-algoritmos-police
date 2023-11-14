#pragma once
#include "COPOM\COPOMFunc.cpp"
#include "viaturaFunctions\filaPrioridade.cpp"
#include "viaturaFunctions\verViatura.cpp"
#include "viaturaFunctions\viaturaEstadoNeutro.cpp"
#include "viaturaFunctions\viaturaOcorrencia.cpp"
#include "viaturaFunctions\pmFunctions.cpp"
void enqueueOcorrencias(Nodo* &pOcorrencia, Nodo* &qOcorrencia, void* item);
void copomFun(Nodo* &listOcorrencias, Nodo* &listViaturas, Nodo* &pOcorrencias, Nodo* &qOcorrencias,
    Nodo* &pPrioritaria, Nodo* &pNormal, Nodo* &pFilaRegistros, Nodo* &qFilaRegistros
);
void veriNeutro(Nodo* &listViaturas);
void viaturaOcorrencia(Nodo* &listPessoas, Nodo* &listViaturas, Nodo* &pOcorrencias, Nodo* &qOcorrencias, Nodo* &pLogRegistro, Nodo* &qLogRegistro, Nodo* &listViaturasFinalizadas);
void addNewBoletin(Nodo* &listOcorrencias, Nodo* &listViaturas, Nodo* &listBoletim);