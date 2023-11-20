#ifndef TURNO_H
#define TURNO_H

#include "../lib/Inimigos.hpp"

// Coloca o inimigo e o jogador para lutarem;
void Luta(Inimigos *_inimigo, Personagem *_jogador);
//Confere se o jogador e o inimigo já foram derrotados;
void ConferirVida(Inimigos *_inimigo, Personagem *_jogador);
//Função que controla entre cada batalha de inimigos;
void EntreTurnos(Personagem *_jogador);
//Função que leva para a batalha contra o último inimigo;
void LutaFinal(Inimigos *_inimigo, Personagem *_jogador);

#endif
