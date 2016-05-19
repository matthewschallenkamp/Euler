#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> digits(int n)
{
    vector<int> m;
    while(n > 0)
    {
        m.push_back(n % 10);
        n /= 10;
    }
    return m;
}

int number(vector<int> m)
{
    int n = 0;
    while(m.size())
    {
        n *= 10;
        n += m.back();
        m.pop_back();
    }
    return n;
}

bool is_prime(int n)
{
    static set<int> primes = {2, 3, 5, 7, 11, 13};
    if(n > *(primes.rbegin()))
    {
        for(int i = *(primes.rbegin()); i < n+10; i += 2)
        {
            bool prime = true;
            for(auto it : primes)
            {
                if(i % it == 0)
                {
                    prime = false;
                    break;
                }
                if(it*it > n + 10)
                    break;
            }
            if(prime)
                primes.insert(i);
        }
        //build more upto n
    }
    if(primes.find(n) != primes.end())
        return 1;
    else
        return 0;
}

bool truncatable(int n)
{
    vector<int> v;
    if(!is_prime(n))
        return 0;

    v = digits(n);
    v.pop_back();
    while(v.size())
    {
        //cout << "truncated " << number(v) << endl;
        if(!is_prime(number(v)))
            return 0;
        v.pop_back();
    }

    v = digits(n);
    v.erase(v.begin());
    while(v.size())
    {
        //cout << "truncated " << number(v) << endl;
        if(!is_prime(number(v)))
            return 0;
        v.erase(v.begin());
    }
    return 1;
}


int main()
{
    long long total = 0;
    int temp = 0;
    vector<int> v;
    for(int i = 10; v.size() < 11; i++)
    {
        //cout << "testing " << i << endl;
        if(truncatable(i))
        {
            cout << i << " was truncatable" << endl;
            v.push_back(i);
        }
    }
    cout << "total was " << accumulate(v.begin(), v.end(), 0);
    return 0;
}
