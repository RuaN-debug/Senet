#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j, p = 0, a = 1, jogador, proximo, vez = 0, player1 = 0, player2 = 0;
char x[30] = {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
     o[30] = {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
     m[30], pe, ope;

void Senet(){
    printf("\n\t\t\t\t\t------------------------------------");
    printf("\n\t\t\t\t\t---------------Senet----------------");
    printf("\n\t\t\t\t\t------------------------------------");
}
int sorteiaEstilete(){ //Sorteio do estiletes
    int s;
    srand(time(NULL) * a);

    s = rand() % 2 + rand() % 2 + rand() % 2 + rand() % 2;
    a++;

    if(s == 0)
        s = 6;

    return s;
}
int escolhePeca(){ //O jogador sorteado escolhe a peca que deseja usar
    char peca;

    printf("Escolha uma peca [x/o]: ");
    do{
        scanf("%c", &peca);
        getchar();
        if(peca != 'x' && peca != 'o')
            printf("\nPeca invalida\n");
    }while(peca != 'x' && peca != 'o');

    if(peca == 'x'){
        for (i = 0; i < 30; i++){
            m[i] = x[i];
            p = 1;
        }
    }else{
        for (i = 0; i < 30; i++)
            m[i] = o[i];
    }

    return p;
}
void tabuleiro(){ //Printa o tabuleiro
    system("cls");
    printf("\n");

    printf("   0      1      2      3      4      5      6      7      8      9\n");
    for(i = 0; i < 10; i++)
        printf(" [ %c ] ", m[i]);

    printf("\n");
    printf("  19     18     17     16     15     14     13     12     11     10\n");
    for(i = 19; i >= 10; i--)
        printf(" [ %c ] ", m[i]);

    printf("\n");
    printf("  20     21     22     23     24     25     26     27     28     29\n");
    for(i = 20; i < 25; i++)
        printf(" [ %c ] ", m[i]);
    
    for(i = 25; i < 30; i++){ //Printa as letras das casas especiais
        if(m[i] == ' ')
            printf(" [ %c ] ", 40 + i);
        else
            printf(" [ %c ] ", m[i]);
    }
    printf("\n\n");
    printf("\nJogador 1 = %c\tJogador 2 = %c\n\n", pe, ope);
    printf("\n\t\t\t\t   Placar\n\n");
    printf("\t\t\tJogador 1 = %d\tJogador 2 = %d\n\n", player1, player2);
}
int conferePri(char peca){ //Confere se tem peca na primeira fileira
    for(i = 0; i < 10; i++){
        if(m[i] == peca)
            return 1;
    }
    return 0;
}
int verificaMovimento(int peca, int sorteio){
    if(peca < 0 || peca > 29) //Verifica se a peca escolhida esta no tabuleiro
        return 1;

    if((jogador == 1 && m[peca] != pe) || (jogador == 2 && m[peca] != ope)) //Verifica se a peca escolhida e uma peca do jogador
        return 1;

    if((jogador == 1 && m[peca + sorteio] == pe) || (jogador == 2 && m[peca + sorteio] == ope)) //Verifica se a casa destino nao possui uma peca do jogador
        return 1;

    if((jogador == 1 && m[peca + sorteio] == ope && (m[peca + sorteio - 1] == ope || m[peca + sorteio + 1] == ope)) || //Verifica se a casa destino possui uma peca protegida
        (jogador == 2 && m[peca + sorteio] == pe && (m[peca + sorteio - 1] == pe || m[peca + sorteio + 1] == pe)))
        return 1;
    
    if((peca + sorteio == 25 || peca + sorteio == 27 || peca + sorteio == 28) && m[peca + sorteio] != ' ') //Verifica se a casa destino e uma casa especial e possui uma peca
        return 1;

    if(peca + sorteio > 29 && m[29] == m[peca] && conferePri(m[peca]) == 1) //Verifica se tem peca na primeira fileira
        return 1;
    
    return 0;
}
int testaMovimento(int sorteio){ //Verifica se tem algum movimento possivel para o jogador
    for(i = 0; i < 30; i++){
        if(((jogador == 1 && m[i] == pe) || (jogador == 2 && m[i] == ope)) && verificaMovimento(i, sorteio) == 0)
            return 0;
    }
    return 1;
}
void move(int peca, int sorteio){
    char aux;

    if(peca + sorteio == 26){ //Se a peca cair na casa 26 ela volta pra casa 14, caso jc esteja ocupada a peca volta para o inicio do jogo e anda a quantidade tirada nos estiletes
        if (m[14] == ' ')
            m[14] = m[peca];
        else{
            j = sorteio;
            while(m[j] != ' ')
                j++;
            m[j] = m[peca];
        }
        m[peca] = ' ';
    }
    if(peca + sorteio >= 29){ //Se o jogador retirar uma peca do jogo o placar aumenta em 1, senao a peca fica na casa 29
        if(conferePri(m[peca]) == 0){
            m[peca] = ' ';

            if (jogador == 1)
                player1++;

            if (jogador == 2)
                player2++;

        }else if(m[29] != m[peca]){
            aux = m[peca];
            m[peca] = m[29];
            m[29] = aux;
        }
    }
    if(peca + sorteio < 29 && peca + sorteio != 26){ //Move as pecas
        aux = m[peca];
        m[peca] = m[peca + sorteio];
        m[peca + sorteio] = aux;
    }
}
void movimento(){
    int aux, peca, sorteio;
    sorteio = sorteiaEstilete();
    if(vez == 1){ //A primeira jogada do segundo jogador deve ser a sua ultima peca
        for(i = 9; i >= 0; i--){
            if((jogador == 1 && m[i] == pe) || (jogador == 2 && m[i] == ope)){
                move(i, sorteio);
                tabuleiro();
                break;
            }
        }
        vez++;
        return;
    }
    if(testaMovimento(sorteio) == 1){ //Se nao ha jogadas possiveis para um jogador, a vez e passada para o outro
        printf("\nNao ha jogadas possiveis\n");

        if(jogador == 1)
            jogador = 2;
        else
            jogador = 1;

        printf("\njogador = %d vez=%d", jogador, vez);
        return;
    }
    while((sorteio == 1 || sorteio == 4 || sorteio == 6) && player1 < 5 && player2 < 5){ //Enquanto o jogador tirar 1,4 ou 6 nos estiletes ele continua jogando
        printf("\n\nVez do jogador %d", jogador);
        printf("\n\nEstilete = %d\n\n", sorteio);

        printf("\nQual peca deseja mover? ");
        scanf("%d", &peca);

        while(verificaMovimento(peca, sorteio) == 1){ //Verifica se o movimento e valido
            tabuleiro();

            printf("\n\nVez do jogador %d", jogador);
            printf("\n\nEstilete = %d\n\n", sorteio);

            printf("\nMovimento invalido\n\nDigite novamente:");
            scanf("%d", &peca);
        }
        move(peca, sorteio); //Move a peca
        tabuleiro();
        sorteio = sorteiaEstilete();
    }
    if(player1 >= 5 || player2 >= 5) //Se o placar chegar a 5, sai do looping
        return;
    
    printf("\n\nVez do jogador %d", jogador); //Se o jogador tirar 2 ou 3 nos estiletes, ele move a peca mais uma vez
    printf("\n\nEstilete = %d\n\n", sorteio);

    printf("\nQual peca deseja mover? ");
    scanf("%d", &peca);

    while(verificaMovimento(peca, sorteio) == 1){ //Verifica se o movimento e valido
        tabuleiro();

        printf("\n\nVez do jogador %d", jogador);
        printf("\n\nEstilete = %d\n\n", sorteio);

        printf("\nMovimento invalido\n\nDigite novamente:");
        scanf("%d", &peca);
    }

    move(peca, sorteio); //Move a peca pela ultima vez
    tabuleiro();
    vez++;

    if(jogador == 1) //Passa a vez
        jogador = 2;
    else
        jogador = 1;
    
}
int main(int argc, char *argv[]){
    int p, sorteio;
    system("color 0A");

    Senet();

    printf("\n\n\n\n\t\t\t\tSorteando o primeiro a jogar...\n\n");

    while(sorteio != 1){ //O primeiro jogador a tirar 1 comeca jogando
        sorteio = sorteiaEstilete();
        if(sorteio == 1){
            printf("\nJogador 1 comeca!\n");
            jogador = 1;
            break;
        }
        sorteio = sorteiaEstilete();
        if(sorteio == 1){
            printf("\nJogador 2 comeca!\n");
            jogador = 2;
            break;
        }
    }
    p = escolhePeca();

    if(p == 1 && jogador == 1){ //Salva a peca de cada jogador
        pe = 'X';
        ope = 'O';
    }else if(p == 1 && jogador == 2){
        pe = 'O';
        ope = 'X';
    }else if(p == 0 && jogador == 1){
        pe = 'O';
        ope = 'X';
    }else if(p == 0 && jogador == 2){
        pe = 'X';
        ope = 'O';
    }
    tabuleiro();

    while(player1 < 5 && player2 < 5) //Enquanto os pontos sao menores que 5, continua a movimentacao
        movimento();

    system("cls");

    if (player1 == 5) //Quando um dos jogadores atinge os 5 pontos o jogo encerra
        printf("\n\n\n\t\t\t\tJOGADOR 1 GANHOU!!!!\n\n\n");
    else
        printf("\n\n\n\t\t\t\tJOGADOR 2 GANHOU!!!!\n\n\n");
    
    return 0;
}
