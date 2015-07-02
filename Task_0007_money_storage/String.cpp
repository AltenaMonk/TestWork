#include "String.h"

#include <cstring>

#include <locale> // std::locale, std::tolower, std::toupper

namespace Library
{

/// @attention limits do not work on terminals.
String::TSize const String::NoPosition = static_cast<String::TSize>(-1);

/// @brief Конструктор создаёт пустой пакет.
String::String()
    : m_string()
{
    NullEnd();
}

/// @brief Конструктор создаёт пакет на основе другого пакета.
/// @param string Пакет, копию которого мы получим.
String::String(String const & string)
    : m_string(string.m_string)
{
}

/// @brief Конструктор создаёт пакет на основе символа.
/// @param data Символ.
String::String(unsigned char data)
    : m_string(1, data)
{
    NullEnd();
}

/// @brief Конструктор создаёт пакет на основе символа.
/// @param data Символ.
String::String(char data)
    : m_string(1, static_cast<unsigned char>(data))
{
    NullEnd();
}

/// @brief Конструктор создаёт пакет на основе строки в стиле C.
/// @param data Строка с данными в стиле C для пакета.
String::String(char const * data)
    : m_string(data, data + strlen(data))
{
    NullEnd();
}

/// @brief Конструктор создаёт пакет на основе строки.
/// @param data Строка с данными для пакета.
/// @param size Размер данных в строке data.
String::String(char const * data, TSize size)
    : m_string(data, data + size)
{
    NullEnd();
}

/// @brief Конструктор создаёт пакет на основе массива байт.
/// @param data Массив байт.
String::String(std::vector<unsigned char> const & data)
    : m_string(data)
{
    NullEnd();
}

/// @brief Деструктор.
String::~String()
{
}

/// @brief Удалить все данные из пакета.
void String::Clear()
{
    m_string.clear();
    NullEnd();
}

/// @brief Поменять данные в 2-ух пакетах друг с другом.
/// @param string Пакет с которым меняемся содержимым.
void String::Swap(String & string)
{
    m_string.swap(string.m_string);
}

/// @brief Размер данных в пакете.
/// @return Размер данных в пакете.
String::TSize String::Size() const
{
    return m_string.size() - 1;
}

/// @brief Вернуть признак того, что пакет пустой.
/// @return Признак того, что пакет пустой.
/// @retval true Пакет пустой.
/// @retval false Пакет не пустой.
bool String::IsEmpty() const
{
    return Size() == 0;
}

/// @brief Пакет состоящий из части пакета от индекса from длинной в size байт.
/// @param from Начальный индекс, с которого берутся данные, если лежит за пределами пакета, то вернётся пустой пакет.
/// @param size Размер подпакета, если больше чем возможно, то скопируется только существующая часть.
/// @return Пакет состоящий из части текущего пакета.
String String::SubString(TSize from, TSize size) const
{
    String result;
    if (from > Size())
    {
        return result;
    }
    if (from + size > Size() || size > Size())
    {
        size = Size() - from;
    }
    result.Assign(ToCString() + from, size);
    return result;
}

/// @brief Пакет состоящий из части пакета от индекса from и до конца.
/// @param from Начальный индекс, с которого берутся данные, если лежит за пределами пакета, то вернётся пустой пакет.
/// @return Пакет состоящий из части текущего пакета.
String String::SubString(TSize from) const
{
    return SubString(from, Size());
}

/// @brief Преобразовать данные пакета в строку в стиле C.
/// @return Строка в стиле C.
char const * String::ToCString() const
{
    /// @internal It is safe, because we always use NullEnd and m_string.size() != 0.
    return reinterpret_cast<char const *>(&m_string[0]);
}

String::TString String::ToVector() const
{
    TString vector(m_string);
    vector.pop_back();
    return vector;
}

namespace Private
{

unsigned char IntToChar(unsigned char data)
{
    return static_cast<unsigned char>(data + (data <= 9 ? '0' : ('A' - 10)));
}

String ByteToString(unsigned char data)
{
    return String(IntToChar(data / 16)) + IntToChar(data % 16);
}

} // namespace Private

/// @brief Преобразоватьданные пакета в строку в шеснадцатиричной записи через пробел.
/// @return Строка с шестнадцатиричной записью данных из пакета.
String String::ToHex() const
{
    String spacer("");
    String result("");
    for (unsigned int i(0); i < Size(); ++i)
    {
        result += spacer;
        spacer = " ";
        result += "0x" + Private::ByteToString(m_string[i]);
    }
    return result;
}

/// @brief Посчитать исключаещее или от всех данных пакета.
/// @return Значение исключающего или.
unsigned char String::XOr() const
{
    unsigned char result(0);
    for (TSize index(0); index != Size(); ++index)
    {
        result = result ^ m_string[index];
    }
    return result;
}

/// @brief Посчитать сумму от всех данных пакета.
/// @return Значение суммы.
unsigned char String::Summ() const
{
    unsigned char result(0);
    for (TSize index(0); index != Size(); ++index)
    {
        result = static_cast<unsigned char>(result + m_string[index]);
    }
    return result;
}

/// @brief Оператор присваивания одного пакета другому.
/// @param string Пакет с копируемыми данными.
/// @return Ссылка на изменённый пакет.
String & String::operator=(String const & string)
{
    String temp(string);
    Swap(temp);
    return *this;
}

/// @brief Оператор присваивания пакета символу.
/// @param data Символ.
/// @return Ссылка на изменённый пакет.
String & String::operator=(unsigned char data)
{
    String temp(data);
    Swap(temp);
    return *this;
}

/// @brief Оператор присваивания пакета символу.
/// @param data Символ.
/// @return Ссылка на изменённый пакет.
String & String::operator=(char data)
{
    String temp(data);
    Swap(temp);
    return *this;
}

/// @brief Оператор присваивания пакета строке в стиле C.
/// @param data Строка с данными в стиле C.
/// @return Ссылка на изменённый пакет.
String & String::operator=(char const * data)
{
    String temp(data);
    Swap(temp);
    return *this;
}

/// @brief Оператор присваивания пакета массиву байт.
/// @param data Массив байт.
/// @return Ссылка на изменённый пакет.
String & String::operator=(std::vector<unsigned char> const & data)
{
    String temp(data);
    Swap(temp);
    return *this;
}

/// @brief Присваивание одного пакета другому.
/// @param string Пакет с копируемыми данными.
void String::Assign(String const & string)
{
    String temp(string);
    Swap(temp);
}

/// @brief Присваивание пакета символу.
/// @param data Символ.
void String::Assign(unsigned char data)
{
    String temp(data);
    Swap(temp);
}

/// @brief Присваивание пакета символу.
/// @param data Символ.
void String::Assign(char data)
{
    String temp(data);
    Swap(temp);
}

/// @brief Присваивание пакета строке в стиле C.
/// @param data Строка с данными в стиле C.
void String::Assign(char const * data)
{
    String temp(data);
    Swap(temp);
}

/// @brief Присваивание пакета строке в стиле C.
/// @param data Строка с данными в стиле C.
/// @param size Размер данных в копируемой строке в байтах.
void String::Assign(char const * data, TSize size)
{
    String temp(data, size);
    Swap(temp);
}

/// @brief Присваивание пакета массиву байт.
/// @param data Массив байт.
void String::Assign(std::vector<unsigned char> const & data)
{
    String temp(data);
    Swap(temp);
}

/// @brief Функция сравнения пакетов. Сравнивается общая длинна содержимого, если равна, то больше будет более длинный пакет.
/// @param data Пакет с которым сравниваеи текущий.
/// @return Отношение пакетов друг к другу.
/// @retval -1 Текущий пакет меньше.
/// @retval  0 Пакеты равны.
/// @retval +1 Текущий пакет больше.
int String::Compare(String const & data) const
{
    int result(memcmp(ToCString(), data.ToCString(), std::min(Size(), data.Size())));
    if (result == 0)
    {
        if (Size() < data.Size())
        {
            return -1;
        }
        if (Size() > data.Size())
        {
            return 1;
        }
    }
    return result;
}

/// @brief Оператор индексации данных.
/// @param index Индекс.
/// @return Ссылка на символ.
unsigned char const & String::operator[](TSize index) const
{
    return m_string[index];
}

/// @brief Оператор индексации данных.
/// @param index Индекс.
/// @return Ссылка на символ.
unsigned char & String::operator[](TSize index)
{
    return m_string[index];
}

/// @brief Добавление пакету другого пакета.
/// @param string Пакет с копируемыми данными.
/// @return Ссылка на изменённый пакет.
String & String::Append(String const & string)
{
    if (string.Size() == 0)
    {
        return *this;
    }
    return Append(string.ToCString(), string.Size());
}

/// @brief Добавление пакету символа.
/// @param data Символ.
/// @return Ссылка на изменённый пакет.
String & String::Append(unsigned char data)
{
    return Append(reinterpret_cast<char const *>(&data), 1);
}

/// @brief Добавление пакету символа.
/// @param data Символ.
/// @return Ссылка на изменённый пакет.
String & String::Append(char data)
{
    return Append(&data, 1);
}

/// @brief Добавление пакету строки в стиле C.
/// @param data Строка с данными в стиле C.
/// @return Ссылка на изменённый пакет.
String & String::Append(char const * data)
{
    return Append(data, strlen(data));
}

/// @brief Добавление пакету строки в стиле C.
/// @param data Строка с данными в стиле C.
/// @param size Размер данных в копируемой строке в байтах.
/// @return Ссылка на изменённый пакет.
String & String::Append(char const * data, TSize size)
{
    m_string.pop_back();
    std::copy(data, data + size, std::back_insert_iterator<TString>(m_string));
    NullEnd();
    return *this;
}

/// @brief Добавление пакету массива байт.
/// @param data Массив байт.
/// @return Ссылка на изменённый пакет.
String & String::Append(std::vector<unsigned char> const & data)
{
    if (data.empty())
    {
        return *this;
    }
    return Append(reinterpret_cast<char const *>(&data[0]), data.size());
}

/// @brief Добавление пакету массива байт.
/// @param data Массив байт.
/// @return Ссылка на изменённый пакет.
String & String::Resize(TSize size, unsigned char value)
{
    if (Size() > size)
    {
        Assign(SubString(0, size));
    }
    for ( ; Size() < size; )
    {
        Append(value);
    }
    return *this;
}

/// @brief Поиск в пакете подпакета.
/// @param string Искомый подпакет.
/// @param from Начиная с какого байта искать.
/// @return Индекс с которого начинается подпакет.
/// @retval -1 Если пакет не содержит искомый подпакет.
String::TSize String::Find(String const & string, TSize from) const
{
    TSize size(Size());
    TSize stringSize(string.Size());
    for (TSize start(from); (start + stringSize) <= size; ++start)
    {
        bool equal(true);
        for(TSize index(0); index != stringSize; ++index)
        {
            if ((*this)[start + index] != string[index])
            {
                equal = false;
                break;
            }
        }
        if (equal)
        {
            return start;
        }
    }
    return NoPosition;
}

/// @brief Поиск в пакете подпакета.
/// @param string Искомый подпакет.
/// @param from Начиная с какого байта искать.
/// @return Индекс с которого начинается подпакет.
/// @retval -1 Если пакет не содержит искомый подпакет.
String::TSize String::ReverseFind(String const & string, TSize from) const
{
    TSize size(Size());
    TSize stringSize(string.Size());
    if (size < (from + stringSize))
    {
        return NoPosition;
    }
    for (TSize start(size - from); (start - stringSize) <= size; --start)
    {
        bool equal(true);
        for(TSize index(0); index != stringSize; ++index)
        {
            if ((*this)[start + index] != string[index])
            {
                equal = false;
                break;
            }
        }
        if (equal)
        {
            return start;
        }
    }
    return NoPosition;
}

/// @brief Разбить строку на подстроки по разделителю.
/// @param delimeter Разделитель.
/// @param isSkipEmpty Пропускать результаты нулевой длинны.
/// @return Массив подстрок.
String::TStrings String::Split(String const & delimeter, bool isSkipEmpty) const
{
    TStrings result;
    if (delimeter.Size() == 0)
    {
        if (isSkipEmpty == false || Size())
        {
            result.push_back(*this);
        }
        return result;
    }
    TSize position(0);
    do
    {
        TSize oldPosition(position);
        position = Find(delimeter, position);
        String temp;
        if (position != String::NoPosition)
        {
            temp = SubString(oldPosition, position - oldPosition);
            position += delimeter.Size();
        }
        else
        {
            temp = SubString(oldPosition, Size() - oldPosition);
        }
        if (isSkipEmpty == false || temp.Size())
        {
            result.push_back(temp);
        }
    }
    while (position != String::NoPosition);
    return result;
}

/// @brief Собрать строку из подстрок с разделителем.
/// @param data Массив подстрок.
/// @param delimeter Разделитель.
/// @return Строка.
String String::Join(std::vector<String> const & data, String const & delimeter)
{
    String result;
    bool isFirst(true);
    typedef std::vector<String> TData;
    TData::const_iterator iterator(data.begin());
    TData::const_iterator end     (data.end  ());
    for (; iterator != end; ++iterator)
    {
        if (isFirst == false)
        {
            result += delimeter;
        }
        isFirst = false;
        result += *iterator;
    }
    return result;
}

/// @brief Заменить все вхождения from на to.
/// @param from Что заменяем.
/// @param to На что заменяем.
/// @return Результирующая строка.
String String::Replace(String const & from, String const & to) const
{
    return Join(Split(from), to);
}

/// @brief Найти первый различающийся символ.
/// @param string Пакет с которым сравниваем.
/// @return Номер первого различающегося символа.
/// @retval NoPosition если строки равны.
String::TSize String::Difference(String const & string) const
{
    TSize end(std::min(Size(), string.Size()));
    for (TSize index(0); index < end; ++index)
    {
        if (string[index] != operator[](index))
        {
            return index;
        }
    }
    if (Size() != string.Size())
    {
        return end;
    }
    return NoPosition;
}

/// @brief Check is string begins with "data".
/// @param data Пакет с которым сравниваем.
/// @return Is string begins with "data".
bool String::BeginsWith(String const & data) const
{
    return SubString(0, data.Size()) == data;
}

/// @brief Check is string ends with "data".
/// @param data Пакет с которым сравниваем.
/// @return Is string ends with "data".
bool String::EndsWith(String const & data) const
{
    if (Size() < data.Size())
    {
        return false;
    }
    return SubString(Size() - data.Size()) == data;
}

/// @brief To lower case string
/// @todo UnitTest
/// @todo For english text only
/// @return Lower case string
String String::ToLower() const
{
    String result = *this;
    result.Resize(Size());
    unsigned char value('\x20');
    for (TSize i(0); i < Size(); ++i)
    {
        if (m_string[i] >= 'A' && m_string[i] <= 'Z')
        {
            result[i] = m_string[i] | value;
        }
    }
    return result;
}

/// @brief To upper case string
/// @todo UnitTest
/// @todo For english text only
/// @return Upper case string
String String::ToUpper() const
{
    String result;
    result = *this;
    unsigned char value('\x20');
    value = static_cast<unsigned char>(~value);
    for (TSize i(0); i < Size(); ++i)
    {
        if (m_string[i] >= 'a' && m_string[i] <= 'z')
        {
            result[i] = m_string[i] & value;
        }
    }
    return result;
}

String::TStrings String::ToChars(Charsets charset) const
{
    TStrings result;
    TSize size(0);
    for (TSize index(0); index < Size(); index += size)
    {
        size = GetCharSize(index, charset);
        if (size == 0)
        {
            break;
        }
        if (index + size <= Size())
        {
            result.push_back(SubString(index, size));
        }
    }
    return result;
}

bool String::IsWhiteSpace(TSize index, unsigned int config) const
{
    if (index >= Size())
    {
        return WhiteSpaceConfig_isEmptyWhiteSpace & config;
    }
    if (m_string[index] == ' ' || m_string[index] == '\v' || m_string[index] == '\t')
    {
        return true;
    }
    if ((WhiteSpaceConfig_isNewLineWhiteSpace & config) && (m_string[index] == '\r' || m_string[index] == '\n'))
    {
        return true;
    }
    if ((WhiteSpaceConfig_isNullWhiteSpace & config) && m_string[index] == '\0')
    {
        return true;
    }
    return false;
}

String String::Trim(unsigned int config) const
{
    if (Size() == 0)
    {
        return String();
    }
    TSize begin(0);
    TSize end(Size());
    for (TSize index(begin); index < end; ++index)
    {
        if (IsWhiteSpace(index, config) == true)
        {
            begin = index + 1;
        }
        else
        {
            break;
        }
    }
    for (TSize index(end); index > begin; --index)
    {
        if (IsWhiteSpace(index - 1, config) == true)
        {
            end = index - 1;
        }
        else
        {
            break;
        }
    }
    return SubString(begin, end - begin);
}

String::TSize String::GetCharSize(TSize index, Charsets charset) const
{
    switch (charset)
    {
        case Charset_UTF8:
        {
            TSize size(0);
            if (index < Size())
            {
                unsigned char utf8 = 0x80;
                if (m_string[index] < utf8)
                {
                    return 1u;
                }
                unsigned char mask = 0x80;
                for (; size < 6 && ((index + size) <= Size()) && ((m_string[index] & mask) == mask); ++size)
                {
                    mask = utf8 | static_cast<unsigned char>(mask >> 1);
                }
            }
            return size;
        }
        case Charset_Char:
        {
            return 1u;
        }
        case Charset_UTF16:
        {
            return 2u;
        }
        case Charset_UTF32:
        {
            return 4u;
        }
        default:
        {
        }
        break;
    }
    return 0u;
}

void String::NullEnd()
{
    m_string.push_back(0);
}

/// @brief Оператор добавления пакету другого пакета.
/// @param string Пакет с копируемыми данными.
/// @return Ссылка на изменённый пакет.
String & String::operator+=(String const & string)
{
    return Append(string);
}

/// @brief Оператор добавления пакету символа.
/// @param data Символ.
/// @return Ссылка на изменённый пакет.
String & String::operator+=(unsigned char data)
{
    return Append(data);
}

/// @brief Оператор добавления пакету символа.
/// @param data Символ.
/// @return Ссылка на изменённый пакет.
String & String::operator+=(char data)
{
    return Append(data);
}

/// @brief Оператор добавления пакету строки в стиле C.
/// @param data Строка с данными в стиле C.
/// @return Ссылка на изменённый пакет.
String & String::operator+=(char const * data)
{
    return Append(data);
}

/// @brief Добавление пакету массива байт.
/// @param data Массив байт.
/// @return Ссылка на изменённый пакет.
String & String::operator+=(std::vector<unsigned char> const & data)
{
    return Append(data);
}

/// @brief Опетор сравнения пакетов на равенство.
/// @param string Первый пакет.
/// @param data Второй пакет.
/// @return Признак, равны ли пакеты.
/// @retval true Пакеты равны.
/// @retval false Пакеты не равны.
bool operator==(String const & string, String const & data)
{
    return string.Compare(data) == 0;
}

/// @brief Опетор сравнения пакетов на не равенство.
/// @param string Первый пакет.
/// @param data Второй пакет.
/// @return Признак, не равны ли пакеты.
/// @retval true Пакеты не равны.
/// @retval false Пакеты равны.
bool operator!=(String const & string, String const & data)
{
    return string.Compare(data) != 0;
}

/// @brief Опетор сравнения пакетов: меньше или равно.
/// @param string Первый пакет.
/// @param data Второй пакет.
/// @return Признак, не равны ли пакеты.
/// @retval true Пакеты не равны.
/// @retval false Пакеты равны.
bool operator<=(String const & string, String const & data)
{
    return string.Compare(data) <= 0;
}

/// @brief Опетор сравнения пакетов: меньше.
/// @param string Первый пакет.
/// @param data Второй пакет.
/// @return Признак, не равны ли пакеты.
/// @retval true Пакеты не равны.
/// @retval false Пакеты равны.
bool operator< (String const & string, String const & data)
{
    return string.Compare(data) <  0;
}

/// @brief Опетор сравнения пакетов: больше или равно.
/// @param string Первый пакет.
/// @param data Второй пакет.
/// @return Признак, не равны ли пакеты.
/// @retval true Пакеты не равны.
/// @retval false Пакеты равны.
bool operator>=(String const & string, String const & data)
{
    return string.Compare(data) >= 0;
}

/// @brief Опетор сравнения пакетов: больше.
/// @param string Первый пакет.
/// @param data Второй пакет.
/// @return Признак, не равны ли пакеты.
/// @retval true Пакеты не равны.
/// @retval false Пакеты равны.
bool operator> (String const & string, String const & data)
{
    return string.Compare(data) >  0;
}

/// @brief Сложение 2ух пакетов.
/// @param string Первый пакет.
/// @param data Второй пакет.
/// @return Новый пакет, содержащий в себе сумму.
String operator+(String const & string, String const & data)
{
    String result(string);
    result += data;
    return result;
}

/// @brief Сложение пакета и символа.
/// @param string Пакет.
/// @param data Символ.
/// @return Новый пакет, содержащий в себе сумму.
String operator+(String const & string, unsigned char data)
{
    String result(string);
    result += data;
    return result;
}

/// @brief Сложение пакета и символа.
/// @param string Пакет.
/// @param data Символ.
/// @return Новый пакет, содержащий в себе сумму.
String operator+(String const & string, char data)
{
    String result(string);
    result += data;
    return result;
}

/// @brief Сложение пакета и строки в стиле C.
/// @param string Пакет.
/// @param data Строка в стиле C.
/// @return Новый пакет, содержащий в себе сумму.
String operator+(String const & string, char const * data)
{
    String result(string);
    result += data;
    return result;
}

/// @brief Сложение пакета и массива байт.
/// @param string Пакет.
/// @param data Массив байт.
/// @return Новый пакет, содержащий в себе сумму.
String operator+(String const & string, std::vector<unsigned char> const & data)
{
    String result(string);
    result += data;
    return result;
}

std::basic_ostream<char> & operator<<(std::basic_ostream<char> & stream, String const & data)
{
    stream.write(data.ToCString(), static_cast<std::streamsize>(data.Size()));
    return stream;
}

std::basic_istream<char> & operator>>(std::basic_istream<char> & stream, String & data)
{
    data.Assign("");
    size_t const bufferSize(1024);
    char buffer[bufferSize + 1] = { 0, };
    while(stream.good())
    {
        stream.read(buffer, bufferSize);
        String::TSize size(static_cast<String::TSize>(stream.gcount()));
        data.Append(buffer, size);
    }
    return stream;
}

} // namespace Library
