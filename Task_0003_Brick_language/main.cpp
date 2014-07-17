#include <iostream>
#define WORD_COUNT 30
#define WORD_LENGHT 80

int main()
{
    char text[WORD_LENGHT] = {0, };                         // массив, храняций строку
    char word_array[WORD_COUNT][WORD_LENGHT] = {0, };       // массив с разделёнными словами
    char word_brick[WORD_COUNT][WORD_LENGHT] = {0, };       // массив с кирпичными словами
    int word_index = 0, char_index = 0, brick_index = 0;
    gets(text);
    std::cout << text << std::endl;
    for (int i = 0; i < WORD_LENGHT; ++i)                   // цикл разделения строки на слова
    {
        if (text[i] == ' ' || text[i] == 0)                 // пробелами и концом строки
        {
            ++word_index;
            char_index = 0;
        }
        else
        {
            word_array[word_index][char_index] = text[i];
            ++char_index;
        }
        if (text[i] == 0)
        {
            break;
        }
    }
    word_index = 0;
    char_index = 0;
    for (int i = 0; i < WORD_LENGHT; ++i)                       // Построение кирпичного массива
    {
        if (word_array[word_index][char_index] == 0 && i > 0)
        {
            ++word_index;
            char_index = 0;
            brick_index = 0;
        }
        if    (word_array[word_index][char_index] == 'a'        // Условие уирпичного языка
            || word_array[word_index][char_index] == 'e'
            || word_array[word_index][char_index] == 'i'
            || word_array[word_index][char_index] == 'o'
            || word_array[word_index][char_index] == 'u'
            || word_array[word_index][char_index] == 'y')

        { // Распределение символов в кирпичный массив если выполняется условие для "кирпичности"
            word_brick[word_index][brick_index] = word_array[word_index][char_index];
            word_brick[word_index][brick_index+3] = word_array[word_index][char_index+1];
            word_brick[word_index][brick_index+1] = 'k';
            word_brick[word_index][brick_index+2] = word_array[word_index][char_index];
            brick_index = brick_index+3;
            ++char_index;
        }
        else
        {
            word_brick[word_index][brick_index] = word_array[word_index][char_index];
            ++char_index;
            ++brick_index;
        }
        if (word_array[word_index][0] == 0)
        {
            break;
        }
    }
    for (int i = 0, a = 0, b = 0; i < WORD_LENGHT; ++i)         // Цикл вывода кирпичного массива
    {
        if (word_brick[a][b] == 0 && b > 0)
        {
            std::cout << std::endl;
            b = 0;
            ++a;
        }
        else
        {
            std::cout << word_brick[a][b];
            ++b;
        }
        if (word_brick[a][0] == 0 && a > 0)
        {
            break;
        }
    }
    return 0;   // Чуть не забыл в этот раз...
}