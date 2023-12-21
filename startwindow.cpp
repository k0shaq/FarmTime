#include <QDebug>
#include <QString>
#include "startwindow.h"
#include <QMessageBox>
#include "ui_startwindow.h"
#include "cabinet.h"

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("tab1");
    model->select();
    record = model->record();
    loadNames();
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::loadNames() {
    ui->listWidget->clear();
    ui->listWidget->addItem(" ");
    int nameColumn = model->fieldIndex("name");
    if (nameColumn != -1) {
        for (int r = 0; r < model->rowCount(); ++r) {
            QModelIndex index = model->index(r, nameColumn);
            QVariant value = model->data(index);
            if (value.isValid()) {
                QString name = value.toString();
                ui->listWidget->addItem(name);
            }
        }
    }
}

void StartWindow::clearAccount(){
    int idAcc = ui->listWidget->currentRow();
    idAcc = idAcc-1;
    QModelIndex ind;

    int nameCol = model->fieldIndex("name");
    ind = model->index(idAcc, nameCol);
    model->setData(ind, "Player");
    model->submitAll();
    model->select();

    nameCol = model->fieldIndex("balance");
    ind = model->index(idAcc, nameCol);
    model->setData(ind, "10000");
    model->submitAll();
    model->select();

    nameCol = model->fieldIndex("fields");
    ind = model->index(idAcc, nameCol);
    model->setData(ind, "1");
    model->submitAll();
    model->select();

    for (int i = 4; i<=25; i++){
    ind = model->index(idAcc, i);
    model->setData(ind, "0");
    model->submitAll();
    model->select();
    }
    QMessageBox::about(this,"Інформація", "Акаунт успішно очищено");
}



void StartWindow::on_pushButton_clicked()
{
    clearAccount();
    loadNames();
}


void StartWindow::on_pushButton_2_clicked()
{

    int idAcc = ui->listWidget->currentRow();
    qDebug()<<idAcc;
    if (idAcc<=5 && idAcc>=1 ){
    Cabinet cab;
    hide();
    cab.startCab(idAcc-1);}
    else{
    QMessageBox::critical(this,"Помилка", "Ви не обрали акаунт!");
    }
}

