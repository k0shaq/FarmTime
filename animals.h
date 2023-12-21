#ifndef ANIMALS_H
#define ANIMALS_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class animals;
}

class animals : public QDialog
{
    Q_OBJECT

public:
    QSqlTableModel *model;
    QSqlRecord record;
    int row;

    int Cows, Pigs, Chickens, Sheeps, Feed, Eggs;
    bool chickens_NotHungry = false;
    bool isEggs = false;
    int eggsInFarm = 0;

    void startAnimals(int idAdd);
    void countDates();
    void upgradeDates();
    void uploadDesign();

    explicit animals(QWidget *parent = nullptr);
    ~animals();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void updateCapt();

    void on_pushButton_2_clicked();

private:
    Ui::animals *ui;
};

#endif // ANIMALS_H
