struct money_value
{

public:

    money_value (int _int, int _hund);
    money_value (money_value const &other);
    money_value ();
    money_value &operator = (money_value const &other);
    money_value &operator += (money_value const &other);
    void print() const;
    money_value add (money_value const &x) const;
    money_value subtract(money_value const &x) const;
    money_value multiply(int mod) const;

private:

    int value;
};
