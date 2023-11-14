#include <bits/stdc++.h>

void getViaturaInfo(char *codeViatura, int *quantPM) {
    printf("Código da viatura: ");
    scanf(" %[^\n]", codeViatura);
    printf("Quantidade de PMs: ");
    scanf("%d", quantPM);
}

int veriQuantOp1(int quantPM) {
    return (quantPM > 4 || quantPM < 2) ? 0 : 1;
}

int veriQuantOp2(int quantPM) {
    return (quantPM == 4) ? 1 : 0;
}
