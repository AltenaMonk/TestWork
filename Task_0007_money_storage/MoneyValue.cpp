#include "MoneyValue.h"
#include <iostream>
#include <String.h>
#include <sstream>
#include "cstring"
#include <string>


///Friends
std::istream & operator>>(std::istream & in, MoneyValue & x)
{
    x.m_value = 0;
    char c = 0;
    c = in.get();
    bool isMinus = false;

    /// Проверка знака числа
    if (c == '-' || c == '+')
    {
        isMinus = c == '-';
        c = in.get();
        if (c <= '0' || c >= '9')
        {
            in.unget();
            in.unget();
            return in;
        }
    }

    /// Получаем и записываем цифры, из которых состоит получаемое число
    /// Проверка, не начинается ли число с 0
    if (c == '0')
    {
        c = in.get();
    }
    else
    {
        if (c >= '1' && c <= '9')
        {
            do
            {
                x.m_value = x.m_value * 10 + (c - '0');
                c = in.get();
            }
            while (c >= '0' && c <= '9');
        }
    }
    x.m_value = x.m_value * 100;

    /// Получаем дробную часть числа (если она есть)
    if (c == '.')
    {
        c = in.get();
        if (c >= '0' && c <= '9')
        {
            x.m_value += 10 * (c - '0');
            c = in.get();
        }
        if (c >= '0' && c <= '9')
        {
            x.m_value += c - '0';
            c = in.get();
        }
    }
    in.unget();

    /// Применяем признак отрицательности числа к конецному результату
    if (isMinus == true)
    {
        x.m_value = - x.m_value;
    }

    /// Возвращаем поток
    return in;
}

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


Library::String MoneyValue::ToString() const
{
    std::stringstream str;
    if (m_value >= 10)
    {
        str << (m_value / 100) << "." << (m_value % 100) << "0";
    }
    if ((m_value > -100) && (m_value < -10))
    {
        str << "-" << m_value / 100 << "." <<(-1) * (m_value % 100);
    }
    if ((m_value > -10) && (m_value < 0))
    {
        str << "-0.0" << (-1) * (m_value % 100);
    }
    if ((m_value < 10) && (m_value > 0))
    {
        str << "0.0" << m_value % 100;
    }
    if ((m_value >= 0) && (m_value < 10) && (m_value % 10 == 0))
    {
        str << m_value / 100 << "." << m_value % 100 << "0";
    }
    if (m_value < -100)
    {
        str << m_value / 100 << "." << (-1) * (m_value % 100);
    }
    return str.str().c_str();
}
