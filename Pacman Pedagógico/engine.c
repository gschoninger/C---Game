// Defini��es, bibliotecas e prot�tipos de fun��es
#include "defines.h"

// Fun��o que desenha o Jogador
void desenhaJogador(JOGADOR *jogador)
{
    // Desenha o Jogador
    al_draw_bitmap(jogador->sprite, TAMANHO_BLOCO * jogador->coluna + X_MAPA, TAMANHO_BLOCO * jogador->linha + Y_MAPA, 0);
}

void desenhaInfo(JOGADOR *jogador, INFO *info, LIVROS *livros)
{
    int i;

    al_draw_textf(info->fonte[FONTE_48], al_map_rgb(0,0,0), 880, 130, 0, "%d", jogador->pontos);

    // Mostra a quantidade de vidas de forma gr�fica
    for(i = 0; i < jogador->vidas; i++){
        al_draw_bitmap(info->spriteVida, 855 + (i * TAMANHO_BLOCO), 430, 0);
    }

    // Mostra a quantidade de livros de forma gr�fica
    for(i = 0; i < livros->quantidade; i++){
        al_draw_bitmap(info->iconeLivros, 835 + (i * TAMANHO_BLOCO), 600, 0);
    }

    // Desenha a moldura para a barra de pontos
    al_draw_bitmap(info->spriteMoldura, 795, 230, 0);

    // Mostra a quantidade de pontos de forma gr�fica
    for(i = 0; i < jogador->pontosColetados; i++){
        al_draw_bitmap(info->spritePontos, 800 + i, 235, 0);
    }

    jogador->pontosPercentual = jogador->pontosColetados / 2.06;
    al_draw_textf(info->fonte[FONTE_20], al_map_rgb(0,0,0), 890, 248, 0, "%d%%", jogador->pontosPercentual);
}

// Fun��o que desenha o Valent�o
void desenhaValentao(VALENTAO valentao[], int numeroValentao)
{
    int valentaoAtual;

    for(valentaoAtual = 0; valentaoAtual < numeroValentao; valentaoAtual++){
        al_draw_bitmap(valentao[valentaoAtual].sprite, TAMANHO_BLOCO * valentao[valentaoAtual].coluna + X_MAPA, TAMANHO_BLOCO * valentao[valentaoAtual].linha + Y_MAPA, 0);
    }
}

// Fun��o que desenha o Mapa
void desenhaMapa(int mapa[COL][LIN], IMAGEM *imagem)
{
    int i, j;
    int posAtualX = X_MAPA;
    int posAtualY = Y_MAPA;

    for(i = 0; i < COL - 1; i++){
        for(j = 0; j < LIN - 1; j++){
            int iMais = i + 1;
            int iMenos = i - 1;
            int jMais = j + 1;
            int jMenos = j - 1;

            switch(mapa[i][j]){
            case 0:
                // Espa�o em branco
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
                if(mapa[iMenos][j] == 3 && mapa[iMais][j] == 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] != 3){
                    // Parede A
                    al_draw_rotated_bitmap(imagem->parede[0], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] != 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] == 3){
                    // Parede A + 90�
                    al_draw_rotated_bitmap(imagem->parede[0], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                }

                // Desenha as Paredes B
                if(mapa[iMenos][j] != 3 && mapa[iMais][j] == 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] == 3){
                    // Parede B
                    al_draw_rotated_bitmap(imagem->parede[1], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] != 3 && mapa[iMais][j] == 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] != 3){
                    // Parede B + 90�
                    al_draw_rotated_bitmap(imagem->parede[1], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] == 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] != 3){
                    // Parede B + 180�
                    al_draw_rotated_bitmap(imagem->parede[1], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] == 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] == 3){
                    // Parede B + 270�
                    al_draw_rotated_bitmap(imagem->parede[1], TAMANHO_BLOCO, 0, posAtualX, posAtualY, 270 * M_PI / 180, 0);
                }

                // Desenha as Paredes C
                if(mapa[iMenos][j] != 3 && mapa[iMais][j] == 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] != 3){
                    // Parede C
                    al_draw_rotated_bitmap(imagem->parede[2], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] != 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] != 3){
                    // Parede C + 90�
                    al_draw_rotated_bitmap(imagem->parede[2], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] == 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] != 3){
                    // Parede C + 180�
                    al_draw_rotated_bitmap(imagem->parede[2], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] != 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] == 3){
                    // Parede C + 270�
                    al_draw_rotated_bitmap(imagem->parede[2], TAMANHO_BLOCO, 0, posAtualX, posAtualY, 270 * M_PI / 180, 0);
                }

                // Desenha as Paredes D
                if(mapa[iMenos][j] == 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] == 3){
                    // Parede D�
                    al_draw_rotated_bitmap(imagem->parede[3], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }else if(mapa[iMais][j] == 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] == 3){
                    // Parede D + 180�
                    al_draw_rotated_bitmap(imagem->parede[3], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }

                // Desenha as Paredes E
                if(mapa[iMenos][j] != 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] != 3){
                    // Parede E
                    al_draw_rotated_bitmap(imagem->parede[4], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }
                break;
            case 4:
                // Desenha as Paredes F
                if(mapa[iMenos][j] != 4 && mapa[iMais][j] == 4 && mapa[i][jMenos] != 4 && mapa[i][jMais] == 4){
                    // Parede F
                    al_draw_rotated_bitmap(imagem->parede[5], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] != 4 && mapa[iMais][j] == 4 && mapa[i][jMenos] == 4 && mapa[i][jMais] != 4){
                    // Parede F + 90�
                    al_draw_rotated_bitmap(imagem->parede[5], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] == 4 && mapa[iMais][j] != 4 && mapa[i][jMenos] == 4 && mapa[i][jMais] != 4){
                    // Parede F + 180�
                    al_draw_rotated_bitmap(imagem->parede[5], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] == 4 && mapa[iMais][j] != 4 && mapa[i][jMenos] != 4 && mapa[i][jMais] == 4){
                    // Parede F + 270�
                    al_draw_rotated_bitmap(imagem->parede[5], 35, 0, posAtualX, posAtualY, 270 * M_PI / 180, 0);
                }

                if(mapa[iMenos][j] == 4 && mapa[iMais][j] == 4 && mapa[i][jMenos] != 4 && mapa[i][jMais] != 4){
                    // Parede G Vertical
                    if(j < 10){
                        al_draw_rotated_bitmap(imagem->parede[6], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                    }else{
                        al_draw_rotated_bitmap(imagem->parede[6], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                    }
                }else if(mapa[iMenos][j] != 4 && mapa[iMais][j] != 4 && mapa[i][jMenos] == 4 && mapa[i][jMais] == 4){
                    // Parede G Horizontal
                    if(i < 10){
                        al_draw_rotated_bitmap(imagem->parede[6], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                    }else{
                        al_draw_rotated_bitmap(imagem->parede[6], TAMANHO_BLOCO, 0, posAtualX, posAtualY, 270 * M_PI / 180, 0);
                    }
                }

                break;
            case 5:
                if(j < 10){
                    // Seta
                    al_draw_rotated_bitmap(imagem->bloco[2], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }else{
                    // Seta + 180�
                    al_draw_rotated_bitmap(imagem->bloco[2], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }
                break;
            case 6:
                al_draw_bitmap(imagem->livros, posAtualX , posAtualY, 0);
                break;
            }
            posAtualX += TAMANHO_BLOCO;
        }
        posAtualX = X_MAPA;
        posAtualY += TAMANHO_BLOCO;
    }
}

// Fun��o que movimenta o Jogador
void moveJogador(JOGADOR *jogador, VALENTAO valentao[], int mapa[COL][LIN], char sentido, int numeroValentao)
{
    int valentaoAtual;

    switch(sentido){
    case 'U':
        jogador->linha--;

        if(mapa[jogador->linha][jogador->coluna] != 3 && mapa[jogador->linha][jogador->coluna] != 4){
            jogador->colunaAnt = jogador->coluna;
            jogador->linhaAnt = jogador->linha;
        }else{
            jogador->linha++;
        }

        if(jogador->linha == -1){
            jogador->linha = 18;
        }
        break;
    case 'D':
        jogador->linha++;

        if(mapa[jogador->linha][jogador->coluna] != 3 && mapa[jogador->linha][jogador->coluna] != 4){
            jogador->colunaAnt = jogador->coluna;
            jogador->linhaAnt = jogador->linha;
        }else{
            jogador->linha--;
        }

        if(jogador->linha == 19){
            jogador->linha = 0;
        }
        break;
    case 'L':
        jogador->coluna--;

        if(mapa[jogador->linha][jogador->coluna] != 3 && mapa[jogador->linha][jogador->coluna] != 4){
            jogador->colunaAnt = jogador->coluna;
            jogador->linhaAnt = jogador->linha;
        }else{
            jogador->coluna++;
        }

        // Pula pro lado direito do mapa
        if(jogador->coluna == -1){
            jogador->coluna = 20;
        }
        break;
    case 'R':
        jogador->coluna++;

        if(mapa[jogador->linha][jogador->coluna] != 3 && mapa[jogador->linha][jogador->coluna] != 4)
        {
            jogador->colunaAnt = jogador->coluna;
            jogador->linhaAnt = jogador->linha;
        }else{
            jogador->coluna--;
        }

        // Pula pro lado esquerdo do mapa
        if(jogador->coluna == 21){
            jogador->coluna = 0;
        }
        break;
    }

    // Soma pontos +1
    if(mapa[jogador->linha][jogador->coluna] == 1){
        mapa[jogador->linha][jogador->coluna] = 0;
        jogador->pontos++;
        jogador->pontosColetados++;
    }

    // Soma pontos +10
    if(mapa[jogador->linha][jogador->coluna] == 2){
        mapa[jogador->linha][jogador->coluna] = 0;
        jogador->pontos += 10;
        jogador->pontosColetados += 10;
    }

    for(valentaoAtual = 0; valentaoAtual < numeroValentao; valentaoAtual++){
        if(jogador->coluna == valentao[valentaoAtual].coluna && jogador->linha == valentao[valentaoAtual].linha){
            jogador->vidas--;
            jogador->linha = JOGADOR_LINHA;
            jogador->coluna = JOGADOR_COLUNA;
        }
    }
}

// Fun��o que movimenta o Valent�o
void moveValentao(VALENTAO valentao[], JOGADOR *jogador, int valentaoAtual, int mapa[COL][LIN])
{
    // inserir a fun��o de movimento do Valent�o
}

// Fun��o que solta as Teclas pressionadas
void desabilitaTeclas(bool keys[])
{
    int i;

    for(i = 0; i < 9; i++){
        keys[i] = false;
    }
}

// Fun��o que calcula a dist�ncia entre dois pontos da matriz
float calculaDistancia(JOGADOR *jogador, VALENTAO valentao[], int valentaoAtual, int mapa[COL][LIN])
{
        float distancia = sqrt(pow((jogador->coluna - valentao[valentaoAtual].coluna), 2) + pow((jogador->linha - valentao[valentaoAtual].linha), 2));
        return distancia;
}

void compraLivros(JOGADOR *jogador, LIVROS *livros)
{
    if(jogador->pontos > PONTOS_LIVRO && livros->quantidade < 4){
        livros->quantidade++;
        jogador->pontos -= PONTOS_LIVRO;
    }
}

void largaLivros(JOGADOR *jogador, int mapa[COL][LIN], LIVROS *livros)
{
    if(livros->quantidade > 0){
        mapa[jogador->linha][jogador->coluna] = 6;
        livros->quantidade--;
    }
}

void desenhaPontuacao(JOGADOR *jogador, INFO *info)
{
    al_draw_textf(info->fonte[FONTE_300], al_map_rgb(0,0,0), 100, 425, 0, "%d%%", jogador->pontosPercentual);
}
