#include "../lib/Mochila.hpp"

Mochila::Mochila(int qnt_cura, Pocao *_cura, int qnt_mana, Pocao *_mana, int qnt_stamina, Pocao *_stamina)
{
    for (int i = 0; i < qnt_cura; i++)
    {
        this->cura.push_back(_cura);
    }

    for (int i = 0; i < qnt_mana; i++)
    {
        this->mana.push_back(_mana);
    }

    for (int i = 0; i < qnt_stamina; i++)
    {
        this->stamina.push_back(_stamina);
    }
}

Mochila::Mochila()
{
}

void Mochila::adicionarItens(Pocao *Item, int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
        this->cura.push_back(Item);
    }

    for (int i = 0; i < qnt; i++)
    {
        this->mana.push_back(Item);
    }

    for (int i = 0; i < qnt; i++)
    {
        this->stamina.push_back(Item);
    }
}