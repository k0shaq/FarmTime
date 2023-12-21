#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include <QDir>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString currentPath = QDir::currentPath();
    QString filename = "DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};FIL={MS Access};DBQ=" + currentPath + "/BD.accdb";
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(filename);
    if (db.open()){
        qDebug("Open");
    }
    else {
          qDebug()<<" we have this dirvers: "<<QSqlDatabase::drivers();
          qDebug()<<"and we get this error: "<<db.lastError().text();
    }
    model = new QSqlTableModel(this,db);
    model->setTable("tab1");
    model->select();
     ui->tableView->setModel(model);
    QSqlRecord record = model->record();
}
MainWindow::~MainWindow()
{
    delete ui;
}

