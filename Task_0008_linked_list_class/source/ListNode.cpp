#include "ListNode.h"

ListNode::ListNode()
{
}
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
int ListNode::GetData()
{
    return m_data;
}
void ListNode::SetData(int data)
{
    m_data = data;
}
