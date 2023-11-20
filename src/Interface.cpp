#include "../lib/Interface.hpp"
#include <unistd.h>

Personagem Criar_Personagem(Classe *_Mago, Classe *_Guerreiro, Classe *_Ladino, Mochila *_Mochila)
{
    LimparTela();

    std::string nome;

    std::cout << "Bem vindo(a) a Batalha RPG" << std::endl
              << std::endl;
    Pausar();
    std::cout << "Vamos começar criando o seu personagem:" << std::endl;
    Pausar();
    LimparTela();

    std::cout << "Qual o seu nome?" << std::endl
              << std::endl;

    std::getline(std::cin, nome);

    std::cout << std::endl;

    Classe *Escolha;

    int parada = 0;
    int escolha = 0;
    std::string aux;
    while (parada == 0)
    {
        std::cout << "Escolha o número da sua Classe:" << std::endl;
        std::cout << "1 - Mago" << std::endl
                  << "2 - Guerreiro" << std::endl
                  << "3 - Ladino" << std::endl;

        std::cin >> escolha;

        switch (escolha)
        {
        case 1:
            Escolha = _Mago;
            parada = 1;
            break;
        case 2:
            Escolha = _Guerreiro;
            parada = 1;
            break;
        case 3:
            Escolha = _Ladino;
            parada = 1;
            break;
        default:
            std::cout << "O número não foi escolhido corretamente, escolha novamente:";
            parada = 0;
            break;
        }
    }

    Personagem Jogador(nome, 5, 5, 5, 5, Escolha, _Mochila);

    LimparTela();
    Pausar();

    std::cout << "Nome: " << Jogador.getNome() << std::endl
              << "Classe: " << Jogador.getClasse()->getNome() << std::endl
              << "Ataque: " << Jogador.getAtaque() << std::endl
              << "Defesa: " << Jogador.getDefesa() << std::endl
              << "Vida: " << Jogador.getVida() << std::endl
              << "Stamina: " << Jogador.getStamina() << std::endl
              << "Mana: " << Jogador.getMana() << std::endl
              << "DES: " << Jogador.getDES() << std::endl
              << "INT: " << Jogador.getINT() << std::endl
              << "CON: " << Jogador.getCON() << std::endl
              << "FOR: " << Jogador.getFOR() << std::endl;

    std::cout << std::endl;
    Pausar();
    Pausar();

    return Jogador;
};

int menuInicial()
{
    int parada = 0;
    while (parada == 0)
    {
        std::cout << "MENU" << std::endl
                  << std::endl;
        std::cout << "Escolha uma opção" << std::endl;
        std::cout << "1 - Começar" << std::endl
                  << "2 - Créditos" << std::endl
                  << "3 - Fechar" << std::endl;

        int escolha;
        
        std::cin >> escolha;

        switch (escolha)
        {
        case 1:
            return 1;
            parada = 1;
            break;
        case 2:
            return 2;
            parada = 1;
            break;
        case 3:
            return 3;
            parada = 1;
            break;
        default:
            break;
        }
    }
    return 0;
};

void LimparTela()
{
    int teste = system("clear");
    if (teste == -1)
        std::cout << "Erro ao limpar a tela" << std::endl;
}

void Pausar()
{
    sleep(3);
}

int usarMochila(Personagem *_jogador)
{
    int escolha;
    std::cout << "Inventário" << std::endl
              << "Pocão de cura: " << _jogador->getMochila()->cura.size() << std::endl
              << "Pocão de mana: " << _jogador->getMochila()->mana.size() << std::endl
              << "Pocão de stamina: " << _jogador->getMochila()->stamina.size() << std::endl;

    std::cout << "Escolha um item para ser utilizado:" << std::endl;
    std::cout << "1 - Poção de Cura" << std::endl
              << "2 - Poção de Mana" << std::endl
              << "3 - Poção de Stamina" << std::endl
              << "4 - Fechar" << std::endl;

    std::cin >> escolha;

    int parada = 0;

    while (parada == 0)
    {

        switch (escolha)
        {
        case 1:
            parada = 1;
            _jogador->usarItem(1);
            std::cout << _jogador->getNome() << " adicionou " << 30 * _jogador->getLVL() << " pontos de vida" << std::endl;
            return 1;
            break;
        case 2:
            parada = 1;
            _jogador->usarItem(2);
            std::cout << _jogador->getNome() << " adicionou " << 30 * _jogador->getLVL() << " pontos de mana" << std::endl;
            return 1;
            break;
        case 3:

            parada = 1;
            _jogador->usarItem(3);
            std::cout << _jogador->getNome() << " adicionou " << 30 * _jogador->getLVL() << " pontos de stamina" << std::endl;
            return 1;
            break;
        case 4:
            parada = 1;
            return 4;
            break;
        default:
            LimparTela();
            std::cout << "Escolha errada" << std::endl;
            return 1;
            break;
        }
        LimparTela();
    }
    return 1;
};