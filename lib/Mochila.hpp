#ifndef MOCHILA_H
#define MOCHILA_H

#include "../lib/Itens.hpp"
#include <vector>
class Mochila
{
public:

    std::vector<Pocao *> cura;
    std::vector<Pocao *> mana;
    std::vector<Pocao *> stamina;

    Mochila(int qnt_cura, Pocao *cura, int qnt_mana, Pocao *mana, int qnt_stamina, Pocao *stamina);
    Mochila();
    //Responsável por adicionar mais poções na Mochila;
    void adicionarItens(Pocao *Item, int qnt);
};

#endif