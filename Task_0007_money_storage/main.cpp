#include <cstddef>
#include <money.h>
#include <iostream>

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
    return 0;
}
