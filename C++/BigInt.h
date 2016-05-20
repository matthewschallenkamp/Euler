#ifndef BIGINT_H
#define BIGINT_H
#include <string>
#include <iostream>

using namespace std;

class BigInt
{
public:
        BigInt();
        BigInt(long long a);
        BigInt(int a);
        BigInt(string s);
        ~BigInt();

        long long digit_sum();
        string to_string();
        BigInt multiply(const BigInt &a, const BigInt &b);
        BigInt add(const BigInt &a, const BigInt &b);
        friend ostream& operator<<(ostream &out, const BigInt &b);
        BigInt operator+(const BigInt &a) const;
        BigInt operator*(const BigInt &a) const;
        bool operator==(const BigInt &a) const;
        bool operator!=(const BigInt &a) const;
        int log10();
protected:
private:
        bool positive;
        string num;
};

#endif // BIGINT_H
