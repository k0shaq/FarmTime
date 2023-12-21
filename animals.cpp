#include "animals.h"
#include "ui_animals.h"
#include <QPixmap>
#include "cabinet.h"
#include <QTimer>
#include <QMessageBox>

animals::animals(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::animals)
{
    ui->setupUi(this);
}

animals::~animals()
{
    delete ui;
}


void animals::startAnimals(int idAcc){
    row = idAcc;
    model = new QSqlTableModel(this);
    model->setTable("tab1");
    model->select();
    record = model->record();
    uploadDesign();
    countDates();
    exec();
}

void animals::uploadDesign(){
    QPixmap chikHouse(":/pic/chickenHouse.png");
    int H = ui->chickHouse->width();
    int W = ui->chickHouse->height();
    ui->chickHouse->setPixmap(chikHouse.scaled(H, W, Qt::KeepAspectRatio));
}

void animals::countDates(){
    int col = model->fieldIndex("chickens");
    QModelIndex ind = model->index(row, col);
    QVariant data = ind.data();
    Chickens = data.toInt();

    col - model->fieldIndex("eggs");
    ind = model->index(row,col);
    data=ind.data();
    Eggs = data.toInt();
}

void animals::upgradeDates(){
    int col = model->fieldIndex("chickens");
    QModelIndex index = model->index(row,col);
    model->setData(index,Chickens);

    col = model->fieldIndex("eggs");
    index = model->index(row,col);
    model->setData(index,Eggs);

    model->submitAll();
    model->select();
}

void animals::on_pushButton_3_clicked()
{
    hide();
    Cabinet c;
    c.startCab(row);
}

void animals::updateCapt(){
    if (chickens_NotHungry){
        isEggs = true;
        ui->stanKubla_label->setText("Можна збирати.");
    }
}

void animals::on_pushButton_clicked()
{
    if (Feed>0) {
        Feed = Feed - 1;
        chickens_NotHungry=true;
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateCapt()));
        timer->start(15000);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас немає корму");}
}


void animals::on_pushButton_2_clicked()
{
    if (isEggs){
        QMessageBox::information(this,"Інформація","Ви успішно зібрали яйця");
        isEggs = false;
        chickens_NotHungry = false;
        Eggs = Eggs + 3;
        upgradeDates();
        ui->stanKubla_label->setText("Пусто");
    }
    else { QMessageBox::critical(this,"Помилка", "У кублі немає яєць.");}
}


