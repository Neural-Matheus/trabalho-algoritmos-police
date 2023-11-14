#include <bits/stdc++.h>
#include "../structs/cad.h"
#include "../arqV2.h"

void addNewNode(Nodo* &list, void* item) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    novo->item = item;
    novo->prox = list;
    list = novo;
}

void viaturaLogin(Nodo* &listViaturas, Nodo* &listViaturasFull, Nodo* &pPrioritaria, Nodo* &qPrioritaria, Nodo* &pNormal, Nodo* &qNormal, Nodo* &listPessoas, Nodo* &listOcorrencias, Nodo* &pOcorrencia, Nodo* &qOcorrencia, Nodo* &pRegistros, Nodo* &qRegistros, Nodo* &listViaturasFinalizadas) {
    printf("Polícia Regular - 1\n");
    printf("Polícia Especializada - 2\n");

    int op;
    scanf("%d", &op);

    char codeViatura[MAX];
    int quantPM;

    if (op == 1) {
        getViaturaInfo(codeViatura, &quantPM);


        Nodo* aux = listViaturas;

        while (aux != NULL) {
            Viaturas* verifi = (Viaturas*)aux->item;
            
            if (verifi->usoAtual == true && strcmp(verifi->codigo, codeViatura) == 0) {
                strcpy(verifi->ocorrendo, "ocorrendo");
                printf("\nSPM - Viatura Chamada Policial\n");
                printf("Descrição: %s\n", verifi->descricao);
                printf("Localização: %s\n", verifi->localiza);
                printf("Confirmada ação polícial - 1  Ação Polícial Dispensada - 2\n");
                int op; scanf("%d", &op);
                if (op == 1) {
                  viaturaOcorrencia(listPessoas, listViaturas, pOcorrencia, qOcorrencia, pRegistros, qRegistros, listViaturasFinalizadas);
                } else {
                    return;
                }
                break;
                return;
            }

            aux = aux->prox;
        }
        if (!veriQuantOp1(quantPM)) {
            printf("Autorização de embarque negada!");
            return;
        }

        char **vet = (char**)calloc(quantPM, sizeof(char*));

        for (int i = 0; i < quantPM; i++) {
            vet[i] = (char*)malloc(50 * sizeof(char));
            printf("Identificação dos PMs %d: ", i + 1);
            scanf(" %[^\n]", vet[i]);
        }

        int newOp;
        
        printf("SPM - Viatura Login\n");
        printf("1 - Apto para atender ocorrência\n");
        printf("2 - Cancelar Embarcação\n");
        scanf("%d", &newOp);

        
        Viaturas *novo = (Viaturas*)malloc(sizeof(Viaturas));
        strcpy(novo->codigo, codeViatura);
        strcpy(novo->tipoViatura, "regular");
        novo->nomesPoliciais = (char**)malloc(quantPM * sizeof(char*));
        for (int i = 0; i < quantPM; i++) {
            novo->nomesPoliciais[i] = (char*)malloc(50 * sizeof(char));
            strcpy(novo->nomesPoliciais[i], vet[i]);
        }
        novo->numPoliciais = quantPM;
        novo->quantUso = 0;
        strcpy(novo->temBoletim, "false");
        addNewNode(listViaturas, novo);

        int caso;
        printf("1 - Prioritária\n");
        printf("2 - Não prioritária\n");
        scanf("%d", &caso);

        

        if (caso == 1) {
            enqueuePrioritaria(pPrioritaria, qPrioritaria, novo);
            comparaFila(pOcorrencia, pPrioritaria, listViaturas);
        } else {
            enqueueNormal(pNormal, qNormal, novo);
            comparaFila(pOcorrencia, pNormal, listViaturas);
        }

        Nodo* aux2 = listViaturas;

        while (aux2 != NULL) {
            Viaturas* verifi = (Viaturas*)aux2->item;

            if (verifi->usoAtual == true && strcmp(verifi->codigo, codeViatura) == 0) {
                strcpy(verifi->ocorrendo, "ocorrendo");
                printf("\nSPM - Viatura Chamada Policial\n");
                printf("Descrição: %s\n", verifi->descricao);
                printf("Localização: %s\n", verifi->localiza);
                printf("Confirmada ação polícial - 1  Ação Polícial Dispensada - 2\n");
                int op; scanf("%d", &op);
                if (op == 1) {
                  viaturaOcorrencia(listPessoas, listViaturas, pOcorrencia, qOcorrencia, pRegistros, qRegistros, listViaturasFinalizadas);
                } else {
                    return;
                }
                break;
                return;
            }
            aux2 = aux2->prox;
            
        }
        veriNeutro(listViaturas);
    } else if (op == 2) {
        getViaturaInfo(codeViatura, &quantPM);
        Nodo* aux = listViaturas;

        while (aux != NULL) {
            Viaturas* verifi = (Viaturas*)aux->item;

            if (verifi->usoAtual == true && strcmp(verifi->codigo, codeViatura) == 0) {
                strcpy(verifi->ocorrendo, "ocorrendo");
                printf("\nSPM - Viatura Chamada Policial\n");
                printf("Descrição: %s\n", verifi->descricao);
                printf("Localização: %s\n", verifi->localiza);
                printf("Confirmada ação polícial - 1  Ação Polícial Dispensada - 2\n");
                int op; scanf("%d", &op);
                if (op == 1) {
                  viaturaOcorrencia(listPessoas, listViaturas, pOcorrencia, qOcorrencia, pRegistros, qRegistros, listViaturasFinalizadas);
                } else {
                    return;
                }
                break;
                return;
            }

            aux = aux->prox;
        }

        if (!veriQuantOp2(quantPM)) {
            printf("Autorização de embarque negada!\n");
            return;
        }

        char **vet = (char**)calloc(quantPM, sizeof(char*));

        for (int i = 0; i < quantPM; i++) {
            vet[i] = (char*)malloc(50 * sizeof(char));
            printf("Identificação dos PMs %d: ", i + 1);
            scanf(" %[^\n]", vet[i]);
        }

        
        int newOp;
        printf("SPM - Viatura Login\n");
        printf("1 - Apto para atender ocorrência\n");
        printf("2 - Cancelar Embarcação\n");
        scanf("%d", &newOp);

        if (newOp == 2) return;

        Viaturas *novo = (Viaturas*)malloc(sizeof(Viaturas));
        strcpy(novo->codigo, codeViatura);
        strcpy(novo->tipoViatura, "regular");
        novo->nomesPoliciais = (char**)malloc(quantPM * sizeof(char*));
        for (int i = 0; i < quantPM; i++) {
            novo->nomesPoliciais[i] = (char*)malloc(50 * sizeof(char));
            strcpy(novo->nomesPoliciais[i], vet[i]);
        }
        novo->numPoliciais = quantPM;
        novo->quantUso = 0;
        strcpy(novo->temBoletim, "false");
        addNewNode(listViaturas, novo);
        enqueuePrioritaria(pPrioritaria, qPrioritaria, novo);
        comparaFila(pOcorrencia, pPrioritaria, listViaturas);

        Nodo* aux2 = listViaturas;
        int alt;
        while (aux2 != NULL) {
            Viaturas* verifi = (Viaturas*)aux2->item;

            if (verifi->usoAtual == true && strcmp(verifi->codigo, codeViatura) == 0) {

                strcpy(verifi->ocorrendo, "ocorrendo");
                printf("\nSPM - Viatura Chamada Policial");
                printf("Descrição: %s\n", verifi->descricao);
                printf("Localização: %s\n", verifi->localiza);
                printf("Confirmada ação polícial - 1  Ação Polícial Dispensada - 2\n");
                int op; scanf("%d", &op);
                if (op == 1) {
                    alt = 1;
                  viaturaOcorrencia(listPessoas, listViaturas, pOcorrencia, qOcorrencia, pRegistros, qRegistros, listViaturasFinalizadas);
                } else {
                    return;
                }
                break;
                return;
            }

            aux2 = aux2->prox;
        }
        if (alt == 1) return;
        else veriNeutro(listViaturas);
    } else {
        printf("Opção não existente!\n");
        return;
    }
}
