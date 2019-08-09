#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <iostream>

#include "minmax.h"

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MinMax* algMinMax;

    void setPosComputador(int* melhorJogada);

    bool reiniciou;

    int contador;


private slots:
    void on_pushButton_33_clicked();
    void on_pushButton_32_clicked();
    void on_pushButton_31_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_11_clicked();

    void execute();
    void about_Create();

};

#endif // MAINWINDOW_H
