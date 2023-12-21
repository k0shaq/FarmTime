#include "cabinet.h"
#include "ui_cabinet.h"
#include <QPixmap>
#include <QString>
#include "myfields.h"
#include "shop.h"
#include "animals.h"

Cabinet::Cabinet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cabinet)
{
    ui->setupUi(this);

}

void Cabinet::startCab(int idAcc){
    row = idAcc;
    model = new QSqlTableModel(this);
    model->setTable("tab1");
    model->select();
    record = model->record();

    QPixmap accPict(":/pic/accPict.png");
    int Wap = ui->accPic->width();
    int Hap = ui->accPic->height();
    ui->accPic->setPixmap(accPict.scaled(Wap,Hap,Qt::KeepAspectRatio));

    QModelIndex index = model->index(idAcc,1);
    QVariant data = model->data(index);
    QString Name = data.toString();
    ui->lab_name->setText(Name);

    index = model->index(idAcc,2);
    data = model->data(index);
    QString Bal = data.toString();
    Bal+=" грн";
    ui->lab_balance->setText(Bal);
    setInv();
    upgradeInfo();
    exec();
}

Cabinet::~Cabinet()
{
    delete ui;
}

void Cabinet::setInv(){
    QPixmap s_carrot(":/pic/s_carrot.png");
    QPixmap s_onion(":/pic/s_onion.png");
    QPixmap s_potato(":/pic/s_potato.png");
    QPixmap s_cucumber(":/pic/s_cucumber.png");
    QPixmap s_tomato(":/pic/s_tomato.png");
    QPixmap s_sunflower(":/pic/s_sunflower.png");
    QPixmap h_carrot(":/pic/h_carrot.png");
    QPixmap h_onion(":/pic/h_onion.png");
    QPixmap h_potato(":/pic/h_potato.png");
    QPixmap h_cucumber(":/pic/h_cucumber.png");
    QPixmap h_tomato(":/pic/h_tomato.png");
    QPixmap h_sunflower(":/pic/h_sunflower.png");
    QPixmap eggs(":/pic/eggs.png");
    QPixmap meat(":/pic/meat.png");
    QPixmap milk(":/pic/milk.png");
    QPixmap wool(":/pic/wool.png");
   // QPixmap fertilizer(":/pic/fertilizer.png");
    QPixmap feed(":/pic/feer.png");
    int w = ui->s_carrot->width();
    int h = ui->s_carrot->height();
    ui->s_carrot->setPixmap(s_carrot.scaled(w,h,Qt::KeepAspectRatio));
    ui->s_cucumber->setPixmap(s_cucumber.scaled(w,h,Qt::KeepAspectRatio));
    ui->s_onion->setPixmap(s_onion.scaled(w,h,Qt::KeepAspectRatio));
    ui->s_potato->setPixmap(s_potato.scaled(w,h,Qt::KeepAspectRatio));
    ui->s_tomato->setPixmap(s_tomato.scaled(w,h,Qt::KeepAspectRatio));
    ui->s_sunflower->setPixmap(s_sunflower.scaled(w,h,Qt::KeepAspectRatio));
    ui->h_carrot->setPixmap(h_carrot.scaled(w,h,Qt::KeepAspectRatio));
    ui->h_cucumber->setPixmap(h_cucumber.scaled(w,h,Qt::KeepAspectRatio));
    ui->h_onion->setPixmap(h_onion.scaled(w,h,Qt::KeepAspectRatio));
    ui->h_potato->setPixmap(h_potato.scaled(w,h,Qt::KeepAspectRatio));
    ui->h_tomato->setPixmap(h_tomato.scaled(w,h,Qt::KeepAspectRatio));
    ui->h_sunflower->setPixmap(h_sunflower.scaled(w,h,Qt::KeepAspectRatio));
    ui->eggs->setPixmap(eggs.scaled(w,h,Qt::KeepAspectRatio));
    ui->meat->setPixmap(meat.scaled(w,h,Qt::KeepAspectRatio));
    ui->milk->setPixmap(milk.scaled(w,h,Qt::KeepAspectRatio));
    ui->wool->setPixmap(wool.scaled(w,h,Qt::KeepAspectRatio));
  //  ui->fertilizer->setPixmap(fertilizer.scaled(w,h,Qt::KeepAspectRatio));
    ui->feed->setPixmap(feed.scaled(w,h,Qt::KeepAspectRatio));
}

void Cabinet::upgradeInfo(){
    int col = model->fieldIndex("h_carrot");
    QModelIndex ind = model->index(row,col);
    QVariant data = ind.data();
    QString info = data.toString();
    ui->lab_h_carrot->setText(info);

    col = model->fieldIndex("h_potato");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_h_potato->setText(info);

    col = model->fieldIndex("h_onion");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_h_onion->setText(info);

    col = model->fieldIndex("h_tomato");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_h_tomato->setText(info);

    col = model->fieldIndex("h_cucumber");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_h_cucumber->setText(info);

    col = model->fieldIndex("h_sunflower");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_h_sunflower->setText(info);

    col = model->fieldIndex("s_carrot");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_s_carrot->setText(info);

    col = model->fieldIndex("s_potato");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_s_potato->setText(info);

    col = model->fieldIndex("s_onion");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_s_onion->setText(info);

    col = model->fieldIndex("s_tomato");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_s_tomato->setText(info);

    col = model->fieldIndex("s_cucumber");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_s_cucumber->setText(info);

    col = model->fieldIndex("s_sunflower");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_s_sunflower->setText(info);

    col = model->fieldIndex("eggs");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_eggs->setText(info);


    col = model->fieldIndex("meat");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_meat->setText(info);

    col = model->fieldIndex("milk");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_milk->setText(info);

    col = model->fieldIndex("wool");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_wool->setText(info);

    col = model->fieldIndex("fertilizer");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
  //  ui->lab_fertilizer->setText(info);

    col = model->fieldIndex("feed");
    ind = model->index(row,col);
    data = ind.data();
    info = data.toString();
    ui->lab_feed->setText(info);
}

void Cabinet::on_changeName_but_clicked()
{
    QString newName;
    newName=ui->changeName_lineEdit->text();
    QModelIndex index = model->index(row,1);
    model->setData(index,newName);
    model->submitAll();
    model->select();
    ui->lab_name->setText(newName);
}


void Cabinet::on_button_fields_clicked()
{
    hide();
    MyFields f;
    f.startFields(row);
}


void Cabinet::on_button_animals_clicked()
{
    hide();
    animals a;
    a.startAnimals(row);
}


void Cabinet::on_button_shop_clicked()
{
    hide();
    shop s;
    s.startShop(row);
}

