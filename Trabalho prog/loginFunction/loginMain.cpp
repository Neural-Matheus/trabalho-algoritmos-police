#include <bits/stdc++.h>
#include "../structs/cad.h"


void encryptPassword(char *password) {
    int length = strlen(password);
    
    for (int i = 0; i < length; i++) {
        password[i] += 3;
    }
    
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

int loginInit(Nodo *listPoliciais, char patente[][20], int numPatentes) {
    Nodo *aux = listPoliciais;
    char nomeGuerra[100]; 

    printf("Digite o seu nome de guerra: ");   
    scanf(" %[^\n]", nomeGuerra);

    char senhaCripto[100];
    int nomeEncontrado = 0;
    
    while (aux != NULL) {
        if (strcasecmp(((Policiais*)aux->item)->nomeGuerra, nomeGuerra) == 0) {
            nomeEncontrado = 1;
            for (int i = 0; i < numPatentes; i++) {
                if (strcmp(patente[i], ((Policiais*)aux->item)->cargo) == 0) {
                    printf("Digite sua senha: ");
                    scanf(" %[^\n]", senhaCripto);

                    encryptPassword(senhaCripto); 

                    char senhaArquivo[100];
                    strncpy(senhaArquivo, ((Policiais*)aux->item)->senha, sizeof(senhaArquivo));
                    encryptPassword(senhaArquivo); 

                    if (strcmp(senhaArquivo, senhaCripto) == 0) {
                        return 1;  
                    } else {
                        return 0;
                    }
                }
            }
        }
        aux = aux->prox;
    }
    
    if (!nomeEncontrado) {
        return -1; 
    }

    return 0;
}
