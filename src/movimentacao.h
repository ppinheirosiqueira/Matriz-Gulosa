#ifndef MOVIMENTACAO_H 
#define MOVIMENTACAO_H

#include "matriz.h"

void checkMov(int movs[3][2], int linha, int coluna, int n, int caminho[][n]);
void checkValor(int valores[3], int movs[3][2], int matriz[][n]);
void movimentar(int valores[3], int movs[3][2], int caminho[][n], int escolha, int preferencia[2], int* linha, int* coluna);

#endif