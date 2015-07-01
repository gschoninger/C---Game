// Bibliotecas do Allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// Bibliotecas do C
#include <stdio.h>
#include <math.h>

// Header das Estruturas
#include "struct.h"

#define FULLSCREEN false

#define COL 20
#define LIN 22

#define TAMANHO_BLOCO 35

#define VELOCIDADE_PREDADOR 60

#define X_MAPA 51
#define Y_MAPA 51

#define LARGURA_TELA    1024
#define ALTURA_TELA     768

#define TELA_INICIAL    0
#define TELA_INSTRUCAO  1
#define JOGO_RODANDO    2
#define TELA_PAUSA      3
#define TELA_FINAL      4
#define TELA_CREDITOS   5

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
#define JOGADOR_PARCIAL     0
#define JOGADOR_TOTAL       0
#define JOGADOR_VIDAS       5
#define JOGADOR_LIVROS      1

void desenhaJogador(PERSONAGEM *jogador, INFO *info);
void desenhaPredador(PERSONAGEM predador[], int numeroPredador);
void desabilitaTeclas(bool keys[]);
void moveJogador(PERSONAGEM *jogador, int mapa[COL][LIN], char sentido);
void movePredador(PERSONAGEM predador[], PERSONAGEM *jogador, int predadorAtual, int mapa[COL][LIN]);
void desenhaMapa(int mapa[COL][LIN], IMAGEM *imagem);
float calculaDistancia(PERSONAGEM *jogador, PERSONAGEM predador[], int predadorAtual, int mapa[COL][LIN]);
void compraLivros(PERSONAGEM *jogador);
void largaLivros(PERSONAGEM *jogador, int mapa[COL][LIN]);
