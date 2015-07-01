struct money_value
{
private:

    int value;

public:

    void print();
    money_value add (money_value & x);
    money_value subtract(money_value & x);
    money_value multiply(int mod);
    money_value (int _int, int _hund);
};
