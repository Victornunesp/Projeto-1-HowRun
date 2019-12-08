#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVector>
#include <QFileDialog>
#include <QFile>
#include <QStringList>

#include "setup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void atualizarTabela();

    bool nomeRep(QString n);

    void clear();

private slots:
    void on_addSetupButton_clicked();

    void on_tabela_cellDoubleClicked(int row, int column);

    void on_homeEd_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_excluirEd_clicked();

    void on_salvarEd_clicked();

    void on_apelidoSetupLine_2_textChanged(const QString &arg1);

    QString comoRoda(int s);

    void on_actionAbrir_triggered();

    void on_actionSalvar_triggered();

private:
    Ui::MainWindow *ui;
    QVector <Setup> lista;
    int setupAberto;
    bool trocouNome;


};
#endif // MAINWINDOW_H
