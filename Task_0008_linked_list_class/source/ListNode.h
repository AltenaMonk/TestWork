#ifndef LISTNODE_H
#define LISTNODE_H


class ListNode
{
public:
    void SetNext(ListNode * next);
    ListNode * GetNext();
    ListNode const * GetNext() const;
    int GetData() const;
    void SetData(int data);
private:
    int m_data;
    ListNode * m_next;
};

#endif // LISTNODE_H
