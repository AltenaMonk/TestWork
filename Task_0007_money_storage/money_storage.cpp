#include <cstddef>

#include <iostream>

struct money_value
{
    int value;
};

money_value add (money_value first, money_value second)
{
    first.value = first.value + second.value;
    return first;
}

money_value subtract (money_value first, money_value second)
{
    first.value = first.value - second.value;
    return first;
}

money_value multiply (money_value first, int second)
{
    first.value = first.value * second;
    return first;
}

void print (money_value value)
{
    std::cout << value.value / 100 << std::endl;
}

int main(int, char *[])
{
    money_value price  = {-75};
    money_value balance = {0};
    money_value error = {6000};
    std::cout << "Add: ";
    add(balance, price);
    print(balance);
    std::cout << std::endl;
    int hour = 4;
    std::cout << "Multiply by hours: ";
    multiply(balance, hour);
    print(balance);
    std::cout << std::endl;
    int days = 20;
    std::cout << "Multiply by days: ";
    multiply(balance, days);
    print(balance);
    std::cout << std::endl;
    std::cout << "Subtract by error: ";
    subtract(balance, error);
    print(balance);
    std::cout << std::endl;
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
