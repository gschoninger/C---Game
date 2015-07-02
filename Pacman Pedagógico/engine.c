// Definições, bibliotecas e protótipos de funções
#include "defines.h"

// Função que desenha o Jogador
void desenhaJogador(PERSONAGEM *jogador, INFO *info)
{
    int i;

    al_draw_textf(info->fonte[3], al_map_rgb(50,10,70), 830, 200, 0, "%d", jogador->pontosTotal);

    // Desenha o Jogador
    al_draw_bitmap(jogador->sprite, TAMANHO_BLOCO * jogador->coluna + X_MAPA, TAMANHO_BLOCO * jogador->linha + Y_MAPA, 0);

    // Mostra a quantidade de vidas de forma gráfica
    for(i = 0; i < jogador->vidas; i++){
        al_draw_bitmap(info->spriteVida, 830 + (i * TAMANHO_BLOCO), 430, 0);
    }

    // Mostra a quantidade de livros de forma gráfica
    for(i = 0; i < jogador->livros; i++){
        al_draw_bitmap(info->iconeLivros, 830 + (i * TAMANHO_BLOCO), 630, 0);
    }

    // Desenha a moldura para a barra de pontos
    al_draw_bitmap(info->spriteMoldura, 830, 250, 0);

    // Mostra a quantidade de pontos de forma gráfica
    for(i = 0; i < jogador->pontosParcial; i++){
        if(jogador->pontosParcial > 30){
            jogador->pontosParcial -= 30;
        }

        al_draw_bitmap(info->spritePontos, 835 + (i * 5), 255, 0);
    }
}

// Função que desenha o Valentão
void desenhaPredador(PERSONAGEM predador[], PERSONAGEM *jogador, int numeroPredador)
{
    int predadorAtual;

    for(predadorAtual = 0; predadorAtual < numeroPredador; predadorAtual++){
        if(predador[0].linha == predador[1].linha && predador[0].coluna == predador[1].coluna)
        {
        al_draw_bitmap((al_load_bitmap("Sprites/Jogador/Jogador.bmp")), TAMANHO_BLOCO * predador[0].coluna + X_MAPA, TAMANHO_BLOCO * predador[0].linha + Y_MAPA, 0);
        al_draw_bitmap((al_load_bitmap("Sprites/Jogador/Jogador.bmp")), TAMANHO_BLOCO * predador[1].coluna + X_MAPA, TAMANHO_BLOCO * predador[1].linha + Y_MAPA, 0);
        }
        else
        {
        al_draw_bitmap(predador[predadorAtual].sprite, TAMANHO_BLOCO * predador[predadorAtual].coluna + X_MAPA, TAMANHO_BLOCO * predador[predadorAtual].linha + Y_MAPA, 0);
        }
        if(predador[0].linha == predador[2].linha && predador[0].coluna == predador[2].coluna)
        {
        al_draw_bitmap((al_load_bitmap("Sprites/Jogador/Jogador.bmp")), TAMANHO_BLOCO * predador[0].coluna + X_MAPA, TAMANHO_BLOCO * predador[0].linha + Y_MAPA, 0);
        al_draw_bitmap((al_load_bitmap("Sprites/Jogador/Jogador.bmp")), TAMANHO_BLOCO * predador[2].coluna + X_MAPA, TAMANHO_BLOCO * predador[2].linha + Y_MAPA, 0);
        }
        else
        {
        al_draw_bitmap(predador[predadorAtual].sprite, TAMANHO_BLOCO * predador[predadorAtual].coluna + X_MAPA, TAMANHO_BLOCO * predador[predadorAtual].linha + Y_MAPA, 0);
        }
        if(predador[0].linha == predador[3].linha && predador[0].coluna == predador[3].coluna)
        {
        al_draw_bitmap((al_load_bitmap("Sprites/Jogador/Jogador.bmp")), TAMANHO_BLOCO * predador[0].coluna + X_MAPA, TAMANHO_BLOCO * predador[0].linha + Y_MAPA, 0);
        al_draw_bitmap((al_load_bitmap("Sprites/Jogador/Jogador.bmp")), TAMANHO_BLOCO * predador[3].coluna + X_MAPA, TAMANHO_BLOCO * predador[3].linha + Y_MAPA, 0);
        }
        else
        {
        al_draw_bitmap(predador[predadorAtual].sprite, TAMANHO_BLOCO * predador[predadorAtual].coluna + X_MAPA, TAMANHO_BLOCO * predador[predadorAtual].linha + Y_MAPA, 0);
        }
        if(predador[1].linha == predador[2].linha && predador[1].coluna == predador[2].coluna)
        {
        al_draw_bitmap((al_load_bitmap("Sprites/Jogador/Jogador.bmp")), TAMANHO_BLOCO * predador[1].coluna + X_MAPA, TAMANHO_BLOCO * predador[1].linha + Y_MAPA, 0);
        al_draw_bitmap((al_load_bitmap("Sprites/Jogador/Jogador.bmp")), TAMANHO_BLOCO * predador[2].coluna + X_MAPA, TAMANHO_BLOCO * predador[2].linha + Y_MAPA, 0);
        }
        else
        {
        al_draw_bitmap(predador[predadorAtual].sprite, TAMANHO_BLOCO * predador[predadorAtual].coluna + X_MAPA, TAMANHO_BLOCO * predador[predadorAtual].linha + Y_MAPA, 0);
        }
        if(predador[1].linha == predador[3].linha && predador[1].coluna == predador[3].coluna)
        {
        al_draw_bitmap((al_load_bitmap("Sprites/Jogador/Jogador.bmp")), TAMANHO_BLOCO * predador[1].coluna + X_MAPA, TAMANHO_BLOCO * predador[1].linha + Y_MAPA, 0);
        }
        else
        {
        al_draw_bitmap(predador[predadorAtual].sprite, TAMANHO_BLOCO * predador[predadorAtual].coluna + X_MAPA, TAMANHO_BLOCO * predador[predadorAtual].linha + Y_MAPA, 0);
        }
        if(predador[2].linha == predador[3].linha && predador[2].coluna == predador[3].coluna)
        {
        al_draw_bitmap((al_load_bitmap("Sprites/Jogador/Jogador.bmp")), TAMANHO_BLOCO * predador[2].coluna + X_MAPA, TAMANHO_BLOCO * predador[2].linha + Y_MAPA, 0);
        al_draw_bitmap((al_load_bitmap("Sprites/Jogador/Jogador.bmp")), TAMANHO_BLOCO * predador[3].coluna + X_MAPA, TAMANHO_BLOCO * predador[3].linha + Y_MAPA, 0);
        }
        else
        {
        al_draw_bitmap(predador[predadorAtual].sprite, TAMANHO_BLOCO * predador[predadorAtual].coluna + X_MAPA, TAMANHO_BLOCO * predador[predadorAtual].linha + Y_MAPA, 0);
        }
}
}
// Função que desenha o Mapa
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
                if(mapa[iMenos][j] == 3 && mapa[iMais][j] == 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] != 3){
                    // Parede A
                    al_draw_rotated_bitmap(imagem->parede[0], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] != 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] == 3){
                    // Parede A + 90º
                    al_draw_rotated_bitmap(imagem->parede[0], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                }

                // Desenha as Paredes B
                if(mapa[iMenos][j] != 3 && mapa[iMais][j] == 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] == 3){
                    // Parede B
                    al_draw_rotated_bitmap(imagem->parede[1], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] != 3 && mapa[iMais][j] == 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] != 3){
                    // Parede B + 90º
                    al_draw_rotated_bitmap(imagem->parede[1], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] == 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] != 3){
                    // Parede B + 180º
                    al_draw_rotated_bitmap(imagem->parede[1], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] == 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] == 3){
                    // Parede B + 270º
                    al_draw_rotated_bitmap(imagem->parede[1], TAMANHO_BLOCO, 0, posAtualX, posAtualY, 270 * M_PI / 180, 0);
                }

                // Desenha as Paredes C
                if(mapa[iMenos][j] != 3 && mapa[iMais][j] == 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] != 3){
                    // Parede C
                    al_draw_rotated_bitmap(imagem->parede[2], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] != 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] != 3){
                    // Parede C + 90º
                    al_draw_rotated_bitmap(imagem->parede[2], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] == 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] != 3){
                    // Parede C + 180º
                    al_draw_rotated_bitmap(imagem->parede[2], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] != 3 && mapa[iMais][j] != 3 && mapa[i][jMenos] != 3 && mapa[i][jMais] == 3){
                    // Parede C + 270º
                    al_draw_rotated_bitmap(imagem->parede[2], TAMANHO_BLOCO, 0, posAtualX, posAtualY, 270 * M_PI / 180, 0);
                }

                // Desenha as Paredes D
                if(mapa[iMenos][j] == 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] == 3){
                    // Parede Dº
                    al_draw_rotated_bitmap(imagem->parede[3], 0, 0, posAtualX, posAtualY, 0 * M_PI / 180, 0);
                }else if(mapa[iMais][j] == 3 && mapa[i][jMenos] == 3 && mapa[i][jMais] == 3){
                    // Parede D + 180º
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
                    // Parede F + 90º
                    al_draw_rotated_bitmap(imagem->parede[5], 0, TAMANHO_BLOCO, posAtualX, posAtualY, 90 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] == 4 && mapa[iMais][j] != 4 && mapa[i][jMenos] == 4 && mapa[i][jMais] != 4){
                    // Parede F + 180º
                    al_draw_rotated_bitmap(imagem->parede[5], TAMANHO_BLOCO, TAMANHO_BLOCO, posAtualX, posAtualY, 180 * M_PI / 180, 0);
                }else if(mapa[iMenos][j] == 4 && mapa[iMais][j] != 4 && mapa[i][jMenos] != 4 && mapa[i][jMais] == 4){
                    // Parede F + 270º
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
                    // Seta + 180º
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
// Função que movimenta o Jogador
void moveJogador(PERSONAGEM *jogador, PERSONAGEM predador[], int mapa[COL][LIN], char sentido, int predadorAtual)
{
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
        jogador->pontosParcial++;
        jogador->pontosTotal++;
    }

    // Soma pontos +10
    if(mapa[jogador->linha][jogador->coluna] == 2){
        mapa[jogador->linha][jogador->coluna] = 0;
        jogador->pontosParcial += 10;
        jogador->pontosTotal += 10;
    }
        for(predadorAtual = 0; predadorAtual < 4; predadorAtual++)
        {

            if(jogador->coluna == predador[predadorAtual].coluna && jogador->linha == predador[predadorAtual].linha)
            {
                jogador->vidas--;
                jogador->linha = JOGADOR_LINHA;
                jogador->coluna = JOGADOR_COLUNA;
            }
        }
}

// Função que movimenta o Valentão
 void movePredador(PERSONAGEM predador[], PERSONAGEM *jogador, int predadorAtual, int mapa[COL][LIN])
    {
        float distancia[4];
        float menorDistancia = 0;
        int menorSentido = 0;
        int i;


        predador[predadorAtual].linha--;

        if(mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 3
           && mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 4
           && mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 6
           && predador[predadorAtual].linha != predador[predadorAtual + 1].linha
           && predador[predadorAtual].coluna != predador[predadorAtual + 1].coluna)
        {
            distancia[0] = calculaDistancia(jogador, predador, predadorAtual, mapa);
        }
        else
        {
            distancia[0] = 99;
        }

        predador[predadorAtual].linha += 2;

        if(mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 3
           && mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 4
           && mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 6
           && predador[predadorAtual].linha != predador[predadorAtual + 1].linha
           && predador[predadorAtual].coluna != predador[predadorAtual + 1].coluna)
        {
            distancia[1] = calculaDistancia(jogador, predador, predadorAtual, mapa);
        }
        else
        {
            distancia[1] = 99;
        }

        predador[predadorAtual].linha--;
        predador[predadorAtual].coluna--;

        if(mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 3
           && mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 4
           && mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 6
           && predador[predadorAtual].linha != predador[predadorAtual + 1].linha
           && predador[predadorAtual].coluna != predador[predadorAtual + 1].coluna)
        {
            distancia[2] = calculaDistancia(jogador, predador, predadorAtual, mapa);
        }
        else
        {
            distancia[2] = 99;
        }

        predador[predadorAtual].coluna += 2;

        if(mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 3
           && mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 4
           && mapa[predador[predadorAtual].linha][predador[predadorAtual].coluna] != 6
           && predador[predadorAtual].linha != predador[predadorAtual + 1].linha
           && predador[predadorAtual].coluna != predador[predadorAtual + 1].coluna)
        {
            distancia[3] = calculaDistancia(jogador, predador, predadorAtual, mapa);
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
        for(predadorAtual = 0; predadorAtual < 4; predadorAtual++)
        {

            if(jogador->coluna == predador[predadorAtual].coluna && jogador->linha == predador[predadorAtual].linha)
            {
                jogador->vidas--;
               jogador->linha = JOGADOR_LINHA;
                jogador->coluna = JOGADOR_COLUNA;            }
       }
    }


// Função que solta as Teclas pressionadas
void desabilitaTeclas(bool keys[])
{
    int i;

    for(i = 0; i < 9; i++){
        keys[i] = false;
    }
}

// Função que calcula a distância entre dois pontos da matriz
float calculaDistancia(PERSONAGEM *jogador, PERSONAGEM predador[], int predadorAtual, int mapa[COL][LIN])
{
        float distancia = sqrt(pow((jogador->coluna - predador[predadorAtual].coluna), 2) + pow((jogador->linha - predador[predadorAtual].linha), 2));
        return distancia;
}

void compraLivros(PERSONAGEM *jogador)
{
    if(jogador->pontosTotal > 10 && jogador->livros < 5){
        jogador->livros++;
        jogador->pontosTotal -= 10;
        jogador->pontosParcial -= 10;
    }
}

void largaLivros(PERSONAGEM *jogador, int mapa[COL][LIN])
{
    if(jogador->livros > 0 && mapa[jogador->linha][jogador->coluna] != 6){
        mapa[jogador->linha][jogador->coluna] = 6;
        jogador->livros--;
    }
}
