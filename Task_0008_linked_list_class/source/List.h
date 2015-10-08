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
    ListNode * GetHead();
    ListNode const * GetHead() const;
    ListNode * Get(int number);
    ListNode const * Get(int number) const;
    ListNode * Insert(int pos, int data);
    ListNode * PopFront();

private:
    ListNode * m_head;
};

#endif // LIST_H
