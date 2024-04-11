#include "dairyfarm.h"
#include <QDateTime>

QString DairyFarm::getName() const
{
    return name;
}

void DairyFarm::setName(const QString &newName)
{
    name = newName;
}

void DairyFarm::accept(Visitor *visitor)
{
    visitor->visitFarm(this);
}

DairyFarm::DairyFarm() {}

Milk *DairyFarm::makeMilk()
{
    return new Milk(this, QDateTime::currentDateTime());
}
