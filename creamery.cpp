#include "creamery.h"

QString Creamery::getName() const
{
    return name;
}

void Creamery::setName(const QString &newName)
{
    name = newName;
}

void Creamery::accept(Visitor *visitor)
{
    visitor->visitCreamery(this);
}

Creamery::Creamery() {}

Cheese *Creamery::makeCheese(Milk *milk)
{
    return new Cheese(this, milk, QDateTime::currentDateTime());
}
