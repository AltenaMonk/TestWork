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
            // Проверяем, хватает ли выделенной длины соответствуещего слова.
            // Если не хватает - удваиваем
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
    // Контрольный вывод массива обычных слов
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

    // Создаём массив для кирпичных слов
    char ** brick_words = new char * [WORD_COUNT];
    memset(brick_words, 0, WORD_COUNT * sizeof(char *));

    // Создаём массив для хранения значений длины кирпичных слов
    int * brick_word_size = new int[WORD_COUNT];
    memset(brick_word_size, 0, WORD_COUNT * sizeof(int));
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        brick_word_size[i] = 1;
        brick_words[i] = new char[brick_word_size[i]];
        memset(brick_words[i], 0, brick_word_size[i] * sizeof(char));
    }

    // Заполняем кирпичный массив окирпиченными словами
    int brick_char_index = 0;
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        for (int j = 0; j < STRING_LENGHT; ++j)
        {
            // Проверяем, хватает ли выделенной длины соответствуещего кирпичного слова.
            // Если не хватает - удваиваем
            if (j - brick_word_size[i] - brick_char_index == 0)
            {
                int new_brick_size = brick_word_size[i] * 2;
                char * brick_temp = new char[new_brick_size];
                memset(brick_temp, 0, new_brick_size * sizeof(char));
                for (int k = 0; k < brick_word_size[i]; ++k)
                {
                    brick_temp[k] = brick_words[i][k];
                }
                brick_word_size[i] = new_brick_size;
                delete [] brick_words[i];
                brick_words[i] = brick_temp;
            }
            if (words[i][j] == 0)
            {
                brick_char_index = 0;
                break;
            }
            else if (words[i][j] == 'a' ||
                     words[i][j] == 'e' ||
                     words[i][j] == 'i' ||
                     words[i][j] == 'o' ||
                     words[i][j] == 'u' ||
                     words[i][j] == 'y')
            {
                brick_words[i][brick_char_index+0] = words[i][j];
                brick_words[i][brick_char_index+1] = 'k';
                brick_words[i][brick_char_index+2] = words[i][j];
                brick_char_index = brick_char_index+3;
            }
            else
            {
                brick_words[i][brick_char_index] = words[i][j];
                ++brick_char_index;
            }
        }
        if (words[i][0] == 0)
        {
            break;
        }
    }

    // Вывод кирпичного массива
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        for (int k = 0; k < STRING_LENGHT; ++k)
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
        if (brick_words[i][0] == 0)
        {
            break;
        }
    }

    // Удаляем массив кирпичных слов
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        delete [] brick_words[i];
    }
    delete [] brick_words;

    // Удаляем массив обычных слов
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        delete [] words[i];
    }
    delete [] words;

    // Удаляем массив длин кирпичных слов
    delete [] brick_word_size;

    // Удаляем массив длин обычных слов
    delete [] word_size;

    // Чистим начальную строку
    delete [] text;
    return 0;
}
