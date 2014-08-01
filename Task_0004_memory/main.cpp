#include <iostream>
#include <cstdio>
#include <memory.h>

#define WORD_COUNT 30
#define WORD_LENGHT 80

int main ()
{
    // Объявляем переменную для хранения начальной строки.
    char * text = new char[WORD_LENGHT];

    // Очищаем начальную строку
    memset(text, 0, WORD_LENGHT * sizeof(char));

    // Вводим начальную строку
    gets(text);

    // Объявляем массив для хранения слов
    char ** words = new char * [WORD_COUNT];
    memset(words, 0, WORD_COUNT * sizeof(char *));

    // Очищаем массив для хранения строк
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        words[i] = new char[WORD_LENGHT];
        memset(words[i], 0, WORD_LENGHT * sizeof(char));
    }

    // Разбиваем начальную строку на массив слов
    int word_index = 0, char_index = 0;
    for (int i = 0; i < WORD_LENGHT; ++i)
    {
        if (text[i] == ' ' || text[i] == 0)
        {
            ++word_index;
            char_index = 0;
        }
        else
        {
            words[word_index][char_index] = text[i];
            ++char_index;
        }
        if (text[i] == 0)
        {
            break;
        }
    }

    // Объявляем массив для хранения кирпичных слов
    char ** brick_words = new char * [WORD_COUNT];
    memset(brick_words, 0, WORD_COUNT * sizeof(char *));

    // Очищаем массив для хранения кирпичных слов
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        brick_words[i] = new char[WORD_LENGHT];
        memset(brick_words[i], 0, WORD_LENGHT * sizeof(char));
    }

    // Заполняем массив кирпичных слов из массива слов, параллельно их кирпичинизируя
    int brick_char_count = 0;
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        for (int j = 0; j < WORD_LENGHT; ++j)
        {
            if (words[i][j] == 0)
            {
                brick_char_count = 0;
                break;
            }
            else if (words[i][j] == 'a' ||
                     words[i][j] == 'e' ||
                     words[i][j] == 'i' ||
                     words[i][j] == 'o' ||
                     words[i][j] == 'u' ||
                     words[i][j] == 'y')
            {
                brick_words[i][brick_char_count+0] = words[i][j];
                brick_words[i][brick_char_count+1] = 'k';
                brick_words[i][brick_char_count+2] = words[i][j];
                brick_char_count = brick_char_count+3;
            }
            else
            {
                brick_words[i][brick_char_count] = words[i][j];
                ++brick_char_count;
            }
        }
    }

    // Выводим на экран массив кирпичных слов
    for (int i = 0; i< WORD_COUNT; ++i)
    {
        for (int k = 0; k < WORD_LENGHT; ++k)
        {
            if (brick_words[i][k] == 0)
            {
                std::cout << std::endl;
                break;
            }
            else
            {
                std::cout << brick_words[i][k];
            }
        }
    }

    // Удаляем массивы с кирпичными словами
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        delete[] brick_words[i];
    }
    delete[] brick_words;

    // Удаляем массивы с обычными словами
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        delete[] words[i];
    }
    delete[] words;

    // Удаляем начальную строку
    delete [] text;
    return  0;
}