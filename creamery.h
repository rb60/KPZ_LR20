#ifndef CREAMERY_H
#define CREAMERY_H
#include "dairyfarm.h"
#include "visitorelement.h"
#include "cheese.h"

class Creamery : public VisitorElement
{
private:
    QString name;
public:
    Creamery();
    Cheese* makeCheese(Milk* milk);
    QString getName() const;
    void setName(const QString &newName);
    void accept(Visitor *visitor) override;
    ~Creamery() override{}
};

#endif // CREAMERY_H
