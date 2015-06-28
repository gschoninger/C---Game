/*
|------------------------------------------------------------------------------------------------|
|    Jogo educacional desenvolvido para a disciplina de Programação em Linguagemm C por          |
|------------------------------------------------------------------------------------------------|
|    Gabriel Bolgenhagen Schöninger e Vitor Volpato Goulart                                      |
|------------------------------------------------------------------------------------------------|
|    Utilizando a biblioteca Allegro 5.0.10                                                      |
|------------------------------------------------------------------------------------------------|
*/

// Bibliotecas Allegro
//****************************************************************************************************************************************************************************************************************
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
//****************************************************************************************************************************************************************************************************************
// Outras bibliotecas
//****************************************************************************************************************************************************************************************************************
#include <stdio.h>
#include <math.h>
//****************************************************************************************************************************************************************************************************************
// Define o tamanho do mapa
//****************************************************************************************************************************************************************************************************************
#define COL 20
#define LIN 22

#define TAMANHO_BLOCO 35

#define VELOCIDADE_PREDADOR 60/4

#define X_MAPA 144
#define Y_MAPA 51

#define TELA_X 1024
#define TELA_Y 768

#define TELA_INICIAL 0
#define TELA_INSTRUCAO 1
#define JOGO_RODANDO 2
#define TELA_PAUSA 3
#define TELA_FINAL 4
#define TELA_CREDITOS 5
//****************************************************************************************************************************************************************************************************************
enum KEYS {UP, DOWN, LEFT, RIGHT, ENTER, ESC, PAUSA}; // DECLARAÇÃO DAS TECLAS DE INTERFACE

// DECLARAÇÃO DA ESTRUTURA JOGADOR
//****************************************************************************************************************************************************************************************************************
typedef struct personagem
{
    int linha;
    int coluna;
    int linhaAnt;
    int colunaAnt;

    int vidas;
    int pontosParcial;
    int pontosTotal;

    ALLEGRO_BITMAP *sprite;
} PERSONAGEM;
//****************************************************************************************************************************************************************************************************************
// DECLARAÇÃO DA ESTRUTURA DE INFORMAÇÃO DO JOGADOR
//****************************************************************************************************************************************************************************************************************
typedef struct info
{
    ALLEGRO_BITMAP *spriteVida;
    ALLEGRO_BITMAP *spritePontos;
    ALLEGRO_BITMAP *spriteMoldura;

    ALLEGRO_FONT *fonte[10];
} INFO;
//****************************************************************************************************************************************************************************************************************
// DECLARAÇÃO DAS ESTRUTURAS DE TELAS
//****************************************************************************************************************************************************************************************************************
typedef struct imagem
{
    ALLEGRO_BITMAP *bloco[3];
    ALLEGRO_BITMAP *parede[7];
} IMAGEM;

typedef struct telas
{
    ALLEGRO_BITMAP *inicial;
    ALLEGRO_BITMAP *instrucao;
    ALLEGRO_BITMAP *pausa;
    ALLEGRO_BITMAP *creditos;
    ALLEGRO_BITMAP *final;
} TELAS;
//****************************************************************************************************************************************************************************************************************
// DECLARAÇÃO DAS FUNÇÕES
//****************************************************************************************************************************************************************************************************************
void desenhaJogador(PERSONAGEM *jogador, INFO *info);
void desenhaPredador(PERSONAGEM predador[], int predadorAtual);
void desabilitaTeclas(bool keys[]);
void moveJogador(PERSONAGEM *jogador, int mapa[COL][LIN], char sentido);
void movePredador(PERSONAGEM predador[], PERSONAGEM *jogador, int predadorAtual, int mapa[COL][LIN]);
void desenhaMapa(int mapa[COL][LIN], IMAGEM *imagem);
float calculaDistancia(PERSONAGEM *jogador, PERSONAGEM predador[], int predadorAtual, int mapa[COL][LIN]);
//****************************************************************************************************************************************************************************************************************
int main(void)
{
    // Tamanho da tela
    int largura = TELA_X;
    int altura = TELA_Y;

    int estado = 0;

    int predadorAtual = 0;
    int numeroPredador = 4;
    int numeroPresa = 0;

    // Criação da Estrutura Boneco
    PERSONAGEM jogador;
    PERSONAGEM predador[numeroPredador];
    PERSONAGEM presa[numeroPresa];

    IMAGEM imagem;
    INFO info;
    TELAS telas;

    // Posição inicial do personagem
    jogador.linha = 11;
    jogador.coluna = 10;
    jogador.pontosParcial = 0;
    jogador.pontosTotal = 0;
    jogador.vidas = 3;

    predador[0].linha = 1;
    predador[0].coluna = 1;
    predador[1].linha = 1;
    predador[1].coluna = 19;
    predador[2].linha = 17;
    predador[2].coluna = 1;
    predador[3].linha = 17;
    predador[3].coluna = 19;

    // Matriz do mapa
                        // 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20
    int mapa[COL][LIN] = {{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},  // 0
                          {3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3},  // 1
                          {3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3},  // 2
                          {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},  // 3
                          {3, 1, 3, 3, 3, 1, 3, 1, 3, 3, 3, 3, 3, 1, 3, 1, 3, 3, 3, 1, 3},  // 4
                          {3, 1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 3},  // 5
                          {3, 1, 3, 1, 3, 3, 3, 3, 3, 1, 3, 1, 3, 3, 3, 3, 3, 1, 3, 1, 3},  // 6
                          {3, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 3},  // 7
                          {3, 3, 3, 3, 3, 1, 3, 0, 4, 4, 4, 4, 4, 0, 3, 1, 3, 3, 3, 3, 3},  // 8
                          {5, 0, 0, 0, 0, 1, 3, 0, 4, 0, 0, 0, 4, 0, 3, 1, 0, 0, 0, 0, 5},  // 9
                          {3, 3, 3, 3, 3, 1, 3, 0, 4, 4, 4, 4, 4, 0, 3, 1, 3, 3, 3, 3, 3},  // 10
                          {3, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 3},  // 11
                          {3, 1, 3, 1, 3, 3, 3, 3, 3, 1, 3, 1, 3, 3, 3, 3, 3, 1, 3, 1, 3},  // 12
                          {3, 1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 3},  // 13
                          {3, 1, 3, 3, 3, 1, 3, 1, 3, 3, 3, 3, 3, 1, 3, 1, 3, 3, 3, 1, 3},  // 14
                          {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},  // 15
                          {3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3},  // 16
                          {3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3},  // 17
                          {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}   // 18
    };

    bool done = false;
    bool redraw = true;

    // Contagem de quadros por segundo
    int FPS = 60;
    int contaTimer = 0;

    // Vetor das Teclas pressionadas
    bool keys[7] = {false, false, false, false,false, false, false};

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_FONT *fonte = NULL;

    // Testa a inicialização do Allegro
    if(!al_init())
        return -1;

    // Cria e testa o Display
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    display = al_create_display(largura, altura);
    if(!display)
        return -1;

    al_init_primitives_addon();
    al_install_keyboard();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    imagem.bloco[0] = al_load_bitmap("Sprites/Blocos/BlocoA.bmp");
    imagem.bloco[1] = al_load_bitmap("Sprites/Blocos/BlocoB.bmp");
    imagem.bloco[2] = al_load_bitmap("Sprites/Blocos/Seta.bmp");

    imagem.parede[0] = al_load_bitmap("Sprites/Paredes/ParedeA.bmp");
    imagem.parede[1] = al_load_bitmap("Sprites/Paredes/ParedeB.bmp");
    imagem.parede[2] = al_load_bitmap("Sprites/Paredes/ParedeC.bmp");
    imagem.parede[3] = al_load_bitmap("Sprites/Paredes/ParedeD.bmp");
    imagem.parede[4] = al_load_bitmap("Sprites/Paredes/ParedeE.bmp");
    imagem.parede[5] = al_load_bitmap("Sprites/Paredes/ParedeF.bmp");
    imagem.parede[6] = al_load_bitmap("Sprites/Paredes/ParedeG.bmp");

    jogador.sprite = al_load_bitmap("Sprites/Jogador/Jogador.bmp");

    for(predadorAtual = 0; predadorAtual < numeroPredador; predadorAtual++)
    {
        predador[predadorAtual].sprite = al_load_bitmap("Sprites/Predador/Predador.bmp");
    }

    info.spriteVida = al_load_bitmap("Sprites/Icones/Vida.bmp");
    info.spritePontos = al_load_bitmap("Sprites/Icones/Ponto.bmp");
    info.spriteMoldura = al_load_bitmap("Sprites/Icones/MolduraPonto.bmp");

    telas.inicial = al_load_bitmap("Sprites/Telas/Inicial.bmp");
    telas.instrucao = al_load_bitmap("Sprites/Telas/Instrucao.bmp");
    telas.pausa = al_load_bitmap("Sprites/Telas/Pausa.bmp");
    telas.creditos = al_load_bitmap("Sprites/Telas/Creditos.bmp");
    telas.final = al_load_bitmap("Sprites/Telas/Final.bmp");

    info.fonte[0] = al_load_ttf_font("Fontes/pac.ttf", 20, 0);
    info.fonte[1] = al_load_ttf_font("Fontes/arc-classic.ttf", 28, 0);
    info.fonte[2] = al_load_ttf_font("Fontes/presstart.ttf", 18, 0); // Fonte Tela de Inicio
    info.fonte[3] = al_load_ttf_font("Fontes/bit-led.ttf", 25, 0); // Fonte Atual tela do Jogo

    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    // Laço de repetição, enquanto ESC não for pressionado
    while(!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        // Testa o pressionamento de teclas
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                keys[UP] = true;
                break;
            case ALLEGRO_KEY_DOWN:
                keys[DOWN] = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                keys[RIGHT] = true;
                break;
            case ALLEGRO_KEY_LEFT:
                keys[LEFT] = true;
                break;
            case ALLEGRO_KEY_ENTER:
                keys[ENTER] = true;
                break;
            case ALLEGRO_KEY_ESCAPE:
                keys[ESC] = true;
                break;
            case ALLEGRO_KEY_P:
                keys[PAUSA] = true;
                break;
            }
        }

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }

        // Laço de repetição disparado pelo Timer
        if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            switch(estado)
            {
            case 0:
                // Início
                al_draw_bitmap(telas.inicial, 0, 0, 0);

                if(keys[ESC])
                    return 0;

                if(keys[ENTER])
                    estado = TELA_INSTRUCAO;
                break;
            case 1:
                // Instruções
                al_draw_bitmap(telas.instrucao, 0, 0, 0);

                if(keys[ESC])
                    return 0;

                if(keys[ENTER])
                    estado = JOGO_RODANDO;

                break;
            case 2:
                // Jogo rodando
                if(keys[UP])
                {
                    moveJogador(&jogador, mapa, 'U');
                }

                if(keys[DOWN])
                    moveJogador(&jogador, mapa, 'D');

                if(keys[LEFT])
                    moveJogador(&jogador, mapa, 'L');

                if(keys[RIGHT])
                    moveJogador(&jogador, mapa, 'R');

                if(keys[ESC])
                    estado = TELA_FINAL;

                if(keys[PAUSA])
                    estado = TELA_PAUSA;

                desenhaMapa(mapa, &imagem);
                desenhaJogador(&jogador, &info);

                for(predadorAtual = 0; predadorAtual < numeroPredador; predadorAtual++)
                {
                    desenhaPredador(predador, predadorAtual);
                }

                contaTimer++;

                if(contaTimer == VELOCIDADE_PREDADOR)
                {
                    contaTimer = 0;
                    for(predadorAtual = 0; predadorAtual < numeroPredador; predadorAtual++)
                    {
                        movePredador(predador, &jogador, predadorAtual, mapa);
                    }
                }

                break;
            case 3:
                // Pausa
                al_draw_bitmap(telas.pausa, 0, 0, 0);

                if(keys[ESC])
                    estado = TELA_FINAL;

                if(keys[PAUSA])
                    estado = JOGO_RODANDO;

                break;
            case 4:
                // Final
                al_draw_bitmap(telas.final, 0, 0, 0);

                if(keys[ENTER])
                    estado = TELA_CREDITOS;

                if(keys[ESC])
                    return 0;

                break;
            case 5:
                // Créditos
                al_draw_bitmap(telas.creditos, 0, 0, 0);

                if(keys[ENTER] || keys[ESC])
                    return 0;

                break;
            }

            desabilitaTeclas(keys);
            redraw = true;
        }

        // Redesenha a tela
        if(redraw && al_is_event_queue_empty(event_queue))
        {
            redraw = false;
            al_flip_display();
            al_clear_to_color(al_map_rgb(255, 255, 255));
        }
    }

    // Destrói os objetos
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_display(display);

    return 0;
}

void desenhaJogador(PERSONAGEM *jogador, INFO *info)
{
    int i;

    al_draw_textf(info->fonte[3], al_map_rgb(50,10,70), 144, 28, 0, "Total de Pontos  %d", jogador->pontosTotal);

    // Desenha o Jogador
    al_draw_bitmap(jogador->sprite, TAMANHO_BLOCO * jogador->coluna + X_MAPA, TAMANHO_BLOCO * jogador->linha + Y_MAPA, 0);

    // Mostra a quantidade de vidas de forma gráfica
    for(i = 0; i < jogador->vidas; i++)
    {
        al_draw_bitmap(info->spriteVida, 665 + X_MAPA - (i * TAMANHO_BLOCO), 673 + Y_MAPA, 0);
    }

    // Desenha a moldura para a barra de pontos
    al_draw_bitmap(info->spriteMoldura, TAMANHO_BLOCO + X_MAPA, 673 + Y_MAPA, 0);

    // Mostra a quantidade de pontos de forma gráfica
    for(i = 0; i < jogador->pontosParcial; i++)
    {
        if(jogador->pontosParcial > 30)
        {
            jogador->pontosParcial -= 30;
        }

        al_draw_bitmap(info->spritePontos, 40 + X_MAPA + (i * 5), 678 + Y_MAPA, 0);
    }

    al_draw_textf(info->fonte[3], al_map_rgb(50,10,70), 144, 28, 0, "Total de Pontos  %d", jogador->pontosTotal);
}

void desenhaPredador(PERSONAGEM predador[], int predadorAtual)
{
    // Desenha o Predador
    al_draw_bitmap(predador[predadorAtual].sprite, TAMANHO_BLOCO * predador[predadorAtual].coluna + X_MAPA, TAMANHO_BLOCO * predador[predadorAtual].linha + Y_MAPA, 0);
}

// Função que desenha o Mapa na Tela
void desenhaMapa(int mapa[COL][LIN], IMAGEM *imagem)
{
    int i, j;
    int posAtualX = X_MAPA;
    int posAtualY = Y_MAPA;

    for(i = 0; i < 19; i++)
    {
        for(j = 0; j < 21; j++)
        {

            int iMais = i + 1;
            int iMenos = i - 1;
            int jMais = j + 1;
            int jMenos = j - 1;

            switch(mapa[i][j])
            {
            case 0:
                // Espaço em branco
                al_draw_filled_rectangle(posAtualX, posAtualY, posAtualX + TAMANHO_BLOCO, posAtualY + TAMANHO_BLOCO, al_map_rgb(255, 255, 255));
                break;
            case 1:
                // Bloco A
                al_draw_rotated_bitmap(imagem->bloco[0], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                break;
            case 2:
                // Bloco B
                al_draw_rotated_bitmap(imagem->bloco[1], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                break;
            case 3:
                // Desenha as Paredes A
                if(mapa[iMenos][j] == 3 && mapa[iMais][j] == 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] != 3)
                {
                    // Parede A
                    al_draw_rotated_bitmap(imagem->parede[0], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }
                else if(mapa[iMenos][j] != 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] == 3)
                {
                    // Parede A + 90º
                    al_draw_rotated_bitmap(imagem->parede[0], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                }

                // Desenha as Paredes B
                if(mapa[iMenos][j] != 3 && mapa[iMais][j] == 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] == 3)
                {
                    // Parede B
                    al_draw_rotated_bitmap(imagem->parede[1], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }
                else if(mapa[iMenos][j] != 3 && mapa[iMais][j] == 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] != 3)
                {
                    // Parede B + 90º
                    al_draw_rotated_bitmap(imagem->parede[1], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                }
                else if(mapa[iMenos][j] == 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] != 3)
                {
                    // Parede B + 180º
                    al_draw_rotated_bitmap(imagem->parede[1], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }
                else if(mapa[iMenos][j] == 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] == 3)
                {
                    // Parede B + 270º
                    al_draw_rotated_bitmap(imagem->parede[1], TAMANHO_BLOCO, 0, posAtualX, posAtualY, 270 * M_PI / 180, 0);
                }

                // Desenha as Paredes C
                if(mapa[iMenos][j] != 3 && mapa[iMais][j] == 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] != 3)
                {
                    // Parede C
                    al_draw_rotated_bitmap(imagem->parede[2], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }
                else if(mapa[iMenos][j] != 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] != 3)
                {
                    // Parede C + 90º
                    al_draw_rotated_bitmap(imagem->parede[2], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                }
                else if(mapa[iMenos][j] == 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] != 3)
                {
                    // Parede C + 180º
                    al_draw_rotated_bitmap(imagem->parede[2], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }
                else if(mapa[iMenos][j] != 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] == 3)
                {
                    // Parede C + 270º
                    al_draw_rotated_bitmap(imagem->parede[2], TAMANHO_BLOCO, 0, posAtualX, posAtualY, 270 * M_PI / 180, 0);
                }

                // Desenha as Paredes D
                if(mapa[iMenos][j] == 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] == 3)
                {
                    // Parede Dº
                    al_draw_rotated_bitmap(imagem->parede[3], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }
                else if(mapa[iMais][j] == 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] == 3)
                {
                    // Parede D + 180º
                    al_draw_rotated_bitmap(imagem->parede[3], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }

                // Desenha as Paredes E
                if(mapa[iMenos][j] != 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] != 3)
                {
                    // Parede E
                    al_draw_rotated_bitmap(imagem->parede[4], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }
                break;
            case 4:
                // Desenha as Paredes F
                if(mapa[iMenos][j] != 4 && mapa[iMais][j] == 4 && mapa[i][jMenos] != 4 && mapa[i][jMais] == 4)
                {
                    // Parede F
                    al_draw_rotated_bitmap(imagem->parede[5], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }
                else if(mapa[iMenos][j] != 4 && mapa[iMais][j] == 4 && mapa[i][jMenos] == 4 && mapa[i][jMais] != 4)
                {
                    // Parede F + 90º
                    al_draw_rotated_bitmap(imagem->parede[5], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                }
                else if(mapa[iMenos][j] == 4 && mapa[iMais][j] != 4 && mapa[i][jMenos] == 4 && mapa[i][jMais] != 4)
                {
                    // Parede F + 180º
                    al_draw_rotated_bitmap(imagem->parede[5], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }
                else if(mapa[iMenos][j] == 4 && mapa[iMais][j] != 4 && mapa[i][jMenos] != 4 && mapa[i][jMais] == 4)
                {
                    // Parede F + 270º
                    al_draw_rotated_bitmap(imagem->parede[5], 35, 0, posAtualX, posAtualY, 270 * M_PI / 180, 0);
                }

                if(mapa[iMenos][j] == 4 && mapa[iMais][j] == 4 && mapa[i][jMenos] != 4 && mapa[i][jMais] != 4)
                {
                    // Parede G Vertical
                    if(j < 10)
                    {
                        al_draw_rotated_bitmap(imagem->parede[6], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                    }
                    else
                    {
                        al_draw_rotated_bitmap(imagem->parede[6], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                    }
                }
                else if(mapa[iMenos][j] != 4 && mapa[iMais][j] != 4 && mapa[i][jMenos] == 4 && mapa[i][jMais] == 4)
                {
                    // Parede G Horizontal
                    if(i < 10)
                    {
                        al_draw_rotated_bitmap(imagem->parede[6], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                    }
                    else
                    {
                        al_draw_rotated_bitmap(imagem->parede[6], TAMANHO_BLOCO, 0, posAtualX, posAtualY, 270 * M_PI / 180, 0);
                    }
                }

                break;
            case 5:
                if(j < 10)
                {
                    // Seta
                    al_draw_rotated_bitmap(imagem->bloco[2], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }
                else
                {
                    // Seta + 180º
                    al_draw_rotated_bitmap(imagem->bloco[2], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }
                break;
            }
            posAtualX += TAMANHO_BLOCO;
        }
        posAtualX = X_MAPA;
        posAtualY += TAMANHO_BLOCO;
    }
}

// Função que movimenta o Boneco
void moveJogador(PERSONAGEM *jogador, int mapa[COL][LIN], char sentido)
{
    switch(sentido)
    {
    case 'U':
        jogador->linha--;

        if(mapa[jogador->linha][jogador->coluna] != 3 && mapa[jogador->linha][jogador->coluna] != 4)
        {
            jogador->colunaAnt = jogador->coluna;
            jogador->linhaAnt = jogador->linha;
        }
        else
        {
            jogador->linha++;
        }

        if(jogador->linha == -1)
        {
            jogador->linha = 18;
        }
        break;
    case 'D':
        jogador->linha++;

        if(mapa[jogador->linha][jogador->coluna] != 3 && mapa[jogador->linha][jogador->coluna] != 4)
        {
            jogador->colunaAnt = jogador->coluna;
            jogador->linhaAnt = jogador->linha;
        }
        else
        {
            jogador->linha--;
        }

        if(jogador->linha == 19)
        {
            jogador->linha = 0;
        }
        break;
    case 'L':
        jogador->coluna--;

        if(mapa[jogador->linha][jogador->coluna] != 3 && mapa[jogador->linha][jogador->coluna] != 4)
        {
            jogador->colunaAnt = jogador->coluna;
            jogador->linhaAnt = jogador->linha;
        }
        else
        {
            jogador->coluna++;
        }

        // Pula pro lado direito do mapa
        if(jogador->coluna == -1)
        {
            jogador->coluna = 20;
        }
        break;
    case 'R':
        jogador->coluna++;

        if(mapa[jogador->linha][jogador->coluna] != 3 && mapa[jogador->linha][jogador->coluna] != 4)
        {
            jogador->colunaAnt = jogador->coluna;
            jogador->linhaAnt = jogador->linha;
        }
        else
        {
            jogador->coluna--;
        }

        // Pula pro lado esquerdo do mapa
        if(jogador->coluna == 21)
        {
            jogador->coluna = 0;
        }
        break;
    }

    // Soma pontos +1
    if(mapa[jogador->linha][jogador->coluna] == 1)
    {
        mapa[jogador->linha][jogador->coluna] = 0;
        jogador->pontosParcial++;
        jogador->pontosTotal++;
    }

    // Soma pontos +10
    if(mapa[jogador->linha][jogador->coluna] == 2)
    {
        mapa[jogador->linha][jogador->coluna] = 0;
        jogador->pontosParcial += 10;
        jogador->pontosTotal += 10;
    }
}

// Função que movimenta o Inimigo
void movePredador(PERSONAGEM predador[], PERSONAGEM *jogador, int predadorAtual, int mapa[COL][LIN])
{
    float distancia[4];
    float menorDistancia = 0;
    int menorSentido = 0;
    int i;

    predador[predadorAtual].linha--;

    if(mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 3 && mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 4)
    {
        distancia[0] = calculaDistancia(jogador, predador, predadorAtual, mapa[COL][LIN]);
    }
    else
    {
        distancia[0] = 99;
    }

    predador[predadorAtual].linha += 2;

    if(mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 3 && mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 4)
    {
        distancia[1] = calculaDistancia(jogador, predador, predadorAtual, mapa[COL][LIN]);
    }
    else
    {
        distancia[1] = 99;
    }

    predador[predadorAtual].linha--;
    predador[predadorAtual].coluna--;

    if(mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 3 && mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 4)
    {
        distancia[2] = calculaDistancia(jogador, predador, predadorAtual, mapa[COL][LIN]);
    }
    else
    {
        distancia[2] = 99;
    }

    predador[predadorAtual].coluna += 2;

    if(mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 3 && mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 4)
    {
        distancia[3] = calculaDistancia(jogador, predador, predadorAtual, mapa[COL][LIN]);
    }
    else
    {
        distancia[3] = 99;
    }

    predador[predadorAtual].coluna--;

    menorDistancia = distancia[0];

    for(i = 0; i < 4; i++)
    {
        if(distancia[i] <= menorDistancia && distancia[i] != 99)
        {
            menorDistancia = distancia[i];
            menorSentido = i;
        }
    }

        switch(menorSentido)
        {
        case 0:
            predador[predadorAtual].linha--;
            break;
        case 1:
            predador[predadorAtual].linha++;
            break;
        case 2:
            predador[predadorAtual].coluna--;
            break;
        case 3:
            predador[predadorAtual].coluna++;
            break;
        }

}

// Função que solta as Teclas pressionadas
void desabilitaTeclas(bool keys[])
{
    int i;

    for(i = 0; i < 7; i++)
    {
        keys[i] = false;
    }
}

float calculaDistancia(PERSONAGEM *jogador, PERSONAGEM predador[], int predadorAtual, int mapa[COL][LIN])
{
        float distancia = sqrt(pow((jogador->coluna - predador[predadorAtual].coluna), 2) + pow((jogador->linha - predador[predadorAtual].linha), 2));
        return distancia;
}
