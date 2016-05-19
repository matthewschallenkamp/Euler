#include "BigInt.h"

BigInt::BigInt()
{
    //ctor
    num = "0";
    positive = true;
}

BigInt::BigInt(long long a)
{
    //ctor
    positive = a >= 0;
    a = a >= 0 ? a : -a;
    num = (a == 0) ? "0" : "";
    while(a > 0)
    {
        num.push_back(a % 10 + '0');
        a /= 10;
    }
}

BigInt::BigInt(int a)
{
    //ctor
    positive = a >= 0;
    a = a >= 0 ? a : -a;
    num = (a == 0) ? "0" : "";
    while(a > 0)
    {
        num.push_back(a % 10 + '0');
        a /= 10;
    }
}

BigInt::BigInt(string s)
{
    //ctor
    if(s.front() == '-')
    {
        positive = 0;
        s = s.substr(1, s.length() - 1);
    }
    else
        positive = 1;
    for(int i = s.length() - 1; i >= 0; i--)
    {
        num.push_back(s[i]);
    }
}

BigInt BigInt::add(const BigInt &a, const BigInt &b)
{
    if(a.num == "0")
         *this = b;
    else if(b.num == "0")
         *this = a;
    else
    {
        *this = a;
        string bs = b.num;
        if(bs.size() < num.size())
            bs.resize(num.size(), '0');
        if(num.size() < bs.size())
            num.resize(bs.size(), '0');
        bool carry = false;
        for(int i = 0; i < num.size(); i++)
        {
            num[i] += b.num[i] - '0';
            if(carry)
                num[i]++;
            carry = false;
            if(num[i] > '9')
            {
                carry = true;
                num[i] -= 10;
            }
        }
        if(carry)
            num.push_back('1');
    }
    return *this;
}

BigInt BigInt::multiply(const BigInt &a, const BigInt &b)
{
    if(a.num == "0")
         *this = 0;
    else if(b.num == "0")
         *this = 0;
    else
    {
        *this = 0;
        if(a.num.size() > b.num.size())
        {
            for(int i = b.num.size() - 1; i > 0; i--)
            {
                for(char c = '0'; c < b.num[i]; c++)
                {
                    *this = *this + a;
                }
                this->num = "0" + this->num;
            }
            for(char c = '0'; c < b.num[0]; c++)
            {
                *this = *this + a;
            }
        }
        else
        {
            for(int i = a.num.size() - 1; i > 0; i--)
            {
                for(char c = '0'; c < a.num[i]; c++)
                {
                    *this = *this + b;
                }
                this->num = "0" + this->num;
            }
            for(char c = '0'; c < a.num[0]; c++)
            {
                *this = *this + b;
            }
        }
    }
    return *this;
}

string rev(string s)
{
    string rs = s;
    for(int i = 0; i < s.size(); i ++)
    {
        rs[i] = s[s.size() - i - 1];
    }
    return rs;
}


string BigInt::to_string()
{
    return rev(num);
}

BigInt BigInt::operator+(const BigInt &a) const
{
    BigInt ret;
    ret.add(a, *this);
    return ret;
}

BigInt BigInt::operator*(const BigInt &a) const
{
    BigInt ret;
    ret.multiply(a, *this);
    return ret;
}

bool BigInt::operator==(const BigInt &a) const
{
    return(a.num == this->num && a.positive == this->positive);
}

bool BigInt::operator!=(const BigInt &a) const
{
    return !(*this == a);
}

ostream& operator<<(ostream &out, const BigInt &b)
{
    for(int i = b.num.size() - 1; i >= 0; i--)
        out << b.num[i];
    return out;
}

long long BigInt::digit_sum()
{
    long long ret = 0;
    for(char c : num)
        ret += c - '0';
    return ret;
}

int BigInt::log10()
{
    return num.size();
}

BigInt::~BigInt()
{
    //dtor
}
