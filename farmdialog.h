#ifndef FARMDIALOG_H
#define FARMDIALOG_H

#include <QDialog>
#include "dairyfarm.h"

namespace Ui {
class FarmDialog;
}

class FarmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FarmDialog(QWidget *parent = nullptr);
    ~FarmDialog();

    DairyFarm *getFarm() const;
    void setFarm(DairyFarm *newFarm);
    void showEvent(QShowEvent* event) override;

private slots:
    void setChanges();

private:
    DairyFarm* farm = nullptr;
    Ui::FarmDialog *ui;
};

#endif // FARMDIALOG_H
