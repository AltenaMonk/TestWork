#include "MoneyValue.h"
#include <iostream>

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
        out << x.m_value / 100 << "." << x.m_value % 100 << std::endl;
    }
    if ( (x.m_value > -100) && (x.m_value < -10))
    {
        out << "-" << x.m_value / 100 << "." <<(-1) * (x.m_value % 100) << std::endl;
    }
    if ((x.m_value > -10) && (x.m_value < 0))
    {
        out << "-0.0" << (-1) * (x.m_value % 100) << std::endl;
    }
    if ((x.m_value < 10) && (x.m_value > 0))
    {
        out << "0.0" << x.m_value % 100 << std::endl;
    }
    if ((x.m_value >= 0) && (x.m_value < 10) && (x.m_value % 10 == 0))
    {
        out << x.m_value / 100 << "." << x.m_value % 100 << "0" << std::endl;
    }
    if (x.m_value < -100)
    {
        out << x.m_value / 100 << "." << (-1) * (x.m_value % 100) << std::endl;
    }
}

MoneyValue MoneyValue::operator>>(std::istream & in, MoneyValue & x)
{

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
