#include "MoneyValue.h"
#include <iostream>

namespace Library
{
/// Constructors
MoneyValue::MoneyValue(long m_int, long m_hund)
{
    m_value = m_int * 100 + m_hund;
}

MoneyValue::MoneyValue(MoneyValue const & other)
{
    m_value = other.m_value;
}

MoneyValue::MoneyValue()
{
    m_value = 0;
}

/// Destruct
MoneyValue::~MoneyValue()
{
}


/// Operators
MoneyValue & MoneyValue::operator=(MoneyValue const &other)
{
    m_value = other.m_value;
    return * this;
}

MoneyValue &MoneyValue::operator+=(MoneyValue const &other)
{
    m_value += other.m_value;
    return * this;
}

MoneyValue &MoneyValue::operator-=(MoneyValue const &other)
{
    m_value -= other.m_value;
    return * this;
}

MoneyValue &MoneyValue::operator*=(long other)
{
    m_value *= other;
    return * this;
}

MoneyValue &MoneyValue::operator/=(long other)
{
    m_value /= other;
    return * this;
}

MoneyValue &MoneyValue::operator%=(long other)
{
    m_value %= other;
    return * this;
}

MoneyValue MoneyValue::operator+(MoneyValue const &other) const
{
    MoneyValue result(* this);
    result += other;
    return result;
}

MoneyValue MoneyValue::operator-(MoneyValue const &other) const
{
    MoneyValue result(* this);
    result -= other;
    return result;
}

MoneyValue MoneyValue::operator*(long other) const
{
    MoneyValue result(* this);
    result *= other;
    return result;
}

MoneyValue MoneyValue::operator/(long other) const
{
    MoneyValue result(* this);
    result /= other;
    return result;
}

MoneyValue MoneyValue::operator%(long other) const
{
    MoneyValue result(* this);
    result %= other;
    return result;
}

std::ostream & operator<<(std::ostream & out, MoneyValue const & x)
{
    if (x.m_value >= 10)
    {
        out << x.m_value / 100 << "." << x.m_value % 100;
    }
    if ( (x.m_value > -100) && (x.m_value < -10))
    {
        out << "-" << x.m_value / 100 << "." <<(-1) * (x.m_value % 100);
    }
    if ((x.m_value > -10) && (x.m_value < 0))
    {
        out << "-0.0" << (-1) * (x.m_value % 100);
    }
    if ((x.m_value < 10) && (x.m_value > 0))
    {
        out << "0.0" << x.m_value % 100;
    }
    if ((x.m_value >= 0) && (x.m_value < 10) && (x.m_value % 10 == 0))
    {
        out << x.m_value / 100 << "." << x.m_value % 100 << "0";
    }
    if (x.m_value < -100)
    {
        out << x.m_value / 100 << "." << (-1) * (x.m_value % 100);
    }

}

std::istream & operator>>(std::istream & in, MoneyValue & x)
{
    x.m_value = 0;
    char c = 0;
    c = in.get();
    if (с == '0')
    {
    }
    else if (c >= '1' && c <= '9')
    {
        do
        {
            x.m_value = x.m_value * 10 + (c - '0');
            c = in.get();
        }
        while (с >= '0' && c <= '9');
        in.unget();
    }
    if (c == '.')
    {
        c = in.get();
        if (с >= '0' && c <= '9')
        {
            x.m_value = x.m_value * 10 + (c - '0');
            c = in.get();
        }
        if (с >= '0' && c <= '9')
        {
            x.m_value = x.m_value * 10 + (c - '0');
            c = in.get();
        }
        x.m_value = x.m_value / 100;
    }
    else
    {
        in.unget();
    }
    return in;
}

/// Functions
void MoneyValue::Print() const
{
    if (m_value >= 10)
    {
        std::cout << m_value / 100 << "." << m_value % 100 << std::endl;
    }
    if ( (m_value > -100) && (m_value < -10))
    {
        std::cout << "-" << m_value / 100 << "." <<(-1) * (m_value % 100) << std::endl;
    }
    if ((m_value > -10) && (m_value < 0))
    {
        std::cout << "-0.0" << (-1) * (m_value % 100) << std::endl;
    }
    if ((m_value < 10) && (m_value > 0))
    {
        std::cout << "0.0" << m_value % 100 << std::endl;
    }
    if ((m_value >= 0) && (m_value < 10) && (m_value % 10 == 0))
    {
        std::cout << m_value / 100 << "." << m_value % 100 << "0" << std::endl;
    }
    if (m_value < -100)
    {
        std::cout << m_value / 100 << "." << (-1) * (m_value % 100) << std::endl;
    }
}
}