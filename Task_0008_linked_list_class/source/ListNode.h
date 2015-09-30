#ifndef LISTNODE_H
#define LISTNODE_H


class ListNode
{
public:
    /// Constructors
    ListNode ();
    ListNode (ListNode const &from);

    /// Destructor
    ~ListNode();

    /// Methods
    void SetNext(ListNode * next);
    ListNode * GetNext();
    ListNode const * GetNext() const;
    void SetData(int data);
    int GetData() const;

    /// Operators
    ListNode & operator=(ListNode const & x);

    /// Functions
    void Swap(ListNode & other);

private:
    int m_data;
    ListNode * m_next;
};

#endif // LISTNODE_H
