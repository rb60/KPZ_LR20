#ifndef VISITOR_H
#define VISITOR_H

class DairyFarm;
class Milk;
class Creamery;
class Cheese;

class Visitor
{
public:
    virtual void visitFarm(DairyFarm* farm) = 0;
    virtual void visitMilk(Milk* milk) = 0;
    virtual void visitCreamery(Creamery* creamery) = 0;
    virtual void visitChese(Cheese* cheese) = 0;
};

#endif // VISITOR_H
