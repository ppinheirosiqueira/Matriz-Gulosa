# Matriz Gulosa: Implementação em C

Exercício feito para a disciplina de Algoritmo e Estruturas de Dados I do curso de Engenharia de Computação do CEFET - MG, Campus V.

O exercício proposto era tal que:

Dada uma matriz NxN, onde N é uma entrada do programa, fossem realizados os seguintes passos:

1. Preenche-se a matriz com números inteiros positivos de 0 a 99;
2. Considere a posição Linha 0 e Coluna 0 como ínicio do programa;
3. Considere a posição Linha N e Coluna N como final do programa;
4. Percorra a Matriz a partir do ínicio, somando a cada passo, o próximo maior valor encontrado;
5. O próximo valor pode ser o que está na mesma linha e imediatamente à direita, imediatamente à esquerda, bem como, o que está na coluna abaixo do numero corrente, sem a opção de voltar;
   * Há apenas uma exceção de percurso. Ao chegar na última linha deve-se percorre-la até o fim sem realizar mais migrações para colunas acima.
6. Andando na matriz conforme as regras acima, qual o maior caminho do início até o final, sabendo-se que a soma das posições representa o tamanho do caminho. 

Como exemplo nos foi passado a imagem abaixo.

![exemplo]

[exemplo]: https://github.com/ppinheirosiqueira/Matriz-Gulosa/blob/main/images/matriz.png "Exemplo de Resolução"

## Entradas

Com o exercício proposto, se torna necessário que a entrada primária do problema precisa ser um Inteiro Positivo, pois esta entrada determina o tamanho da matriz, sendo então impossível que tal valor seja negativo ou nulo.

Além desta entrada, outra(s) é(são) requisitada(s) ao usuário, sendo a terceira/quarta dependente da resposta da segunda. Estas entradas são necessárias para que o Usuário escolha o que o algoritmo irá fazer caso exista um conflito, ou seja, que durante a execução do algoritmo exista algum momento que exista duas (sendo estas maiores que a terceira) ou três opções de mesmo valor, como demonstrado no exemplo abaixo.

![exemplo2]

[exemplo2]: https://github.com/ppinheirosiqueira/Matriz-Gulosa/blob/main/images/Opcoes-Iguais.png "Exemplo de Conflito"

Esta segunda entrada é um mero valor de 0 ou 1, onde ao escolher 0, o Usuário permite que esta decisão ocorra pelo padrão do algoritmo, que é para baixo ou direita (se baixo não for uma opção no movimento específico).

Caso escolha criar seu próprio padrão, o usuário poderá escolher entre esquerda, direita, baixo ou que seja randomica a seleção do próximo número.

## Implementação 

Apesar da entrada dependente do usuário, o exercício foi proposto sem a utilização de Malloc, tornando necessária a utilização de uma pequena gambiarra, ao declarar o inteiro N no source (matriz.h). Com exceção deste detalhe, os outros pontos de implementação foram mais básicos.

Para a criação da matriz foi feito utilizando valores rândomicos criados por uma seed dependente do tempo atual, para a cada execução conseguirmos valores diferentes. Além da criação da matriz principal, também é criada uma matriz nula de mesmo tamanho. Esta matriz será preenchida com o caminho realizado pelo programa.

Com o intuito de percorrer a matriz foram utilizados auxiliares, sendo estes dois inteiros, um vetor de inteiros de três posições e uma matriz de inteiros de 3x2. Os dois inteiros iniciais representam a linha e coluna atual, ou seja, eles que determinarão quando o código irá parar de rodar, ao chegar em NxN. A matriz de inteiros possuirá as coordenadas para os três possíveis movimentos que são idealizados no problema. O vetor de inteiros de três posições possui o valor desses três possíveis movimentos. 

O programa consiste em um loop, onde:
* São verificados os três movimentos possíveis;
    * O vetor de movimentos é preenchido ao se subtrair e somar 1 da Coluna Atual e mantendo a Linha Atual, e também somar 1 para a Linha Atual, deixando a Coluna Atual.
* É feita a verificação se estes movimentos podem ser realizados:
    * Checando se o movimento não fará bater em nenhum limite lateral ou inferior;
    * Que não está indo para um ponto que já foi percorrido;
    * Que não está na última linha, pois, caso esteja, o único movimento permitido é o para a direita.
* De posse dos movimentos possíveis e realizáveis, são coletados os valores destes movimentos;
* Tais valores são comparados;
    * Caso possua conflito entre os maiores valores, é feita a decisão de qual movimento será feito pelo padrão escolhido pelo Usuário;
*  O movimento é feito para este valor maior;
*  A linha ou coluna é atualizada;
*  O valor na matriz de caminho é atualizado;
*  Checagem de ter chegado ao NxN;
   *  Retorno ao começo do loop ou final do loop.

Ao chegar em NxN, tanto as matrizes inicial quanto de caminho são mostradas, bem como o custo total adquirido pelo algoritmo.

# Compilação e Execução

O exercício disponibilizado possui um arquivo Makefile cedido pelo professor que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |