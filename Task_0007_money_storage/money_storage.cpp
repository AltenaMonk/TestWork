#include <cstddef>
struct money_value
{
    int value_int;
    int value_dec;
    int value_hund;
};

void add (money_value * first, money_value * second)
{
    if (first == NULL || second == NULL)
    {
        return;
    }
    money_value.value_int = first->value_int + second->value_int;
    money_value.value_dec = first->value_dec + second->value_dec;
    money_value.value_hund = first->value_hund + second->value_hund;
}

void substruct (money_value * first, money_value * second)
{
    if (first == NULL || second == NULL)
    {
        return;
    }
    first->value_int = first->value_int - second->value_int;
    first->value_dec = first->value_dec - second->value_dec;
    first->value_hund = first->value_hund - second->value_hund;
}

void multiply (money_value * first, int * second)
{
    if (first == NULL || second == NULL)
    {
        return;
    }
    first->value_int = first->value_int * second;
    first->value_dec = first->value_dec * second;
    first->value_hund = first->value_hund * second;
}

/*void print (money_value * value)
{

}*/
