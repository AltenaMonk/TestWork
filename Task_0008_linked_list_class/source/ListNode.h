#ifndef LISTNODE_H
#define LISTNODE_H


class ListNode
{
public:
    void SetNext(ListNode * next);
    ListNode * GetNext();
    ListNode const * GetNext() const;
    void SetData(int data);
    int GetData() const;
private:
    int m_data;
    ListNode * m_next;
};

#endif // LISTNODE_H
