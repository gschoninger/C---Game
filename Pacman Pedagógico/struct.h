typedef struct personagem
{
    int linha;
    int coluna;
    int linhaAnt;
    int colunaAnt;

    bool movimentoAtual[4];
    bool movimentoAnt[4];

    int sentido;

    int vidas;
    int livros;

    int pontosParcial;
    int pontosTotal;

    ALLEGRO_BITMAP *sprite;
} PERSONAGEM;

typedef struct info
{
    ALLEGRO_BITMAP *spriteVida;
    ALLEGRO_BITMAP *spritePontos;
    ALLEGRO_BITMAP *spriteMoldura;
    ALLEGRO_BITMAP *iconeLivros;

    ALLEGRO_FONT *fonte[10];
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
    ALLEGRO_BITMAP *pausa;
    ALLEGRO_BITMAP *creditos;
    ALLEGRO_BITMAP *ganhou;
    ALLEGRO_BITMAP *perdeu;

    int telaAtual;
    int proximaTela;
} TELAS;
