#include "edit.h"
#include "ui_edit.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>

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
    ui->textEdit->setPlainText(texto);
    arquivo.close();


}

void edit::on_actionNovo_triggered()
{
    ui->textEdit->clear();
    ui->textEdit->setFocus();
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
    QString texto = ui->textEdit->toPlainText();
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
    QString texto = ui->textEdit->toPlainText();
    entrada << texto;
    arquivo.close();
}

void edit::on_actionfonte_triggered()
{
    bool ok = true;
    QFont fonte = QFontDialog::getFont(&ok,this);
    ui->textEdit->setFont(fonte);
}

void edit::on_actionCor_da_letra_triggered()
{
    QColor cor =QColorDialog::getColor(Qt::white,this);
    ui->textEdit->setTextColor(cor);
}

void edit::on_actionCor_do_background_triggered()
{
    QColor cor = QColorDialog::getColor(Qt::white,this);
    ui->textEdit->setTextBackgroundColor(cor);
}

void edit::on_actionCortar_triggered()
{
    ui->textEdit->cut();
}

void edit::on_actionColar_triggered()
{
    ui->textEdit->paste();
}

void edit::on_actionCopiar_triggered()
{
    ui->textEdit->copy();
}

void edit::on_actionRefazer_triggered()
{
    ui->textEdit->redo();
}

void edit::on_actionDesfazer_triggered()
{
    ui->textEdit->undo();
}
