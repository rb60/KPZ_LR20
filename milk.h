#ifndef MILK_H
#define MILK_H
#include "visitorelement.h"
#include <QDateTime>

class DairyFarm;

class Milk : public VisitorElement
{
private:
    DairyFarm* producer;
    QDateTime productionTime;
public:
    Milk(DairyFarm* producer, const QDateTime & productionTime);
    DairyFarm *getProducer() const;
    QDateTime getProductionTime() const;
    void accept(Visitor *visitor) override;
    ~Milk() override{}
};

#endif // MILK_H
