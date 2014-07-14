#include <iostream>
#include <cstdio>
#define LEN 80 //длина строки

int main()
{
    std::cout << "Your line:";
    char text[LEN] = {0, };
    gets(text);
    std::cout << "line out:" << text << std::endl;
    int space_index = 0;
    for (int i = 0; i <= LEN; ++i)
    {
        if (text[i] == ' ')
        {
            for (int k = space_index; k <= i; ++k)
            {
                std::cout << text[k];
                space_index = k;
            }
             std::cout <<""<< std::endl;
        }
    }
    return 0;
}