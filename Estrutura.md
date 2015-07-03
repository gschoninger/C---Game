# Estrutura do Jogo

A seguir estão declarado as funções desenvolvidas para o funcionamento do jogo:


## void desenhaJogador(JOGADOR *jogador);

* Esta função, utiliza a posição do jogador no mapa (posição matricial), e imprime o bitmap do mesmo.

## void moveJogador(JOGADOR *jogador, VALENTAO valentao[], int mapa[COL][LIN], char sentido, int valentaoAtual);

* Esta função testa as colisoes com os blocos do mapa, e atualiza a posição se possível.

## void desenhaValentao(VALENTAO valentao[], JOGADOR *jogador, int numeroValentao);

* Esta função, utiliza a posição do jogador no mapa (posição matricial), e imprime o bitmap dos quatro valentões.

## void moveValentao(VALENTAO valentao[], JOGADOR *jogador, int valentaoAtual, int mapa[COL][LIN]);

* Esta função testa as colisoes dos valentões com os blocos do mapa e livros. Também realiza os movimentos baseado na distância em relação ao jogador // Coresponde também a IA dos valentões.

## void desenhaInfo(JOGADOR *jogador, INFO *info, LIVROS *livros);

* Desenha os elementos gráficos de Pontuação, Porcentagem do Mapa concluída, Vidas e Livros disponíveis

## 	void desenhaMapa(int mapa[COL][LIN], IMAGEM *imagem);

* Desenha os blocos de bitmap que compoe o mapa, faz isso em função dos elementos numericos da matriz, reconhecendo qual será as conexões que fará com as redondezas e então selecion a qual tipo de bitmap irá imprimir, e qual será o seu angulo de rotação.



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

## 	void desenhaPontuacao(JOGADOR *jogador, INFO *info);

* desenha a pontuação total na tela final do jogo

## 	void compraLivros(JOGADOR *jogador, LIVROS *livros);

* Compara a pontuação até o momento e se disponível, adiciona livros a estrututra.

## 	void largaLivros(JOGADOR *jogador, int mapa[COL][LIN], LIVROS *livros);

* Libera os livros e os imprime na posição do jogador, ao mover os livros continuam, e ao morrer os livros desaparecem.

## 	float calculaDistancia(JOGADOR *jogador, VALENTAO valentao[], int valentaoAtual, int mapa[COL][LIN]);

* Calcula a distância entre o jogador e cada um dos predadores usando as cordenadas de linhas e colunas da matriz.

## 	void desabilitaTeclas(bool keys[]);

* Desabilita as teclas para que o evento de tecla pressionada não esteja ativo sempre.



# Comandos

Setas	Movimentam o jogador
C		Compra livros
D		Derruba os livros
P		Pausa o jogo
Enter	Avança
Esc		Fecha