#include "edit.h"
#include "ui_edit.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

edit::edit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::edit)
{
    ui->setupUi(this);


}

edit::~edit()
{
    delete ui;
}


void edit::on_actionabrir_triggered()
{
    QString filtro="Todos os arquivos(*.*) ;;Arquivos de texto(*.txt)";
    QString nome_arquivo=QFileDialog::getOpenFileName(this,"Gerenciador de arquivos",QDir::homePath(),filtro);
    QFile arquivo(nome_arquivo);
    local_arquivo=nome_arquivo;
    if(!arquivo.open(QFile::ReadOnly | QFile::Text))
    {
        ui->textEdit_2->setText("Arquivo ñ foi aberto");
        return;
    }
    QTextStream saida(&arquivo);
    QString texto= saida.readAll();
    ui->plainTextEdit->setPlainText(texto);
    arquivo.close();


}

void edit::on_actionNovo_triggered()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setFocus();
    local_arquivo="";
}

void edit::on_actionSalvar_Como_triggered()
{
    QString filtro = "Todos os arquivos(*.*) ;; Arquivos de texto(*.txt)";
    QString nome_arquivo = QFileDialog::getSaveFileName(this,"Gerenciador de arquivos",QDir::homePath(),filtro);
    QFile arquivo(nome_arquivo);
    local_arquivo = nome_arquivo;
    if(!arquivo.open(QFile::WriteOnly | QFile::Text)){
        ui->textEdit_2->setText("Arquivo salvo");
    }
    QTextStream entrada(&arquivo);
    QString texto = ui->plainTextEdit->toPlainText();
    entrada << texto;
    arquivo.close();

}

void edit::on_actionSalvar_triggered()
{
    QFile arquivo(local_arquivo);
    if(!arquivo.open(QFile::WriteOnly | QFile::Text)){
        ui->textEdit_2->setText("Arquivo salvo");
    }
    QTextStream entrada(&arquivo);
    QString texto = ui->plainTextEdit->toPlainText();
    entrada << texto;
    arquivo.close();
}
