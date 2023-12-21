#ifndef SHOP_H
#define SHOP_H
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDialog>

namespace Ui {
class shop;
}

class shop : public QDialog
{
    Q_OBJECT

public:
    QSqlTableModel *model;
    QSqlRecord record;
    int row;

    void countDatas();
    void upgradeDatas();
    int seed_carrot, seed_potato, seed_onion, seed_cucumber, seed_tomato, seed_sunflower;
    int harvest_carrot, harvest_potato, harvest_onion, harvest_cucumber, harvest_tomato, harvest_sunflower;
    int balance, countFields;
    int feed, eggs;

    void designShop();
    void startShop(int idAcc);

    explicit shop(QWidget *parent = nullptr);
    ~shop();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

private:
    Ui::shop *ui;
};

#endif // SHOP_H
