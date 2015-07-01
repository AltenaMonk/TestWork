#include <iostream>
#include <money.h>

void print ()
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

money_value (int _int, int _hund)
{
    value = _int * 100 + _hund;
}

money_value money_value::add(money_value &second)
{
    money_value result(value / 100, value % 100);
    result.value += second.value;
    return result;
}

money_value money_value::subtract (money_value & second)
{
    money_value result(value / 100, value % 100);
    result.value -= second.value;
    return result;
}

money_value money_value::multiply (int second)
{
    money_value result(value / 100, value % 100);
    result.value *= second;
    return result;
}
