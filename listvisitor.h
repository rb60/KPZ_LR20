#ifndef LISTVISITOR_H
#define LISTVISITOR_H

#include "visitorelement.h"
#include "dairyfarm.h"
#include "milk.h"
#include "creamery.h"
#include "cheese.h"
#include <QListWidget>
#include <QList>

class ListVisitor : public Visitor
{
private:
    QListWidget* widget = nullptr;
public:
    ListVisitor();
    void updateWidget(QList<VisitorElement*>* list);
    void visitFarm(DairyFarm *farm) override;
    void visitMilk(Milk *milk) override;
    void visitCreamery(Creamery *creamery) override;
    void visitChese(Cheese *cheese) override;
    QListWidget *getWidget() const;
    void setWidget(QListWidget *newWidget);
};

#endif // LISTVISITOR_H
