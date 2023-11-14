#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include "../arqV2.h"

void removerDaLista(Nodo*& lista, const char* idViatura) {
    if (lista == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Nodo* current = lista;
    Nodo* previous = NULL;

    while (current != NULL) {
        Viaturas* viatura = (Viaturas*)current->item;

        if (viatura != NULL && strcmp(viatura->codigo, idViatura) == 0) {
            if (previous != NULL) {
                previous->prox = current->prox;
            } else {
                lista = current->prox;
            }

            free(current->item);
            free(current);

            printf("Viatura removida da lista com sucesso.\n");
            return;
        }

        previous = current;
        current = current->prox;
    }

    printf("Viatura não encontrada na lista.\n");
}



void removerOcorrenciaEMover(Nodo*& pOrigem, Nodo*& qOrigem, Nodo*& pDestino, Nodo*& qDestino, const char* idViatura, const char* tipoOcorrencia) {
    Nodo* current = pOrigem;
    Nodo* previous = NULL;

    while (current != NULL) {
        ocorrenciaCOPOM* ocorrencia = (ocorrenciaCOPOM*)current->item;

        if (ocorrencia != NULL && strcmp(ocorrencia->idViatura, idViatura) == 0 && strcmp(ocorrencia->tipoPolicial, tipoOcorrencia) == 0) {
            if (previous != NULL) {
                previous->prox = current->prox;
                if (current == qOrigem) {
                    qOrigem = previous;
                }
            } else {
                pOrigem = current->prox;
                if (pOrigem == NULL) {
                    qOrigem = NULL;
                }
            }

            // Adiciona a ocorrência à fila de destino
            current->prox = NULL;
            if (pDestino == NULL) {
                pDestino = qDestino = current;
            } else {
                qDestino->prox = current;
                qDestino = current;
            }

            printf("Ocorrência removida e movida para outra fila com sucesso.\n");
            return;
        }

        previous = current;
        current = current->prox;
    }

    printf("Ocorrência não encontrada para a viatura %s e tipo %s.\n", idViatura, tipoOcorrencia);
}
void adicionarViatura(Nodo*& listViaturasFinalizadas, Viaturas* viatura) {
    // Cria um novo nodo para a viatura
    Nodo* novoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (novoNodo == NULL) {
        printf("Erro ao alocar memória para o novo nodo.\n");
        exit(1);
    }

    // Atribui a viatura ao item do novo nodo
    novoNodo->item = viatura;
    novoNodo->prox = NULL;

    // Adiciona o novo nodo ao final da lista de viaturas finalizadas
    if (listViaturasFinalizadas == NULL) {
        listViaturasFinalizadas = novoNodo;
    } else {
        Nodo* current = listViaturasFinalizadas;
        while (current->prox != NULL) {
            current = current->prox;
        }
        current->prox = novoNodo;
    }
}

void encerrarOcorrencia(Nodo*& pOcorrencias, Nodo*& qOcorrencias, Nodo*& listViaturas, Nodo*& listViaturasFinalizadas, const char* idViatura, const char* tipoOcorrencia) {
    // Remove a ocorrência da fila de ocorrências
    removerOcorrenciaEMover(pOcorrencias, qOcorrencias, pOcorrencias, qOcorrencias, idViatura, tipoOcorrencia);

    // Encontra a viatura na fila de viaturas
    Nodo* currentViatura = listViaturas;
    while (currentViatura != NULL) {
        Viaturas* viatura = (Viaturas*)currentViatura->item;
        if (strcmp(viatura->codigo, idViatura) == 0) {
            // Remove as informações de ocorrência da viatura
            strcpy(viatura->estadoAtual, "neutro");
            strcpy(viatura->ocorrendo, "");
            viatura->usoAtual = false;
            // Adiciona a viatura à lista de viaturas finalizadas
            adicionarViatura(listViaturasFinalizadas, viatura);

            break;
        }
        currentViatura = currentViatura->prox;
    }
}

bool viaturaNaFila(Viaturas* viatura, Nodo* fila) {
    Nodo* current = fila;
    while (current != nullptr) {
        Viaturas* viaturaFila = (Viaturas*)current->item;
        if (viaturaFila == viatura) {
            return true;
        }
        current = current->prox;
    }

    return false;
}

int contarElementos(Nodo* fila) {
    int count = 0;
    Nodo* current = fila;

    while (current != nullptr) {
        count++;
        current = current->prox;
    }

    return count;
}

Viaturas* obterViaturaComMenosUso(Nodo* listViaturas, Nodo* fila) {
    Viaturas* viaturaMenosUso = nullptr;
    int menorUso = INT_MAX;

    Nodo* current = listViaturas;
    while (current != nullptr) {
        Viaturas* viatura = (Viaturas*)current->item;

        if (viaturaNaFila(viatura, fila) && viatura->quantUso < menorUso) {
            menorUso = viatura->quantUso;
            viaturaMenosUso = viatura;
        }

        current = current->prox;
    }

    return viaturaMenosUso;
}

void enqueueOcorrencias(Nodo* &pOcorrencia, Nodo* &qOcorrencia, void* item) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->item = item;
    novo->prox = NULL;

    if (pOcorrencia == NULL) {
        pOcorrencia = novo;
        qOcorrencia = novo;
    } else {
        qOcorrencia->prox = novo;
        qOcorrencia = novo;
    }
}

void comparaFila(Nodo* &pOcorrencia, Nodo* &pPrioridade, Nodo* &listViaturas) {
    int countOcorrencias = contarElementos(pOcorrencia);
    int countPrioridade = contarElementos(pPrioridade);

    Viaturas* viaturaMenosUso = nullptr;

    if (countOcorrencias < countPrioridade) {
        viaturaMenosUso = obterViaturaComMenosUso(listViaturas, pOcorrencia);
    } else {
        viaturaMenosUso = obterViaturaComMenosUso(listViaturas, pPrioridade);
    }

    if (viaturaMenosUso != NULL) {
        ocorrenciaCOPOM* ocorrencia = (ocorrenciaCOPOM*)pOcorrencia->item;
        strncpy(ocorrencia->idViatura, viaturaMenosUso->codigo, sizeof(ocorrencia->idViatura)-1);
        ocorrencia->idViatura[sizeof(ocorrencia->idViatura)-1] = '\0';  
        viaturaMenosUso->usoAtual = true;
        viaturaMenosUso->quantUso++;
        strcpy(viaturaMenosUso->estadoAtual, "em ocorrência");
        strcpy(viaturaMenosUso->localiza, ocorrencia->localizacao);
        strcpy(viaturaMenosUso->descricao, ocorrencia->descricao);
        ocorrencia->temBoletim = false;
        ocorrencia->uso = true;
        printf("Uso atual atribuído para viatura %s\n", viaturaMenosUso->codigo);
    } else {
        printf("Não há chamadas que são compatíveis com essa viatura ou não existe viatura disponível.\n");
    }
}




void copomFun(Nodo* &listOcorrencias, Nodo* &listViaturas, Nodo* &pOcorrencias, Nodo* &qOcorrencias,
    Nodo* &pPrioritaria, Nodo* &pNormal, Nodo* &pFilaRegistros, Nodo* &qFilaRegistros
) {
    printf("SPM - COPOM\n");

    char tipoPolice[100];
    char desc[100];
    char localizacao[100];

    printf("Polícia Regular - 1 Especializada - 2: ");
    scanf(" %[^\n]", tipoPolice);

    if (strcmp(tipoPolice, "1") == 0) {
        strcpy(tipoPolice, "regular");
    } else {
        strcpy(tipoPolice, "especializada");
    }


    printf("Descrição: ");
    scanf(" %[^\n]", desc);

    printf("Localização: ");
    scanf(" %[^\n]", localizacao);

    ocorrenciaCOPOM* novo = (ocorrenciaCOPOM*)malloc(sizeof(ocorrenciaCOPOM));
    strcpy(novo->tipoPolicial, tipoPolice);
    strcpy(novo->descricao, desc);
    strcpy(novo->localizacao, localizacao);
    novo->temBoletim = false;

    enqueueOcorrencias(pOcorrencias, qOcorrencias, novo);

    if (strcmp(tipoPolice, "regular") == 0) {
        int opPrioritaria;
        printf("Polícia Normal Prioritária - 1 / Polícia Normal - 2: ");
        scanf("%d", &opPrioritaria);

        if (opPrioritaria == 1) {
            comparaFila(pOcorrencias, pPrioritaria, listViaturas);
        } else if (opPrioritaria == 2) {
            comparaFila(pOcorrencias, pNormal, listViaturas);
        } else {
            printf("Opção inválida!\n");
        }
    } else if (strcmp(tipoPolice, "especializada") == 0) {
        comparaFila(pOcorrencias, pPrioritaria, listViaturas);
    } else {
        printf("Tipo de polícia inválido!\n");
    }
}