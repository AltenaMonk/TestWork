struct money_value
{

public:

    money_value (long _int, long _hund);
    money_value (money_value const &other);
    money_value ();
    money_value &operator = (money_value const &other);
    money_value &operator += (money_value const &other);
    money_value &operator -= (money_value const &x);
    money_value &operator *= (long x);
    money_value &operator /= (long x);
    money_value &operator %= (long x);
    money_value operator + (money_value const &x) const;
    money_value operator - (money_value const &x) const;
    money_value operator * (long x) const;
    money_value operator / (long x) const;
    money_value operator % (long x) const;
    void print() const;

private:

    long value;
};
