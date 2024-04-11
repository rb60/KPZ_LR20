#ifndef VISITORELEMENT_H
#define VISITORELEMENT_H
#include "visitor.h"


class VisitorElement
{
public:
    virtual void accept(Visitor* visitor) = 0;
    virtual ~VisitorElement() {}
};

#endif // VISITORELEMENT_H
