#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool pandigital(string s)
{
    sort(s.begin(), s.end());
    return s == "123456789";
}

string sadd(string a, string &b)
{
    bool carry = 0;
    if(b.length() < a.length())
        b.resize(a.length(), '0');
    if(a.length() < b.length())
        a.resize(b.length(), '0');
    for(int i = 0; i < a.length(); i++)
    {
        a[i] += b[i] - '0';
        if(carry)
            a[i]++;
        carry = false;
        if(a[i] > '9')
        {
            a[i] -= 10;
            carry = true;
        }
    }
    if(carry)
        a.push_back('1');
    return a;
}

int main()
{
    string a = "0", b = "1", c;
    bool f = 0;
    long long i;
    for(i = 0; 1; i++)
    {
        if( i % 1000 == 0)
            cout << i << endl;
        if(pandigital(a.substr(0,9)))
        {
            cout << "first digits were pandigital for " << i << endl;
            f = 1;
        }
        if(a.length() >= 9 && pandigital(a.substr(a.length()-9, 9)))
        {
            cout << "last digits were pandigital for " << i << endl;
            if(f)
                break;
        }
        a.swap(c);
        a = sadd(c,b);
        b.swap(c);
        f = 0;
    }

    cout << i << endl;

    return 0;
}

