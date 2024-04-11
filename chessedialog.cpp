#include "chessedialog.h"
#include "ui_chessedialog.h"
#include <QMenuBar>
#include "listvisitor.h"

ChesseDialog::ChesseDialog(QList<VisitorElement *> *creamerys, QList<VisitorElement *> *milk, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChesseDialog)
    , creamerys(creamerys)
    , milk(milk)
{
    ui->setupUi(this);

    connect(this, &QDialog::accepted, this, &ChesseDialog::makeCheese);

    QMenuBar* menu = new QMenuBar(this);
    menu->addAction("Add", this, SLOT(accept()));
    menu->addAction("Canel", this, SLOT(reject()));
    this->layout()->setMenuBar(menu);
    ListVisitor visitor;
    visitor.setWidget(ui->CreameryList);
    visitor.updateWidget(creamerys);
    visitor.setWidget(ui->milkList);
    visitor.updateWidget(milk);

}

ChesseDialog::~ChesseDialog()
{
    delete ui;
}

void ChesseDialog::makeCheese()
{
    if(ui->CreameryList->currentRow() >= 0 && ui->milkList->currentRow() >=0)
    {
        cheese =  ((Creamery*)(creamerys->at(ui->CreameryList->currentRow())))->makeCheese((Milk*)(milk->at(ui->milkList->currentRow())));
    }
}

Cheese *ChesseDialog::getCheese() const
{
    return cheese;
}

void ChesseDialog::showEvent(QShowEvent *event)
{
    ListVisitor visitor;
    visitor.setWidget(ui->CreameryList);
    visitor.updateWidget(creamerys);
    visitor.setWidget(ui->milkList);
    visitor.updateWidget(milk);
}
