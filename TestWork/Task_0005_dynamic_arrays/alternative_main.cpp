#include <iostream>
#include <cstdio>
#include <memory.h>

#define WORD_LENGHT 1024

int main ()
{
    // Объявляем переменную для хранения начальной строки.
    char * text = new char[WORD_LENGHT];

    // Очищаем начальную строку
    memset(text, 0, WORD_LENGHT * sizeof(char));

    // Вводим начальную строку
    gets(text);
    
    // Считаем сколько слов (= количество строк в новом массиве, хранящем слова) получилось
    int string_count = 0;
    for (int i = 0; i < WORD_LENGHT; ++i)
    {
        if (text[i] == ' ' || text[i] == 0)
        {
            ++string_count;
        }
        if (text[i] == 0)
        {
            break;
        }
    }

    // Объявляем массив для хранения слов
    char ** words = new char * [string_count];
    memset(words, 0, string_count * sizeof(char *));

    // Очищаем массив для хранения строк
    int space_index = 0;
    
    int word_size = new int * [string_count];
    memset(word_size, 0, string_count);
    
    for (int i = 0; i < string_count; ++i)
    {
        for (int j = space_index; j < WORD_LENGHT; ++j)
        {
            if (text[j] == ' ' || text[j] == 0)
            {
                words[i] = new char[j-space_index];
                memset(words[i], 0, j-space_index * sizeof(char));
                space_index = j;
                word_size[i] = j-space_index;
                break;
            }
        }
    }

    // Разбиваем начальную строку на массив слов
    space_index = 0;
    for (int i = 0; i < string_count; ++i)
    {
        for (int j = space_index; j < word_size[i]; ++j)
        {
            if (text[j] == ' ' || text[i] == 0)
            {
                break;
            }
            else
            {
                words[i][j] = text[j];
            }
        }
    }

    // Объявляем массив для хранения кирпичных слов
    char ** brick_words = new char * [string_count];
    memset(brick_words, 0, string_count * sizeof(char *));
    
    int brick_word_size = new int * [string_count];
    memset(brick_word_size, 0, string_count);
    
    for (int i = 0; i < string_count; ++i)  
    {
        for (int j = 0; j < word_size[i]; ++j)
        {
            if (words[i][j] == 'a' ||
                words[i][j] == 'e' ||
                words[i][j] == 'i' ||
                words[i][j] == 'o' ||
                words[i][j] == 'u' ||
                words[i][j] == 'y')
            {
                    brick_word_size[i] = brick_word_size[i]+3;
            }
            else
            {
                ++brick_word_size[i];
            }
            if (words[i][j] == 0)
            {
                break;
            }
        }
    }
    // Очищаем массив для хранения кирпичных слов
    for (int i = 0; i < string_count; ++i)
    {
        brick_words[i] = new char[brick_word_size[i]];
        memset(brick_words[i], 0, brick_word_size[i] * sizeof(char));
    }

    // Заполняем массив кирпичных слов из массива слов, параллельно их кирпичинизируя
    int brick_char_count = 0;
    for (int i = 0; i < string_count; ++i)
    {
        for (int j = 0; j < brick_word_size[i]; ++j)
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
    for (int i = 0; i < brick_word_size[i]; ++i)
    {
        delete[] brick_words[i];
    }
    delete[] brick_words;

    // Удаляем массивы с обычными словами
    for (int i = 0; i < word_size[i]; ++i)
    {
        delete[] words[i];
    }
    delete[] words;

    // Удаляем начальную строку
    delete [] text;
    
    // Удаляем массив с длинами кирпичных слов
    delete [] brick_word_size;
    
    //  Удаляем массив с длинами обычных слов
    delete [] word_size;
    return  0;
}