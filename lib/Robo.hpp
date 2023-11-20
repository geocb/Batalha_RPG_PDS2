#ifndef ROBO_H
#define ROBO_H

#include <cstdlib>
#include <ctime>
#include "../lib/Inimigos.hpp"

//retorna um número aleatório entre o menor e o maior número indicados;
int numeroAleatorio(int menor, int maior);
// Faz a máquina ter a sua vez na jogada;
void TurnoRobo(Inimigos *_inimigo, Personagem *_jogador);

#endif