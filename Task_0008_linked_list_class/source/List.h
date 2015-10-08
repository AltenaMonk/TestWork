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
    void PushFront(int data);
    void PushBack(int data);
    int GetLength() const;
    ListNode * GetTail();
    ListNode const * GetTail() const;
    void Insert(int pos, int data);

private:
    ListNode * m_head;
};

#endif // LIST_H
