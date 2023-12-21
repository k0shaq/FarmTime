#ifndef MYFIELDS_H
#define MYFIELDS_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QTimer>
#include <QDateTime>
#include "cabinet.h"

namespace Ui {
class MyFields;
}

class MyFields : public QDialog
{
    Q_OBJECT

public:
    QSqlTableModel *model;
    QSqlRecord record;
    int row;
    int trueField;


    bool field1_plant = false;
    bool field2_plant = false;
    bool field3_plant = false;


    bool field1_good = false;
    bool field2_good = false;
    bool field3_good = false;

    int seed_carrot, seed_potato, seed_onion, seed_cucumber, seed_tomato, seed_sunflower;
    int harvest_carrot, harvest_potato, harvest_onion, harvest_cucumber, harvest_tomato, harvest_sunflower;
    int id1, id2, id3;

    void checkerFields();
    void startFields(int idAcc);
    void countSeeds();
    void countHarvest();
    void upgradeSeeds();
    void upgradeHarvest();
    int checkButton();
    int checkButton2();
    int checkButton3();

    explicit MyFields(QWidget *parent = nullptr);
    ~MyFields();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void updateCaption();
    void updateCaption2();
    void updateCaption3();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    QDateTime endTime;
    QTimer timer;

    Ui::MyFields *ui;
};

#endif // MYFIELDS_H
