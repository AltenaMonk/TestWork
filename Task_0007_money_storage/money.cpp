#include "money.h"
#include <iostream>

money_value::money_value(int _int, int _hund)
{
    value = _int * 100 + _hund;
}

money_value::money_value(money_value const &other)
{
    value = other.value;
}

money_value::money_value()
{
    value = 0;
}

void money_value::print() const
{
    if (value >= 10)
    {
        std::cout << value / 100 << "." << value % 100 << std::endl;
    }
    if ( (value > -100) && (value < -10))
    {
        std::cout << "-" << value / 100 << "." <<(-1) * (value % 100) << std::endl;
    }
    if ((value > -10) && (value < 0))
    {
        std::cout << "-0.0" << (-1) * (value % 100) << std::endl;
    }
    if ((value < 10) && (value > 0))
    {
        std::cout << "0.0" << value % 100 << std::endl;
    }
    if ((value >= 0) && (value < 10) && (value % 10 == 0))
    {
        std::cout << value / 100 << "." << value % 100 << "0" << std::endl;
    }
    if (value < -100)
    {
        std::cout << value / 100 << "." << (-1) * (value % 100) << std::endl;
    }
}

money_value & money_value::operator = (money_value const &other)
{
    value = other.value;
    return *this;
}

money_value &money_value::operator += (money_value const &other)
{
    value += other.value;
    return *this;
}

money_value &money_value::operator -= (money_value const &other)
{
    value -= other.value;
    return *this;
}

money_value &money_value::operator *= (int other)
{
    value *= other;
    return *this;
}

money_value &money_value::operator /= (int other)
{
    value /= other;
    return *this;
}

money_value &money_value::operator %= (int other)
{
    value %= other;
    return *this;
}

money_value money_value::operator + (money_value const &other) const
{
    money_value result(*this);
    result += other;
    return result;
}

money_value money_value::operator - (money_value const &other) const
{
    money_value result(*this);
    result -= other;
    return result;
}

money_value money_value::operator * (int other) const
{
    money_value result(*this);
    result *= other;
    return result;
}

money_value money_value::operator / (int other) const
{
    money_value result(*this);
    result /= other;
    return result;
}

money_value money_value::operator % (int other) const
{
    money_value result(*this);
    result %= other;
    return result;
}
