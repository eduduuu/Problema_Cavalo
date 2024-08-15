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

   Solução:
   construir recursivamente todos os caminhos recursivamente, guardando a
   melhor quantidade entre eles.
   Algumas observaçoes foram feitas para otimização. Sem elas o programa
   demoraria muito mais tempo para ser executado. Elas são:
   
   * Finalizar o caminho se a posição atual for o próximo canto. Não há necessidade
   de continuar, pois já chegamos no objetivo.
   
   * Armazenar o melhor caminho até certa posição. Pois, se em outra possibilidade
   de caminho, ocorrer de chegar em uma posição que já foi visitada em outro caminho e
   a distância atual for maior, não vale a pena continuar. Afinal, existe um caminho melhor.
*/


#include <iostream>
#include <climits>
#define TAMANHO_TABULEIRO 8

using namespace std;

int posicao_visitada[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; 
int menos_movimentos_posicao[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
int menos_movimentos = INT16_MAX;

// i e j são a posição no tabuleiro e quantidade é a quantidade
// de movimentos no caminho atual
int busca(int i, int j, int quantidade) {
   // Se está na posição de destino, retorna a quantidade de movimentos
   // até ela nesse caminho
    if (i == TAMANHO_TABULEIRO-1 && j == 0) {
        menos_movimentos = min(menos_movimentos, quantidade);
        return quantidade;
    }

   // Retorna se a posição atual já foi visitada
    if(posicao_visitada[i][j] == 1)
        return quantidade;

   // Retorna se já foi descoberto outro caminho melhor
   // até a posição atual
   if (quantidade >= menos_movimentos_posicao[i][j])
      return quantidade;

   // Define a menor quantidade de movimentos até a posição atual.
   // Esse é o melhor caminho para ela até o momento
   menos_movimentos_posicao[i][j] = quantidade;

   // Variável para comparação entre os melhores caminhos orininados
   // na posição atual
   int q = quantidade;

   // Define a posição atual como visitada
   posicao_visitada[i][j] = 1;

   // Cada condicional checa se as posições para as quais o cavalo pode ir
   // segundo a regra estão dentro do tabuleiro. Caso sim, inicia uma nova
   // busca nela, com a quantidade de movimentos até ela sendo a atual mais um
   if (i < TAMANHO_TABULEIRO-1 && j > 1)
      q =  min(busca (i+1, j-2, quantidade+1), q);
   if (i < TAMANHO_TABULEIRO-1 && j < TAMANHO_TABULEIRO-2)
      q =  min(busca (i+1, j+2, quantidade+1), q);
   if (i > 0 && j > 1)
      q =  min(busca (i-1, j-2, quantidade+1), q);
   if (i > 0 && j < TAMANHO_TABULEIRO-2)
      q =  min(busca (i-1, j+2, quantidade+1), q);
   if (i < TAMANHO_TABULEIRO-2 && j > 0)
      q =  min(busca (i+2, j-1, quantidade+1), q);
   if (i < TAMANHO_TABULEIRO-2 && j < TAMANHO_TABULEIRO-1)
      q =  min(busca (i+2, j+1, quantidade+1), q);
   if (i > 1 && j > 0)
      q =  min(busca (i-2, j-1, quantidade+1), q);
   if (i > 1 && j < TAMANHO_TABULEIRO-1)
      q =  min(busca (i-2, j+1, quantidade+1), q);

   // Define a posição atual como não visitada para caso haja melhores
   // caminhos até ela
   posicao_visitada[i][j] = 0;

   // retorna a menor quantidade da posição atual até o canto de destino
   return q;
}


int main() {
   // Os loops definem os valores em cada posição do tabuleiro como não visitado
   // e os melhores caminhos até cada posição como um número arbitrariamente grande
   // para a comparação posterior.
   for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
      for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
         posicao_visitada[i][j] = 0;
         menos_movimentos_posicao[i][j] = INT16_MAX;
      }
   }

   // Inicia a busca no canto de origem
   busca(0, 0, 0);

   // Não há caminhos se a quantidade de movimentos não mudou.
   // (caso o tamnho do tabuleiro seja 1 ou 2, por exemplo)
   // No contrário. A resposta final é a menor quantidade de movimentos
   // multiplicada por quatro
   if (menos_movimentos == INT16_MAX) cout << 0;
   else cout << menos_movimentos*4;

   return 0;
}
