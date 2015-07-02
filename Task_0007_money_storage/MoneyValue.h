struct MoneyValue
{
public:
    /// Constructors
    MoneyValue (long m_int, long m_hund);
    MoneyValue (MoneyValue const &other);
    MoneyValue ();

    /// Operstors
    MoneyValue & operator=(MoneyValue const & other);
    MoneyValue & operator+=(MoneyValue const & other);
    MoneyValue & operator-=(MoneyValue const & x);
    MoneyValue & operator*=(long x);
    MoneyValue & operator/=(long x);
    MoneyValue & operator%=(long x);
    MoneyValue operator+(MoneyValue const & x) const;
    MoneyValue operator-(MoneyValue const & x) const;
    MoneyValue operator*(long x) const;
    MoneyValue operator/(long x) const;
    MoneyValue operator%(long x) const;

    /// Functions
    void Print() const;

private:
    long m_value;

};
