#include "movimentacao.h"


void checkMov(int movs[3][2], int linha, int coluna, int n, int caminho[][n]){
	// Indo para a Esquerda
	movs[0][0] = linha;
	movs[0][1] = coluna - 1;
	// Indo para a Direita
	movs[1][0] = linha;
	movs[1][1] = coluna + 1;
	// Indo para Baixo
	movs[2][0] = linha + 1;
	movs[2][1] = coluna;

	// Checando se os movimentos de Direita e Esquerda já ocorreram
	if (caminho[movs[0][0]][movs[0][1]] == 1){
		movs[0][0] = -1;
	}
	if (caminho[movs[1][0]][movs[1][1]] == 1){
		movs[1][0] = -1;
	}

	// Checando se bateu na última linha
	if (movs[2][0] == n){
		movs[2][0] = -1;
		// E se bateu, o único movimento possível é ir para a direita
		movs[0][0] = -1;
	}
    else if (movs[0][1] < 0){ // Checando se o movimento da Esquerda é válido
		movs[0][0] = -1;
	}	
    else if (movs[1][1] == n){ // Checando se o movimento da Direita é válido
		movs[1][0] = -1;
	}
}

void checkValor(int valores[3], int movs[3][2], int matriz[][n]){
    for (int i = 0; i < 3; ++i){
        if (movs[i][0] != -1){
            valores[i] = matriz[movs[i][0]][movs[i][1]];
        }
        else{ // Se o movimento for inválido, atribuir -1 é um bom parâmetro, dado que é um algoritmo guloso onde o menor valor possível é 0. 
            valores[i] = -1;
        }
    }
}

void movimentar(int valores[3], int movs[3][2], int caminho[][n], int escolha, int preferencia[2], int* linha, int* coluna){
    int maior = 0;
    int aux = 1; // Sempre existirá pelo menos 1 movimento possível
    int auxRand;

    for (int i = 1; i < 3; ++i){
        if (valores[i] > valores[maior]){
            maior = i;
            aux = 1;
        }
        else if (valores[i] == valores[maior] && valores[maior] != -1){
            aux++; //Se houver outro valor que empata com o maior, então temos um conflito de opções
        }
    }
    if (aux == 1){ // Ou seja, não existe um conflito entre dois valores maiores iguais
        caminho[movs[maior][0]][movs[maior][1]] = 1;
        *linha = movs[maior][0];
        *coluna = movs[maior][1];
    }
    else{
        if(escolha == 0){ // Se a pessoa escolheu seguir o padrão
            if(valores[2] == valores[maior]){ // Checar se o valor indo para baixo é o maior
                caminho[movs[2][0]][movs[2][1]] = 1;
                *linha = movs[2][0];
                *coluna = movs[2][1];
            }
            else{ // Se o para baixo não for o maior, ir para a direita
                caminho[movs[1][0]][movs[1][1]] = 1;
                *linha = movs[1][0];
                *coluna = movs[1][1];
            }
        }
        else{ // Se a pessoa escolheu um padrão próprio
            if (preferencia[0] != 3){ // Se o Padrão dela não for randomico
                if(valores[preferencia[0]] == valores[maior]){ 
                    caminho[movs[preferencia[0]][0]][movs[preferencia[0]][1]] = 1;
                    *linha = movs[preferencia[0]][0];
                    *coluna = movs[preferencia[0]][1];
                }
                else{
                    caminho[movs[preferencia[1]][0]][movs[preferencia[1]][1]] = 1;
                    *linha = movs[preferencia[1]][0];
                    *coluna = movs[preferencia[1]][1];
                }
            }
            else{
                srand(time(0));
                auxRand = rand() % aux; // O randomico pode dar 0, 1 ou 2 dependendo de existirem 2 ou 3 valores iguais

                if(valores[auxRand] != valores[maior]){ // Se o valor já sorteado não for o maior, somar 1
                    auxRand++; 
                    // Se os maiores forem 1 e 2, e o rand cair 0, com a soma iria para o 1
                    // Se os maiores forem 0 e 2 e o rand cair 1, com a soma iria para o 2
                    // Se os maiores forem 0 e 1, não tem como o rand cair 2, pois o aux seria 2, o que faria o auxRand ser no máximo 1
                    // Se os maiores forem os 3, então é impossível entrar no if
                }

                caminho[movs[auxRand][0]][movs[auxRand][1]] = 1;
                *linha = movs[auxRand][0];
                *coluna = movs[auxRand][1];
                
            }
        }
    }
}