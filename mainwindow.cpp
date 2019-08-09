/**
 *
 * @autho Andre
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    algMinMax = new MinMax();


    QObject::connect(ui->actionIniciar_Jogo,SIGNAL(triggered()), this, SLOT(execute()));
    QObject::connect(ui->actionSobre, SIGNAL(triggered()), this, SLOT(about_Create()));
    connect(ui->actionQT, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    ui->pushButton_11->setDisabled(true);
    ui->pushButton_12->setDisabled(true);
    ui->pushButton_13->setDisabled(true);
    ui->pushButton_21->setDisabled(true);
    ui->pushButton_22->setDisabled(true);
    ui->pushButton_23->setDisabled(true);
    ui->pushButton_31->setDisabled(true);
    ui->pushButton_32->setDisabled(true);
    ui->pushButton_33->setDisabled(true);

    reiniciou = false;

    contador = 0;

    ui->statusBar->showMessage("Pronto ...");

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about_Create()
{
   QMessageBox::about(this, ("Sobre o Jogo da Velha"), ("<p>O <b>Jogo da Velha</b> eh um exemplo que demonstra o algoritmo <i>MinMax</i>.</p>"
                                                   "\n<p>COMO JOGAR: \n\n Escolha se o jogador ou o computador inicia o jogo e clique em Iniciar Jogo/Reiniciar.</p>"
                                                   "\n<p><i>Action</i>   Sair fecha o programa.</p>"
                                                   "\n\n<p>Desenvolvido para a disciplina de <b>Controle Inteligente</b> Ministrada pelo prof. Fabio Meneghetti.</p>"
                                                   ));
}


void MainWindow::execute(){

     contador = 0;

    ui->statusBar->clearMessage();

    ui->statusBar->showMessage("Computador = X         Jogador = O");

    if(reiniciou){
        algMinMax->reinicia();

        ui->pushButton_11->setText("");
        ui->pushButton_12->setText("");
        ui->pushButton_13->setText("");
        ui->pushButton_21->setText("");
        ui->pushButton_22->setText("");
        ui->pushButton_23->setText("");
        ui->pushButton_31->setText("");
        ui->pushButton_32->setText("");
        ui->pushButton_33->setText("");

    }

    ui->pushButton_11->setEnabled(true);
    ui->pushButton_12->setEnabled(true);
    ui->pushButton_13->setEnabled(true);
    ui->pushButton_21->setEnabled(true);
    ui->pushButton_22->setEnabled(true);
    ui->pushButton_23->setEnabled(true);
    ui->pushButton_31->setEnabled(true);
    ui->pushButton_32->setEnabled(true);
    ui->pushButton_33->setEnabled(true);

    if(!ui->actionJogador_Inicia->isChecked()){
        algMinMax->setJogadorIniciou(0); //vai receber da tela principal um sinal dizendo se o jogador iniciou ou nao o jogo.
        setPosComputador(algMinMax->getMelhorJogada()); //setando graficamente o que o computador escolheu
    }else{
        algMinMax->setJogadorIniciou(1);
    }

    reiniciou = true;

    ui->actionIniciar_Jogo->setText("Reiniciar");
}

void MainWindow::setPosComputador(int* melhorJogada){
    int aux[3];

    for(int i = 0; i < 3 ; i++){
        aux[i] = melhorJogada[i];
    }

    if(aux[0] != -99){

        if(aux[1] == 0 && aux[2] == 0){
            ui->pushButton_11->setText("X");
            ui->pushButton_11->setDisabled(true);
        }else if(aux[1] == 0 && aux[2] == 1){
            ui->pushButton_12->setText("X");
            ui->pushButton_12->setDisabled(true);
        }else if(aux[1] == 0 && aux[2] == 2){
            ui->pushButton_13->setText("X");
            ui->pushButton_13->setDisabled(true);
        }else if(aux[1] == 1 && aux[2] == 0){
            ui->pushButton_21->setText("X");
            ui->pushButton_21->setDisabled(true);
        }else if(aux[1] == 1 && aux[2] == 1){
            ui->pushButton_22->setText("X");
            ui->pushButton_22->setDisabled(true);
        }else if(aux[1] == 1 && aux[2] == 2){
            ui->pushButton_23->setText("X");
            ui->pushButton_23->setDisabled(true);
        }else if(aux[1] == 2 && aux[2] == 0){
            ui->pushButton_31->setText("X");
            ui->pushButton_31->setDisabled(true);
        }else if(aux[1] == 2 && aux[2] == 1){
            ui->pushButton_32->setText("X");
            ui->pushButton_32->setDisabled(true);
        }else if(aux[1] == 2 && aux[2] == 2){
            ui->pushButton_33->setText("X");
            ui->pushButton_33->setDisabled(true);
        }
    }

    if(aux[0] == -99 || aux[0] == -100 || aux[0] == -101){
        if(aux[0] == -99){
            ui->statusBar->clearMessage();
           ui->statusBar->showMessage("Jogador Ganhou !");
        }
        if(aux[0] == -100){
            ui->statusBar->clearMessage();
           ui->statusBar->showMessage("Computador Ganhou !");
        }
        if(aux[0] == -101){
            ui->statusBar->clearMessage();
           ui->statusBar->showMessage("Deu Empate !");
        }

        ui->pushButton_11->setDisabled(true);
        ui->pushButton_12->setDisabled(true);
        ui->pushButton_13->setDisabled(true);
        ui->pushButton_21->setDisabled(true);
        ui->pushButton_22->setDisabled(true);
        ui->pushButton_23->setDisabled(true);
        ui->pushButton_31->setDisabled(true);
        ui->pushButton_32->setDisabled(true);
        ui->pushButton_33->setDisabled(true);
    }
}

void MainWindow::on_pushButton_11_clicked()
{

    algMinMax->setPosVelha(0,0);//setando na matriz do jogo da velha a posicao que o jogador escolheu

    ui->pushButton_11->setText("O"); //setando graficamente o que o jogador escolheu

    ui->pushButton_11->setDisabled(true);

    setPosComputador(algMinMax->getMelhorJogada()); //setando graficamente o que o computador escolheu

}

void MainWindow::on_pushButton_12_clicked()
{
    algMinMax->setPosVelha(0,1);//setando na matriz do jogo da velha a posicao que o jogador escolheu

    ui->pushButton_12->setText("O"); //setando graficamente o que o jogador escolheu

    ui->pushButton_12->setDisabled(true);

    setPosComputador(algMinMax->getMelhorJogada()); //setando graficamente o que o computador escolheu
}

void MainWindow::on_pushButton_13_clicked()
{
    algMinMax->setPosVelha(0,2);//setando na matriz do jogo da velha a posicao que o jogador escolheu

    ui->pushButton_13->setText("O"); //setando graficamente o que o jogador escolheu

    ui->pushButton_13->setDisabled(true);

    setPosComputador(algMinMax->getMelhorJogada()); //setando graficamente o que o computador escolheu
}

void MainWindow::on_pushButton_21_clicked()
{
    algMinMax->setPosVelha(1,0);//setando na matriz do jogo da velha a posicao que o jogador escolheu

    ui->pushButton_21->setText("O"); //setando graficamente o que o jogador escolheu

    ui->pushButton_21->setDisabled(true);

    setPosComputador(algMinMax->getMelhorJogada()); //setando graficamente o que o computador escolheu
}

void MainWindow::on_pushButton_22_clicked()
{
    algMinMax->setPosVelha(1,1);//setando na matriz do jogo da velha a posicao que o jogador escolheu

    ui->pushButton_22->setText("O"); //setando graficamente o que o jogador escolheu

    ui->pushButton_22->setDisabled(true);

    setPosComputador(algMinMax->getMelhorJogada()); //setando graficamente o que o computador escolheu
}

void MainWindow::on_pushButton_23_clicked()
{
    algMinMax->setPosVelha(1,2);//setando na matriz do jogo da velha a posicao que o jogador escolheu

    ui->pushButton_23->setText("O"); //setando graficamente o que o jogador escolheu

    ui->pushButton_23->setDisabled(true);

    setPosComputador(algMinMax->getMelhorJogada()); //setando graficamente o que o computador escolheu
}

void MainWindow::on_pushButton_31_clicked()
{
    algMinMax->setPosVelha(2,0);//setando na matriz do jogo da velha a posicao que o jogador escolheu

    ui->pushButton_31->setText("O"); //setando graficamente o que o jogador escolheu

    ui->pushButton_31->setDisabled(true);

    setPosComputador(algMinMax->getMelhorJogada()); //setando graficamente o que o computador escolheu
}

void MainWindow::on_pushButton_32_clicked()
{
    algMinMax->setPosVelha(2,1);//setando na matriz do jogo da velha a posicao que o jogador escolheu

    ui->pushButton_32->setText("O"); //setando graficamente o que o jogador escolheu

    ui->pushButton_32->setDisabled(true);

    setPosComputador(algMinMax->getMelhorJogada()); //setando graficamente o que o computador escolheu
}

void MainWindow::on_pushButton_33_clicked()
{
    algMinMax->setPosVelha(2,2);//setando na matriz do jogo da velha a posicao que o jogador escolheu

    ui->pushButton_33->setText("O"); //setando graficamente o que o jogador escolheu

    ui->pushButton_33->setDisabled(true);

    setPosComputador(algMinMax->getMelhorJogada()); //setando graficamente o que o computador escolheu
}
