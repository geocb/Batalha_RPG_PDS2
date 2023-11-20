#ifndef INTERFACE_H
#define INTERFACE_H

#include "../lib/Personagem.hpp"

Personagem Criar_Personagem(Classe *_Mago, Classe *_Guerreiro, Classe *_Ladino, Mochila *_Mochila);
// Cria um menu inicial
int menuInicial(); 
//Limpa a tela do terminal
void LimparTela();
//Faz uma pausa de 3 segundos
void Pausar();
//Função que faz o Jogador usar a Mochila
int usarMochila(Personagem *Jogador);
#endif