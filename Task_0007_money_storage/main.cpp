#include <cstddef>
#include <money.h>

int main ()
{
    money_value price(-75, -28);
    money_value balance(0, 0);
    money_value error(6000, 0);

    int hours = 4;
    int days = 20;
    balance = balance.add(price);
    std::cout << "Add: ";
    balance.print();
    std::cout << std::endl;
    balance = balance.multiply(hours);
    std::cout << "Multiple by hour: ";
    balance.print();
    std::cout << std::endl;
    balance = balance.multiply(days);
    std::cout << "Multiple by hour: ";
    balance.print();
    std::cout << std::endl;
    balance = balance.subtract(error);
    std::cout << "adding error: ";
    balance.print();
    std::cout << std::endl;
    return 0;
}
