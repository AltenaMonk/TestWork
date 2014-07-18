#include <iostream>
#include <cstdio>
#include <memory.h>
#define WORD_COUNT 30
#define WORD_LENGHT 80

int main ()
{
    char * text = new char[WORD_LENGHT];
    memset(text, 0, WORD_LENGHT *sizeof(char));
    char ** word_array = new char * [WORD_COUNT];
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        word_array[i] = new char[WORD_LENGHT];
        memset(word_array[i], 0, WORD_LENGHT * sizeof(char));
    }
    char ** word_brick = new char * [WORD_COUNT];
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        word_brick[i] = new char[WORD_LENGHT];
        memset(word_brick[i], 0, WORD_LENGHT * sizeof(char));
    }
    int * word_index = new int(0);
    int * char_index = new int(0);
    gets(text);
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        for (int j = 0; j < WORD_LENGHT; ++j)
        {
            std::cout << word_array[i][j];
        }
        std::cout << std::endl;
    }
    /*for (int i = 0; i < WORD_LENGHT; ++i)
    {
        if (text[i] == ' ' || text[i] == 0)
        {
            ++*word_index;
            *char_index = 0;
        }
        else
        {
            word_array[*word_index][*char_index] = text[i];
            ++*char_index;
        }
        if (text[i] == 0)
        {
            break;
            delete word_index;
            delete char_index;
        }
    }
    delete word_index;
    delete char_index;
    int * a = new int(0);
    int * b = new int(0);
    for (int i = 0; i < WORD_LENGHT; ++i)
    {
        if (word_array[*a][*b] == 0)
        {
            std::cout << std::endl;
            ++*a;
            *b = 0;
        }
        else
        {
            std::cout << word_array[*a][*b];
        }
    }*/
    for (int i = 0; i < WORD_COUNT; ++i)
    {
        delete []word_array[i];
    }
    delete []word_array;
    for (int i = 0; WORD_COUNT; ++i)
    {
        delete []word_brick[i];
    }
    delete[] word_brick;
    delete[] text;
    delete word_index;
    delete char_index;
    return 0;
}