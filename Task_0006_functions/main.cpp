#include <iostream>
#include <memory.h>
#define STRING_LENGTH 1024

int string_length (char * string)
{
    if (string == NULL)
    {
        return 0;
    }
    int i = 0;
    for (;string[i] != 0; ++i)
    {
    }
    return i;
}
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
    std::cout << ' ';
    return i;
}

int string_copy (char * from, char * to)
{
    if (from == NULL || to == NULL)
    {
        return 0;
    }
    int i = 0;
    for (;from[i] != 0; ++i)
    {
        to[i] = from[i];
    }
    return i;
}

int string_resize (char ** string, int new_size)
{
    if (string == NULL)
    {
        return 0;
    }
    char * new_string = new char[new_size + 1];
    memset (new_string, 0, new_size + 1);
    string_copy( * string, new_string);
    if (* string != NULL)
    {
        delete [] * string;
    }
    * string = new_string;
    return string_length(* string);
}

int word_counter (char * string)
{
    int count = 1;
    int size = string_length(string);
    for (int i = 0; i < size; ++i)
    {
        if (string[i] == ' ' || string[i] == 0)
        {
            ++count;
        }
    }
    return count;
}

char ** string_to_words (char * string)
{
    if (string == NULL)
    {
        return NULL;
    }

    // Размер строки
    int string_size = string_length(string);

    // Размер массива слов
    int words_size = word_counter(string);

    // Выделяем память под массив слов
    char ** words = new char * [words_size];
    memset(words, 0, words_size * sizeof(char *));

    // Переменные для перемещения по массиву
    int word_index = 0, space_index = 0;
    for (int i = 0; i <= string_size; ++i)
    {
        if (string[i] == ' ' || string[i] == 0)
        {

           // Если встретили пробел - отделяем слово, записываем в массив и переходим к следующему
           words[word_index] = NULL;
           string_resize(&words[word_index], i - space_index);
           for (int k = 0; k < i - space_index; ++k)
           {
               words[word_index][k] = string[space_index + k];
           }
           ++word_index;
           space_index = i + 1;
        }
    }
    return words;
}

void words_print(char ** string, int count)
{
    if (string == NULL)
    {
        return;
    }
    for (int i = 0; i < count; ++i)
    {
        string_print(string[i]);
    }
    std::cout << std::endl;
}

void words_free (char *** string, int count)
{
    if (string == NULL || * string == NULL)
    {
        return;
    }
    for (int i = 0; i < count; ++i)
    {
        if ((* string)[i] != NULL)
        {
            delete [] (* string)[i];
        }
    }
    delete [] (* string);
    * string = NULL;
}

char * string_bricking (char * string)
{
    if (string == NULL)
    {
        return NULL;
    }
    int brick_char_index = 0;
    char * brick_string = NULL;
    int string_size = string_length(string);
    int brick_string_size = 0;
    string_resize(&brick_string, string_size);
    for (int i = 0; i < string_size; ++i)
    {
        if (string[i] == 'a' ||
            string[i] == 'e' ||
            string[i] == 'i' ||
            string[i] == 'o' ||
            string[i] == 'u' ||
            string[i] == 'y')
        {
            if (brick_string_size < brick_char_index + 3)
            {
                brick_string_size = string_resize(&brick_string, brick_char_index + 3);
            }
            brick_string[brick_char_index] = string[i];
            brick_string[brick_char_index + 1] = 'k';
            brick_string[brick_char_index + 2] = string[i];
            brick_char_index = brick_char_index + 3;
        }
        else
        {
            if (brick_string_size < brick_char_index + 1)
            {
                brick_string_size = string_resize(&brick_string, brick_char_index + 1);
            }
            brick_string[brick_char_index] = string[i];
            ++brick_char_index;
        }
    }
    return brick_string;
}


int main()
{
   /// Ввод данных
   std::cout << "Your text: ";
   char * text = new char[STRING_LENGTH];
   memset(text, 0, STRING_LENGTH * sizeof(char));
   gets(text);


   /// Обработка данных
   int words_count = word_counter(text);
   char ** words = string_to_words(text);
   char ** bricks = new char * [words_count];
   memset(bricks, 0, words_count * sizeof(char *));
   for (int index = 0; index < words_count; ++index)
   {
       bricks[index] = string_bricking(words[index]);
   }


   /// Вывод результатов
   std::cout << "String length: " << string_length(text) << std::endl;
   std::cout << "String: " << std::endl;
   string_print(text);
   std::cout << std::endl;
   std::cout << "String to words: " << std::endl;
   words_print(words, words_count);
   std::cout << "Bricked string: " << std::endl;
   words_print(bricks, words_count);


   /// Освобаждение оесурсов
   words_free(&bricks, words_count);
   words_free(&words, words_count);
   delete [] text;
   return 0;
}
