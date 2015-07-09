#ifndef MONEYVALUE_H_INCLUDE_GUARD
#define MONEYVALUE_H_INCLUDE_GUARD

#include <iostream>

namespace Library
{

struct MoneyValue
{
    friend std::ostream & operator<<(std::ostream & , MoneyValue const &);
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
    void Print() const;
    Library::String ToString() const;

private:
    long m_value;
};
std::ostream & operator<<(std::ostream & out, MoneyValue const & x);
std::istream & operator>>(std::istream & in, MoneyValue & x);

}
#endif//MONEYVALUE_H_INCLUDE_GUARD
