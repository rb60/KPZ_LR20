#include "cheese.h"

Creamery *Cheese::getProducer() const
{
    return producer;
}

QDateTime Cheese::getProductionTime() const
{
    return productionTime;
}

void Cheese::accept(Visitor *visitor)
{
    visitor->visitChese(this);
}

Milk *Cheese::getMilk() const
{
    return milk;
}

Cheese::Cheese(Creamery *producer, Milk *milk, const QDateTime &productionTime) :
    producer(producer),
    milk(milk),
    productionTime(productionTime)
{}
