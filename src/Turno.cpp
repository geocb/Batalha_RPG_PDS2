#include "../lib/Turno.hpp"
#include "../lib/Interface.hpp"
#include "../lib/Robo.hpp"

void Luta(Inimigos *_inimigo, Personagem *_jogador)
{
    std::cout << _inimigo->getNome() << " VS " << _jogador->getNome() << std::endl;
    Pausar();

    int vida_inimigo = _inimigo->getVida();

    for (int i = 1;; i++)
    {
        LimparTela();
        int escolha = 0;
        int parada = 0;
        int danoInicial = 0;
        int danoFinal = 0;
        int opcao = 0;

        while (parada == 0)
        {
            std::cout << "Turno: " << i << std::endl;
            std::cout << _jogador->getNome() << "| "
                      << "Vida: " << _jogador->getVida() << "   "
                      << "Mana: " << _jogador->getMana() << "   "
                      << "Stamina: " << _jogador->getStamina() << "   " << std::endl;

            std::cout << "Vida do " << _inimigo->getNome() << ": " << _inimigo->getVida() << std::endl
                      << std::endl;
            std::cout << "Escolha seu ataque:" << std::endl;

            _jogador->getClasse()->listarAtaques();

            std::cin >> escolha;
            switch (escolha)
            {
            case 1:
                std::cout << std::endl
                          << _jogador->getNome() << " ";
                danoInicial = _jogador->getClasse()->Ataque_1();
                std::cout << "em " << _inimigo->getNome();
                danoFinal = _jogador->Atacar(danoInicial, _inimigo->getDefesa());
                if (danoFinal == 5000)
                {
                    break;
                }
                else
                {
                    vida_inimigo = vida_inimigo - danoFinal;
                    _inimigo->setVida(vida_inimigo);
                    Pausar();
                    parada = 1;
                    break;
                }

            case 2:
                std::cout << std::endl
                          << _jogador->getNome() << " ";
                danoInicial = _jogador->getClasse()->Ataque_2();
                std::cout << "em " << _inimigo->getNome();
                danoFinal = _jogador->Atacar(danoInicial, _inimigo->getDefesa());
                if (danoFinal == 5000)
                {
                    LimparTela();
                    break;
                }
                else
                {
                    vida_inimigo = vida_inimigo - danoFinal;
                    _inimigo->setVida(vida_inimigo);
                    Pausar();
                    parada = 1;
                    break;
                }

            case 3:
                std::cout << std::endl
                          << _jogador->getNome() << " ";
                danoInicial = _jogador->getClasse()->Ataque_3();
                std::cout << "em " << _inimigo->getNome();
                danoFinal = _jogador->Atacar(danoInicial, _inimigo->getDefesa());
                if (danoFinal == 5000)
                {
                    LimparTela();
                    break;
                }
                else
                {
                    vida_inimigo = vida_inimigo - danoFinal;
                    _inimigo->setVida(vida_inimigo);
                    Pausar();
                    parada = 1;
                    break;
                }

            case 4:
                std::cout << std::endl
                          << _jogador->getNome() << " ";
                danoInicial = _jogador->getClasse()->Ataque_4();
                std::cout << "em " << _inimigo->getNome();
                danoFinal = _jogador->Atacar(danoInicial, _inimigo->getDefesa());
                if (danoFinal == 5000)
                {
                    LimparTela();
                    break;
                }
                else
                {
                    vida_inimigo = vida_inimigo - danoFinal;
                    _inimigo->setVida(vida_inimigo);
                    Pausar();
                    parada = 1;
                    break;
                }
            case 5:
                LimparTela();
                opcao = usarMochila(_jogador);
                if (opcao == 4)
                {
                    parada = 0;
                    LimparTela();
                }
                else
                    parada = 1;

                break;

            default:
                LimparTela();
                std::cout << "Escolha errada" << std::endl;
                break;
            }
        }

        if (_inimigo->getVida() <= 0)
        {
            _inimigo->setVida(0);
            LimparTela();
            break;
        }

        TurnoRobo(_inimigo, _jogador);

        if (_jogador->getVida() <= 0)
        {
            _jogador->setVida(0);
            LimparTela();
            break;
        }

        LimparTela();
    }
};

void ConferirVida(Inimigos *_inimigo, Personagem *_jogador)
{
    if (_inimigo->getVida() <= 0)
    {
        _inimigo->setVida(0);
        LimparTela();
    }
    else if (_jogador->getVida() <= 0)
    {
        _jogador->setVida(0);
        LimparTela();
    }
}

void EntreTurnos(Personagem *_jogador)
{
    int parada = 0;
    while (parada == 0)
    {
        std::cout << "Você venceu a batalha, escolha a próxima opção:" << std::endl;
        std::cout << "1 - Continuar" << std::endl
                  << "2 - Abrir a Mochila" << std::endl;

        int escolha;

        std::cin >> escolha;

        switch (escolha)
        {
        case 1:
            parada = 1;
            LimparTela();
            Pausar();
            std::cout << "Próxima batalha" << std::endl;
            Pausar();
            break;
        case 2:
            parada = 1;
            Pausar();
            LimparTela();
            usarMochila(_jogador);
            Pausar();
            LimparTela();
            Pausar();
            std::cout << "Próxima batalha" << std::endl;
            Pausar();
            break;
        default:
            break;
        }
    }

    LimparTela();
}

void LutaFinal(Inimigos *_inimigo, Personagem *_jogador)
{

    LimparTela();

    std::cout << "BOSS FINAL" << std::endl;
    Pausar();
    Luta(_inimigo, _jogador);
}
