# Senet
A palavra Senet significa passagem, e este jogo simboliza a viagem para o mundo dos mortos. Assim, encontram-se representações de pessoas a jogar ao Senet contra um adversário ausente nos monumentos fúnebres. A ausência de adversário humano indica a presença de Osíris, deus do além. O jogo é considerado o antepassado egípcio do Gamão e os tabuleiros mais antigos encontrados têm cerca de 5000 anos.

# Criação do código
O código foi feito enquanto estava no primeiro semestre do curso de Engenharia de Computação, para a disciplina de Laboratório de Programação, e, portanto, possui possíveis erros e pode não ser o mais eficiente possível, mas foi feito com carinho :).

# O jogo
O jogo consiste em um tabuleiro com 30 casas, 3 linhas com 10 colunas, no qual já estão posicionadas as 5 peças de cada jogador na primeira linha. O objetivo do jogo é fazer com que as peças avancem as casas até saírem do tabuleiro e, ao retirar todas as peças, o jogador vence. Para a movimentação das peças é utilizado um sistema de sorteio rudimentar, com o uso de estiletes, que são pedaços de madeira com duas faces, simulando um dado de duas faces. São jogados 4 estiletes por rodada, e a soma é feita a partir da quantidade de faces planar viradas para cima, sendo que quando não houver nenhuma a soma será 6.

# Regras
1. Os jogadores lançam alternadamente os estiletes até que um deles obtenha 1. Esse jogador escolhe qual peça deseja utilizar, e, feito sua escolha, suas peças são posicionadas nas casas de numeração par. O mesmo jogador lança os estiletes novamente para iniciar sua jogada.
Se o lançamento for de 1, 4 ou 6, o jogador move uma das suas peças o correspondente número de casas e lança novamente os estiletes.
Se o lançamento for de 2 ou 3, o jogador move uma das suas peças o correspondente número de casas e passa a vez ao adversário. O segundo jogador lança os quatro estiletes e começa por mover a peça posicionada na casa 9. Depois disso qualquer peça pode ser movimentada.

2. O jogo continua com o primeiro jogador. Sempre que se tirar 1, 4 ou 6 a vez se mantém, quando sair 2 ou 3, a vez muda.

3. Quando a peça cai numa casa ocupada por uma peça adversária, esta diz-se atacada e as peças trocam de posição.

4. Cada casa só pode conter uma peça.

5. Duas peças do mesmo jogador em casas consecutivas protegem-se mutuamente, não podendo ser atacadas.

6. Se um jogador não tiver nenhuma jogada permitida a vez passa para o adversário.

8. Se uma peça cair na casa 27 vai imediatamente para a casa 15. Se esta casa estiver ocupada, então a peça deve ser recolocada no início do tabuleiro, a partir da quantidade tirada nos estiletes.

9. As casas 26, 28 e 29 são seguras, não podendo ser atacadas.

10. A peça que chegar na casa 30 sai do tabuleiro, desde que o jogador não tenha peças na primeira fileira do tabuleiro, caso contrário, ela permanecerá na casa 30, podendo ser atacada, até que sejam retiradas da primeira fileira todas as peças do jogador.
