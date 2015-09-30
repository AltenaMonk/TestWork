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
    , m_next(from.m_next)
{
}

/// Operator =
ListNode & ListNode::operator=(ListNode const & from)
{
    m_data = from.m_data;
    m_next = from.m_next;
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

int ListNode::GetData()
{
    return m_data;
}
