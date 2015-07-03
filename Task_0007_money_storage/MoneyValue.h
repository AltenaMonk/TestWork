#ifndef MONEYVALUE_H_INCLUDE_GUARD
#define MONEYVALUE_H_INCLUDE_GUARD
#include <iostream>

struct MoneyValue
{
public:
    /// Constructors
    MoneyValue (long m_int, long m_hund);
    MoneyValue (MoneyValue const &other);
    MoneyValue ();

    /// Destruct
    ~MoneyValue();

    /// Operstors
    MoneyValue & operator=(MoneyValue const & x);
    MoneyValue & operator+=(MoneyValue const & x);
    MoneyValue & operator-=(MoneyValue const & x);
    MoneyValue & operator*=(long x);
    MoneyValue & operator/=(long x);
    MoneyValue & operator%=(long x);
    MoneyValue operator+(MoneyValue const & x) const;
    MoneyValue operator-(MoneyValue const & x) const;
    MoneyValue operator*(long x) const;
    MoneyValue operator/(long x) const;
    MoneyValue operator%(long x) const;
    friend std::ostream & operator<<(std::ostream & out, MoneyValue const & x);
    friend std::istream & operator>>(std::istream & in, MoneyValue & x);

    /// Functions
    void Print() const;

private:
    long m_value;
};

#endif//MONEYVALUE_H_INCLUDE_GUARD
