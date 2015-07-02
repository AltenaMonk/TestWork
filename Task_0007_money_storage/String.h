#ifndef LIBRARY_TYPES_STRING_H__INCLUDE_GUARD
#define LIBRARY_TYPES_STRING_H__INCLUDE_GUARD

#include <iostream>
#include <string>
#include <vector>

namespace Library
{

/// @brief Класс пакета используемый для хранения, получения и передачи информации в бинарном виде.
class String
{
    friend bool operator==(String const & string, String const & data);
    friend bool operator!=(String const & string, String const & data);
    friend bool operator<=(String const & string, String const & data);
    friend bool operator< (String const & string, String const & data);
    friend bool operator>=(String const & string, String const & data);
    friend bool operator> (String const & string, String const & data);
public:

    /// @brief TString Внутреняя реализация хранения данных.
    typedef std::vector<unsigned char> TString;
    typedef TString::size_type TSize;
    typedef unsigned char TChar;
    typedef std::vector<String> TStrings;

    enum Charsets
    {
        CharsetBegin  = 0,
        Charset_UTF8  = 0,
        Charset_Char  = 1,
        Charset_UTF16 = 2,
        Charset_UTF32 = 3,
        CharsetEnd
    };

    enum WhiteSpaceConfigs
    {
        WhiteSpaceConfigBegin                 = 0,
        WhiteSpaceConfig_isNewLineWhiteSpace  = 1,
        WhiteSpaceConfig_isNullWhiteSpace     = 2,
        WhiteSpaceConfig_isEmptyWhiteSpace    = 4,
        WhiteSpaceConfigAll                   = WhiteSpaceConfig_isNewLineWhiteSpace | WhiteSpaceConfig_isNullWhiteSpace | WhiteSpaceConfig_isEmptyWhiteSpace,
        WhiteSpaceConfigEnd
    };

    String();
    String(String const & data);
    String(unsigned char data);
    String(char data);
    String(char const * data);
    String(char const * data, TSize size);
    String(std::vector<unsigned char> const & data);
    ~String();

    void Clear();

    void Swap(String & string);

    TSize Size() const;

    bool IsEmpty() const;

    String SubString(TSize from, TSize size) const;
    String SubString(TSize from) const;

    char const * ToCString() const;
    TString ToVector() const;
    String ToHex() const;
    unsigned char XOr() const;
    unsigned char Summ() const;

    String & operator=(String const & string);
    String & operator=(unsigned char data);
    String & operator=(char data);
    String & operator=(char const * data);
    String & operator=(std::vector<unsigned char> const & data);

    void Assign(String const & string);
    void Assign(unsigned char data);
    void Assign(char data);
    void Assign(char const * data);
    void Assign(char const * data, TSize size);
    void Assign(std::vector<unsigned char> const & data);

    int Compare(String const & data) const;

    unsigned char const & operator[](TSize index) const;
    unsigned char &       operator[](TSize index);

    String & operator+=(String const & string);
    String & operator+=(unsigned char data);
    String & operator+=(char data);
    String & operator+=(char const * data);
    String & operator+=(std::vector<unsigned char> const & data);

    String & Append(String const & string);
    String & Append(unsigned char data);
    String & Append(char data);
    String & Append(char const * data);
    String & Append(char const * data, TSize size);
    String & Append(std::vector<unsigned char> const & data);

    String & Resize(TSize size, unsigned char value = 0);

    TSize Find(String const & string, TSize from = 0) const;
    TSize ReverseFind(String const & string, TSize from = 0) const;

    TStrings Split(String const & delimeter, bool isSkipEmpty = false) const;
    static String Join(std::vector<String> const & data, String const & delimeter = String());

    String Replace(String const & from, String const & to) const;

    TSize Difference(String const & string) const;

    bool BeginsWith(String const & data) const;
    bool EndsWith(String const & data) const;

    String ToLower() const;
    String ToUpper() const;

    TStrings ToChars(Charsets charset) const;

    bool IsWhiteSpace(TSize index, unsigned int config = WhiteSpaceConfig_isNewLineWhiteSpace) const;
    String Trim(unsigned int config = WhiteSpaceConfig_isNewLineWhiteSpace) const;

    static TSize const NoPosition;

private:
    TSize GetCharSize(TSize index, Charsets charset) const;

    void NullEnd();

    TString m_string;  ///< Объект хранящий данные.
};

bool operator==(String const & string, String const & data);
bool operator!=(String const & string, String const & data);
bool operator<=(String const & string, String const & data);
bool operator< (String const & string, String const & data);
bool operator>=(String const & string, String const & data);
bool operator> (String const & string, String const & data);

String operator+(String const & string, String const & data);
String operator+(String const & string, unsigned char data);
String operator+(String const & string, char data);
String operator+(String const & string, char const * data);
String operator+(String const & string, std::vector<unsigned char> const & data);

std::basic_ostream<char> & operator<<(std::basic_ostream<char> & stream, String const & data);
std::basic_istream<char> & operator>>(std::basic_istream<char> & stream, String & data);

} // namespace Library

#endif//LIBRARY_TYPES_STRING_H__INCLUDE_GUARD
