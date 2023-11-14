void menu(Nodo* &listViaturas, Nodo* &listViaturasFull, Nodo* &listPoliciais, Nodo* &listPessoas, Nodo* &listPessoasFull, Nodo* &listViaturasEmUso, Nodo* &pPrioritaria, Nodo* &qPrioritaria, Nodo* &pNormal, Nodo* &qNormal, Nodo* &listOcorrencias, Nodo* &pOcorrencia, Nodo* &qOcorrencia, Nodo* &listBoletim, Nodo* &pFilaRegistros, Nodo* &qFilaRegistros, Nodo* &listViaturasFinalizadas) {
    int i = -1;

    do {
        printf("\n\n");
        printf("SPM - Funcionalidades\n\n\n");
        printf("1 - Viatura Login       2 - Viatura em Uso\n");
        printf("3 - COPOM\n");
        printf("4 - Policia Militar\n");
        printf("5 - Oficial\n");
        printf("6 - Comandante Geral    0 - Encerrar Programa\n");

        scanf("%d", &i);
        
        if (i == 1) {
            viaturaLogin(listViaturas, listViaturasFull, pPrioritaria, qPrioritaria, pNormal, qNormal, listPessoas, listOcorrencias, pOcorrencia, qOcorrencia, pFilaRegistros, qFilaRegistros, listViaturasFinalizadas);
        }

        else if (i == 2) {
            viaturaEmUso(listViaturas, listPessoas, listViaturasFull, listViaturasEmUso, listOcorrencias, pOcorrencia, qOcorrencia, pFilaRegistros, qFilaRegistros, listViaturasFinalizadas);
        }

        else if (i == 3) {
            copomFun(listOcorrencias, listViaturas, pOcorrencia, qOcorrencia, pPrioritaria, pNormal, pFilaRegistros, qFilaRegistros);
        }

        else if (i == 4) {
            char patentes[][20] = {"Soldado", "Tenente", "Sargento"};

            int resul = loginInit(listPoliciais, patentes, 3);
            if (resul == 1) {
                printf("Senha correta!\n");
                addNewBoletin(listOcorrencias, listViaturas, listBoletim);
            } else {
                printf("Senha incorreta!\n");
            }
        } 

        else if (i == 5) {
            char patentes[][20] = {"Oficial"};
            int resul = loginInit(listPoliciais, patentes, 1);
            if (resul == 1) {
                printf("Senha correta!\n");
                excluirBoletimOficial(listBoletim);
            } else {
                printf("Senha incorreta!\n");
            }
        } 

        else if (i == 6) {
            char patentes[][20] = {"Comandante"};
            int resul = loginInit(listPoliciais, patentes, 1);
            if (resul == 1) {
                printf("Senha correta!\n");
                imprimirViaturas(listViaturasFinalizadas);
            } else {
                printf("Senha incorreta!\n");
            }
        }

    } while (i != 0);
}


int main() {
    Nodo *listViaturas = NULL;
    Nodo *listViaturasFull = NULL;
    Nodo *listViaturasEmUso = NULL;
    Nodo *listPoliciais = NULL;

    Nodo *listPessoas = NULL;
    Nodo *listPessoasFull = NULL;

    Nodo *pPrioritaria = NULL;
    Nodo *qPrioritaria = NULL;

    Nodo* pNormal = NULL;
    Nodo* qNormal = NULL;

    Nodo* listOcorrencias = NULL;
    Nodo* pOcorrencia = NULL; 
    Nodo* qOcorrencia = NULL;

    Nodo* listBoletim = NULL;
    Nodo* pFilaRegistros = NULL;
    Nodo* qFilaRegistros = NULL;

    Nodo* listViaturasFinalizadas = NULL;

    lerArquivoPessoas(listPessoas);
    lerPoliciaisDoArquivo(listPoliciais);
    

    menu(listViaturas, listViaturasFull, listPoliciais, listPessoas, listPessoasFull, listViaturasEmUso, pPrioritaria, qPrioritaria, pNormal, qNormal, listOcorrencias, pOcorrencia, qOcorrencia, listBoletim, pFilaRegistros, qFilaRegistros, listViaturasFinalizadas); 
    return 0;
}