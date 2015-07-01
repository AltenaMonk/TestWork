struct money_value
{

public:

    money_value (int _int, int _hund);
    void print() const;
    money_value add (money_value const &x) const;
    money_value subtract(money_value const &x) const;
    money_value multiply(int mod) const;

private:

    int value;
};
