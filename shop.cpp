#include "shop.h"
#include "ui_shop.h"
#include "cabinet.h"
#include <QMessageBox>

shop::shop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shop)
{
    ui->setupUi(this);
}

shop::~shop()
{
    delete ui;
}


void shop::startShop(int idAcc){
    row = idAcc;
    model = new QSqlTableModel(this);
    model->setTable("tab1");
    model->select();
    record = model->record();
    countDatas();

    designShop();
    exec();
}

void shop::designShop(){
    QPixmap h_carrot(":/pic/h_carrot.png");
    QPixmap h_onion(":/pic/h_onion.png");
    QPixmap h_potato(":/pic/h_potato.png");
    QPixmap h_cucumber(":/pic/h_cucumber.png");
    QPixmap h_tomato(":/pic/h_tomato.png");
    QPixmap h_sunflower(":/pic/h_sunflower.png");
    QPixmap s_carrot(":/pic/s_carrot.png");
    QPixmap s_onion(":/pic/s_onion.png");
    QPixmap s_potato(":/pic/s_potato.png");
    QPixmap s_cucumber(":/pic/s_cucumber.png");
    QPixmap s_tomato(":/pic/s_tomato.png");
    QPixmap s_sunflower(":/pic/s_sunflower.png");
    QPixmap feed(":/pic/feer.png");
    QPixmap egg(":/pic/eggs.png");

    int w = ui->sh_carrot->width();
    int h = ui->sh_carrot->height();
    ui->sh_eggs->setPixmap(egg.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_feed_2->setPixmap(feed.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_carrot->setPixmap(h_carrot.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_cucumber->setPixmap(h_cucumber.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_onion->setPixmap(h_onion.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_potato->setPixmap(h_potato.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_tomato->setPixmap(h_tomato.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_sunflower->setPixmap(h_sunflower.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_carrot_14->setPixmap(s_carrot.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_cucumber_2->setPixmap(s_cucumber.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_onion_2->setPixmap(s_onion.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_potato_2->setPixmap(s_potato.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_tomato_2->setPixmap(s_tomato.scaled(w,h,Qt::KeepAspectRatio));
    ui->sh_sunflower_2->setPixmap(s_sunflower.scaled(w,h,Qt::KeepAspectRatio));
    QString bal = "Баланс: " + QString::number(balance) + " грн";
    ui->lab_bal->setText(bal);
    int col = model->fieldIndex("fields");
    QModelIndex ind = model->index(row,col);
    QVariant data = ind.data();
    int countFields = data.toInt();
    int last = 3 - countFields;
    QString buyFields = "Купити поле (доступно: " + QString::number(last) + " ) | Ціна: 5.000 грн";
    ui->pushButton_8->setText(buyFields);
}

void shop::countDatas(){
    int col = model->fieldIndex("h_carrot");
    QModelIndex ind = model->index(row, col);
    QVariant data = ind.data();
    harvest_carrot = data.toInt();

    col = model->fieldIndex("h_potato");
    ind = model->index(row, col);
    data = ind.data();
    harvest_potato = data.toInt();

    col = model->fieldIndex("h_onion");
    ind = model->index(row, col);
    data = ind.data();
    harvest_onion = data.toInt();

    col = model->fieldIndex("h_tomato");
    ind = model->index(row, col);
    data = ind.data();
    harvest_tomato = data.toInt();

    col = model->fieldIndex("h_cucumber");
    ind = model->index(row, col);
    data = ind.data();
    harvest_cucumber = data.toInt();

    col = model->fieldIndex("h_sunflower");
    ind = model->index(row, col);
    data = ind.data();
    harvest_sunflower = data.toInt();

    col = model->fieldIndex("s_carrot");
    ind = model->index(row, col);
    data = ind.data();
    seed_carrot = data.toInt();

    col = model->fieldIndex("s_potato");
    ind = model->index(row, col);
    data = ind.data();
    seed_potato = data.toInt();

    col = model->fieldIndex("s_onion");
    ind = model->index(row, col);
    data = ind.data();
    seed_onion = data.toInt();

    col = model->fieldIndex("s_tomato");
    ind = model->index(row, col);
    data = ind.data();
    seed_tomato = data.toInt();

    col = model->fieldIndex("s_cucumber");
    ind = model->index(row, col);
    data = ind.data();
    seed_cucumber = data.toInt();

    col = model->fieldIndex("s_sunflower");
    ind = model->index(row, col);
    data = ind.data();
    seed_sunflower = data.toInt();

    col = model->fieldIndex("balance");
    ind = model->index(row, col);
    data = ind.data();
    balance = data.toInt();

    col = model->fieldIndex("feed");
    ind = model->index(row, col);
    data = ind.data();
    feed = data.toInt();

    col = model->fieldIndex("eggs");
    ind = model->index(row, col);
    data = ind.data();
    eggs = data.toInt();

    col = model->fieldIndex("fields");
    ind = model->index(row, col);
    data = ind.data();
    countFields = data.toInt();
}

void shop::upgradeDatas(){
    int col = model->fieldIndex("h_carrot");
    QModelIndex index = model->index(row,col);
    model->setData(index,harvest_carrot);
    col = model->fieldIndex("h_onion");
    index = model->index(row,col);
    model->setData(index,harvest_onion);
    col = model->fieldIndex("h_potato");
    index = model->index(row,col);
    model->setData(index,harvest_potato);
    col = model->fieldIndex("h_tomato");
    index = model->index(row,col);
    model->setData(index,harvest_tomato);
    col = model->fieldIndex("h_cucumber");
    index = model->index(row,col);
    model->setData(index,harvest_cucumber);
    col = model->fieldIndex("h_sunflower");
    index = model->index(row,col);
    model->setData(index,harvest_sunflower);
    col = model->fieldIndex("s_carrot");
    index = model->index(row,col);
    model->setData(index,seed_carrot);
    col = model->fieldIndex("s_onion");
    index = model->index(row,col);
    model->setData(index,seed_onion);
    col = model->fieldIndex("s_potato");
    index = model->index(row,col);
    model->setData(index,seed_potato);
    col = model->fieldIndex("s_tomato");
    index = model->index(row,col);
    model->setData(index,seed_tomato);
    col = model->fieldIndex("s_cucumber");
    index = model->index(row,col);
    model->setData(index,seed_cucumber);
    col = model->fieldIndex("s_sunflower");
    index = model->index(row,col);
    model->setData(index,seed_sunflower);
    col=model->fieldIndex("balance");
    index = model->index(row,col);
    model->setData(index,balance);
    col=model->fieldIndex("fields");
    index = model->index(row,col);
    model->setData(index,countFields);
    col=model->fieldIndex("feed");
    index = model->index(row,col);
    model->setData(index,feed);
    col=model->fieldIndex("eggs");
    index = model->index(row,col);
    model->setData(index,eggs);
    model->submitAll();
    model->select();
}

void shop::on_pushButton_clicked()
{
    hide();
    Cabinet c;
    c.startCab(row);
}


void shop::on_pushButton_2_clicked()
{
    if (harvest_carrot>=10) {
        harvest_carrot = harvest_carrot - 10;
        balance = balance + 250;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо товару"); }
}


void shop::on_pushButton_3_clicked()
{
    if (harvest_potato>=10){
        harvest_potato = harvest_potato - 10;
        balance = balance + 150;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо товару"); }
}


void shop::on_pushButton_4_clicked()
{
    if (harvest_onion>=10){
        harvest_onion = harvest_onion - 10;
        balance = balance + 300;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо товару"); }
}


void shop::on_pushButton_5_clicked()
{
    if (harvest_cucumber>=10){
        harvest_cucumber=harvest_cucumber-10;
        balance = balance + 250;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо товару"); }
}


void shop::on_pushButton_7_clicked()
{
    if (harvest_tomato>=10){
        harvest_tomato=harvest_tomato-10;
        balance = balance + 30;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо товару"); }
}


void shop::on_pushButton_6_clicked()
{
    if (harvest_sunflower>=10){
        harvest_sunflower=harvest_sunflower-10;
        balance = balance + 500;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо товару"); }
}


void shop::on_pushButton_8_clicked()
{
    if (balance>=5000 && countFields < 3){
        balance = balance - 5000;
        countFields++;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);

        int col = model->fieldIndex("fields");
        QModelIndex ind = model->index(row,col);
        QVariant data = ind.data();
        int countFields = data.toInt();
        int last = 3 - countFields;
        QString buyFields = "Купити поле (доступно: " + QString::number(last) + " ) | Ціна: 5.000 грн";
        ui->pushButton_8->setText(buyFields);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо коштів або ліміт кількості полів."); }
}


void shop::on_pushButton_11_clicked()
{
    if (balance >= 75) {
        balance = balance - 75;
        seed_carrot = seed_carrot + 5;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо коштів."); }
}


void shop::on_pushButton_9_clicked()
{
    if (balance >=50) {
        balance = balance - 50;
        seed_potato = seed_potato + 10;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо коштів."); }
}


void shop::on_pushButton_10_clicked()
{
    if (balance>=100){
        balance = balance - 100;
        seed_onion = seed_onion+5;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо коштів."); }
}


void shop::on_pushButton_12_clicked()
{
    if (balance>=100){
        balance = balance - 100;
        seed_cucumber = seed_cucumber + 10;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо коштів."); }
}


void shop::on_pushButton_15_clicked()
{
    if (balance>=100){
        balance = balance - 100;
        seed_tomato = seed_tomato + 5;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
        else { QMessageBox::critical(this, "Помилка", "У вас недостатньо коштів."); }
    }


void shop::on_pushButton_13_clicked()
{
    if (balance>=200){
        balance = balance - 200;
        seed_sunflower = seed_sunflower + 10;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо коштів."); }
}


void shop::on_pushButton_14_clicked()
{
    if (balance>=300){
        balance = balance - 300;
        feed = feed + 10;
        upgradeDatas();
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо коштів."); }

}


void shop::on_pushButton_16_clicked()
{
    if (eggs>=3){
        eggs = eggs - 3;
        balance = balance + 300;
        QString bal = "Баланс: " + QString::number(balance) + " грн";
        ui->lab_bal->setText(bal);
        upgradeDatas();
    }
    else { QMessageBox::critical(this, "Помилка", "У вас недостатньо коштів."); }
}

