#include "milkdialog.h"
#include "ui_milkdialog.h"
#include "listvisitor.h"
#include <QMenuBar>

MilkDialog::MilkDialog(QList<VisitorElement *> *farms, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MilkDialog)
    , farms(farms)
{
    ui->setupUi(this);

    connect(this, &QDialog::accepted, this, &MilkDialog::generateMilk);

    QMenuBar* menu = new QMenuBar(this);
    menu->addAction("Add", this, SLOT(accept()));
    menu->addAction("Canel", this, SLOT(reject()));
    this->layout()->setMenuBar(menu);

    ListVisitor visitor;
    visitor.setWidget(ui->listWidget);
    visitor.updateWidget(farms);
}

MilkDialog::~MilkDialog()
{
    delete ui;
}

Milk *MilkDialog::getMilk() const
{
    return milk;
}

void MilkDialog::showEvent(QShowEvent *event)
{
    ListVisitor visitor;
    visitor.setWidget(ui->listWidget);
    visitor.updateWidget(farms);
}

void MilkDialog::generateMilk()
{
    if(ui->listWidget->currentRow() >= 0)
    {
        milk = ((DairyFarm*)(farms->at(ui->listWidget->currentRow())))->makeMilk();
    }
}
