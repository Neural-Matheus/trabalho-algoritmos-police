#include <bits/stdc++.h>
#include "../structs/cad.h"



void pesquisaCPF(Nodo *listPessoas) {
    char busqCPF[13];
    int op;

    printf("SPM - Viatura: Pesquisar Por CPF\n");
    printf("CPF: ");
    scanf(" %[^\n]", busqCPF);


    Nodo *current = listPessoas;

    while (current != NULL && strcasecmp(((Pessoa *)current->item)->CPF, busqCPF) != 0) {
        current = current->prox;
    }

    if (current != NULL) {
        printf("Nome: %s\n", ((Pessoa *)current->item)->nome);
        printf("CPF: %s\n", ((Pessoa *)current->item)->CPF);
        printf("Cidade: %s\n", ((Pessoa *)current->item)->cidade);
        printf("Passagens pela polícia: %d\n", ((Pessoa *)current->item)->passagensPolicia);

        for (int i = 0; i < ((Pessoa *)current->item)->nInadimplencias; ++i) {
            printf("Inadimplência %d: %s\n", i + 1, ((Pessoa *)current->item)->inadimplencias[i]);
        }

        printf("1 - Encerrar Visualização\n");
        scanf("%d", &op);
    } else {
        printf("Pessoa com CPF %s não encontrada na lista.\n", busqCPF);

        printf("1 - Encerrar Visualização\n");
        scanf("%d", &op);
        return;
    }
    return;
}

void solicitarReforco(Nodo* &listViaturas, Nodo* &pOcorrencias) {
    printf("SPM - Viatura: Solicitar Reforços\n");

    Nodo* currentViatura = listViaturas;

    while (currentViatura != NULL) {
        Viaturas* viatu = (Viaturas*)currentViatura->item;

        // Atende ao pedido de reforço apenas se a viatura estiver em estado neutro
        if (viatu != NULL && strcmp(viatu->estadoAtual, "neutro") == 0) {
            // Mostra detalhes do pedido de reforço
            printf("Pedido de Reforço:\n");
            printf("Descrição: %s\n", viatu->descricao);
            printf("Localização: %s\n", viatu->localiza);

            int op;
            printf("1 - Confirmar Solicitação de Reforço\n");
            printf("2 - Cancelar\n");
            scanf("%d", &op);

            if (op == 1) {
                // Atualiza o estado da viatura para "reforço"
                strcpy(viatu->estadoAtual, "neutro");

                printf("Pedido de reforço atendido pela viatura %s\n", viatu->codigo);
            } else {
                printf("Pedido de reforço cancelado.\n");
            }
        }

        currentViatura = currentViatura->prox;
    }
    return;
}



void addToList(Nodo** head, void* item) {
    Nodo* newNode = (Nodo*)malloc(sizeof(Nodo));
    if (newNode == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    newNode->item = item;
    newNode->prox = *head;
    *head = newNode;
}



Nodo* pesquisaCPFPri(Nodo *listPessoas, const char *busqCPF) {
    Nodo *current = listPessoas;

    while (current != NULL && strcmp(((pessoa*)current->item)->CPF, busqCPF) != 0) {
        current = current->prox;
    }

    return current;
}

void prisaoAndamento(Nodo* &listPessoas, Nodo* &listViaturas) {
    int quantCondu;

    printf("SPM - Viatura: Prisão em Andamento\n");
    printf("Indivíduo(s) conduzido(s) para DP: ");
    scanf("%d", &quantCondu);
    
    printf("CPFs:\n");

    char cpf[13];  
    Pessoa **presos = (Pessoa **) calloc(quantCondu, sizeof(Pessoa *));

    for (int i = 0; i < quantCondu; i++) {
        printf("CPF %d: ", i + 1);
        scanf(" %[^\n]", cpf);

        Nodo *encontrado = pesquisaCPFPri(listPessoas, cpf);

        if (encontrado != NULL) {
            presos[i] = (Pessoa *)encontrado->item;
        } else {
            printf("Pessoa com CPF %s não encontrada na lista.\n", cpf);
            presos[i] = NULL; 
        }
    }

    // Adiciona os presos à viatura
    Nodo *currentViatura = listViaturas;
    while (currentViatura != NULL) {
        Viaturas* viatu = (Viaturas*)currentViatura->item;
        if (strcmp(viatu->estadoAtual, "em ocorrência") == 0) {
            viatu->presos = presos;
            viatu->numPresos = quantCondu;
            break;
        }
        currentViatura = currentViatura->prox;
    }

    printf("Presos:\n");
    for (int i = 0; i < quantCondu; i++) {
        if (presos[i] != NULL) {
            printf("\t- %s, %s;\n", presos[i]->nome, presos[i]->CPF);
        }
    }
}

void viaturaOcorrencia(Nodo* &listPessoas, Nodo* &listViaturas, Nodo* &pOcorrencias, Nodo* &qOcorrencias, Nodo* &pLogRegistro, Nodo* &qLogRegistro, Nodo* &listViaturasFinalizadas) {
    int op;

    printf("SPM - Viatura Ocorrência\n");
    printf("1 - Pesquisar por CPF\n");
    printf("2 - Solicitar Reforços\n");
    printf("3 - Prisão em Andamento\n");
    printf("4 - Encerrar Ocorrência\n");
    scanf("%d", &op);

    Nodo* aux = listViaturas;
    Nodo* auxv2 = listPessoas;

    while (aux != NULL) {
        Viaturas* verifi = (Viaturas*)aux->item;

        if (strcmp(verifi->estadoAtual, "em ocorrência") == 0) {
            if (op == 1) {
                strcpy(verifi->estadoAtual, "pesquisando CPF.");
                pesquisaCPF(listPessoas);
            } else if (op == 2) {
                strcpy(verifi->estadoAtual, "solicitando reforços.");
                solicitarReforco(listViaturas, pOcorrencias);
            } else if (op == 3) {
                strcpy(verifi->estadoAtual, "prisão em andamento.");
                prisaoAndamento(listPessoas, listViaturas);
            } else if (op == 4) {
                strcpy(verifi->estadoAtual, "finalizada.");
                strcpy(verifi->ocorrendo, "acabada");
                verifi->usoAtual = false;
                encerrarOcorrencia(pOcorrencias, qOcorrencias, listViaturas, listViaturasFinalizadas, verifi->codigo, verifi->tipoViatura);

                strcpy(verifi->estadoAtual, "neutro");
                return;
            }
        }

        aux = aux->prox;
    }

}
