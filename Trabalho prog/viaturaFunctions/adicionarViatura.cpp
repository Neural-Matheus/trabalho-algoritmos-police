#include <bits/stdc++.h>
#include "../structs/cad.h"
#include "../viaturaFunctions\verViatura.cpp"
#ifdef _WIN32
#define PATH_VIATURAS "bancoDados\\viaturas.txt"
#else
#define PATH_VIATURAS "bancoDados/viaturas.txt"
#endif

void addNewNode(Nodo* &list, void* item) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    novo->item = item;
    novo->prox = list;
    list = novo;
}

void saveViaturasToFile(Nodo* &listViaturasFull) {
    FILE* file = fopen(PATH_VIATURAS, "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    Nodo* current = listViaturasFull;
    while (current != NULL) {
        Viaturas* viatura = (Viaturas*)current->item;
        fprintf(file, "%04d\n%s\n", viatura->codigo, viatura->tipoViatura);
 
        fprintf(file, "\n");

        current = current->prox;
    }

    fclose(file);
    printf("Viatura adicionada com sucesso!\n");
}

void lerViaturasDoArquivo(Nodo* &listViaturas) {
    FILE* file = fopen(PATH_VIATURAS, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    int code;
    char tipoViatura[50];
    while (fscanf(file, "%d", &code) != EOF) {
        fgetc(file);

        if (fgets(tipoViatura, sizeof(tipoViatura), file) == NULL) {
            break;
        }
        tipoViatura[strcspn(tipoViatura, "\n")] = '\0';

        Viaturas* novaViatura = (Viaturas*)malloc(sizeof(Viaturas));
        novaViatura->codigo = code;
        strncpy(novaViatura->tipoViatura, tipoViatura, sizeof(novaViatura->tipoViatura));
        addNewNode(listViaturas, novaViatura);
    }
    fclose(file);
}

void viaturaLogin(Nodo* &listViaturas, Nodo* &listViaturasFull) {
    lerViaturasDoArquivo(listViaturasFull);
    printf("Polícia Regular - 1\n");
    printf("Polícia Especializada - 2\n");

    int op;
    scanf("%d", &op);

    int codeViatura;
    int quantPM;

    if (op == 1) {
        getViaturaInfo(&codeViatura, &quantPM);

        if (!veriQuantOp1(quantPM)) {
            printf("Autorização de embarque negada!");
            return;
        }

        char **vet = (char**)calloc(quantPM, sizeof(char*));

        for (int i = 0; i < quantPM; i++) {
            vet[i] = (char*)malloc(50 * sizeof(char));
            printf("Identificação dos PMs %d: ", i + 1);
            scanf(" %s", vet[i]);
        }

        int newOp;

        printf("SPM - Viatura Login\n");
        printf("1 - Apto para atender ocorrência\n");
        printf("2 - Cancelar Embarcação\n");
        scanf("%d", &newOp);

        if (newOp == 2) return;

        Viaturas *novo = (Viaturas*)malloc(sizeof(Viaturas));
        novo->codigo = codeViatura;
        strcpy(novo->tipoViatura, "regular");
        addNewNode(listViaturas, novo);
        saveViaturasToFile(listViaturas);


    } else if (op == 2) {
        getViaturaInfo(&codeViatura, &quantPM);

        if (!veriQuantOp2(quantPM)) {
            printf("Autorização de embarque negada!\n");
            return;
        }

        char **vet = (char**)calloc(quantPM, sizeof(char*));

        for (int i = 0; i < quantPM; i++) {
            vet[i] = (char*)malloc(50 * sizeof(char));
            printf("Identificação dos PMs %d: ", i + 1);
            scanf(" %s", vet[i]);
        }

        int newOp;
        
        printf("1 - Apto para atender ocorrência\n");
        printf("2 - Cancelar Embarcação\n");
        scanf("%d", &newOp);

        if (newOp == 2) return;

        Viaturas *novo = (Viaturas*)malloc(sizeof(Viaturas));
        novo->codigo = codeViatura;
        strcpy(novo->tipoViatura, "regular");
        addNewNode(listViaturas, novo);
        saveViaturasToFile(listViaturas);

    } else {
        printf("Opção não existente!\n");
        return;
    }
}
