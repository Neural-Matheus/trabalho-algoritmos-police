#pragma once
#include "viaturaFunctions\adicionarViatura.cpp"
#include "structs\cad.h"
#include "viaturaFunctions\viaturasEmUso.cpp"
#include "pessoaFunctions\pessoasAtuais.cpp"

void viaturaLogin(Nodo* &listViaturas, Nodo* &listViaturasFull);

void viaturaEmUso(Nodo* &listViaturas, Nodo* &listViaturasFull);

void lerPessoasDoArquivo(Nodo* &listPessoas);

