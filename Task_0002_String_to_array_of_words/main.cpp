#include <iostream>
#define WORD_COUNT 30
#define WORD_LENGHT 80

int main()
{
    char text[WORD_LENGHT] = {0, };                     // Массив для хранения заданной строки
    char word_array[WORD_COUNT][WORD_LENGHT] = {0, };   // Массив для хранения разделенной на слова строки
    std::cout << "Enter your string:" << std::endl;
    gets(text);
    int word_number = 0, char_index = 0;
    for (int k = 0; k < WORD_LENGHT; ++k)               // Цикл записи в массив разделённых слов
    {
        if (text[k] == ' ' && k > 0)                    // Условие разделения на слова
        {
            ++word_number;
            char_index = 0;
        }
        else
        {
            word_array[word_number][char_index] = text[k];
            ++char_index;
         }
        if (text[k] == 0)
        {
            break;
        }
    }
    word_number = 0;
    char_index = 0;
    std::cout << "array of words [word_number][char_index]:" << std::endl;
    for (int k = 0; k < WORD_LENGHT; ++k)               // Цикл вывода двумерного массива по словам
    {
        if (word_array[word_number][char_index] == 0 && char_index > 0) //каждое слово с новой строки
        {
            std::cout << std::endl;
            ++word_number;
            char_index = 0;
        }
        if (word_array[word_number][0] == 0 && word_number > 0)     // Условие выхода из цикла, если встретится нулевое слово
        {
            break;
        }
        std::cout << word_array[word_number][char_index];
        ++char_index;
    }
    return 0;
}