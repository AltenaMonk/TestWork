#include <iostream>
#include <memory.h>
#define STRING_LENGTH 1024

int string_print (char * string)
{
    if (string == NULL)
    {
        return 0;
    }
    int i = 0;
    for (;string[i] != 0; ++i)
    {
        std::cout << string[i];
    }
    return i;
}

void words_print(char ** string, int count)
{
    for (int i = 0; i < count; ++i)
    {
        string_print(string[i]);
    }
}

void words_free (char *** string, int count)
{
    for (int i = 0; i < count; ++i)
    {
        delete [] string[i];
    }
    delete [] string;
}
