typedef struct jogador
{
    int linha;
    int coluna;
    int linhaAnt;
    int colunaAnt;

    int vidas;

    int pontos;
    int pontosColetados;
    int pontosPercentual;

    ALLEGRO_BITMAP *sprite;
} JOGADOR;

typedef struct valentao
{
    int linha;
    int coluna;

    bool movimentoAtual[4];
    bool movimentoAnt[4];

    int tempoAtualizacao;

    int sentido;

    ALLEGRO_BITMAP *spriteGrande;
    ALLEGRO_BITMAP *sprite;
} VALENTAO;

typedef struct livros
{
    int quantidade;
    int tempoLivro[4];

    ALLEGRO_BITMAP *sprite;
} LIVROS;

typedef struct info
{
    ALLEGRO_BITMAP *spriteVida;
    ALLEGRO_BITMAP *spritePontos;
    ALLEGRO_BITMAP *spriteMoldura;
    ALLEGRO_BITMAP *iconeLivros;

    ALLEGRO_FONT *fonte[4];
} INFO;

typedef struct imagem
{
    ALLEGRO_BITMAP *bloco[3];
    ALLEGRO_BITMAP *parede[7];
    ALLEGRO_BITMAP *livros;
} IMAGEM;

typedef struct telas
{
    ALLEGRO_BITMAP *inicialA;
    ALLEGRO_BITMAP *inicialB;
    ALLEGRO_BITMAP *instrucao;
    ALLEGRO_BITMAP *jogo;
    ALLEGRO_BITMAP *pausa;
    ALLEGRO_BITMAP *creditos;
    ALLEGRO_BITMAP *ganhou;
    ALLEGRO_BITMAP *perdeu;

    int telaAtual;
    int proximaTela;
} TELAS;
