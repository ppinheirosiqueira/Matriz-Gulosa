#include "matriz.h"

void geraMatrizAleatoria(int matriz[][n], int n){
	srand(time(0));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			matriz[i][j] = rand() % 100;
		}
	}
}

void geraMatrizVazia(int matriz[][n], int n){

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			matriz[i][j] = 0;
		}
	}
}