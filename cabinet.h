#ifndef CABINET_H
#define CABINET_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class Cabinet;
}

class Cabinet : public QDialog
{
    Q_OBJECT

public:
    QSqlTableModel *model;
    QSqlRecord record;
    int row;

    void startCab(int idAcc);
    void setInv();
    void upgradeInfo();

    explicit Cabinet(QWidget *parent = nullptr);
    ~Cabinet();

private slots:
    void on_changeName_but_clicked();

    void on_button_fields_clicked();

    void on_button_animals_clicked();

    void on_button_shop_clicked();

private:
    Ui::Cabinet *ui;

};

#endif // CABINET_H
