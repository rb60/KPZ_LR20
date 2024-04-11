#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , farmDialog(new FarmDialog(this))
    , milkDialog(new MilkDialog(&farms, this))
    , creameryDialog(new CreameryDialog(this))
    , cheeseDialog(new ChesseDialog(&creamerys, &milk, this))
{
    ui->setupUi(this);


    connect(ui->addFarmButton, &QPushButton::clicked, this, &MainWindow::addFarm);
    connect(ui->addMilkButton, &QPushButton::clicked, this, &MainWindow::addMilk);
    connect(ui->addCreameryButton, &QPushButton::clicked, this, &MainWindow::addCreamery);
    connect(ui->addCheeseButton, &QPushButton::clicked, this, &MainWindow::addCheese);

}

MainWindow::~MainWindow()
{
    delete ui;
    deleteList(farms);
    deleteList(milk);
    deleteList(usedMilk);
    deleteList(creamerys);
    deleteList(cheese);
}

void MainWindow::addFarm()
{
    VisitorElement* farm;
    farmDialog->setFarm(nullptr);
    if(farmDialog->exec() == QDialog::Accepted)
    {
        farm = farmDialog->getFarm();
        farms.append(farm);
        visitor.setWidget(ui->farmList);
        visitor.updateWidget(&farms);
    }
}

void MainWindow::addMilk()
{
    VisitorElement* newMilk;
    if(milkDialog->exec() == QDialog::Accepted && milkDialog->getMilk() != nullptr)
    {
        newMilk = milkDialog->getMilk();
        milk.append(newMilk);
        visitor.setWidget(ui->milkList);
        visitor.updateWidget(&milk);
    }
}

void MainWindow::addCreamery()
{
    VisitorElement* creamery;
    creameryDialog->setCreamery(nullptr);
    if(creameryDialog->exec() == QDialog::Accepted)
    {
        creamery = creameryDialog->getCreamery();
        creamerys.append(creamery);
        visitor.setWidget(ui->creameryList);
        visitor.updateWidget(&creamerys);
    }
}

void MainWindow::addCheese()
{
    VisitorElement* newCheese;
    if(cheeseDialog->exec() == QDialog::Accepted && cheeseDialog->getCheese() != nullptr)
    {
        newCheese = cheeseDialog->getCheese();
        cheese.append(newCheese);

        usedMilk.append(((Cheese*)newCheese)->getMilk());
        milk.removeAll(((Cheese*)newCheese)->getMilk());

        visitor.setWidget(ui->cheeseList);
        visitor.updateWidget(&cheese);
        visitor.setWidget(ui->milkList);
        visitor.updateWidget(&milk);

    }
}

void MainWindow::deleteList(QList<VisitorElement *> list)
{
    for (int i = 0; i < list.size(); ++i)
    {
        delete list[i];
    }
}
