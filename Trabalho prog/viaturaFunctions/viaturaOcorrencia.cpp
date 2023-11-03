#include <bits/stdc++.h>
#include "../structs/cad.h"

#ifdef _WIN32
#define PATH_LOGSOCORRENCIAS "bancoDados\\logsOcorrencias.txt"
#else
#define PATH_LOGSOCORRENCIAS "bancoDados/logsOcorrencias.txt"
#endif

void pesquisaCPF(Nodo *listPessoas) {
    char busqCPF[13]; 
    int op;

    printf("SPM - Viatura: Pesquisar Por CPF\n");
    printf("CPF: ");
    scanf(" %12s", busqCPF); 

    Nodo *current = listPessoas;

    while (current != NULL && strcmp(((pessoa*)current->item)->CPF, busqCPF) != 0) {
        current = current->prox;
    }

    if (current != NULL) {
        printf("Nome: %s\n",  ((pessoa*)current->item)->nome);
        printf("CPF: %s\n", ((pessoa*)current->item)->CPF);

        printf("1 - Encerrar Visualização\n");
        scanf("%d", &op);
    } else {
        printf("Pessoa com CPF %s não encontrada na lista.\n", busqCPF);

        printf("1 - Encerrar Visualização\n");
        scanf("%d", &op);
    }
}
void solicitarReforco() {
    int op; 

    printf("SPM - Viatura:Solicitar Reforços\n");
    printf("1 - Confirmar Solicitação de Reforços\n");
    printf("2 - Cancelar\n");
    scanf("%d", &op);
    
    if (op == 1) {
        return;
    } else {
        return;
    }
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


void saveListToFile(Nodo* head) {
    FILE* file = fopen("PATH_LOGSOCORRENCIAS", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    Nodo* current = head;
    while (current != NULL) {
        struct ocorrenciaDP* ocorrencia = (struct ocorrenciaDP*)current->item;
        fprintf(file, "Quantidade: %d\n", ocorrencia->quant);
        for (int i = 0; i < ocorrencia->quant; i++) {
            fprintf(file, "CPF %d: %s\n", i + 1, ocorrencia->CPFs[i]);
        }
        fprintf(file, "\n");

        current = current->prox;
    }

    fclose(file);
}

Nodo* pesquisaCPFPri(Nodo *listPessoas, const char *busqCPF) {
    Nodo *current = listPessoas;

    while (current != NULL && strcmp(((pessoa*)current->item)->CPF, busqCPF) != 0) {
        current = current->prox;
    }

    return current;
}

void prisaoAndamento(Nodo* &listPessoas) {
    int quantCondu;

    printf("SPM - Viatura: Prisão em Andamento\n");
    printf("Indivíduo(s) conduzido(s) para DP: ");
    scanf("%d", &quantCondu);
    
    printf("CPFs:\n");

    char cpf[13];  
    Pessoa **presos = (Pessoa **) calloc(quantCondu, sizeof(Pessoa *));

    for (int i = 0; i < quantCondu; i++) {
        printf("CPF %d: ", i + 1);
        scanf(" %12s", cpf);

        Nodo *encontrado = pesquisaCPFPri(listPessoas, cpf);

        if (encontrado != NULL) {
            presos[i] = (Pessoa *)encontrado->item;
        } else {
            printf("Pessoa com CPF %s não encontrada na lista.\n");
            presos[i] = NULL; 
        }
    }

    for (int i = 0; i < quantCondu; i++) {
        if (presos[i] != NULL) {
            free(presos[i]);
        }
    }
    free(presos);
}

void viaturaOcorrencia(Nodo *listPessoas) {
    int op;

    printf("SPM - Viatura Ocorrência\n");
    printf("1 - Pesquisar por CPF\n");
    printf("2 - Solicitar Reforços\n");
    printf("3 - Prisão em Andamento\n");
    printf("4 - Encerrar Ocorrência\n");
    scanf("%d", &op);

    if (op == 1) {
        pesquisaCPF(listPessoas);
    } else if (op == 2) {
        solicitarReforco();
    } else if (op == 3) {
        prisaoAndamento(listPessoas);
    }
}
