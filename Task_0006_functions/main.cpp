#include <iostream>
#include <memory.h>
#include <cstdio>

/// Общее стилистическое замечание, лучше именовать функции по методу объект_действие, примеры:
/// string_lenght
/// string_copy
/// string_print  а не print_string
/// string_resize а не resize_string
/// Это добавляет читабельности и лёгкости запоминания, а то каждый раз думать что вперёд идёт объект или действие.
/// Ну и такой порядок записи станет более привычен когда будем классы проходить.

/// По сути всё правильно. Для этой функции только маленькие замечания.
int string_lenght (char * string)
{
    int i = 0;
    /// Писать i = 0 в данном месте не обязательно, можно просто for (; string[i] != 0; ++i)
    /// Все 3 поля являются не обязательными.
    for (; string[i] != 0; ++i)
    {
        /// Это тоже не надо, спокойно можно писать.
        /// for (; string[i] != 0; ++i)
        /// {
        /// }
    }
    return i + 1;
}
/// Тут приведены мои варианты написания аналогичных функций с теми же знаниями, что есть у тебя:
//int string_lenght(char * string)
//{
//    int i = 0;
//    for (i = 0; string[i] != 0; ++i)
//    {
//    }
//    return i + 1;
//}

/// По сути всё правильно. Для этой функции только маленькие замечания.
int word_counter (char * string)
{
    int count = 1;
    /// Лучше вычислять длинну 1 раз и потом использовать постоянно.
    /// Примерно так:
    /// int size = string_lenght(string);
    /// for (int i = 0; i < size; ++i)
    int size = string_lenght(string);
    for (int i = 0; i < size; ++i)
    {
        /// Зачем проверка на 0ой символ, у тебя длинна и так уже проверяет до 0ого символа.
        if (string[i] == ' ')
        {
            ++count;
        }
    }
    return count;
}
/// Тут приведены мои варианты написания аналогичных функций с теми же знаниями, что есть у тебя:
//int word_count(char * string)
//{
//    int count = 1;
//    int size = string_lenght(string);
//    for (int i = 0; i < size; ++i)
//    {
//        if (string[i] == ' ')
//        {
//            ++count;
//        }
//    }
//    return count;
//}
//int word_count(char * string)
//{
//    int count = 1;
//    for (int i = 0; string[0] != 0; ++i)
//    {
//        if (string[i] == ' ')
//        {
//            ++count;
//        }
//    }
//    return count;
//}

/// По сути всё правильно. Для этой функции только малеькие замечания.
int string_print (char * string)
{
    /// Лучше вычислять длинну 1 раз и потом использовать постоянно.
    /// Примерно так:
    /// int size = string_lenght(string);
    /// for (int i = 0; i < size; ++i)
    int size = string_lenght(string);
    for (int i = 0; i < size; ++i)
    {
        /// Зачем это, если длинна и так считается до 0 не включительно? Думаю можно условие полностью вырезать, и оставить только std::cout << string[i];
        {
            std::cout << string[i];
        }
    }
}
/// Тут приведены мои варианты написания аналогичных функций с теми же знаниями, что есть у тебя:
//int string_print(char * string)
//{
//    int size = string_lenght(string);
//    for (int i = 0; i < size; ++i)
//    {
//        std::cout << string[i];
//    }
//}
//int string_print(char * string)
//{
//    for (int i = 0; string[i] != 0; ++i)
//    {
//        std::cout << string[i];
//    }
//}


/// Ошибка тут есть.
/// char * new_string передавать нельзя.
/// Пример, ты извне передал сюда адрес 0x2000 => Переменная new_string = 0x2000, это просто число.
/*int resize_string (char * origin_string, char * new_string)
{
    for (int i = 0; string_lenght(new_string) < string_lenght(origin_string); ++i)
    {
        /// Здесь ты выделил память и тебе вернули адрес 0x3000, тоже просто число, но по этому адресу для тебя выделили требуемую тобой память.
        char * temp = new char[string_lenght(new_string) * 2];
        /// Затем ты здесь удалил память по адресу 0x2000.
        delete [] new_string;
        /// Здесь переменная new_string стала равна 0x3000, просто новому числу.
        /// НО!!! Эта переменная после выхода из функции ни где не останется. Эта информация будет потеряна.
        new_string = temp;
        /// Надо либо в качестве результата возвращать new_string, а в месте приёмки присваивать переменной новый указатель.
        /// Либо принимать указатель на указатель: char ** new_string и менять значение *new_string = temp.
    }
    return 0;
}*/
/// А вообще эту функцию лучше реализовывать как-то так:
/// @brief Выделяет память под строку в указанном количестве. Использует в качестве вспомагательной string_copy.
/// @param string Исходная строка.
/// @param new_size Новый размер буфера.
/// void string_resize(char ** string, int new_size);

void string_resize (char ** string, int size_new)
{
    char ** temp = new char[10];
    memset(temp, 0, 10 * sizeof(char *));
    for (int i = 0; i < 10; ++i)
    {
        temp[i] = new char[size_new];
        memset(temp[i], 0, size_new * sizeof(char));
    }

    int * old_size = new int[100];
    memset(old_size, 0, 100 * sizeof(int));
    for (int i = 0; i < 10; ++i)
    {
        old_size[i] = string_copy(string[i],temp[i]);
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int k = 0; )
    }
}


/// Тут есть идейные ошибки.
int string_copy (char * origin_string, char * copied_string)
{
    /// Тут идеалогически не хорошо выделять память, это должен сделать тот кто вызывает функцию.
    /// Ты только копируешь.
    /// Может там раньше был ОГРОМНЫЙ буфер(1024*1024*1024), а ты его заменил на что-то маленькое(10*2).
    for (int i = 0; origin_string != 0; ++i)
    {
        copied_string[i] = origin_string[i];
    }
    return i;
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
/*
int print_string (char * string)
{

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
    gets(text);
    char * test_string = new char[10];
    /// Ой-ой-ой, а где там у нас будет первый ноль при определении длинны? Тут надо писать полный размер, его знаешь только ты. memset(test_string, 0, 10 * sizeof(test_string[0]));
    memset(test_string, 0, string_lenght(test_string));
    std::cout << "Длина строки (исходная, тестовая)" << string_lenght(text) << ", " << string_lenght(test_string) << std::endl;
    std::cout << "Количество слов:" << word_counter(text) << std::endl;
    std::cout << "Исходная строка:" << std::endl;
    std::cout << print_string(text) << std::endl;
    string_copy(text,test_string);
    std::cout << print_string(test_string) << std::endl;

    /// А кто буфер освобождать будет?
    /// char * test_string = new char[10];

    /// А кто буфер освобождать будет?
    /// char * text = new char[1024];

    return 0;
}
