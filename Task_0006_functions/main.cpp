#include <iostream>
#include <memory.h>
#include <cstdio>

int string_lenght(char * string)
{
    /// Защита от дурака.
    if (string == NULL)
    {
        return 0;
    }
    int i = 0;
    for (; string[i] != 0; ++i)
    {
    }
    /// Возвращать правильнее размер занимаемый полезными данными, а не техническим нулём. return i; a не return i + 1;
    return i;
}

int string_print(char * string)
{
    /// Защита от дурака.
    if (string == NULL)
    {
        return 0;
    }
    int i = 0;
    for (; string[i] != 0; ++i)
    {
        std::cout << string[i];
    }
    /// Необходимо вернуть количество напечатанных символов. Иначе зачем вообще стоит int в описании функции?
    return i;
}

int string_copy(char * from, char * to)
{
    /// Защита от дурака.
    if (from == NULL || to == NULL)
    {
        return 0;
    }
    int i = 0;
    /// Здесь правильнее копировать всё до нулевого символа from[i] != 0, а не до нулевой строкм from != 0, так как иначе это бесконечный цикл.
    for (; from[i] != 0; ++i)
    {
        to[i] = from[i];
    }
    return i;
}

/// @brief Выделяет память под строку в указанном количестве. Использует в качестве вспомагательной string_copy.
/// @param string Исходная строка.
/// @param new_size Новый размер буфера.
void string_resize (char ** string, int size_new)
{
    /// Если указатель на изменяемую строку равен 0, то выходим ни чего не сделав.
    if (string == NULL)
    {
        return;
    }

    /// Выделяем память в указанном количестве под новую строку.
    char * newString = new char[size_new + 1];
    memset(newString, 0, size_new + 1);

    /// Копируем старую строку в новую.
    string_copy(*string, newString);

    /// Если под изменяемую строку была выделена память, то освободим эту память.
    if (*string != NULL)
    {
        delete [] *string;
    }

    /// Начнём хранить по указателю на строку нашу вовую строку.
    *string = newString;
}

int word_counter (char * string)
{
    int count = 1;
    int size = string_lenght(string);
    /// Если возвращать размер полезных данных, то правильнее будет i <= size;
    for (int i = 0; i < size; ++i)
    {
        if (string[i] == ' ')
        {
            ++count;
        }
    }
    return count;
}

/// А вообще эту функцию лучше реализовывать как-то так:
/// @brief Копирует одну строку в другую, не меняет буферы, так что вызывающая сторона должна обеспечить достаточность памяти.
/// @param from Исходная строка.
/// @param to Куда копируем.
/// @return Количество скопированных символов.
/// int string_copy(char * from, char * to);

/*int string_bricking (char * string)
{
    for (int i = 0; i < string_lenght(string); ++i)
    {
        if (string[i] == 'a' ||
            string[i] == 'e' ||
            string[i] == 'i' ||
            string[i] == 'o' ||
            string[i] == 'u' ||
            string[i] == 'y')
        {
            int brick_index = i;
            char * brick_string = new char[string_lenght(string)];
            memset(brick_string, 0, string_lenght(brick_string) * sizeof(char));
            for (int j = 0; j < string_lenght(string); ++j)
            {
                brick_string[j] = string[j+1];
            }
        }
    }
    return 0;
}
*/

/// Примерно, с моей точки зрения, должно использование этого выглядеть так:
///   /// Тут скучно.
///   char * text = new char[1024];         /// Создали буфер.
///   memset(text, 0, 1024 * sizeof(char)); /// Обнулили.
///   gets(text);                           /// Прочитали с клавиатуры.
///   char * test_string(NULL);             /// Создали новую строку для хранения данных.
///   /// Пошло интересное.
///   int size = string_resize(&test_string, string_lenght(text) * 2); /// Выделили под строку данных в 2 раза больше
///   string_copy(text, test_string);       /// Скопировали данные из одной строки в другую.

int main()
{
    char * text = new char[1024];
    memset(text, 0, 1024 * sizeof(char));
    std::cout << "Введите строку для кирпичинизции:" << std::endl;
    gets(text);
    /// Выделять память сдесь нет ни какого смысла, так как в последствии мы её все равно освобождаем.
    char * test_string = NULL;
    std::cout << "Длина строки (исходная, тестовая): " << string_lenght(text) << ", " << string_lenght(test_string) << std::endl;
    std::cout << "Количество слов: " << word_counter(text) << std::endl;
    std::cout << "Исходная строка: " << std::endl;
    string_print(text);
    std::cout << std::endl;
    /// Здесь мы заботимся о том, что бы для нашёй строки хватило места.
    string_resize(&test_string, string_lenght(text));
    string_copy(text, test_string);
    std::cout << "Скопированная строка:" << std::endl;
    string_print(test_string);
    std::cout << std::endl;

    /// А кто буфер освобождать будет?!!!!!!!!!!!!!!
    /// А кто буфер освобождать будет?!!!!!!!!!!!!!!
    delete [] test_string;
    delete [] text;

    return 0;
}
