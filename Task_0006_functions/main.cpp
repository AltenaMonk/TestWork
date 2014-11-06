#include <iostream>
#include <memory.h>
#include <cstdio>

int string_lenght (char * string)
{
    int i = 0;
    for (i = 0; string[i] != 0; ++i)
    {
        ;
    }
    return i + 1;
}

int word_counter (char * string)
{
    int counter = 0;
    for (int i = 0; i < string_lenght(string); ++i)
    {
        if (string[i] == ' ' || string[i] == 0)
        {
            ++counter;
        }
    }
    return counter;
}

int print_string (char * string)
{
    for (int i = 0; i < string_lenght(string); ++i)
    {
        if (string[i] == 0)
        {
            break;
        }
        else
        {
            std::cout << string[i];
        }
    }
}

int resize_string (char * origin_string, char * new_string)
{
    for (int i = 0; string_lenght(new_string) < string_lenght(origin_string); ++i)
    {
        char * temp = new char[string_lenght(new_string) * 2];
        delete [] new_string;
        new_string = temp;
    }
    return 0;
}

int string_copy (char * origin_string, char * copied_string)
{
    resize_string(origin_string, copied_string);
    for (int i = 0; origin_string != 0; ++i)
    {
        copied_string[i] = origin_string[i];
    }
    return 0;
}

/*int string_bricking (char * string)
{
    for (int i = 0; i < string_lenght(string); ++i)
    {
        if (string[i] == 'a' ||
            string[i] == 'e' ||
            string[i] == 'i' ||
            string[i] == 'o' ||
            string[i] == 'u' ||
            string[i] == 'y')
        {
            int brick_index = i;
            char * brick_string = new char[string_lenght(string)];
            memset(brick_string, 0, string_lenght(brick_string) * sizeof(char));
            for (int j = 0; j < string_lenght(string); ++j)
            {
                brick_string[j] = string[j+1];
            }
        }
    }
    return 0;
}
/*
int print_string (char * string)
{

}
*/
int main()
{
    char * text = new char[1024];
    memset(text, 0, 1024 * sizeof(char));
    gets(text);
    char * test_string = new char[10];
    memset(test_string, 0, string_lenght(test_string));
    std::cout << "Длина строки (исходная, тестовая)" << string_lenght(text) << ", " << string_lenght(test_string) << std::endl;
    std::cout << "Количество слов:" << word_counter(text) << std::endl;
    std::cout << "Исходная строка:" << std::endl;
    std::cout << print_string(text) << std::endl;
    string_copy(text,test_string);
    std::cout << print_string(test_string) << std::endl;

    return 0;
}

