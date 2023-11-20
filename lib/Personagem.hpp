#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include "../lib/Classe.hpp"
#include "../lib/Mochila.hpp"

class Personagem
{
private:
    int ataque, defesa, vida, stamina, mana, DES, INT, CON, FOR; // Atributos
    int level, experiencia;                                      // Atributos de Evolução

    Mochila *Mochila_Jogador = new Mochila;
    Classe *Classe_Personagem = new Classe;

    std::string nome;

public:
    Personagem(std::string nome, int _DES, int _INT, int _CON, int _FOR, Classe *_Classe, Mochila *_Mochila);
    Personagem();
    ~Personagem();


    //Setters
    void setAtaque(int _ataque);
    void setDefesa(int _defesa);
    void setVida(int _vida);
    void setStamina(int _Stamina);
    void setMana(int _mana);
    void setDES(int _DES);
    void setINT(int _INT);
    void setCON(int _CON);
    void setFOR(int _FOR);
    void setLVL(int _LVL);
    void setEXP(int _EXP);

    void setClasse(Classe *_Classe);
    void setNome(std::string _nome);
    
    //Getters
    int getAtaque();
    int getDefesa();
    int getVida();
    int getStamina();
    int getMana();
    int getDES();
    int getINT();
    int getCON();
    int getFOR();
    int getLVL();
    int getEXP();
    std::string getNome();
    Classe *getClasse();
    Mochila *getMochila();

    // Faz com que o personagem retorne para os seus atributos iniciais;
    void ConfiguracoesIniciais();
    //Retorna o valor de ataque, se baseando no dano de ataque e na defesa do adversário;
    int Atacar(int dano, int defesa);
    //Retorna se o ataque foi crítico ou não;
    int Critico();
    //A partir da experiencia obtida ao derrotar um inimigo é calculado se o jogador subiu de nivel;
    void SubirdeNivel(int exp);
    //Função responsável por permitir a adição de atributos ao personagem quando este sobre de nível;
    void EscolhaDeAtributos();
    //Função responsável por utilizar um item da mochila;
    void usarItem(int item);
};
#endif
