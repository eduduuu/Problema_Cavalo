/* PROBLEMA DO CAVALO
   Um cavalo é colocado em um dos cantos de um tabuleiro de xadrez.
   O desafio consiste em dizer qual o menor número de movimentos necessários
   para que o cavalo passe por todos os outros três cantos, em sentido horário,
   e volte para a mesma posição onde iniciou.

   Para relembrar, um cavalo que está na posição C, pode se mover para
   qualquer um dos *, desde que esteja dentro do tabuleiro:

   . . . . . . .
   . . * . * . .
   . * . . . * .
   . . . C . . .
   . * . . . * .
   . . * . * . .
   . . . . . . . 

   Observação: como o tabuleiro é simétrico, é necessário apenas saber a quantidade
   de movimentos para um canto mais próximo e então multiplicar por quatro.
   Pois os movimentos podem ser refletidos.
*/

#include <iostream>
#include <climits>
#include <queue>
#define TAMANHO_TABULEIRO 10000

using namespace std;

long long int posicao_visitada[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

struct Estado {
    long long int x, y, movimentos;
};


bool valido(int x, int y) {
    return (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO);
}

int busca(int i, int j) {
    queue<Estado> lista;

    lista.push({0, 0, 0});
    posicao_visitada[0][0] = 1;

    while (!lista.empty()) {
        Estado atual = lista.front();
        lista.pop();

        if (atual.y == 0 && atual.x == TAMANHO_TABULEIRO-1) 
            return atual.movimentos;

        if (valido(atual.x+1, atual.y-2) && posicao_visitada[atual.x+1][atual.y-2] == 0) {
            posicao_visitada[atual.x+1][atual.y-2] = 1;
            lista.push({atual.x+1, atual.y-2, atual.movimentos+1});
        }
        if (valido(atual.x+1, atual.y+2) && posicao_visitada[atual.x+1][atual.y+2] == 0) {
            posicao_visitada[atual.x+1][atual.y+2] = 1;
            lista.push({atual.x+1, atual.y+2, atual.movimentos+1});
        }
        if (valido(atual.x-1, atual.y-2) && posicao_visitada[atual.x-1][atual.y-2] == 0) {
            posicao_visitada[atual.x-1][atual.y-2] = 1;
            lista.push({atual.x-1, atual.y-2, atual.movimentos+1});
        }
        if (valido(atual.x-1, atual.y+2) && posicao_visitada[atual.x-1][atual.y+2] == 0) {
            posicao_visitada[atual.x-1][atual.y+2] = 1;
            lista.push({atual.x-1, atual.y+2, atual.movimentos+1});
        }
        if (valido(atual.x+2, atual.y-1) && posicao_visitada[atual.x+2][atual.y-1] == 0) {
            posicao_visitada[atual.x+2][atual.y-1] = 1;
            lista.push({atual.x+2, atual.y-1, atual.movimentos+1});
        }
        if (valido(atual.x+2, atual.y+1) && posicao_visitada[atual.x+2][atual.y+1] == 0) {
            posicao_visitada[atual.x+2][atual.y+1] = 1;
            lista.push({atual.x+2, atual.y+1, atual.movimentos+1});
        }
        if (valido(atual.x-2, atual.y-1) && posicao_visitada[atual.x-2][atual.y-1] == 0) {
            posicao_visitada[atual.x-2][atual.y-1] = 1;
            lista.push({atual.x-2, atual.y-1, atual.movimentos+1});
        }
        if (valido(atual.x-2, atual.y+1) && posicao_visitada[atual.x-2][atual.y+1] == 0) {
            posicao_visitada[atual.x-2][atual.y+1] = 1;
            lista.push({atual.x-2, atual.y+1, atual.movimentos+1});
        }
    }
    
    return INT16_MAX;

}


int main() {
   // Os loops definem os valores em cada posição do tabuleiro como não visitado
   // e os melhores caminhos até cada posição como um número arbitrariamente grande
   // para a comparação posterior.
   for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
      for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
         posicao_visitada[i][j] = 0;
      }
   }

   cout << busca(0, 0)*4;

   return 0;
}