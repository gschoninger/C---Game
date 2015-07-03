// Bibliotecas do Allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

// Bibliotecas do C
#include <stdio.h>
#include <math.h>

// Header das Estruturas
#include "struct.h"

#define FULLSCREEN true

#define COL 20
#define LIN 22

#define TAMANHO_BLOCO 35

#define TEMPO_VALENTAO   20
#define TEMPO_LIVRO      600

#define X_MAPA 51
#define Y_MAPA 51

#define LARGURA_TELA    1024
#define ALTURA_TELA     768

#define TELA_INICIAL    0
#define TELA_INSTRUCAO  1
#define JOGO_RODANDO    2
#define TELA_PAUSA      3
#define TELA_GANHOU     4
#define TELA_PERDEU     5
#define TELA_CREDITOS   6

#define GANHOU_0 "Sprites/Telas/Ganhou_0.bmp"
#define GANHOU_1 "Sprites/Telas/Ganhou_1.bmp"
#define GANHOU_2 "Sprites/Telas/Ganhou_2.bmp"
#define GANHOU_3 "Sprites/Telas/Ganhou_3.bmp"

#define QUADROS 60

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3
#define ENTER   4
#define ESC     5
#define PAUSA   6
#define COMPRA  7
#define LARGA   8

#define JOGADOR_LINHA       11
#define JOGADOR_COLUNA      10
#define JOGADOR_PONTOS      0
#define JOGADOR_VIDAS       3
#define JOGADOR_LIVROS      1
#define PONTOS_LIVRO        20

#define NUMERO_VALENTAO 4

#define VALENTAO_DESENHO true

#define FONTE_20    0
#define FONTE_48    1
#define FONTE_100   2
#define FONTE_300   3


void desenhaJogador(JOGADOR *jogador);
void moveJogador(JOGADOR *jogador, VALENTAO valentao[], int mapa[COL][LIN], char sentido, int valentaoAtual);

void desenhaValentao(VALENTAO valentao[], JOGADOR *jogador, int numeroValentao);
void moveValentao(VALENTAO valentao[], JOGADOR *jogador, int valentaoAtual, int mapa[COL][LIN]);

void desenhaInfo(JOGADOR *jogador, INFO *info, LIVROS *livros);

void desenhaMapa(int mapa[COL][LIN], IMAGEM *imagem);

void desenhaPontuacao(JOGADOR *jogador, INFO *info);

void compraLivros(JOGADOR *jogador, LIVROS *livros);
void largaLivros(JOGADOR *jogador, int mapa[COL][LIN], LIVROS *livros);

float calculaDistancia(JOGADOR *jogador, VALENTAO valentao[], int valentaoAtual, int mapa[COL][LIN]);

void desabilitaTeclas(bool keys[]);
