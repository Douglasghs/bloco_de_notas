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

private:
    Ui::edit *ui;
    QString local_arquivo;
};
#endif // EDIT_H
