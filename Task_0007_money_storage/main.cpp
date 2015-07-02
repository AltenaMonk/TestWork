#include <iostream>
#include "MoneyValue.h"

int main ()
{
    MoneyValue price(-75, -28);
    MoneyValue balance(0, 0);
    MoneyValue error(6000, 0);

    int hours = 4;
    int days = 20;
    balance = balance + price;
    std::cout << "Add: ";
    balance.Print();
    std::cout << std::endl;
    balance *= hours;
    std::cout << "Multiple by hour: ";
    balance.Print();
    std::cout << std::endl;
    balance *= days;
    std::cout << "Multiple by hour: ";
    balance.Print();
    std::cout << std::endl;
    balance -= error;
    std::cout << "adding error: ";
    balance.Print();
    std::cout << std::endl;
    return 0;
}
