#include "myfields.h"
#include "ui_myfields.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDateTime>
#include "cabinet.h"
#include <QButtonGroup>

MyFields::MyFields(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyFields)
{
    ui->setupUi(this);
}

MyFields::~MyFields()
{
    delete ui;
}

void MyFields::startFields(int idAcc){
    row = idAcc;
    model = new QSqlTableModel(this);
    model->setTable("tab1");
    model->select();
    record = model->record();
    checkerFields();
    countSeeds();
    countHarvest();
    exec();
}

void MyFields::checkerFields(){
    int col = model->fieldIndex("fields");
    QModelIndex ind = model->index(row, col);
    QVariant data = ind.data();
    QString info = data.toString();
    trueField = info.toInt();

    QPixmap not_field(":/pic/not-field.png");
    QPixmap field_true(":/pic/field-true.png");
    QPixmap field_false(":/pic/field-false.png");
    int Wfield = ui->field1->width();
    int Hfield = ui->field1->height();
    if (trueField == 1){
        ui->field2->setPixmap(not_field.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
        ui->field3->setPixmap(not_field.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
        if (field1_plant) {ui->field1->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));}
        else {ui->field1->setPixmap(field_false.scaled(Wfield,Hfield, Qt::KeepAspectRatio));}
    }
    else if (trueField == 2){
        ui->field3->setPixmap(not_field.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
        if (field1_plant) {ui->field1->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));}
        else {ui->field1->setPixmap(field_false.scaled(Wfield,Hfield, Qt::KeepAspectRatio));}
        if (field2_plant) {ui->field2->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));}
        else {ui->field2->setPixmap(field_false.scaled(Wfield,Hfield, Qt::KeepAspectRatio));}
    }
    else if (trueField == 3){
        if (field1_plant) {ui->field1->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));}
        else {ui->field1->setPixmap(field_false.scaled(Wfield,Hfield, Qt::KeepAspectRatio));}
        if (field2_plant) {ui->field2->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));}
        else {ui->field2->setPixmap(field_false.scaled(Wfield,Hfield, Qt::KeepAspectRatio));}
        if (field3_plant) {ui->field3->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));}
        else {ui->field3->setPixmap(field_false.scaled(Wfield,Hfield, Qt::KeepAspectRatio));}
    }

}

void MyFields::countSeeds(){
    int col = model->fieldIndex("s_carrot");
    QModelIndex ind = model->index(row, col);
    QVariant data = ind.data();
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
}

void MyFields::countHarvest(){
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
}

void MyFields::upgradeHarvest(){
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

    model->submitAll();
    model->select();
}

void MyFields::upgradeSeeds(){
    int col = model->fieldIndex("s_carrot");
    QModelIndex index = model->index(row,col);
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

    model->submitAll();
    model->select();
}

void MyFields::on_pushButton_clicked()
{
    hide();
    Cabinet c;
    c.startCab(row);

}

int MyFields::checkButton(){
    QButtonGroup *buttonGroup = new QButtonGroup();
    buttonGroup->addButton(ui->rb_carrot, 1);
    buttonGroup->addButton(ui->rb_potato, 2);
    buttonGroup->addButton(ui->rb_onion, 3);
    buttonGroup->addButton(ui->rb_cucumber, 4);
    buttonGroup->addButton(ui->rb_tomato, 5);
    buttonGroup->addButton(ui->rb_sunflower, 6);
       if (buttonGroup->checkedId() != -1) {
        return buttonGroup->checkedId(); }
       else QMessageBox::critical(this,"Помилка", "Оберіть насіння");
}

int MyFields::checkButton2(){
       QButtonGroup *buttonGroup = new QButtonGroup();
       buttonGroup->addButton(ui->rb_carrot_2, 1);
       buttonGroup->addButton(ui->rb_potato_2, 2);
       buttonGroup->addButton(ui->rb_onion_2, 3);
       buttonGroup->addButton(ui->rb_cucumber_2, 4);
       buttonGroup->addButton(ui->rb_tomato_2, 5);
       buttonGroup->addButton(ui->rb_sunflower_2, 6);
       if (buttonGroup->checkedId() != -1) {
        return buttonGroup->checkedId(); }
       else QMessageBox::critical(this,"Помилка", "Оберіть насіння");
}

int MyFields::checkButton3(){
       QButtonGroup *buttonGroup = new QButtonGroup();
       buttonGroup->addButton(ui->rb_carrot_3, 1);
       buttonGroup->addButton(ui->rb_potato_3, 2);
       buttonGroup->addButton(ui->rb_onion_3, 3);
       buttonGroup->addButton(ui->rb_cucumber_3, 4);
       buttonGroup->addButton(ui->rb_tomato_3, 5);
       buttonGroup->addButton(ui->rb_sunflower_3, 6);
       if (buttonGroup->checkedId() != -1) {
        return buttonGroup->checkedId(); }
       else QMessageBox::critical(this,"Помилка", "Оберіть насіння");
}

void MyFields::updateCaption(){
       if (field1_plant){
       ui->lab_timer->setText("0");
       field1_good = true;
       ui->lab_stan->setText("Можна збирати.");
       }
}
void MyFields::updateCaption2(){
       if (field2_plant){
       ui->lab_timer_2->setText("0");
       field2_good = true;
       ui->lab_stan_2->setText("Можна збирати.");
       }
}
void MyFields::updateCaption3(){
       if (field3_plant){
       ui->lab_timer_3->setText("0");
       field3_good = true;
       ui->lab_stan_3->setText("Можна збирати.");
       }
}
void MyFields::on_pushButton_2_clicked()
{
       QPixmap field_true(":/pic/field-true.png");
       int Wfield = ui->field1->width();
       int Hfield = ui->field1->height();

    if (field1_plant) {QMessageBox::critical(this,"Помика", "Це поле зайняте"); }
    else { id1 = checkButton();
        if (id1==1){
            if (seed_carrot>0){
                ui->field1->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_carrot--;
                field1_plant = 1;
                ui->lab_stan->setText("Росте.");
                ui->lab_timer->setText("15");
                QTimer *timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
                timer->start(15000);
            }

        else { QMessageBox::critical(this, "Помилка", "У вас немає насіння моркви.");}
        }
        if (id1==2){
            if (seed_potato>0){
                ui->field1->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_potato--;
                field1_plant = 1;
                ui->lab_stan->setText("Росте.");
                ui->lab_timer->setText("15");
                QTimer *timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
                timer->start(15000);
            }
        else { QMessageBox::critical(this, "Помилка", "У вас немає насіння картоплі.");}
        }
        if (id1==3){
            if (seed_onion>0){
                ui->field1->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_onion--;
                field1_plant = 1;
                ui->lab_stan->setText("Росте.");
                ui->lab_timer->setText("15");
                QTimer *timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
                timer->start(15000);
                   }
        else { QMessageBox::critical(this, "Помилка", "У вас немає насіння цибулі.");}
        }
        if (id1==4){
            if (seed_cucumber>0){
                ui->field1->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_cucumber--;
                field1_plant = 1;
                ui->lab_stan->setText("Росте.");
                ui->lab_timer->setText("15");
                QTimer *timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
                timer->start(15000);
            }
         else { QMessageBox::critical(this, "Помилка", "У вас немає насіння огірків.");}
        }
        if (id1==5){
            if (seed_tomato>0){
                ui->field1->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_tomato--;
                field1_plant = 1;
                ui->lab_stan->setText("Росте.");
                ui->lab_timer->setText("15");
                QTimer *timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
                timer->start(15000);
            }
        else { QMessageBox::critical(this, "Помилка", "У вас немає насіння помідорів.");}
        }
        if (id1==6){
            if (seed_sunflower>0){
                ui->field1->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_sunflower--;
                field1_plant = 1;
                ui->lab_stan->setText("Росте.");
                ui->lab_timer->setText("15");
                QTimer *timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
                timer->start(15000);
            }

            else {QMessageBox::critical(this, "Помилка", "У вас немає насіння соняху.");          }


    }
        upgradeSeeds();
}
}


void MyFields::on_pushButton_3_clicked()
{
if (field1_good){
    QMessageBox::information(this,"Інформація","Ви успішно зібрали урожай");
    field1_good = false;
    field1_plant = false;
    countHarvest();
    if (id1==1) {harvest_carrot+=5;}
    if (id1==2) {harvest_potato+=5;}
    if (id1==3) {harvest_onion+=5;}
    if (id1==4) {harvest_cucumber+=5;}
    if (id1==5) {harvest_tomato+=5;}
    if (id1==6) {harvest_sunflower+=5;}
    upgradeHarvest();
    QPixmap field_false(":/pic/field-false.png");
    int Wfield = ui->field1->width();
    int Hfield = ui->field1->height();
    ui->field1->setPixmap(field_false.scaled(Wfield,Hfield,Qt::KeepAspectRatio));
    ui->lab_stan->setText("Пусто");
}
else { QMessageBox::critical(this,"Помилка", "На цьому полі немає урожаю.");}
}


void MyFields::on_pushButton_4_clicked()
{
QPixmap field_true(":/pic/field-true.png");

int Wfield = ui->field1->width();
int Hfield = ui->field1->height();

if (field2_plant) {QMessageBox::critical(this,"Помика", "Це поле зайняте"); }
    else { id2 = checkButton2();
    if (id2==1){
            if (seed_carrot>0){
                ui->field2->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_carrot--;
                field2_plant = 1;
                ui->lab_stan_2->setText("Росте.");
                ui->lab_timer_2->setText("15");
                QTimer *timer2 = new QTimer(this);
                connect(timer2, SIGNAL(timeout()), this, SLOT(updateCaption2()));
                timer2->start(15000);
            }

            else { QMessageBox::critical(this, "Помилка", "У вас немає насіння моркви.");}
    }
    if (id2==2){
            if (seed_potato>0){
                ui->field2->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_potato--;
                field2_plant = 1;
                ui->lab_stan_2->setText("Росте.");
                ui->lab_timer_2->setText("15");
                QTimer *timer2 = new QTimer(this);
                connect(timer2, SIGNAL(timeout()), this, SLOT(updateCaption2()));
                timer2->start(15000);
            }
            else { QMessageBox::critical(this, "Помилка", "У вас немає насіння картоплі.");}
    }
    if (id2==3){
            if (seed_onion>0){
                ui->field2->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_onion--;
                field2_plant = 1;
                ui->lab_stan_2->setText("Росте.");
                ui->lab_timer_2->setText("15");
                QTimer *timer2 = new QTimer(this);
                connect(timer2, SIGNAL(timeout()), this, SLOT(updateCaption2()));
                timer2->start(15000);
            }
            else { QMessageBox::critical(this, "Помилка", "У вас немає насіння цибулі.");}
    }
    if (id2==4){
            if (seed_cucumber>0){
                ui->field2->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_cucumber--;
                field2_plant = 1;
                ui->lab_stan_2->setText("Росте.");
                ui->lab_timer_2->setText("15");
                QTimer *timer2 = new QTimer(this);
                connect(timer2, SIGNAL(timeout()), this, SLOT(updateCaption2()));
                timer2->start(15000);
            }
            else { QMessageBox::critical(this, "Помилка", "У вас немає насіння огірків.");}
    }
    if (id2==5){
            if (seed_tomato>0){
                ui->field2->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_tomato--;
                field2_plant = 1;
                ui->lab_stan_2->setText("Росте.");
                ui->lab_timer_2->setText("15");
                QTimer *timer2 = new QTimer(this);
                connect(timer2, SIGNAL(timeout()), this, SLOT(updateCaption2()));
                timer2->start(15000);
            }
            else { QMessageBox::critical(this, "Помилка", "У вас немає насіння помідорів.");}
    }
    if (id2==6){
            if (seed_sunflower>0){
                ui->field2->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_sunflower--;
                field2_plant = 1;
                ui->lab_stan_2->setText("Росте.");
                ui->lab_timer_2->setText("15");
                QTimer *timer2 = new QTimer(this);
                connect(timer2, SIGNAL(timeout()), this, SLOT(updateCaption2()));
                timer2->start(15000);
            }

            else {QMessageBox::critical(this, "Помилка", "У вас немає насіння соняху.");          }


    }
    upgradeSeeds();
}
}


void MyFields::on_pushButton_5_clicked()
{
if (field2_good){
    QMessageBox::information(this,"Інформація","Ви успішно зібрали урожай");
    field2_good = false;
    field2_plant = false;
    countHarvest();
    if (id2==1) {harvest_carrot+=5;}
    if (id2==2) {harvest_potato+=5;}
    if (id2==3) {harvest_onion+=5;}
    if (id2==4) {harvest_cucumber+=5;}
    if (id2==5) {harvest_tomato+=5;}
    if (id2==6) {harvest_sunflower+=5;}
    upgradeHarvest();
    QPixmap field_false(":/pic/field-false.png");
    int Wfield = ui->field1->width();
    int Hfield = ui->field1->height();
    ui->field2->setPixmap(field_false.scaled(Wfield,Hfield,Qt::KeepAspectRatio));
    ui->lab_stan_2->setText("Пусто");
}
else { QMessageBox::critical(this,"Помилка", "На цьому полі немає урожаю.");}
}


void MyFields::on_pushButton_6_clicked()
{
QPixmap field_true(":/pic/field-true.png");
int Wfield = ui->field1->width();
int Hfield = ui->field1->height();

if (field3_plant) {QMessageBox::critical(this,"Помика", "Це поле зайняте"); }
    else { id3 = checkButton3();
    if (id3==1){
            if (seed_carrot>0){
                ui->field3->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_carrot--;
                field3_plant = 1;
                ui->lab_stan_3->setText("Росте.");
                ui->lab_timer_3->setText("15");
                QTimer *timer3 = new QTimer(this);
                connect(timer3, SIGNAL(timeout()), this, SLOT(updateCaption3()));
                timer3->start(15000);
            }

            else { QMessageBox::critical(this, "Помилка", "У вас немає насіння моркви.");}
    }
    if (id3==2){
            if (seed_potato>0){
                ui->field3->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_potato--;
                field3_plant = 1;
                ui->lab_stan_3->setText("Росте.");
                ui->lab_timer_3->setText("15");
                QTimer *timer3 = new QTimer(this);
                connect(timer3, SIGNAL(timeout()), this, SLOT(updateCaption3()));
                timer3->start(15000);
            }
            else { QMessageBox::critical(this, "Помилка", "У вас немає насіння картоплі.");}
    }
    if (id3==3){
            if (seed_onion>0){
                ui->field3->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_onion--;
                field3_plant = 1;
                ui->lab_stan_3->setText("Росте.");
                ui->lab_timer_3->setText("15");
                QTimer *timer3 = new QTimer(this);
                connect(timer3, SIGNAL(timeout()), this, SLOT(updateCaption3()));
                timer3->start(15000);
            }
            else { QMessageBox::critical(this, "Помилка", "У вас немає насіння цибулі.");}
    }
    if (id3==4){
            if (seed_cucumber>0){
                ui->field3->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_cucumber--;
                field3_plant = 1;
                ui->lab_stan_3->setText("Росте.");
                ui->lab_timer_3->setText("15");
                QTimer *timer3 = new QTimer(this);
                connect(timer3, SIGNAL(timeout()), this, SLOT(updateCaption3()));
                timer3->start(15000);
            }
            else { QMessageBox::critical(this, "Помилка", "У вас немає насіння огірків.");}
    }
    if (id3==5){
            if (seed_tomato>0){
                ui->field3->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_tomato--;
                field3_plant = 1;
                ui->lab_stan_3->setText("Росте.");
                ui->lab_timer_3->setText("15");
                QTimer *timer3 = new QTimer(this);
                connect(timer3, SIGNAL(timeout()), this, SLOT(updateCaption3()));
                timer3->start(15000);
            }
            else { QMessageBox::critical(this, "Помилка", "У вас немає насіння помідорів.");}
    }
    if (id3==6){
            if (seed_sunflower>0){
                ui->field3->setPixmap(field_true.scaled(Wfield, Hfield, Qt::KeepAspectRatio));
                seed_sunflower--;
                field3_plant = 1;
                ui->lab_stan_3->setText("Росте.");
                ui->lab_timer_3->setText("15");
                QTimer *timer3 = new QTimer(this);
                connect(timer3, SIGNAL(timeout()), this, SLOT(updateCaption3()));
                timer3->start(15000);
            }

            else {QMessageBox::critical(this, "Помилка", "У вас немає насіння соняху.");          }


    }
    upgradeSeeds();
}
}


void MyFields::on_pushButton_7_clicked()
{

if (field3_good){
    QMessageBox::information(this,"Інформація","Ви успішно зібрали урожай");
    field3_good = false;
    field3_plant = false;
    countHarvest();
    if (id3==1) {harvest_carrot+=5;}
    if (id3==2) {harvest_potato+=5;}
    if (id3==3) {harvest_onion+=5;}
    if (id3==4) {harvest_cucumber+=5;}
    if (id3==5) {harvest_tomato+=5;}
    if (id3==6) {harvest_sunflower+=5;}
    upgradeHarvest();
    QPixmap field_false(":/pic/field-false.png");
    int Wfield = ui->field1->width();
    int Hfield = ui->field1->height();
    ui->field3->setPixmap(field_false.scaled(Wfield,Hfield,Qt::KeepAspectRatio));
    ui->lab_stan_3->setText("Пусто");
}
else { QMessageBox::critical(this,"Помилка", "На цьому полі немає урожаю.");}

}

