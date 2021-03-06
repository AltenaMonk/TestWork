#ifndef LISTNODE_H
#define LISTNODE_H


class ListNode
{
public:
    /// Constructors
    ListNode ();
    ListNode (ListNode const & from);

    /// Operator =
    ListNode & operator=(ListNode const & x);

    /// Function Swap
    void Swap(ListNode & other);

    /// Destructor
    ~ListNode();

    /// Functions
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
