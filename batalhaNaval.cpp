#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#define tam 10
#define vetorEsp "     "
#define espaco "   "

    void imprimetab (char tab [tam][tam]) {

        cout << endl << endl;
        cout << vetorEsp << "  ";

        for (int a = 0; a < tam; a++)
            cout << espaco << a+1;
            cout << endl << endl;

        for (int i = 0; i < tam; i++) {
            cout << vetorEsp << (char) ('A' + i) << " ";
            for (int j = 0; j < tam; j++) {
                cout << espaco << tab [i][j];
            }
            cout << endl << endl;
        }

        cout << endl;
    }
    void inicializacao (char tab [tam][tam]) {
        for (int i = 0; i < tam; i ++)  {
            for (int j = 0; j < tam; j++)
                tab [i][j] = '.';
        }
    }
    void gerartab (char tabuleiro [tam][tam]) {

    unsigned seed = time (0);
    srand(time(NULL));

    // para marcar as duas frotas de tamanho 3:
    for (int i = 0; i < 3; i ++) {
        int e = rand ()%tam;
        int f = rand ()%tam;
        int g = rand ()%2;
        int julia = 0;

        if (g%2 == 0
            && tabuleiro [e][f-2] == '.'
            && tabuleiro [e][f-1] == '.'
            && tabuleiro [e][f] == '.'
            && tabuleiro [e][f+1] == '.'
            && tabuleiro [e][f+2] == '.'

            && tabuleiro [e-1][f-1] == '.'
            && tabuleiro [e-1][f] == '.'
            && tabuleiro [e-1][f+1] == '.'

            && tabuleiro [e+1][f-1] == '.'
            && tabuleiro [e+1][f] == '.'
            && tabuleiro [e+1][f+1] == '.'

            && f < (tam-3)
            && f > 0) {

            tabuleiro [e][f-1] = 'o';
            tabuleiro [e][f] = 'o';
            tabuleiro [e][f+1] = 'o';
            julia = julia + 1;
        }


        if (g%2 != 0
            && tabuleiro [e-2][f] == '.'
            && tabuleiro [e-1][f] == '.'
            && tabuleiro [e][f] == '.'
            && tabuleiro [e+1][f] == '.'
            && tabuleiro [e+2][f] == '.'

            && tabuleiro [e-1][f-1] == '.'
            && tabuleiro [e][f-1] == '.'
            && tabuleiro [e+1][f-1] == '.'

            && tabuleiro [e-1][f+1] == '.'
            && tabuleiro [e][f+1] == '.'
            && tabuleiro [e+1][f+1] == '.'

            && f < (tam-3)
            && f > 0) {

            tabuleiro [e-1][f] = 'o';
            tabuleiro [e][f] = 'o';
            tabuleiro [e+1][f] = 'o';
            julia = julia +1;
        }


        if (julia == 0)
            i --;
        }

          // para marcar as três frotas de tamanho 2:
    for (int i = 0; i < 4; i ++) {
        int c = rand ()%tam;
        int d = rand ()%tam;
        int l = rand ()%2;
        if (l%2 == 0
            && tabuleiro [c][d-1] == '.'
            && tabuleiro [c][d] == '.'
            && tabuleiro [c][d+1] == '.'
            && tabuleiro [c][d+2] == '.'
            && tabuleiro [c+1][d] == '.'
            && tabuleiro [c+1][d+1] == '.'
            && tabuleiro [c-1][d] == '.'
            && tabuleiro [c-1][d+1] == '.'
            && d < (tam-2)) {

            tabuleiro [c][d] = '?';
            tabuleiro [c][d+1] = '?';
        }
        if (l%2 != 0
            && tabuleiro [c-1][d] == '.'
            && tabuleiro [c+2][d] == '.'
            && tabuleiro [c][d+1] == '.'
            && tabuleiro [c][d-1] == '.'
            && tabuleiro [c+1][d-1] == '.'
            && tabuleiro [c+1][d+1] == '.'
            && tabuleiro [c][d] == '.'
            && tabuleiro [c][d+1] == '.'
            && c < (tam-2)) {

            tabuleiro [c][d] = '?';
            tabuleiro [c+1][d] = '?';
        }
        else
            i--; // para repetir o processo novamente
        }

        // para marcar as quatro frotas de tamanho 1:
    for (int i = 0; i < 5; i++) {
        int a = rand ()%tam;
        int b = rand ()%tam;

        if (tabuleiro [a-1][b] == '.'
            && tabuleiro [a][b] == '.'
            && tabuleiro [a+1][b] == '.'
            && tabuleiro [a][b-1] == '.'
            && tabuleiro [a][b+1] == '.')

            tabuleiro [a][b] = 'x';

        else
            i--;
    }
}
    void copiatab (char tab [tam][tam], char tabaux [tam][tam]) {
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j ++)
            tabaux [i][j] = tab [i][j];
        }
    }
    void ganhador (int jogador1, int jogador2) {
        int vencedor;
        if (jogador1 > jogador2)
            vencedor = 1;
        if (jogador1 < jogador2)
            vencedor = 2;
        if (jogador1 == jogador2)
            vencedor = 0;

        if (vencedor == 0) {
            cout << vetorEsp << endl << "HOUVE UM EMPATE!!" << endl;
            cout << vetorEsp << endl << vetorEsp << "Pontuação: " << endl;
            cout << vetorEsp << "Jogador 1: " << jogador1 << " pontos" << endl;
            cout << vetorEsp << "Jogador 2: " << jogador2 << " pontos" << endl;
       }
        else {
            cout << vetorEsp << endl << endl << vetorEsp << "O VENCEDOR FOI: " << endl;
            cout << vetorEsp << "JOGADOR" << vencedor << "!!!" << endl;
            cout << vetorEsp << endl << vetorEsp << "Pontuação: " << endl;
            cout << vetorEsp << "Jogador 1: " << jogador1 << " pontos" << endl;
            cout << vetorEsp << "Jogador 2: " << jogador2 << " pontos" << endl << endl;
        }
    }

int main()
{

    int leo = 0; // para reiniciar o jogo

    do {
    char tabuleiro [tam][tam];
    char tabjogo [tam][tam];
    char tabaux [tam][tam];

    int jogador1 = 0;
    int jogador2 = 0;
    int aux = 0;
    int linha;

    inicializacao (tabuleiro);
    inicializacao (tabjogo);

    gerartab (tabuleiro); // para gerar um tabuleiro aleatório
    copiatab (tabuleiro, tabaux); // para copiar o gabarito para uma matriz auxiliar

    //imprimetab (tabuleiro);
    imprimetab (tabjogo);

    do {

          char linha [2];
          int coluna, numLinha;
          int alt = 0; //variável utilizada para alternar as jogadas

          cout << vetorEsp << "INSIRA EM QUAL POSIÇÃO O JOGADOR 1 DESEJA JOGAR: ";

        while (alt != 1) {
                cin >> linha [0] >> coluna;

                if (linha [0] >= 'a' && linha [0] <= 'z') // para validar letras maiúsculas ou minúsculas
                    linha [0] = linha [0] - 32;

                numLinha = linha [0] - 65; // para alterar o código ASCII da variável de char para inteiro

                //Para evitar posições inexistentes:
                if ((linha [0] < 'A' || linha [0] > 'J') || (coluna < 0 || coluna > 10) || (tabjogo [numLinha][coluna-1] != '.'))
                    cout << vetorEsp << "POSIÇÃO INVÁLIDA.  INSIRA OUTRA POSIÇÃO:";

                else { // caso a posição esteja disponível

                    //Marcar a pontuação e as posições selecionadas:
                    if (tabuleiro [numLinha][coluna -1] == 'o') { // navios de 3 posições
                        jogador1 = jogador1 + 5;
                        tabjogo [numLinha][coluna-1] = 'x';
                    }

                    if (tabuleiro [numLinha][coluna -1] == '?') { // navios de 2 posições
                        jogador1 = jogador1 + 10;
                        tabjogo [numLinha][coluna-1] = 'x';
                    }

                    if (tabuleiro [numLinha][coluna -1] == 'x') { // navios de uma posição
                        jogador1 = jogador1 + 25;
                        tabjogo [numLinha][coluna-1] = 'x';
                    }

                    if (tabuleiro [numLinha][coluna-1] == '.') { // posição vazia
                        tabjogo [numLinha][coluna-1] = ' ';
                    }

                    tabaux [numLinha][coluna -1] = '.'; //apagar a posição selecionada no tabuleiro auxiliar
                    imprimetab (tabjogo);
                    alt = 1;
                }
            }

            aux = 0; // variável utilizada para auxiliar no encerramento do jogo.
            for (int i = 0; i < tam; i++) {
                for (int j = 0; j < tam; j++) {
                    if (tabaux [i][j] == '.')
                        aux = aux + 0;
                        // caso todo o tabuleiro aux estiver com '.', o jogo acabou.
                    else
                        aux = aux + 1; //se o jogo não acabou, aux será != 0 e o programa continuará no while.
                }
            }

            if (aux != 0 )
                alt = 0;

            cout << vetorEsp << "INSIRA EM QUAL POSIÇÃO O JOGADOR 2 DESEJA JOGAR: ";
            while (alt != 1) {
                cin >> linha [0] >> coluna;

                if (linha [0] >= 'a' && linha [0] <= 'z')
                    linha [0] = linha [0] - 32;

                numLinha = linha [0] - 65;

                if ((linha [0] < 'A' || linha [0] > 'J') || (coluna < 0 || coluna > 10) || (tabjogo [numLinha][coluna-1] != '.')){
                    cout << vetorEsp << "POSIÇÃO INVÁLIDA.  INSIRA OUTRA POSIÇÃO: " << endl;
                }

                else {

                    if (tabuleiro [numLinha][coluna-1] == 'o') {
                        jogador2 = jogador2 + 5;
                        tabjogo [numLinha][coluna-1] = 'x';

                    }

                    if (tabuleiro [numLinha][coluna-1] == '?') {
                        jogador2 = jogador2 + 10;
                        tabjogo [numLinha][coluna-1] = 'x';

                    }

                    if (tabuleiro [numLinha][coluna-1] == 'x') {
                        jogador2 = jogador2 + 25;
                        tabjogo [numLinha][coluna-1] = 'x';

                    }

                    if (tabuleiro [numLinha][coluna-1] == '.') {
                        tabjogo [numLinha][coluna-1] = ' ';
                    }

                    tabaux [numLinha][coluna -1] = '.';
                    imprimetab (tabjogo);
                    alt = 1;
                }
            }


    // para testar se todas as posições foram reveladas:
    aux = 0;
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
           if (tabaux [i][j] == '.')
                aux = aux + 0;

            else
                aux = aux + 1;
        }
    }
}
    while (aux != 0);

    ganhador (jogador1, jogador2);

    cout << vetorEsp << "Deseja jogar novamente? " << endl << vetorEsp << "Sim: Digite 1" << endl << vetorEsp << "Não: Digite 0" << endl << vetorEsp;
    cin >> leo;
    }
    while (leo != 0);
    return 0;
}
