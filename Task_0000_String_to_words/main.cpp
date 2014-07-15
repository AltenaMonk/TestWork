#include <iostream>
#include <cstdio>
#define LEN 80 //Длина строки

int main()
{
    std::cout << "Your line:";
    char text[LEN] = {0,  };        // Массив символов, который будет хранить строку
    gets(text);                     // Читаем строку
    std::cout << "line out:" << text << std::endl;
    int space_index = 0;            // Хранит индекс символа, который находим далее как разделитель
    for (int i = 0; i < LEN; ++i)   
    {
        if (text[i] == ' ' || text[i] == 0) 
        {
            for (int k = space_index; k < i; ++k)   // Выводим слово
            {
                std::cout << text[k];
            }
        space_index = i+1;                          // Убираем пробел в начале вывода слова
        std::cout << std::endl;
        }
        if (text[i] == 0)
        {
            break;
        }
    }
    return 0;
}