/*
|------------------------------------------------------------------------------------------|
|    Jogo educacional desenvolvido para a disciplina de Programação em Linguagemm C por    |
|------------------------------------------------------------------------------------------|
|               Gabriel Bolgenhagen Schöninger e Vitor Volpato Goulart                     |
|------------------------------------------------------------------------------------------|
|                      Utilizando a biblioteca Allegro 5.0.10                              |
|------------------------------------------------------------------------------------------|
*/

// Definições, bibliotecas e protótipos de funções
#include "defines.h"

int main(void)
{
    // Tamanho da tela
    int largura = LARGURA_TELA;
    int altura = ALTURA_TELA;

    int predadorAtual = 0;
    int numeroPredador = 1;

    // Criação da Estrutura Boneco
    PERSONAGEM jogador;
    PERSONAGEM predador[numeroPredador];

    IMAGEM imagem;
    INFO info;
    TELAS telas;

    telas.telaAtual = TELA_INICIAL;
    telas.proximaTela = JOGO_RODANDO;

    // Posição inicial do personagem
    jogador.linha = JOGADOR_LINHA;
    jogador.coluna = JOGADOR_COLUNA;
    jogador.pontosParcial = JOGADOR_PARCIAL;
    jogador.pontosTotal = JOGADOR_TOTAL;
    jogador.vidas = JOGADOR_VIDAS;
    jogador.livros = JOGADOR_LIVROS;

    predador[0].linha = 1;
    predador[0].coluna = 1;

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
    int FPS = QUADROS;
    int contaTimer = 0;

    // Vetor das Teclas pressionadas
    bool keys[9] = {false, false, false, false, false, false, false, false, false};

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_FONT *fonte = NULL;

    // Testa a inicialização do Allegro
    if(!al_init())
        return -1;

    // Cria e testa o Display
    if(FULLSCREEN)
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

    imagem.livros = al_load_bitmap("Sprites/Blocos/Livros.bmp");

    imagem.parede[0] = al_load_bitmap("Sprites/Paredes/ParedeA.bmp");
    imagem.parede[1] = al_load_bitmap("Sprites/Paredes/ParedeB.bmp");
    imagem.parede[2] = al_load_bitmap("Sprites/Paredes/ParedeC.bmp");
    imagem.parede[3] = al_load_bitmap("Sprites/Paredes/ParedeD.bmp");
    imagem.parede[4] = al_load_bitmap("Sprites/Paredes/ParedeE.bmp");
    imagem.parede[5] = al_load_bitmap("Sprites/Paredes/ParedeF.bmp");
    imagem.parede[6] = al_load_bitmap("Sprites/Paredes/ParedeG.bmp");

    jogador.sprite = al_load_bitmap("Sprites/Jogador/Jogador.bmp");

    for(predadorAtual = 0; predadorAtual < numeroPredador; predadorAtual++){
        predador[predadorAtual].sprite = al_load_bitmap("Sprites/Predador/Predador.bmp");
    }

    info.spriteVida = al_load_bitmap("Sprites/Icones/Vida.bmp");
    info.spritePontos = al_load_bitmap("Sprites/Icones/Ponto.bmp");
    info.spriteMoldura = al_load_bitmap("Sprites/Icones/MolduraPonto.bmp");
    info.iconeLivros = al_load_bitmap("Sprites/Blocos/Livros.bmp");

    telas.inicialA = al_load_bitmap("Sprites/Telas/InicialA.bmp");
    telas.inicialB= al_load_bitmap("Sprites/Telas/InicialB.bmp");
    telas.instrucao = al_load_bitmap("Sprites/Telas/Instrucao.bmp");
    telas.jogo = al_load_bitmap("Sprites/Telas/Jogo.bmp");
    telas.pausa = al_load_bitmap("Sprites/Telas/Pausa.bmp");
    telas.creditos = al_load_bitmap("Sprites/Telas/Creditos.bmp");
    telas.ganhou = al_load_bitmap("Sprites/Telas/Ganhou.bmp");
    telas.perdeu = al_load_bitmap("Sprites/Telas/Perdeu.bmp");

    info.fonte[0] = al_load_ttf_font("Fontes/pac.ttf", 20, 0);
    info.fonte[1] = al_load_ttf_font("Fontes/arc-classic.ttf", 28, 0);
    info.fonte[2] = al_load_ttf_font("Fontes/presstart.ttf", 18, 0); // Fonte Tela de Inicio
    info.fonte[3] = al_load_ttf_font("Fontes/bit-led.ttf", 25, 0); // Fonte Atual tela do Jogo
    info.fonte[4] = al_load_ttf_font("Fontes/presstart.ttf", 30, 0);
    info.fonte[5] = al_load_ttf_font("Fontes/presstart.ttf", 22, 0);

    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    // Laço de repetição, enquanto ESC não for pressionado
    while(!done){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        // Testa o pressionamento de teclas
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            switch(ev.keyboard.keycode){
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
            case ALLEGRO_KEY_C:
                keys[COMPRA] = true;
                break;
            case ALLEGRO_KEY_D:
                keys[LARGA] = true;
                break;
            }
        }

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            done = true;
        }

        // Laço de repetição disparado pelo Timer
        if(ev.type == ALLEGRO_EVENT_TIMER){
            switch(telas.telaAtual){
            case 0:
                // Início
                if(keys[DOWN] || keys[UP]){
                    switch(telas.proximaTela){
                    case TELA_INSTRUCAO:
                        telas.proximaTela = JOGO_RODANDO;
                        break;
                    case JOGO_RODANDO:
                        telas.proximaTela = TELA_INSTRUCAO;
                        break;
                    }
                }

                switch(telas.proximaTela){
                case JOGO_RODANDO:
                    al_draw_bitmap(telas.inicialA, 0, 0, 0);
                    break;
                case TELA_INSTRUCAO:
                    al_draw_bitmap(telas.inicialB, 0, 0, 0);
                    break;
                }

                if(keys[ESC])
                    return 0;

                if(keys[ENTER])
                    telas.telaAtual = telas.proximaTela;
                break;
            case 1:
                // Instruções
                al_draw_bitmap(telas.instrucao, 0, 0, 0);

                if(keys[ESC])
                    return 0;

                if(keys[ENTER])
                    telas.telaAtual = JOGO_RODANDO;

                break;
            case 2:
                // Jogo rodando
                if(keys[UP]){
                    moveJogador(&jogador, predador, mapa, 'U', predadorAtual);
                }

                if(keys[DOWN])
                    moveJogador(&jogador, predador, mapa, 'D', predadorAtual);

                if(keys[LEFT])
                    moveJogador(&jogador, predador, mapa, 'L', predadorAtual);

                if(keys[RIGHT])
                    moveJogador(&jogador, predador, mapa, 'R', predadorAtual);

                if(keys[COMPRA])
                    compraLivros(&jogador);

                if(keys[LARGA])
                    largaLivros(&jogador, mapa);

                al_draw_bitmap(telas.jogo, 0, 0, 0);
                desenhaMapa(mapa, &imagem);
                desenhaJogador(&jogador, &info);
                desenhaPredador(predador, numeroPredador);

                contaTimer++;

                if(contaTimer == VELOCIDADE_PREDADOR){
                    contaTimer = 0;
                    for(predadorAtual = 0; predadorAtual < numeroPredador; predadorAtual++){
                        movePredador(predador, &jogador, predadorAtual, mapa);
                    }
                }

                if(jogador.pontosTotal == 206)
                    telas.telaAtual = TELA_GANHOU;

                if(jogador.vidas == 0)
                    telas.telaAtual = TELA_PERDEU;

                if(keys[ESC])
                    telas.telaAtual = TELA_CREDITOS;

                if(keys[PAUSA])
                    telas.telaAtual = TELA_PAUSA;

                break;
            case 3:
                // Pausa
                al_draw_bitmap(telas.pausa, 0, 0, 0);

                if(keys[ESC])
                    telas.telaAtual = TELA_CREDITOS;

                if(keys[PAUSA])
                    telas.telaAtual = JOGO_RODANDO;

                break;
            case 4:
                // Ganhou
                al_draw_bitmap(telas.ganhou, 0, 0, 0);

                if(keys[ENTER])
                    telas.telaAtual = TELA_CREDITOS;

                if(keys[ESC])
                    return 0;

                break;
            case 5:
                // Perdeu
                al_draw_bitmap(telas.perdeu, 0, 0, 0);

                if(keys[ENTER])
                    telas.telaAtual = TELA_CREDITOS;

                if(keys[ESC])
                    return 0;

                break;
            case 6:
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
        if(redraw && al_is_event_queue_empty(event_queue)){
            redraw = false;
            al_flip_display();
            al_clear_to_color(al_map_rgb(255, 255, 255));
        }
    }

    // Destrói os objetos
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_display(display);
    // Destruir Bitmaps

    return 0;
}
