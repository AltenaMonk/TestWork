#include <iostream>
#define HEIGHT 30   // Число строк
#define WIDTH 80    // Длина строки

int main()
{
    char text[HEIGHT][WIDTH] = {0, };               // Массив для хранения текста
    std::cout << "Enter your text:" <<std::endl;
    for (int i = 0; i < HEIGHT; ++i)                // Ввод текста
    {
        gets(text[i]);
        if (text[i][0] == 0)                        // Прекращение ввода если строка пуста
        {
            break;
        }
    }
    std::cout << "Your text:" <<std::endl;
    for (int i = 0; i < HEIGHT; ++i)                // Вывод текста
    {
        std::cout << text[i] << std::endl;
        if (text[i][0] == 0)                        // Прекратить вывод, если встретилась пустая строка.
        {
            break;
        }
    }
}