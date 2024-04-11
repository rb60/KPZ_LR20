#ifndef MILKDIALOG_H
#define MILKDIALOG_H

#include <QDialog>
#include <QList>
#include "milk.h"

namespace Ui {
class MilkDialog;
}

class MilkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MilkDialog(QList<VisitorElement*>* farms, QWidget *parent = nullptr);
    ~MilkDialog();
    Milk *getMilk() const;
    void showEvent(QShowEvent* event) override;
private slots:
    void generateMilk();

private:
    Milk* milk = nullptr;
    QList<VisitorElement*>* farms;
    Ui::MilkDialog *ui;
};

#endif // MILKDIALOG_H
