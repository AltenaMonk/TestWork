#include <iostream>
#define WORD_COUNT 30
#define WORD_LENGHT 80

int main()
{
    char text[WORD_LENGHT] = {0, };
    char word_array[WORD_COUNT][WORD_LENGHT] = {0, };
    int word_index = 0, char_index = 0;
    gets(text);
    std::cout << text << std::endl;
    for (int i = 0; i < WORD_LENGHT; ++i)
    {
        if (text[i] == ' ' || text[i] == 0)
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
    for (int i = 0; i < WORD_LENGHT; ++i)
    {
        if (word_array[word_index][char_index] == 0 && i > 0)
        {
            std::cout << std::endl;
            ++word_index;
            char_index = 0;
        }
        if (word_array[word_index][char_index] == 'a'
            || word_array[word_index][char_index] == 'e'
            || word_array[word_index][char_index] == 'i'
            || word_array[word_index][char_index] == 'o'
            || word_array[word_index][char_index] == 'u'
            || word_array[word_index][char_index] == 'y')

        {
            word_array[word_index][char_index+3] = word_array[word_index][char_index+1];
            word_array[word_index][char_index+1] = 'k';
            word_array[word_index][char_index+2] = word_array[word_index][char_index];
            for (int k = 0; k < char_index+3; ++k)
            {
                std::cout << word_array[word_index][char_index+k];
            }
            char_index = char_index+3;
        }
        else
        {
            std::cout << word_array[word_index][char_index];
            ++char_index;
        }
        if (word_array[word_index][0] == 0)
        {
            break;
        }
    }

}