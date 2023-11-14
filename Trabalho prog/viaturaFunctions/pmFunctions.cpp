#include <bits/stdc++.h>
#include "../structs/cad.h"
#include "../arqV2.h"
#include "../arq.h"

#ifdef _WIN32
#define PATH_BOLETIM "bancoDados\\boletins.txt"
#else
#define PATH_BOLETIM "bancoDados/boletins.txt"
#endif

#ifdef _WIN32
#define PATH_OFICIO "bancoDados\\oficios_ocorrencias.txt"
#else
#define PATH_OFICIO "bancoDados/oficios_ocorrencias.txt"
#endif

void escreverBoletim(Boletim* boletim) {
   FILE* file = fopen(PATH_BOLETIM, "a");
   if (file == NULL) {
       printf("Erro ao abrir o arquivo.\n");
       return;
   }

   fprintf(file, "%s\n", boletim->boletimOco);

   // Fecha o arquivo
   fclose(file);
}

void addNewBoletin(Nodo* &listOcorrencias, Nodo* &listViaturas, Nodo* &listBoletim) {
   char nome[100];
   char boletim[10000];
   printf("Digite seu nome: ");
   scanf(" %[^\n]", nome);

   Nodo *auxVi = listViaturas;

   while (auxVi != NULL) {
       Viaturas *viatura = (Viaturas*)auxVi->item;

       for (int i = 0; i < viatura->numPoliciais; i++) {
           if (strcmp(viatura->nomesPoliciais[i], nome) == 0 && strcmp(viatura->temBoletim, "false") == 0) {
               printf("Nome encontrado na viatura: %s\n", viatura->codigo);
               printf("Digite o boletim: ");
               scanf(" %[^\n]", boletim);
               Boletim *novo = (Boletim*)malloc(sizeof(Boletim));
               strcpy(novo->boletimOco, boletim);
               Nodo *novoNodo = (Nodo*)malloc(sizeof(Nodo));
               novoNodo->item = novo;
               novoNodo->prox = listBoletim;
               listBoletim = novoNodo;
               escreverBoletim(novo);
               printf("Boletim adicionado com sucesso!\n");
               strcpy(viatura->temBoletim, "true");
               return;
           }
       }

       auxVi = auxVi->prox;
   }
}

void excluirBoletim(Nodo* &listBoletim, Boletim* boletim) {
   Nodo *aux = listBoletim;
   Nodo *prev = NULL;

   while(aux != NULL) {
       if(aux->item == boletim) {
           if(prev == NULL) {
               listBoletim = aux->prox;
           } else {
               prev->prox = aux->prox;
           }
           free(aux);
           return;
       }
       prev = aux;
       aux = aux->prox;
   }
}
void excluirBoletimOficial(Nodo* &listBoletim) {
   FILE* file = fopen(PATH_BOLETIM, "r+");
   if (file == NULL) {
       perror("Erro ao abrir o arquivo");
       return;
   }

   Nodo *aux = listBoletim;
   int op;

   while (aux != NULL) {
       Boletim *boletins = (Boletim*)aux->item;
       printf("Boletim: %s\n", boletins->boletimOco);
       printf("1 - Excluir\n");
       printf("2 - Ir para o próximo\n");
       scanf("%d", &op);

       if (op == 1) {
           // Exclui o boletim da lista em memória
           excluirBoletim(listBoletim, boletins);
           printf("Boletim excluído da lista em memória!\n");

           // Exclui o boletim do arquivo
           fseek(file, 0, SEEK_SET); // Volta para o início do arquivo
           FILE* tempFile = fopen("temp.txt", "w"); // Arquivo temporário para armazenar os boletins sem o excluído

           char boletimOco[10000]; // Supondo que MAX_SIZE é o tamanho máximo do boletim
           strcpy(boletimOco, boletins->boletimOco); // Cria uma cópia do boletim que você quer excluir

           while (fscanf(file, "%s", boletins->boletimOco) != EOF) {
               // Verifica se o boletim lido do arquivo é diferente do boletim excluído
               if (strcmp(boletins->boletimOco, boletimOco) != 0) {
                  fprintf(tempFile, "%s\n", boletins->boletimOco);
               }
           }

           fclose(file);
           fclose(tempFile);

           // Renomeia o arquivo temporário para o nome original
           remove(PATH_BOLETIM);
           rename("temp.txt", PATH_BOLETIM);

           printf("Boletim excluído do arquivo!\n");
           return; // Adicionado para sair do loop após excluir o boletim
       } 

       aux = aux->prox;
   }

   // Fecha o arquivo
   fclose(file);
}

void imprimirViaturas(Nodo* listViaturasFinalizadas) {
    Nodo *aux = listViaturasFinalizadas;
    FILE *file = fopen(PATH_OFICIO, "w");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (aux != NULL) {
        Viaturas *viatura = (Viaturas*)aux->item;

        fprintf(file, "Ocorrencias -\n");
        fprintf(file, "\tTipo Policia: %s.\n", viatura->tipoViatura);
        fprintf(file, "\tDescricao: %s - %s.\n", viatura->descricao, viatura->localiza);
        fprintf(file, "\tPoliciais:\n");

        for (int i = 0; i < viatura->numPoliciais; i++) {
            fprintf(file, "\t\t- %s;\n", viatura->nomesPoliciais[i]);
        }

        if (viatura->numPresos > 0) {
            fprintf(file, "\tPresos:\n");
            for (int i = 0; i < viatura->numPresos; i++) {
                fprintf(file, "\t\t- %s, %s;\n", viatura->presos[i]->nome, viatura->presos[i]->CPF);
            }
        }

        fprintf(file, "\n");
        aux = aux->prox;
    }

    fclose(file);
}