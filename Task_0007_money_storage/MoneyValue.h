#ifndef MONEYVALUE_H_INCLUDE_GUARD
#define MONEYVALUE_H_INCLUDE_GUARD

#include <iostream>
#include <String.h>

struct MoneyValue
{
    friend std::istream & operator>>(std::istream & in, MoneyValue & x);
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

    /// Functions
    Library::String ToString () const;

private:
    long m_value;
};
std::istream & operator>>(std::istream & in, MoneyValue & x);

#endif//MONEYVALUE_H_INCLUDE_GUARD
