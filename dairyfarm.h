#ifndef DAIRYFARM_H
#define DAIRYFARM_H
#include <QString>
#include "visitorelement.h"
#include "milk.h"

class DairyFarm : public VisitorElement
{
private:
    QString name;
public:
    DairyFarm();
    Milk* makeMilk();
    QString getName() const;
    void setName(const QString &newName);
    void accept(Visitor *visitor) override;
    ~DairyFarm() override{}
};

#endif // DAIRYFARM_H
