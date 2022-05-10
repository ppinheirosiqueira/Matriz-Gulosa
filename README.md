Matriz Gulosa: Implementação em C
======

Exercício feito para a disciplina de Algoritmo e Estruturas de Dados I do curso de Engenharia de Computação do CEFET - MG, Campus V.

O exercício proposto era tal que:

Dada uma matriz NxN, onde N é uma entrada do programa, fossem realizados os seguintes passos:

1. Preenche-se a matriz com números inteiros positivos de 0 a 99;
2. Considere a posição Linha 0 e Coluna 0 como ínicio do programa;
3. Considere a posição Linha N e Coluna N como final do programa;
4. Percorra a Matriz a partir do ínicio, somando a cada passo, o próximo maior valor encontrado;
5. O próximo valor pode ser o que está na mesma linha e imediatamente à direita, imediatamente à esquerda, bem como, o que está na coluna abaixo do numero corrente;
```
5.1 - Há apenas uma exceção de percurso. Ao chegar na última linha deve-se percorre-la até o fim sem realizar mais migrações para colunas acima.
```
6. Andando na matriz conforme as regras acima, qual o maior caminho do início até o final, sabendo-se que a soma das posições representa o tamanho do caminho. 
