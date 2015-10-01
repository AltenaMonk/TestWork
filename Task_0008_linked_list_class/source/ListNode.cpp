#include "ListNode.h"
#include <cstddef>
#include <utility>


/// Constructor
ListNode::ListNode()
    : m_data(0)
    , m_next(NULL)
{
}

ListNode::ListNode(ListNode const & from)
    : m_data(from.m_data)
    , m_next( m_next == NULL ? NULL : new ListNode(*from.m_next))
{

}

/// Operator =
ListNode & ListNode::operator=(ListNode const & from)
{
    ListNode x(from);
    Swap(x);
    return *this;
}

/// Function Swap
void ListNode::Swap(ListNode &other)
{
    std::swap(m_data, other.m_data);
    std::swap(m_next, other.m_next);
}


/// Destructor
ListNode::~ListNode()
{
    if (m_next != NULL)
    {
        delete m_next;
    }
}

/// Functions
void ListNode::SetNext(ListNode * next)
{
    m_next = next;
}

ListNode * ListNode::GetNext()
{
    return m_next;
}

ListNode const * ListNode::GetNext() const
{
    return m_next;
}

void ListNode::SetData(int data)
{
    m_data = data;
}

int ListNode::GetData() const
{
    return m_data;
}
