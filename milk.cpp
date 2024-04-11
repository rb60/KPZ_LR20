#include "milk.h"

DairyFarm *Milk::getProducer() const
{
    return producer;
}

QDateTime Milk::getProductionTime() const
{
    return productionTime;
}

void Milk::accept(Visitor *visitor)
{
    visitor->visitMilk(this);
}

Milk::Milk(DairyFarm* producer, const QDateTime &productionTime) :
    producer(producer),
    productionTime(productionTime)
{}
