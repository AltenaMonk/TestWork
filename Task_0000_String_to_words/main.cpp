#include <iostream>
#include <cstdio>

int main()
{
    std::cout << "Enter your line:";
    char text[80] = {0, };
    gets(text);
    std::cout << "line out:" << text << std::endl;
    return 0;
}