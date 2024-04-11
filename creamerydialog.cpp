#include "creamerydialog.h"
#include "ui_creamerydialog.h"
#include <QMenuBar>

CreameryDialog::CreameryDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreameryDialog)
{
    ui->setupUi(this);

    connect(this, &QDialog::accepted, this, &CreameryDialog::setChanges);

    QMenuBar* menu = new QMenuBar(this);
    menu->addAction("Add", this, SLOT(accept()));
    menu->addAction("Canel", this, SLOT(reject()));
    this->layout()->setMenuBar(menu);
}

CreameryDialog::~CreameryDialog()
{
    delete ui;
}

Creamery *CreameryDialog::getCreamery() const
{
    return creamery;
}

void CreameryDialog::setCreamery(Creamery *newCreamery)
{
    creamery = newCreamery;
}

void CreameryDialog::showEvent(QShowEvent *event)
{
    ui->nameEdit->setText("");
}

void CreameryDialog::setChanges()
{
    if(creamery == nullptr)
        creamery = new Creamery;
    creamery->setName(ui->nameEdit->text());
}
