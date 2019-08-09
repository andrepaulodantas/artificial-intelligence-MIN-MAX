#ifndef MINMAX_H
#define MINMAX_H

#include <QString>
#include <iostream>

using namespace std;

class MinMax
{
public:
    MinMax();

    int* getMelhorJogada();
    void setJogadorIniciou(bool testeJogador);
    void setPosVelha(int i, int j);

    int** getMatrizVelha();

    void reinicia();

private:

    int **velha; //Posicoes do jogo da velha
    int **aux; // Matriz que auxilia nos calculos do algoritmo

    int melhorAlinhamentoMin[3]; //Vetor com o valor do melhor alinhamento e as coordenadas do mesmo >>
                              //melhorAlinhamentoMin[0] = valor do alinhamento, melhorAlinhamentoMin[1] = coord x, melhorAlinhamentoMin[2] = coord y

    int melhorAlinhamentoMax[3]; //Vetor com o valor do melhor alinhamento e as coordenadas do mesmo >>
                              //melhorAlinhamentoMax[0] = valor do alinhamento, melhorAlinhamentoMax[1] = coord x, melhorAlinhamentoMax[2] = coord y

    int* melhorJogada;

    void imprimeMatriz(int** matriz); //funcao que imprime a matriz auxiliar do jogo da velha

    void zeraMatriz(int** matriz); //zera matriz

    void igualaMatriz();

    int qteAlinhamentosComputador;//conta a qte de alinhamentos do computador
    int qteAlinhamentosJogador;//conta a qte de alinhamentos do jogador

    void testaVertical(int jogador); //testando alinhamentos verticais
    void testaHorizontal(int jogador); //testando alinhamentos horizontais
    void testaDiagonal(int jogador); //testando alinhamentos diagonais

    void completaGrid(int jogador);//funcao para completar posicoes do grid

    bool jogadorInicioujogo;

    int contaJogadas;

    bool testaFechamentos();

    void algoritmoMinMax();

};

#endif // MINMAX_H
