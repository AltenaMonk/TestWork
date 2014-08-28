#include <iostream>
#include <memory.h>
#include <cstdio>

#define STRING_LENGHT 1024
#define WORD_COUNT 30

int main()
{
    // Массив для хранения начальной строки
    char * text = new char[STRING_LENGHT];
    memset(text, 0, STRING_LENGHT * sizeof(char));

    // Получаем начальную строку
    gets(text);

    // Массив для хранения обычных слов
    char ** words = new char * [WORD_COUNT];
    memset(words, 0, WORD_COUNT * sizeof(char *));

    // Массив для хранения значений длины обычных слов
    int * word_size = new int[WORD_COUNT];
    memset(word_size, 0, WORD_COUNT * sizeof(int));
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        word_size[i] = 1;
        words[i] = new char[word_size[i]];
        memset(words[i], 0, word_size[i] * sizeof(char));
    }

    /* Контрольный вывод пустого массива для слов
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        for (int j = 0; j < word_size[i]+1; ++j)
        {
            if (words[i][j] == 0)
            {
                std::cout << "0";
            }
            else
            {
                std::cout << words[i][j];
            }
        }
        std::cout << std::endl;
    }*/

    // Разбиваем начальную строку на слова
    int space_index = 0, word_index = 0, char_index = 0;
    for (int i = 0; i < STRING_LENGHT; ++i)
    {
        if (text[i] == ' ' || text[i] == 0)
        {
            ++word_index;
            char_index = 0;
            space_index = i;
        }
        else
        {
            if ((i - space_index - word_size[word_index]) == 0)
            {
                int new_size = word_size[word_index] * 2;
                char * temp = new char[new_size];
                memset(temp, 0, new_size * sizeof(char));
                for (int k = 0; k < word_size[word_index]; ++k)
                {
                    temp[k] = words[word_index][k];
                }
                word_size[word_index] = new_size;
                delete [] words[word_index];
                words[word_index] = temp;
            }
            words[word_index][char_index] = text[i];
            ++char_index;
        }
        if (text[i] == 0)
        {
            break;
        }
    }
    // Контрольный вывод пустого массива для слов
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        for (int j = 0; j < word_size[i]; ++j)
        {
            if (words[i][j] == 0)
            {
                break;
            }
            else
            {
                std::cout << words[i][j];
            }
        }
        std::cout << std::endl;
        if (words[i][0] == 0)
        {
            break;
        }
    }
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        memset(words[i], 0, word_size[i] * sizeof(char));
        delete [] words[i];
    }
    delete [] words;
    delete [] word_size;
    delete [] text;
    return 0;
}
