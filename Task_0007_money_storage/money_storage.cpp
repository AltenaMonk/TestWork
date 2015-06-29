#include <cstddef>

#include <iostream>

struct money_value
{
private:

    int value;

public:
    money_value (int _int, int _hund)
    {
        value = _int * 100 + _hund;
    }

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

    money_value add (money_value &second)
    {
        money_value result(value / 100, value % 100);
        result.value += second.value;
        return result;
    }

    money_value subtract (money_value & second)
    {
        money_value result(value / 100, value % 100);
        result.value -= second.value;
        return result;
    }

    money_value multiply (int second)
    {
        money_value result(value / 100, value % 100);
        result.value *= second;
        return result;
    }

};


int main(int, char *[])
{
    money_value price(-75, -28);
    money_value balance(0, 0);
    money_value error(6000, 0);
    std::cout << "Add: ";
    balance = balance.add(price);
    balance.print();
    std::cout << std::endl;
    int hour = 4;
    std::cout << "Multiply by hours: ";
    balance = balance.multiply(hour);
    balance.print();
    std::cout << std::endl;
    int days = 20;
    std::cout << "Multiply by days: ";
    balance = balance.multiply(days);
    balance.print();
    std::cout << std::endl;
    std::cout << "Subtract by error: ";
    balance = balance.subtract(error);
    balance.print();
    /*std::cout << std::endl;
    print({1050 });
    std::cout << std::endl;
    print({1015 });
    std::cout << std::endl;
    print({150  });
    std::cout << std::endl;
    print({115  });
    std::cout << std::endl;
    print({50   });
    std::cout << std::endl;
    print({15   });
    std::cout << std::endl;
    print({5    });
    std::cout << std::endl;
    print({0    });
    std::cout << std::endl;
    print({-5   });
    std::cout << std::endl;
    print({-15  });
    std::cout << std::endl;
    print({-50  });
    std::cout << std::endl;
    print({-115 });
    std::cout << std::endl;
    print({-150 });
    std::cout << std::endl;
    print({-1015});
    std::cout << std::endl;
    print({-1050});
    std::cout << std::endl;*/
    return 0;
}

/*void normalize (money_value * value)
{
    if (value == NULL)
    {
        return;
    }
    if (value->value_hund < 0)
    {
        value->value_hund += 100;
        --value->value_int;
    }
    value->value_int += value->value_hund / 100;
    value->value_hund = value->value_hund % 100;
}

bool less ()
{
    
}

void add (money_value * first, money_value * second)
{
    if (first == NULL || second == NULL)
    {
        return;
    }
    int sign = 0;
    if (first->value_sign == second->value_sign)
    {
        sign = first->value_sign;
    }
    else
    {

    }
    first->value_hund = first->value_hund + second->value_hund;
    first->value_int =  first->value_int + second->value_int;
    if (first->value_int < 0) {
        first->value_int *= -1;
        first->value_sign = -1;
    }
    first->value_sign = sign;
    normalize(first);
}

void substruct (money_value * first, money_value * second)
{
    if (first == NULL || second == NULL)
    {
        return;
    }
    first->value_int = (first->value_sign * first->value_int) - (second->value_sign * second->value_int);
    first->value_hund = (first->value_sign * first->value_hund) - (second->value_sign * second->value_hund);
    if (first->value_int < 0) {
        first->value_int *= -1;
        first->value_sign = -1;
    }
    if (first->value_hund < 0) {
        first->value_hund *= -1;
    }
    normalize(first);
}

void multiply (money_value * first, int * second)
{
    if (first == NULL || second == NULL)
    {
        return;
    }
    if (second < 0 && first->value_sign < 0)
    {
        first->value_sign = 1;
    }
    if (second > 0 && first->value_sign > 0)
    {
        first->value_sign = 1;
    }
    else
    {
        first->value_sign = -1;
    }
    first->value_int = first->value_int * *second;
    first->value_hund = first->value_hund * *second;
    normalize(first);
}

void print (money_value * value)
{
    std::cout << value->value_sign * value->value_int << "." << value->value_hund << std::endl;
}


*/
