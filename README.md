# Problema_Cavalo

Esse projeito foi feito com o intuito de ser apresentado no evento Unesp de Portas Abertas, edição de 2024, no curso de Bacharelado em Ciências da Computação do IGCE no campus de Rio Claro.

A ideia foi trazer uma desafio simples para instigar o raciocíonio dos participantes e então usá-lo para explicar de forma simples, conceitos que são usados na computação. Em especial, na computação competitiva, que é o interesse do grupo que apresentou.

O problema apresentado é explicado a seguir:

Um cavalo é colocado em um dos cantos de um tabuleiro de xadrez. O desafio consiste em dizer qual o menor número de movimentos necessários para que o cavalo passe por todos os outros três cantos, em sentido horário (ou anti-horário), e volte para a mesma posição onde iniciou.

Foram feitas duas soluções uma utilizado a métodos de BFS e a outra DFS, elas estão nomeadas conforme os respectivos métodos. Vale notar que o BFS é melhor para esse tipo de problema, chegando a dar solução até tabuleiros com mais de 10000X10000 posições. Enquanto o DFS resolve apenas até 150X150.
