struct money_value
{

public:

    money_value (int _int, int _hund);
    money_value (money_value const &other);
    money_value ();
    money_value &operator = (money_value const &other);
    money_value &operator += (money_value const &other);
    money_value &operator -= (money_value const &x);
    money_value &operator *= (int x);
    money_value &operator /= (int x);
    money_value &operator %= (int x);
    money_value operator + (money_value const &x) const;
    money_value operator - (money_value const &x) const;
    money_value operator * (int x) const;
    money_value operator / (int x) const;
    money_value operator % (int x) const;
    void print() const;

private:

    int value;
};
