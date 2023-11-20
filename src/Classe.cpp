#include "../lib/Classe.hpp"

Classe::Classe(std::string nome_da_classe)
{
    if (nome_da_classe == "Mago")
    {
        this->nome_da_classe = nome_da_classe;
        this->Multiplicador_INT = 3;
        this->Multiplicador_CON = 2;
        this->Multiplicador_DES = 2;
        this->Multiplicador_FOR = 1;
    }
    else if (nome_da_classe == "Guerreiro")
    {
        this->nome_da_classe = nome_da_classe;
        this->Multiplicador_INT = 1;
        this->Multiplicador_CON = 3;
        this->Multiplicador_DES = 2;
        this->Multiplicador_FOR = 2;
    }
    else if (nome_da_classe == "Ladino")
    {
        this->nome_da_classe = nome_da_classe;
        this->Multiplicador_INT = 1;
        this->Multiplicador_CON = 2;
        this->Multiplicador_DES = 3;
        this->Multiplicador_FOR = 2;
    }
    else
    {
        std::cout << "Classe não Encontrada" << std::endl;
    }
};

Classe::Classe()
{
    this->nome_da_classe = "";
    this->Multiplicador_INT = 0;
    this->Multiplicador_CON = 0;
    this->Multiplicador_DES = 0;
    this->Multiplicador_FOR = 0;
};

void Classe::listarAtaques()
{
    if (this->nome_da_classe == "Mago")
    {
        std::cout << "1 - Ataque Básico" << std::endl
                  << "2 - Raio" << std::endl
                  << "3 - Geada" << std::endl
                  << "4 - Bola de Fogo" << std::endl
                  << "5 - Usar Mochila" << std::endl;
    }
    else if (this->nome_da_classe == "Guerreiro")
    {
        std::cout << "1 - Ataque Básico" << std::endl
                  << "2 - Ataque Forte" << std::endl
                  << "3 - Dança das Espadas" << std::endl
                  << "4 - Espadada Fatal" << std::endl
                  << "5 - Usar Mochila" << std::endl;
    }
    else if (this->nome_da_classe == "Ladino")
    {
        std::cout << "1 - Ataque Básico" << std::endl
                  << "2 - Ataque Furtivo" << std::endl
                  << "3 - Estrangulamento" << std::endl
                  << "4 - Adaga Cortante" << std::endl
                  << "5 - Usar Mochila" << std::endl;
    }
    else
    {
        std::cout << "Classe não Encontrada" << std::endl;
    }
}

int Classe::Ataque_1()
{
    std::cout << "utilizou o Ataque Básico ";
    return 1;
}

int Classe::Ataque_2()
{
    if (this->nome_da_classe == "Mago")
    {
        std::cout << "utilizou o Raio ";
    }
    else if (this->nome_da_classe == "Guerreiro")
    {
        std::cout << "utilizou o Ataque Forte ";
    }
    else if (this->nome_da_classe == "Ladino")
    {
        std::cout << "utilizou o Ataque Furtivo ";
    }
    return 2;
}

int Classe::Ataque_3()
{
    if (this->nome_da_classe == "Mago")
    {
        std::cout << "utilizou a Geada ";
    }
    else if (this->nome_da_classe == "Guerreiro")
    {
        std::cout << "utilizou a Dança das Espadas ";
    }
    else if (this->nome_da_classe == "Ladino")
    {
        std::cout << "utilizou o Estrangulamento ";
    }
    return 3;
}

int Classe::Ataque_4()
{
    if (this->nome_da_classe == "Mago")
    {
        std::cout << "utilizou a Bola de Fogo ";
    }
    else if (this->nome_da_classe == "Guerreiro")
    {
        std::cout << "utilizou a Espadada Fatal ";
    }
    else if (this->nome_da_classe == "Ladino")
    {
        std::cout << "utilizou a Adaga Cortante ";
    }
    return 4;
}

int Classe::getMCON()
{
    return this->Multiplicador_CON;
}

int Classe::getMDES()
{
    return this->Multiplicador_DES;
}

int Classe::getMFOR()
{
    return this->Multiplicador_FOR;
}

int Classe::getMINT()
{
    return this->Multiplicador_INT;
}

std::string Classe::getNome()
{
    return nome_da_classe;
}