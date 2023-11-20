<div id="top"></div>

# Batalha_de_RPG ⚔️
Trabalho para a disciplina de PDS 2. Será feito uma simulação de uma batalha em turnos no estilo RPG.

<br/>

## Primeiros passos

Para começar, é necessário atender a alguns requisitos explicitados:

### Pré-requisitos

* Ter o instalado o pacote build-essential no seu ambiente linux
* Ter o git instalado.

### Instalação

1. Clone o repositório.
   ```sh
   git clone https://github.com/geocb/Batalha_RPG_PDS2.git
   ```
2. Entre no diretório do repositório.
    ```sh
    cd Batalha_de_RPG
    ```
3. Execute o comando `make` para gerar o projeto.
    ```sh
    make
    ```

## Como utilizar o Projeto

Para começar a utilizar, após a instalação, dentro do diretório do projeto, basta rodar:

Em um ambiente Linux:
```sh
  bin/main.out
```

## Como Jogar

O jogo utiliza o terminal como ambiente de jogos. Para cada ação dentro do jogo é necessário escrever algum número no terminal, todas as opções são indicadas no terminal do usuário.

## Informações importantes

No decorrer do jogo o jogador terá alguma opções dentro do jogo, como atacar, utilizar poções e subir os atributos do personagem, por conta disso temos as seguintes informações:

DES - Representa a destreza do Jogador. Sua função é melhorar a defesa do personagem e serve como base de ataque da classe Ladino
FOR - Representa a força do Jogador. Sua função é melhorar o ataque físico do personagem e serve como base de ataque da classe Guerreiro
INT - Representa a inteligência do Jogador. Sua função é melhorar a magia do personagem e serve como base de ataque da classe Mago
CON - Representa a constituição do Jogador. Sua função é melhorar a vida do personagem.

### Poções:

As poções dentro deste jogo adicionam Mana, Vida e Stamina para o personagem. Exemplo: Caso o personagem tenha como padrão 100 de mana e tome uma poção que recupera 30 de mana, sua mana agora será de 130.

Cada vez que você vence um inimigo você é recompensado com 2 poções de cada tipo.

## Especificações do Código

### Personagem

A classe personagem é a classe que representa o jogador, nela possuímos vários atributos que moldam o personagem. Dentro da classe temos os métodos:

Getters e Setters -> Responsáveis para obtenção e implementação dos atributos privados;

Personagem(std::string nome, int _DES, int _INT, int _CON, int _FOR, Classe *_Classe, Mochila *_Mochila)-> Construtor;

ConfiguraçõesIniciais() -> Faz com que o personagem retorne para os seus atributos iniciais;

Atacar(int dano, int defesa) -> Retorna o valor de ataque, se baseando no dano de ataque e na defesa do adversário;

int Critico() -> Retorna se o ataque foi crítico ou não;

void SubirdeNivel(int exp) -> A partir da experiencia obtida ao derrotar um inimigo é calculado se o jogador subiu de nivel;

void EscolhaDeAtributos() -> Função responsável por permitir a adição de atributos ao personagem quando este sobre de nível;

void usarItem(int item) -> Função responsável por utilizar um item da mochila;

### Classe

A class Classe representa as classes do jogador (Mago, Guerreiro, Ladino), em seus atirbutos temos os multiplicadores de cada atributo (DES, FOR, CON, INT), sendo que eles se diferem para cada Classe. Dentro da classe temos os métodos:


Classe(std::string _nome_da_classe) -> Construtor;

int Ataque_1() -> Vai de "_1" até "_4". É o método responsável por indicar e printar na tela qual ataque está sendo utilizado;

Getters -> Retorna os valores dos multiplicadores;

void listarAtaques() -> Lista todos os ataques da classe escolhida;

### Inimigos

A class Inimigos é uma subclasse de Personagem. Basicamente é a classe que representa os inimigos do jogo. Dentro da classe temos os métodos:

int Ataque_1() -> Vai de "_1" até "_4". É o método responsável por indicar e printar na tela qual ataque está sendo utilizado pelo Boss final;

Inimigos(std::string _nome, Classe *_classe) -> Construtor;

### Pocao

A struct Pocao representa as poções do jogo, dentro dela temos apenas a variável pontos e um método GetPonto() que retorna o valor dessa variável.

### Mochila

Classe que representa a Mochila do Jogador. Dentro da mochila temos 3 vetores de Pocoes. Sendo cada vetor responsável por representar uma lista de cada tipo de poção (mana, cura, stamina). Dentro da classe temos os métodos:

Mochila(int qnt_cura, Pocao *cura, int qnt_mana, Pocao *mana, int qnt_stamina, Pocao *stamina) -> Construtor 

void adicionarItens(Pocao *Item, int qnt) -> Responsável por adicionar mais poções na Mochila;

### Robo

Dentro dessa biblioteca, temos duas funções:

void TurnoRobo(Inimigos *_inimigo, Personagem *_jogador) -> Faz a máquina ter a sua vez na jogada;

int numeroAleatorio(int menor, int maior) -> retorna um número aleatório entre o menor e o maior número indicados;

### Turno

Dentro dessa biblioteca, temos duas funções:

void Luta(Inimigos *_inimigo, Personagem *_jogador) -> Coloca o inimigo e o jogador para lutarem;

void ConferirVida(Inimigos *_inimigo, Personagem *_jogador) -> Confere se o jogador e o inimigo já foram derrotados;

void EntreTurnos(Personagem *_jogador) -> Função que controla entre cada batalha de inimigos;

void LutaFinal(Inimigos *_inimigo, Personagem *_jogador) -> Função que leva para a batalha contra o último inimigo;





<p align="right">(<a href="#top">Voltar para o topo</a>)</p>
