#ifndef LIST_H
#define LIST_H
#include "ListNode.h"


class List
{
public:
    /// Constructors
    List();
    List(List const & from);

    /// Operator =
    List & operator=(List const & x);

    /// Function Swap
    void Swap(List & other);

    /// Destructor
    ~List();

    /// Functions

private:
    ListNode m_head;
};

#endif // LIST_H
