#include "../lib/Personagem.hpp"
#include "../lib/Robo.hpp"
#include "../lib/Interface.hpp"

Personagem::Personagem(std::string nome, int _DES, int _INT, int _CON, int _FOR, Classe *_Classe, Mochila *_Mochila)
{
    this->nome = nome;
    this->Classe_Personagem = _Classe;
    this->Mochila_Jogador = _Mochila;

    this->DES = this->Classe_Personagem->getMDES() * _DES;
    this->INT = this->Classe_Personagem->getMINT() * _INT;
    this->CON = this->Classe_Personagem->getMCON() * _CON;
    this->FOR = this->Classe_Personagem->getMFOR() * _FOR;

    this->defesa = (this->DES * 5) + this->FOR;
    this->vida = this->CON * 5;
    this->mana = this->INT * 5;
    this->stamina = this->DES * 5;

    this->level = 1;
    this->experiencia = 0;

    if (this->Classe_Personagem->getNome() == "Mago")
        this->ataque = this->INT * 5;
    if (this->Classe_Personagem->getNome() == "Guerreiro")
        this->ataque = this->FOR * 5;
    if (this->Classe_Personagem->getNome() == "Ladino")
        this->ataque = this->DES * 5;
};

Personagem::Personagem()
{
    this->nome = "";
    this->Classe_Personagem = NULL;

    this->DES = 0;
    this->INT = 0;
    this->CON = 0;
    this->FOR = 0;

    this->ataque = 0;
    this->defesa = 0;
    this->vida = 0;
    this->mana = 0;
    this->stamina = 0;

    this->level = 1;
    this->experiencia = 0;
}

Personagem::~Personagem(){};
void Personagem::setVida(int _vida)
{
    this->vida = _vida;
};

void Personagem::setMana(int _mana)
{
    this->mana = _mana;
};
void Personagem::setEXP(int _exp)
{
    this->experiencia = _exp;
}
void Personagem::setAtaque(int _atq)
{
    this->ataque = _atq;
}
void Personagem::setDefesa(int _def)
{
    this->defesa = _def;
}
void Personagem::setDES(int _des)
{
    this->DES = _des;
}
void Personagem::setINT(int _int)
{
    this->INT = _int;
}
void Personagem::setCON(int _con)
{
    this->CON = _con;
}
void Personagem::setClasse(Classe *_classe)
{
    this->Classe_Personagem = _classe;
}

void Personagem::setNome(std::string _nome)
{
    this->nome = _nome;
}
void Personagem::setStamina(int stamina)
{
    this->stamina = stamina;
}

int Personagem::getVida()
{
    return this->vida;
}
int Personagem::getMana()
{
    return this->mana;
}
int Personagem::getEXP()
{
    return this->experiencia;
}
int Personagem::getAtaque()
{
    return this->ataque;
}
int Personagem::getDefesa()
{
    return this->defesa;
}
int Personagem::getDES()
{
    return this->DES;
}
int Personagem::getFOR()
{
    return this->FOR;
}
int Personagem::getINT()
{
    return this->INT;
}
int Personagem::getCON()
{
    return this->CON;
}
int Personagem::getLVL()
{
    return this->level;
}
std::string Personagem::getNome()
{
    return this->nome;
}
Classe *Personagem::getClasse()
{
    return this->Classe_Personagem;
}

int Personagem::getStamina()
{
    return this->stamina;
}

void Personagem::ConfiguracoesIniciais()
{

    this->DES = this->Classe_Personagem->getMDES() * 5;
    this->INT = this->Classe_Personagem->getMINT() * 5;
    this->CON = this->Classe_Personagem->getMCON() * 5;
    this->FOR = this->Classe_Personagem->getMFOR() * 5;

    this->defesa = this->FOR * 5;
    this->vida = this->CON * 5;
    this->mana = this->INT * 5;

    this->level = 1;
    this->experiencia = 0;

    if (this->Classe_Personagem->getNome() == "Mago")
        this->ataque = this->INT * 5;
    if (this->Classe_Personagem->getNome() == "Guerreiro")
        this->ataque = this->FOR * 5;
    if (this->Classe_Personagem->getNome() == "Ladino")
        this->ataque = this->DES * 5;
}

int Personagem::Atacar(int dano, int defesa)
{
    int critico = Critico();
    int danoInicial = dano;
    int aleatorio = numeroAleatorio(1, 2);

    if (critico == 1)
    {
        std::cout << " com acerto crítico";
        int danoMais = numeroAleatorio(0, 99);
        float aux = dano * danoMais;
        aux = aux / 100;
        if (aux < 1)
        {
            aux = 1;
        }

        dano = dano + aux;
    }

    if (this->Classe_Personagem->getNome() == "Mago")
    {

        if (danoInicial == 1)
        {
            if (this->stamina < 5)
            {
                std::cout << std::endl;
                LimparTela();
                std::cout << "Stamina Insuficiente" << std::endl;
                Pausar();
                return 5000;
            }
            else
            {
                dano = dano * (this->getFOR() * 15 * this->getLVL()) - defesa;
                this->stamina = this->stamina - 5;
            }
        }
        else if (danoInicial == 2)
        {
            if (this->mana < 10)
            {

                std::cout << std::endl;
                LimparTela();
                std::cout << "Mana Insuficiente" << std::endl;
                Pausar();
                return 5000;
            }
            else
            {
                dano = dano * this->getAtaque() - defesa;
                this->mana = this->mana - 10;
            }
        }
        else if (danoInicial == 3)
        {
            if (this->mana < 15)
            {
                std::cout << std::endl;
                LimparTela();
                std::cout << "Mana Insuficiente" << std::endl;
                Pausar();
                return 5000;
            }
            else
            {
                dano = dano * this->getAtaque() - (defesa * aleatorio);
                this->mana = this->mana - 15;
            }
        }
        else if (danoInicial == 4)
        {
            if (this->mana < 25)
            {
                std::cout << std::endl;
                LimparTela();
                std::cout << "Mana Insuficiente" << std::endl;
                Pausar();
                return 5000;
            }
            else
            {
                dano = dano * this->getAtaque() - (defesa * aleatorio);
                this->mana = this->mana - 25;
            }
        }
    }
    else if (this->Classe_Personagem->getNome() == "Guerreiro")
    {

        if (danoInicial == 1)
        {
            if (this->stamina < 5)
            {
                std::cout << std::endl;
                LimparTela();
                std::cout << "Stamina Insuficiente" << std::endl;
                Pausar();
                Pausar();
                return 5000;
            }
            else
            {
                dano = dano * this->getAtaque() - defesa;
                this->stamina = this->stamina - 5;
            }
        }
        else if (danoInicial == 2)
        {
            if (this->stamina < 10)
            {
                std::cout << std::endl;
                LimparTela();
                std::cout << "Stamina Insuficiente" << std::endl;
                Pausar();
                return 5000;
            }
            else
            {
                dano = dano * this->getAtaque() - defesa;
                this->stamina = this->stamina - 10;
            }
        }
        else if (danoInicial == 3)
        {
            if (this->stamina < 15)
            {
                std::cout << std::endl;
                LimparTela();
                std::cout << "Stamina Insuficiente" << std::endl;
                Pausar();
                return 5000;
            }
            else
            {
                dano = dano * this->getAtaque() - (defesa * aleatorio);
                this->stamina = this->stamina - 15;
            }
        }
        else if (danoInicial == 4)
        {
            if (this->stamina < 20)
            {
                std::cout << std::endl;
                LimparTela();
                std::cout << "Stamina Insuficiente" << std::endl;
                Pausar();
                return 5000;
            }
            else
            {
                dano = dano * this->getAtaque() - (defesa * aleatorio);
                this->stamina = this->stamina - 20;
            }
        }
    }
    else if (this->Classe_Personagem->getNome() == "Ladino")
    {

        if (danoInicial == 1)
        {
            if (this->stamina < 5)
            {
                std::cout << std::endl;
                LimparTela();
                std::cout << "Stamina Insuficiente" << std::endl;
                Pausar();
                return 5000;
            }
            else
            {
                dano = dano * this->getAtaque() - defesa;
                this->stamina = this->stamina - 5;
            }
        }
        else if (danoInicial == 2)
        {
            if (this->stamina < 10)
            {
                std::cout << std::endl;
                LimparTela();
                std::cout << "Stamina Insuficiente" << std::endl;
                Pausar();
                return 5000;
            }
            else
            {
                dano = dano * this->getAtaque() - defesa;
                this->stamina = this->stamina - 10;
            }
        }
        else if (danoInicial == 3)
        {
            if (this->stamina < 15)
            {
                std::cout << std::endl;
                LimparTela();
                std::cout << "Stamina Insuficiente" << std::endl;
                Pausar();
                return 5000;
            }
            else
            {
                dano = dano * this->getAtaque() - (defesa * aleatorio);
                this->stamina = this->stamina - 15;
            }
        }
        else if (danoInicial == 4)
        {
            if (this->stamina < 20)
            {
                std::cout << std::endl;
                LimparTela();
                std::cout << "Stamina Insuficiente" << std::endl;
                Pausar();
                return 5000;
            }
            else
            {
                dano = dano * this->getAtaque() - (defesa * aleatorio);
                this->stamina = this->stamina - 20;
            }
        }
    }

    if (dano <= 0)
    {
        dano = 0;
    }

    std::cout << " causando " << dano << " de dano." << std::endl;

    return dano;
}
int Personagem::Critico()
{
    /*Inicializa um vetor de 100 inteiros, para cada atributo do personagem coloca o valor do vetor
    como 1, o resto será inicializado com 0. A partir de um indice aleatório, verifica se a posição
    vale 1, se valer, foi dano crítico.*/
    int vec[100];

    for (int i = 0; i < 100; i++)
    {
        vec[i] = 0;
    }

    if (this->Classe_Personagem->getNome() == "Mago")
    {
        int indiceCritico = this->getINT();

        for (int i = 0; i < indiceCritico; i++)
        {
            vec[i] = 1;
        }
    }
    else if (this->Classe_Personagem->getNome() == "Guerreiro")
    {
        int indiceCritico = this->getFOR();

        for (int i = 0; i < indiceCritico; i++)
        {
            vec[i] = 1;
        }
    }
    else if (this->Classe_Personagem->getNome() == "Ladino")
    {
        int indiceCritico = this->getDES();

        for (int i = 0; i < indiceCritico; i++)
        {
            vec[i] = 1;
        }
    }

    int indiceEscolha = numeroAleatorio(0, 99);

    if (vec[indiceEscolha] == 1)
    {
        return 1;
    }
    else
        return 0;
}

void Personagem::SubirdeNivel(int exp)
{
    int expTotal = this->experiencia + exp;

    if (expTotal >= 100)
    {
        this->level = this->level + 1;
        this->experiencia = expTotal - 100;
        std::cout << "Você subiu para o nível: " << this->level << std::endl;
        EscolhaDeAtributos();

        this->defesa = this->FOR * 5;
        this->vida = this->CON * 5 * this->level;
        this->mana = this->INT * 5;
        this->stamina = this->DES * 5;

        if (this->Classe_Personagem->getNome() == "Mago")
            this->ataque = this->INT * 5;
        if (this->Classe_Personagem->getNome() == "Guerreiro")
            this->ataque = this->FOR * 5;
        if (this->Classe_Personagem->getNome() == "Ladino")
            this->ataque = this->DES * 5;
    }
}

void Personagem::EscolhaDeAtributos()
{

    for (int pontosADistribuir = 3; pontosADistribuir > 0; pontosADistribuir--)
    {

        std::cout << "Você tem " << pontosADistribuir << " ponto(s) para distribuir. Escolha um número para acrescentar em um dos atributos:" << std::endl;
        std::cout << "1 - FOR: " << this->FOR << std::endl
                  << "2 - CON: " << this->CON << std::endl
                  << "3 - DES: " << this->DES << std::endl
                  << "4 - INT: " << this->INT << std::endl;

        int escolha = 0;

        int parada = 0;

        while (parada == 0)
        {
            
            
            std::cin >> escolha;

            switch (escolha)
            {
            case 1:
                this->FOR = this->FOR + 1;
                parada = 1;
                break;

            case 2:
                this->CON = this->CON + 1;
                parada = 1;
                break;

            case 3:
                this->DES = this->DES + 1;
                parada = 1;
                break;

            case 4:
                this->INT = this->INT + 1;
                parada = 1;
                break;

            default:
                std::cout << "O número escolhido não foi o certo, escolha novamente" << std::endl;
                Pausar();
                parada = 0;
                break;
            }
        }
        LimparTela();
    }
}

void Personagem::usarItem(int item)
{
    int Pontos;
    if (item == 1)
    {
        if (this->Mochila_Jogador->cura.size() > 0)
        {
            Pontos = this->Mochila_Jogador->cura[0]->getPonto();
            this->setVida(this->vida + (Pontos * this->level));
            this->Mochila_Jogador->cura.erase(this->Mochila_Jogador->cura.begin());
        }
        else
        {
            LimparTela();
            std::cout << "Você não tem mais Pocões de Cura" << std::endl;
        }
    };

    if (item == 2)
    {
        if (this->Mochila_Jogador->mana.size() > 0)
        {
            Pontos = this->Mochila_Jogador->mana[0]->getPonto();
            this->setMana(this->mana + (Pontos * this->level));
            this->Mochila_Jogador->mana.erase(this->Mochila_Jogador->mana.begin());
        }
        else
        {
            LimparTela();
            std::cout << "Você não tem mais Pocões de Mana" << std::endl;
        }
    };

    if (item == 3)
    {
        if (this->Mochila_Jogador->stamina.size() > 0)
        {
            Pontos = this->Mochila_Jogador->stamina[0]->getPonto();
            this->setStamina(this->stamina + (Pontos * this->level));
            this->Mochila_Jogador->stamina.erase(this->Mochila_Jogador->stamina.begin());
        }
        else
        {
            LimparTela();
            std::cout << "Você não tem mais Pocões de Stamina" << std::endl;
        }
    };
}

Mochila *Personagem::getMochila()
{
    return this->Mochila_Jogador;
}
