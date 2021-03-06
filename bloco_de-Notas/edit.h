#ifndef EDIT_H
#define EDIT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class edit; }
QT_END_NAMESPACE

class edit : public QMainWindow
{
    Q_OBJECT

public:
    edit(QWidget *parent = nullptr);
    ~edit();

private slots:
    void on_actionabrir_triggered();

    void on_actionNovo_triggered();

    void on_actionSalvar_Como_triggered();

    void on_actionSalvar_triggered();

    void on_actionfonte_triggered();

    void on_actionCor_da_letra_triggered();

    void on_actionCor_do_background_triggered();

    void on_actionCortar_triggered();

    void on_actionColar_triggered();

    void on_actionCopiar_triggered();

    void on_actionRefazer_triggered();

    void on_actionDesfazer_triggered();

private:
    Ui::edit *ui;
    QString local_arquivo;
};
#endif // EDIT_H
