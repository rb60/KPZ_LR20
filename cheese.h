#ifndef CHEESE_H
#define CHEESE_H
#include "visitorelement.h"
#include <QDateTime>

class Creamery;

class Cheese : public VisitorElement
{
private:
    Creamery* producer;
    Milk* milk;
    QDateTime productionTime;
public:
    Cheese(Creamery *producer, Milk* milk, const QDateTime &productionTime);
    Creamery *getProducer() const;
    QDateTime getProductionTime() const;
    void accept(Visitor *visitor) override;
    ~Cheese() override{}
    Milk *getMilk() const;
};

#endif // CHEESE_H
