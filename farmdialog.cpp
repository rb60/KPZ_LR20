#include "farmdialog.h"
#include "ui_farmdialog.h"
#include <QMenuBar>

FarmDialog::FarmDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FarmDialog)
{
    ui->setupUi(this);


    connect(this, &QDialog::accepted, this, &FarmDialog::setChanges);

    QMenuBar* menu = new QMenuBar(this);
    menu->addAction("Add", this, SLOT(accept()));
    menu->addAction("Canel", this, SLOT(reject()));
    this->layout()->setMenuBar(menu);
}

FarmDialog::~FarmDialog()
{
    delete ui;
}

DairyFarm *FarmDialog::getFarm() const
{
    return farm;
}

void FarmDialog::setFarm(DairyFarm *newFarm)
{
    farm = newFarm;
}

void FarmDialog::showEvent(QShowEvent *event)
{
    ui->nameEdit->setText("");
}

void FarmDialog::setChanges()
{
    if(farm == nullptr)
        farm = new DairyFarm();
    farm->setName(ui->nameEdit->text());
}
