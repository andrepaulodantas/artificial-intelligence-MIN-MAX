/**
 *
 * @autho Andre
 */

#include "minmax.h"

MinMax::MinMax()
{
    velha = new int*[3];
    aux = new int*[3];

    for(int i = 0; i < 3; i++){

        melhorAlinhamentoMin[i] = 10;//iniciando com um valor invalido tanto de alinhamento como de posicao no grid
        melhorAlinhamentoMax[i] = -10;
        velha[i] = new int[3];
        aux[i] = new int[3];

    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            *(&(velha[i][j])) = 0;
        }
    }

    qteAlinhamentosComputador = 0;
    qteAlinhamentosJogador = 0;
    contaJogadas = 0;

}

/**
  * ---------------------------
  * Metodos Publicos
  * ---------------------------
  **/

int* MinMax::getMelhorJogada(){

    contaJogadas++;
    cout << "Contador de Jogadas: " << contaJogadas << endl;

    if ((contaJogadas - 1) == 9){
        igualaMatriz();
        testaVertical(1);
        testaHorizontal(1);
        testaDiagonal(1);
        testaVertical(-1);
        testaHorizontal(-1);
        testaDiagonal(-1);

        if (qteAlinhamentosJogador == 0 && qteAlinhamentosComputador == 0){
            melhorJogada[0] = -101;
        }
        if(qteAlinhamentosJogador != 0){
            melhorJogada[0] = -99;
        }
        if(qteAlinhamentosComputador != 0){
            melhorJogada[0] = -100;
        }

        zeraMatriz(aux);
        qteAlinhamentosJogador = 0;
        qteAlinhamentosComputador = 0;

    }else{

    igualaMatriz();

    testaVertical(1);
    testaHorizontal(1);
    testaDiagonal(1);

    if(qteAlinhamentosJogador != 0){
        melhorJogada[0] = -99;

    }else if(testaFechamentos()){
        cout << "entrou no TESTA FECHAMENTOS !" << endl;
        melhorJogada = melhorAlinhamentoMax;
    }else{

        zeraMatriz(aux);
        qteAlinhamentosJogador = 0;
        qteAlinhamentosComputador = 0;

        algoritmoMinMax();

        melhorJogada = melhorAlinhamentoMax;

        igualaMatriz();

        testaVertical(-1);
        testaHorizontal(-1);
        testaDiagonal(-1);

        if(qteAlinhamentosComputador != 0){
            melhorJogada[0] = -100;
        }

        zeraMatriz(aux);
        qteAlinhamentosJogador = 0;
        qteAlinhamentosComputador = 0;
    }
    }

    return melhorJogada;
}


int** MinMax::getMatrizVelha(){
    return velha;
}


void MinMax::setJogadorIniciou(bool testeJogador){
    jogadorInicioujogo = testeJogador;
}


void MinMax::setPosVelha(int i, int j){
    *(&(velha[i][j])) = 1;
    contaJogadas++;
}

void MinMax::reinicia(){
    zeraMatriz(velha);
    zeraMatriz(aux);

    qteAlinhamentosJogador = 0;
    qteAlinhamentosComputador = 0;
    contaJogadas = 0;

}


/**
  * ---------------------------
  * Metodos Privados
  * ---------------------------
  **/


bool MinMax::testaFechamentos(){
    if((*(&(velha[0][0])) == 0) && ((*(&(velha[0][1])) + *(&(velha[0][2])) == -2) || (*(&(velha[1][0])) + *(&(velha[2][0])) == -2) || (*(&(velha[1][1])) + *(&(velha[2][2])) == -2))){
        *(&(velha[0][0])) = -1;
        melhorAlinhamentoMax[0] = -100;
        melhorAlinhamentoMax[1] = 0;
        melhorAlinhamentoMax[2] = 0;
        return true;
    }
    if((*(&(velha[0][1])) == 0) && ((*(&(velha[0][0])) + *(&(velha[0][2])) == -2) || (*(&(velha[1][1])) + *(&(velha[2][1])) == -2))){
        *(&(velha[0][1])) = -1;
        melhorAlinhamentoMax[0] = -100;
        melhorAlinhamentoMax[1] = 0;
        melhorAlinhamentoMax[2] = 1;
        return true;
    }
    if((*(&(velha[0][2])) == 0) && ((*(&(velha[0][0])) + *(&(velha[0][1])) == -2) || (*(&(velha[1][2])) + *(&(velha[2][2])) == -2) || (*(&(velha[1][1])) + *(&(velha[2][0])) == -2))){
        *(&(velha[0][2])) = -1;
        melhorAlinhamentoMax[0] = -100;
        melhorAlinhamentoMax[1] = 0;
        melhorAlinhamentoMax[2] = 2;
        return true;
    }
    if((*(&(velha[1][0])) == 0) && ((*(&(velha[0][0])) + *(&(velha[2][0])) == -2) || (*(&(velha[1][1])) + *(&(velha[1][2])) == -2))){
        *(&(velha[1][0])) = -1;
        melhorAlinhamentoMax[0] = -100;
        melhorAlinhamentoMax[1] = 1;
        melhorAlinhamentoMax[2] = 0;
        return true;
    }
    if((*(&(velha[1][1])) == 0) && ((*(&(velha[0][0])) + *(&(velha[2][2])) == -2) || (*(&(velha[1][0])) + *(&(velha[1][2])) == -2) || (*(&(velha[0][1])) + *(&(velha[2][1])) == -2) || (*(&(velha[0][2])) + *(&(velha[2][0])) == -2))){
        *(&(velha[1][1])) = -1;
        melhorAlinhamentoMax[0] = -100;
        melhorAlinhamentoMax[1] = 1;
        melhorAlinhamentoMax[2] = 1;
        return true;
    }
    if((*(&(velha[1][2])) == 0) && ((*(&(velha[1][0])) + *(&(velha[1][1])) == -2) || (*(&(velha[0][2])) + *(&(velha[2][2])) == -2))){
        *(&(velha[1][2])) = -1;
        melhorAlinhamentoMax[0] = -100;
        melhorAlinhamentoMax[1] = 1;
        melhorAlinhamentoMax[2] = 2;
        return true;
    }
    if((*(&(velha[2][0])) == 0) && ((*(&(velha[0][0])) + *(&(velha[1][0])) == -2) || (*(&(velha[1][1])) + *(&(velha[0][2])) == -2) || (*(&(velha[2][1])) + *(&(velha[2][2])) == -2))){
        *(&(velha[2][0])) = -1;
        melhorAlinhamentoMax[0] = -100;
        melhorAlinhamentoMax[1] = 2;
        melhorAlinhamentoMax[2] = 0;
        return true;
    }
    if((*(&(velha[2][1])) == 0) && ((*(&(velha[2][0])) + *(&(velha[2][2])) == -2) || (*(&(velha[0][1])) + *(&(velha[1][1])) == -2))){
        *(&(velha[2][1])) = -1;
        melhorAlinhamentoMax[0] = -100;
        melhorAlinhamentoMax[1] = 2;
        melhorAlinhamentoMax[2] = 1;
        return true;
    }
    if((*(&(velha[2][2])) == 0) && ((*(&(velha[0][0])) + *(&(velha[1][1])) == -2) || (*(&(velha[2][0])) + *(&(velha[2][1])) == -2) || (*(&(velha[0][2])) + *(&(velha[1][2])) == -2))){
        *(&(velha[2][2])) = -1;
        melhorAlinhamentoMax[0] = -100;
        melhorAlinhamentoMax[1] = 2;
        melhorAlinhamentoMax[2] = 2;
        return true;
    }
    return false;
}


void MinMax::testaVertical(int jogador){
    if(jogador == -1){

        if (*(&(aux[0][0])) + *(&(aux[1][0])) + *(&(aux[2][0])) == -3){
            qteAlinhamentosComputador++;

        }
        if(*(&(aux[0][1])) + *(&(aux[1][1])) + *(&(aux[2][1])) == -3){
            qteAlinhamentosComputador++;

        }
        if(*(&(aux[0][2])) + *(&(aux[1][2])) + *(&(aux[2][2])) == -3){
            qteAlinhamentosComputador++;

        }

    }else if(jogador == 1){

        if (*(&(aux[0][0])) + *(&(aux[1][0])) + *(&(aux[2][0])) == 3){
            qteAlinhamentosJogador++;

        }
        if(*(&(aux[0][1])) + *(&(aux[1][1])) + *(&(aux[2][1])) == 3){
            qteAlinhamentosJogador++;

        }
        if(*(&(aux[0][2])) + *(&(aux[1][2])) + *(&(aux[2][2])) == 3){
            qteAlinhamentosJogador++;

        }
    }

}

void MinMax::testaHorizontal(int jogador){
    if(jogador == -1){

        if (*(&(aux[0][0])) + *(&(aux[0][1])) + *(&(aux[0][2])) == -3){
            qteAlinhamentosComputador++;

        }
        if (*(&(aux[1][0])) + *(&(aux[1][1])) + *(&(aux[1][2])) == -3){
            qteAlinhamentosComputador++;

        }
        if (*(&(aux[2][0])) + *(&(aux[2][1])) + *(&(aux[2][2])) == -3){
            qteAlinhamentosComputador++;

        }

    }else if(jogador == 1){

        if (*(&(aux[0][0])) + *(&(aux[0][1])) + *(&(aux[0][2])) == 3){
            qteAlinhamentosJogador++;

        }
        if (*(&(aux[1][0])) + *(&(aux[1][1])) + *(&(aux[1][2])) == 3){
            qteAlinhamentosJogador++;

        }
        if (*(&(aux[2][0])) + *(&(aux[2][1])) + *(&(aux[2][2])) == 3){
            qteAlinhamentosJogador++;

        }
    }
}

void MinMax::testaDiagonal(int jogador){
    if(jogador == -1){
        if (*(&(aux[0][0])) + *(&(aux[1][1])) + *(&(aux[2][2])) == -3){
            qteAlinhamentosComputador++;
        }
        if (*(&(aux[0][2])) + *(&(aux[1][1])) + *(&(aux[2][0])) == -3){
            qteAlinhamentosComputador++;
        }

    }else if(jogador == 1){
        if (*(&(aux[0][0])) + *(&(aux[1][1])) + *(&(aux[2][2])) == 3){
            qteAlinhamentosJogador++;

        }
        if (*(&(aux[0][2])) + *(&(aux[1][1])) + *(&(aux[2][0])) == 3){
            qteAlinhamentosJogador++;

        }
    }
}

void MinMax::completaGrid(int jogador){
    for(int r = 0; r < 3; r++){
        for(int s = 0; s < 3; s++){
            if (*(&(aux[r][s])) == 0){
                *(&(aux[r][s])) = jogador;
            }
        }
    }
}


void MinMax::imprimeMatriz(int** matriz){

    QString linha1 = "";
    QString linha2 = "";
    QString linha3 = "";

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 0){
                linha1.append(QString::number(*(&(matriz[i][j])))).append(" ");
            }else if(i == 1){
                linha2.append(QString::number(*(&(matriz[i][j])))).append(" ");
            }else if(i == 2){
                linha3.append(QString::number(*(&(matriz[i][j])))).append(" ");
            }
        }
    }

    cout << linha1.toStdString() << endl;
    cout << linha2.toStdString() << endl;
    cout << linha3.toStdString() << endl;
}


void MinMax::zeraMatriz(int** matriz){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            *(&(matriz[i][j])) = 0;
        }
    }
}

void MinMax::igualaMatriz(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            *(&(aux[i][j])) = *(&(velha[i][j]));
        }
    }
}

void MinMax::algoritmoMinMax(){

    for(int l = 0; l < 3; l++){
        melhorAlinhamentoMin[l] = 10;
        //melhorAlinhamentoMax[l] = -10;
        melhorAlinhamentoMax[l] = 10; //<<<<<<< alterei aki <<<<<<<<<< iniciando com um valor invalido tanto de alinhamento como de posicao no grid
    }


    int soma = 0;
    cout << "------------------------------------------------------" << endl;
    cout << "-----Matriz do Jogo da Velha antes da iteracao-----" << endl;
    imprimeMatriz(velha);

    if (!jogadorInicioujogo){

        for(int r = 0; r < 3; r++){
            for(int s = 0; s < 3; s++){
                if(*(&(velha[r][s])) ==  -1){
                    soma--;
                }
            }
        }
    }

    if(soma == -4){
        for(int r = 0; r < 3; r++){
            for(int s = 0; s < 3; s++){
                if(*(&(velha[r][s])) ==  0){
                    melhorAlinhamentoMax[0] = 5; //valor random pra dizer que foi na jogada final
                    melhorAlinhamentoMax[1] = r;
                    melhorAlinhamentoMax[2] = s;
                }
            }
        }


    }else{


        //Esse 'for' testa todas as jogadas possíveis da situacao atual do computador
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(*(&(velha[i][j])) ==  0){


                    //esse 'for' indica todas as possiveis proximas jogadas do humano
                    for(int k = 0; k < 3; k++){
                        for(int w = 0; w < 3; w++){

                            igualaMatriz();

                            *(&(aux[i][j])) = -1;

                            //So entra no 'se' se a posicao que ele esta for diferente da escolhida no (i, j)
                            if(*(&(aux[k][w])) == 0){

                                *(&(aux[k][w])) = 1;

                                completaGrid(-1);//completando as posicoes vazias do grid com o valor do computador para teste de alinhamento

                                testaVertical(-1); //testando vertical para computador
                                testaHorizontal(-1); //testando horizontal para computador
                                testaDiagonal(-1); //testando diagonal para computador

                                cout << "------------------------------------------------------" << endl;
                                cout << "-----Matriz do Jogo da Velha depois de testar alinhamento computador-----" << endl;
                                imprimeMatriz(aux);

                                zeraMatriz(aux);

                                igualaMatriz();

                                //Gambiarra
                                *(&(aux[i][j])) = -1;
                                *(&(aux[k][w])) = 1;

                                completaGrid(1);//completando as posicoes vazias do grid com o valor do jogador para teste de alinhamento

                                testaVertical(1); //testando vertical para jogador
                                testaHorizontal(1); //testando horizontal para jogador
                                testaDiagonal(1); //testando diagonal para jogador

                                cout << "------------------------------------------------------" << endl;
                                cout << "-----Matriz do Jogo da Velha depois de testar alinhamento jogador-----" << endl;
                                imprimeMatriz(aux);

                                //Atualizando o alinhamento de menor valor (MIN)
                                if (qteAlinhamentosComputador - qteAlinhamentosJogador < melhorAlinhamentoMin[0]){
                                //if (qteAlinhamentosJogador - qteAlinhamentosComputador < melhorAlinhamentoMin[0]){ //jogador - computador
                                    melhorAlinhamentoMin[0] = qteAlinhamentosComputador - qteAlinhamentosJogador;
                                    melhorAlinhamentoMin[1] = k;
                                    melhorAlinhamentoMin[2] = w;
                                }
                                //Zerando posicao utilizada para teste de posicao do jogador humano
                                *(&(aux[k][w])) = 0;

                                qteAlinhamentosComputador = 0; //Zerando contador de alinhamentos do computador para proxima iteracao
                                qteAlinhamentosJogador = 0; //Zerando contador de alinhamentos do jogador para proxima iteracao

                                cout << "valor do melhor alinhamento minimo: " << melhorAlinhamentoMin[0] << " e posicao: (" << melhorAlinhamentoMin[1] << ", "<< melhorAlinhamentoMin[2] << ")" << endl;
                            }
                        }
                    }

                    //Atualizando o alinhamento de maior valor (MAX)
                    if(melhorAlinhamentoMin[0] < melhorAlinhamentoMax[0]){ //<<<<<<< alterei aki <<<<<<<<<< sinal de maior pelo de menor
                    //if(melhorAlinhamentoMin[0] > melhorAlinhamentoMax[0]){
                        for(int x = 0; x < 3 ; x++){
                            melhorAlinhamentoMax[x] = melhorAlinhamentoMin[x];
                        }
                    }

                    cout << "melhor alinhamento da jogada: " << melhorAlinhamentoMax[1] << " " << melhorAlinhamentoMax[2] << " valor: " << melhorAlinhamentoMax[0] << endl;
                    *(&(aux[i][j])) = 0;
                }
            }

        }
    }
    *(&(velha[melhorAlinhamentoMax[1]][melhorAlinhamentoMax[2]])) = -1;

    cout << "------------------------------------------------------" << endl;
    cout << "-----Matriz do Jogo da Velha apos iteracao-----" << endl;
    imprimeMatriz(velha);
    cout << "------------------------------------------------------" << endl;
    cout << "------------------------------------------------------" << endl;

}
