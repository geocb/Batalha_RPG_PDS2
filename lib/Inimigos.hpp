#ifndef INIMIGOS_H
#define INIMIGOS_H

#include "../lib/Personagem.hpp"

class Inimigos : public Personagem
{
private:
public:
    Inimigos(std::string _nome, Classe *_classe);

    //Vai de "_1" até "_4". É o método responsável por indicar e printar na tela qual ataque está sendo utilizado pelo Boss final;
    int Ataque_1();
    int Ataque_2();
    int Ataque_3();
    int Ataque_4();
};

#endif
