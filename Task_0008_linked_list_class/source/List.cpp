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

/*void List::Insert(int pos, int data)
{
    if (m_head == NULL || pos - GetLength() > 1)
    {
        return NULL;
    }
    ListNode * previous  = new ListNode();
}*/
