#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include <QSqlRecord>
#include <QTableView>
#include "mainwindow.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    QSqlTableModel *model;
    QSqlRecord record;
    int row;

    void loadNames();
    void clearAccount();


    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::StartWindow *ui;
};

#endif // STARTWINDOW_H
