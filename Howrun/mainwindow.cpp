#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setup.h"
#include "cadastro.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabela->setColumnWidth(0,600);
    ui->tabela->setColumnWidth(1,75);
    /////////////////SETUP ICONES/////////////////////

    ui->spinBoxNucleos->setMinimum(1);
    trocouNome = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualizarTabela()
{

    QPixmap ca(":/icons/ca icon.png");
    QPixmap caT = ca.scaled(65,65,Qt::KeepAspectRatio);

    QPixmap gta(":/icons/gta5.png");
    QPixmap gtaT = gta.scaled(65,65,Qt::KeepAspectRatio);

    QPixmap lol(":/icons/lol icon.png");
    QPixmap lolT = lol.scaled(65,65,Qt::KeepAspectRatio);

    QPixmap ow(":/icons/ow icon.png");
    QPixmap owT = ow.scaled(65,65,Qt::KeepAspectRatio);

    QPixmap r6(":/icons/r6 icon.png");
    QPixmap r6T = r6.scaled(65,65,Qt::KeepAspectRatio);

    ui->tabela->setRowCount(0);

    for(int i = 0; i < lista.size(); i++){

        QLabel *imagem = new QLabel;

        ui->tabela->insertRow(i);

        ui->tabela->setItem(i,0,new QTableWidgetItem(lista[i].getApelido()));

       if(lista[i].getEstiloJg() == "Combat Arms"){
           imagem->setPixmap(caT);
           ui->tabela->setCellWidget(i, 2, imagem);
       }
       if(lista[i].getEstiloJg() == "Overwatch"){
           imagem->setPixmap(owT);
           ui->tabela->setCellWidget(i, 2, imagem);
       }
       if(lista[i].getEstiloJg() == "League of Legends"){
           imagem->setPixmap(lolT);
           ui->tabela->setCellWidget(i, 2, imagem);
       }
       if(lista[i].getEstiloJg() == "Rainbow 6"){
           imagem->setPixmap(r6T);
           ui->tabela->setCellWidget(i, 2, imagem);
       }
       if(lista[i].getEstiloJg() == "GTA V"){
           imagem->setPixmap(gtaT);
           ui->tabela->setCellWidget(i, 2, imagem);
       }
       ui->tabela->setRowHeight(i,65);

       if(comoRoda(i) == "Roda como recomendado ou superior"){
            ui->tabela->setItem(i, 1, new QTableWidgetItem (comoRoda(i)));
       }
       if(comoRoda(i) == "Roda mínimamente"){
           ui->tabela->setItem(i, 1, new QTableWidgetItem (comoRoda(i)));
       }
       if(comoRoda(i) == "Não Roda"){
           ui->tabela->setItem(i, 1, new QTableWidgetItem (comoRoda(i)));
       }

    }
}

bool MainWindow::nomeRep(QString n)
{
    for(auto proc : lista) if(proc.getApelido() == n) return true;
    return false;
}

void MainWindow::on_addSetupButton_clicked()
{
    Setup a;

    if(ui->comboBoxEstilo->currentIndex() == 0 or nomeRep(ui->apelidoSetupLine->text().toUpper()) or a.setApelido(ui->apelidoSetupLine->text().toUpper()) or a.setClockProc(ui->clockNucleoLine->text().toDouble())) QMessageBox::warning(this, "Valor inválido", "Informe valores válidos");
    else{
        a.setMemVideo(ui->memVideoLine->text().toDouble());
        a.setNPlacas(ui->spinBoxPlacas->text().toInt());
        a.setNNucleos(ui->spinBoxNucleos->text().toInt());
        a.setEstiloJg(ui->comboBoxEstilo->currentText());
        lista.push_back(a);

        QMessageBox::information(this,"OK","Cadastrado com sucesso!");

        atualizarTabela();
        clear();
    }
}

void MainWindow::clear()
{
    ui->spinBoxNucleos->setValue(1);
    ui->spinBoxPlacas->setValue(0);
    ui->comboBoxEstilo->setCurrentIndex(0);
    ui->clockNucleoLine->clear();
    ui->memVideoLine->clear();
    ui->apelidoSetupLine->clear();

}

void MainWindow::on_tabela_cellDoubleClicked(int row, int column)
{
    QPixmap ca(":/icons/ca icon.png");
    QPixmap gta(":/icons/gta5.png");
    QPixmap lol(":/icons/lol icon.png");
    QPixmap ow(":/icons/ow icon.png");
    QPixmap r6(":/icons/r6 icon.png");

    QPixmap r6E = r6.scaled(220,220,Qt::KeepAspectRatio);
    QPixmap owE = ow.scaled(220,220,Qt::KeepAspectRatio);
    QPixmap lolE = lol.scaled(220,220,Qt::KeepAspectRatio);
    QPixmap gtaE = gta.scaled(220,220,Qt::KeepAspectRatio);
    QPixmap caE = ca.scaled(220,220,Qt::KeepAspectRatio);

    setupAberto = row;
    ui->pags->setCurrentIndex(1);

    ui->apelidoSetupLine_2->setText(lista[row].getApelido());
    ui->spinBoxNucleos_2->setValue(lista[row].getNNucleos());
    ui->clockNucleoLine_2->setText(QString::number(lista[row].getClockProc()));
    ui->spinBoxPlacas_2->setValue(lista[row].getNPlacas());
    ui->memVideoLine_2->setText(QString::number(lista[row].getMemVideo()));
    ui->comboBoxEstilo_2->setCurrentText(lista[row].getEstiloJg());

    if(lista[row].getEstiloJg() == "Combat Arms"){
       ui->label_game->setPixmap(caE);
    }
    if(lista[row].getEstiloJg() == "Overwatch"){
        ui->label_game->setPixmap(owE);
    }
    if(lista[row].getEstiloJg() == "League of Legends"){
        ui->label_game->setPixmap(lolE);
    }
    if(lista[row].getEstiloJg() == "Rainbow 6"){
        ui->label_game->setPixmap(r6E);
    }
    if(lista[row].getEstiloJg() == "GTA V"){
        ui->label_game->setPixmap(gtaE);
    }

    ui->labelRun->setText(comoRoda(row));

 }


void MainWindow::on_homeEd_clicked()
{
    ui->pags->setCurrentIndex(0);
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index == 1) ui->pags->setCurrentIndex(0);
}

void MainWindow::on_excluirEd_clicked()
{
    ui->pags->setCurrentIndex(0);
    lista.erase(lista.begin()+setupAberto);
    atualizarTabela();
}

void MainWindow::on_salvarEd_clicked()
{
    if(trocouNome and !nomeRep(ui->apelidoSetupLine_2->text()) and !(ui->comboBoxEstilo_2->currentIndex() != 0 and lista[setupAberto].setApelido(ui->apelidoSetupLine_2->text().toUpper()) and lista[setupAberto].setClockProc(ui->clockNucleoLine_2->text().toDouble()))){
        lista[setupAberto].setMemVideo(ui->memVideoLine_2->text().toDouble());
        lista[setupAberto].setNPlacas(ui->spinBoxPlacas_2->text().toInt());
        lista[setupAberto].setNNucleos(ui->spinBoxNucleos_2->text().toInt());
        lista[setupAberto].setEstiloJg(ui->comboBoxEstilo_2->currentText());
        lista[setupAberto].setApelido(ui->apelidoSetupLine_2->text().toUpper());


        QMessageBox::information(this,"OK","Editado com sucesso!");

        atualizarTabela();
        clear();
    }else if(lista[setupAberto].setApelido(ui->apelidoSetupLine_2->text().toUpper())
              ){
        lista[setupAberto].setMemVideo(ui->memVideoLine_2->text().toDouble());
        lista[setupAberto].setNPlacas(ui->spinBoxPlacas_2->text().toInt());
        lista[setupAberto].setNNucleos(ui->spinBoxNucleos_2->text().toInt());
        lista[setupAberto].setEstiloJg(ui->comboBoxEstilo_2->currentText());
        //lista[setupAberto].setApelido(ui->apelidoSetupLine_2->text().toUpper());

        QMessageBox::information(this,"OK","Editado com sucesso!");

        atualizarTabela();
        clear();


    }
    else QMessageBox::warning(this, "Valor inválido", "Informe valores válidos");
}

void MainWindow::on_apelidoSetupLine_2_textChanged(const QString &arg1)
{
    trocouNome = true;
}

QString MainWindow::comoRoda(int s)
{
    int Score = 0;

    if(lista[s].getEstiloJg() == "Combat Arms"){
        if(lista[s].getNNucleos() >= 1)
        if(lista[s].getClockProc() >= 1000)
        if(lista[s].getMemVideo() >= 64) Score++;

        if(lista[s].getNNucleos() >= 1)
        if(lista[s].getClockProc() >= 2400)
        if(lista[s].getMemVideo() >= 256) Score++;

    }
    if(lista[s].getEstiloJg() == "League of Legends"){
        if(lista[s].getNNucleos() >= 1)
        if(lista[s].getClockProc() >= 2000)
        if(lista[s].getMemVideo() >= 64) Score++;

        if(lista[s].getNNucleos() >= 1)
        if(lista[s].getClockProc() >= 3000)
        if(lista[s].getMemVideo() >= 512) Score++;

    }
    if(lista[s].getEstiloJg() == "Overwatch"){
        if(lista[s].getNNucleos() >= 2)
        if(lista[s].getClockProc() >= 2400)
        if(lista[s].getMemVideo() >= 768) Score++;

        if(lista[s].getNNucleos() >= 4)
        if(lista[s].getClockProc() >= 3000)
        if(lista[s].getMemVideo() >= 2048) Score++;


    }
    if(lista[s].getEstiloJg() == "Rainbow 6"){
        if(lista[s].getNNucleos() >= 2)
        if(lista[s].getClockProc() >= 3000)
        if(lista[s].getMemVideo() >= 1024) Score++;

        if(lista[s].getNNucleos() >= 4)
        if(lista[s].getClockProc() >= 3100)
        if(lista[s].getMemVideo() >= 2048) Score++;


    }
    if(lista[s].getEstiloJg() == "GTA V"){
        if(lista[s].getNNucleos() >= 4)
        if(lista[s].getClockProc() >= 2400)
        if(lista[s].getMemVideo() >= 64) Score++;

        if(lista[s].getNNucleos() >= 4)
        if(lista[s].getClockProc() >= 3200)
        if(lista[s].getMemVideo() >= 256) Score++;


    }

    switch (Score) {

        case(0): return "Não roda";

        case(1): return "Roda mínimamente";

        case(2): return "Roda como recomendado ou superior";

    }
}

void MainWindow::on_actionAbrir_triggered()
{
    ui->tabela->setRowCount(0);
    lista.clear();

    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Abrir Arquivo","","*.csv");

    QFile arquivo(filename);

    arquivo.open(QIODevice::ReadOnly);

    QString linha;
    QStringList dados;

    while(!arquivo.atEnd()){
        Setup temp;

        linha = arquivo.readLine();
        dados = linha.split(",");

        temp.setApelido(dados[0]);
        temp.setNNucleos(dados[1].toInt());
        temp.setClockProc(dados[2].toDouble());
        temp.setNPlacas(dados[3].toInt());
        temp.setMemVideo(dados[4].toDouble());
        temp.setEstiloJg(dados[5]);


        lista.push_back(temp);
    }

    arquivo.close();

    atualizarTabela();

}

void MainWindow::on_actionSalvar_triggered()
{
    QString filename;
    filename = QFileDialog::getSaveFileName(this, "Salvar Arquivo","","*.csv");

    QFile arquivo(filename);

    arquivo.open(QIODevice::WriteOnly);

    for(auto l : lista){
        QString linha = l.getApelido() + "," +
                        QString::number(l.getNNucleos()) + "," +
                        QString::number(l.getClockProc()) + "," +
                        QString::number(l.getNPlacas()) + "," +
                        QString::number(l.getMemVideo()) + "," +
                        l.getEstiloJg() +
                        "\n";

        arquivo.write(linha.toLocal8Bit());

    }
    arquivo.close();
}

