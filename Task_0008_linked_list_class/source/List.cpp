#include "List.h"
#include <cstddef>
#include <utility>

/// Constructors
List::List()
    :m_head(0)
{
}

List::List(List const &from)
    :m_head(from.m_head)
{
}

/// Operator =
List & List::operator=(List const & from)
{
    m_head = from.m_head;
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
