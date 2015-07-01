struct money_value
{

public:

    money_value (int _int, int _hund);
    void print();
    money_value add (money_value & x);
    money_value subtract(money_value & x);
    money_value multiply(int mod);

private:

    int value;
};
