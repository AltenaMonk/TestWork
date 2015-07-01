struct money_value
{

public:

    money_value (int const _int, const int _hund);
    void print() const;
    money_value const add (money_value const &x);
    money_value const subtract(money_value const &x);
    money_value const multiply(int const mod);

private:

    int value;
};
