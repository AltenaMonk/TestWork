struct money_value
{

public:

    money_value (int _int, int _hund);
    void print() const;
    money_value const add (money_value &x);
    money_value const subtract(money_value &x);
    money_value const multiply(int mod);

private:

    int value;
};
