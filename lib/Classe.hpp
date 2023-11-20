#ifndef CLASSE_H
#define CLASSE_H

#include <iostream>
class Classe
{
private:
    std::string nome_da_classe;
    int Multiplicador_INT, Multiplicador_FOR, Multiplicador_CON, Multiplicador_DES; //Multiplicadores de atributos

public:
    Classe(std::string _nome_da_classe);
    Classe();

    // Vai de "_1" até "_4". É o método responsável por indicar e printar na tela qual ataque está sendo utilizado;

    int Ataque_1();
    int Ataque_2();
    int Ataque_3();
    int Ataque_4();

    // Getter e Setters
    int getMINT();
    int getMDES();
    int getMFOR();
    int getMCON();

    // Lista todos os ataques da classe escolhida;
    void listarAtaques();
    std::string getNome();
};

#endif
