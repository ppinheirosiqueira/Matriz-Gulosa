#include "matriz.h"
#include "movimentacao.h"
#include <locale.h>

int main(){

	setlocale(LC_ALL,"portuguese");
	
    int LinhaAtual = 0;
	int ColunaAtual = 0;
    int CustoTotal = 0;
    // Auxiliares para saber os movimentos possíveis e os valores destes movimentos
	int movs[3][2];
    int valores[3];
    
    // Gerando a Matriz
	printf("Digite a dimenção da matriz: \n");
	scanf("%d", &n);

	printf("\n----------------------------\n\n");	
	int matriz[n][n];
	int caminho[n][n];
	
	geraMatrizAleatoria(matriz,n);
	geraMatrizVazia(caminho,n);

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}

	caminho[0][0] = 1;

    printf("\n----------------------------\n\n");
	
    // Escolhendo qual movimento ocorrerá caso dois valores sejam iguais
	int preferencia[2] = {0,0};
	int escPre;
	int auxPre = 0;
	printf("Por padrão o movimento em caso de dois valores iguais sempre será para baixo (ou direita se os valores iguais forem da mesma linha).\n");
	printf("No entanto, você pode escolher outra ordem de prioridade.\n");
	printf("Digite 0 para permanecer no padrão. Digite 1 para escolher o seu próprio padrão.\n");
	scanf("%d",&escPre);
	while(escPre != 0 && escPre != 1){
		printf("Digite 0 para permanecer no padrão. Digite 1 para escolher o seu próprio padrão.\n");
		scanf("%d",&escPre);
	}
	
	printf("\n----------------------------\n\n");	
	
	if(escPre == 1){
		printf("Digite os números na ordem que você deseja que o movimento ocorra.\n");
		printf("Sendo:\n0 - Para Esquerda\n1 - Para Direita\n2 - Para Baixo\n3 - Randomico (caso queira randomicamente, colocar logo no primeiro valor):\n");
		while (auxPre < 2){
			scanf("%d",&preferencia[auxPre]);
			if(preferencia[auxPre] == 3 && auxPre == 0){
				auxPre = 2;
			}
			while(preferencia[auxPre] == 3 && auxPre > 0){
				printf("Colocasse randomicamente primeiro se era o seu desejo, por favor, coloque outro valor:\n");
				scanf("%d",&preferencia[auxPre]);
			}
			auxPre++;
		}
		printf("\n----------------------------\n\n");	
	}

    // Agora sim começar a andar em si
    while (caminho[n-1][n-1] == 0){

        // Checar possíveis movimentos
        checkMov(movs, LinhaAtual, ColunaAtual, n, caminho);

        checkValor(valores, movs, matriz);

        // Movimentar em si
        movimentar(valores, movs, caminho, escPre, preferencia, &LinhaAtual, &ColunaAtual);
    }

    for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			printf("%d ",matriz[i][j]);
		}
		printf(" | ");
		for (int j = 0; j < n; ++j){
			printf("%d ",caminho[i][j]);
		}
		printf("\n");
	}

	printf("\n----------------------------\n\n");

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            CustoTotal = CustoTotal + matriz[i][j]*caminho[i][j];
        }
    }
    printf("O custo total do caminho foi: %d\n", CustoTotal);

    return 0;
}