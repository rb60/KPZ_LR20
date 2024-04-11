#include "listvisitor.h"

QListWidget *ListVisitor::getWidget() const
{
    return widget;
}

void ListVisitor::setWidget(QListWidget *newWidget)
{
    widget = newWidget;
}

ListVisitor::ListVisitor() {}

void ListVisitor::updateWidget(QList<VisitorElement *> *list)
{
    if(widget == nullptr)
    {
        return;
    }
    widget->clear();
    for(int i = 0; i < list->size(); i++)
    {
        list->at(i)->accept(this);
    }
}

void ListVisitor::visitFarm(DairyFarm *farm)
{
    widget->addItem(farm->getName());
}

void ListVisitor::visitMilk(Milk *milk)
{
    widget->addItem(milk->getProducer()->getName() + " " + milk->getProductionTime().toString());
}

void ListVisitor::visitCreamery(Creamery *creamery)
{
    widget->addItem(creamery->getName());
}

void ListVisitor::visitChese(Cheese *cheese)
{

    widget->addItem(cheese->getProducer()->getName() + " " + cheese->getProductionTime().toString());
}
