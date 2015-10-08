#include "List.h"
#include <cstddef>
#include <utility>

/// Constructors
List::List()
    :m_head(NULL)
{
}

List::List(List const &from)
    :m_head(from.m_head)
{
}

/// Operator =
List & List::operator=(List const & from)
{
    List x(from);
    Swap(x);
    return *this;
}

/// Function Swap
void List::Swap(List &other)
{
    std::swap(m_head, other.m_head);
}

/// Destructor
List::~List()
{
    if (m_head == NULL)
    {
        delete m_head;
    }
}

void List::PushFront(int data)
{
    ListNode * newFirstNode = new ListNode();
    newFirstNode->SetData(data);
    newFirstNode->SetNext(m_head);
    m_head = newFirstNode;
}

void List::PushBack(int data)
{
    ListNode * newLastNode = new ListNode();
    newLastNode->SetData(data);
    newLastNode->SetNext(NULL);
    ListNode * tail = GetTail();
    if (tail == NULL)
    {
        m_head = newLastNode;
    }
    else
    {
        tail->SetNext(newLastNode);
    }
}

int List::GetLength() const
{
    ListNode const * current = m_head;
    int i = 0;
    for (;current != NULL; current = current->GetNext())
    {
        ++i;
    }
    return i;
}

ListNode * List::GetTail()
{
    if (m_head == NULL)
    {
        return NULL;
    }
    ListNode * tail = m_head;
    for (;tail->GetNext() != NULL; tail = tail->GetNext())
    {
    }
    return tail;
}

ListNode const * List::GetTail() const
{
    if (m_head == NULL)
    {
        return NULL;
    }
    ListNode const * tail = m_head;
    for (;tail->GetNext() != NULL; tail = tail->GetNext())
    {
    }
    return tail;
}

ListNode * List::GetHead()
{
    return m_head;
}

ListNode const * List::GetHead() const
{
    return m_head;
}

ListNode * List::Get(int number)
{
    ListNode * current = GetHead();
    for (int i = 0; i < number || current != NULL; ++i, current = current->GetNext())
    {
    }
    return current;
}

ListNode const * List::Get(int number) const
{
    ListNode const * current = GetHead();
    for (int i = 0;i < number ||  current != NULL; ++i, current = current->GetNext())
    {
    }
    return current;
}

ListNode * List::Insert(int pos, int data)
{
    ListNode * previous = Get(pos - 1);
    if (previous == NULL)
    {
        return NULL;
    }
    ListNode * target = new ListNode();
    target->SetData(data);
    target->SetNext(previous->GetNext());
    previous->SetNext(target);
    return target;
}
