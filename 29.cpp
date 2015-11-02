#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct divisor
{
    long long prime = 0;
    short power = 0;
};

bool operator== (vector<divisor> l, vector<divisor> r)
{
    divisor &d = l.front();
    for(divisor dr : r)
    {
        bool found = 0;
        for(divisor &dl : l)
            if(dr.prime == dl.prime)
            {
                d = dl;
                found = 1;
                break;
            }
        if(!found)
            return false;
        if(dr.power != d.power)
            return false;
    }
    return true;
}

bool operator< (vector<divisor> l, vector<divisor> r)
{
    if(l.size() < r.size())
        return true;
    if(l.empty())
        return true;
    for(int i = 0; i < l.size(); i++)
        if(l.at(0).prime < r.at(0).prime)
            return true;
    for(int i = 0; i < l.size(); i++)
        if(l.at(0).power < r.at(0).power)
            return true;
    return true;
}

vector<long long> *primes(long long m)
{
    m++;
    static vector<bool> sieve = {0, 0, 1};
    static vector<long long> primes = {2};
    if(m > sieve.size())
    {
        long long last = sieve.size();
        sieve.resize(m, 1);
        long long top = sqrt(sieve.size()) + 1;
        for(int i = 2; i < top; i++)
        {
            if(sieve[i])
            {
                //cout << "seiving " << i << endl;
                for(int j = i*i; j < m; j+= i)
                    sieve[j] = 0;
            }
        }
        for(int i = last; i < m; i++)
        {
            if(sieve[i])
                primes.push_back(i);
        }
        /*
        for(int i = primes.back()+2; i <= m; i+=2)
        {
            int s = sqrt(i) + 1;
            for(auto p : primes)
            {
                if(p > s)
                {
                    primes.push_back(i);
                    cout << i << "\n";
                    break;
                }
                if(i % p == 0)
                    break;
            }
        }
        */
    }
    return &primes;
}

bool is_prime(long long n)
{
    vector<long long> *ps = primes(n+1);
    if(find(ps->begin(), ps->end(), n) != ps->end())
        return true;
    return false;
}

vector<divisor> prime_divisors(long long n)
{
    vector<divisor> divisors;
    divisor div;
    vector<long long> p = *primes(sqrt(n)+1);
    //cout << "got primes" << endl;
    //for(auto i : p)
      //  cout << "prime " << i << endl;
    for(int i = 0; i < p.size() && n > 1; i++)
    {
        //cout << "testing " << p[i] << endl;
        div.prime = p[i];
        div.power = 0;
        while(n % p[i] == 0)
        {
            n /= p[i];
            div.power++;
        }
        if(div.power > 0)
            divisors.push_back(div);
    }
    if(n != 1)
    {
        div.prime = n;
        div.power = 1;
        divisors.push_back(div);
    }
    return divisors;
}

int gcd(set<int> &v)
{
    int i;
    i = *(v.begin());
    for(; i > 0; i--)
    {
        bool is = 1;
        for(auto n : v)
        {
            if(n % i != 0)
            {
                is = false;
                break;
            }
        }
        if(is)
            return i;
    }
    return 1;
}

const int M = 100;

int main()
{
    //how many terms are in a^b for 2 - 100 each
    vector<vector<divisor> > terms = {};
    vector<divisor> div = {}, temp = {};
    for(int a = 2; a <= M; a++)
    {
        div = prime_divisors(a);
        cout << a << " has divisors ";
        for(auto i : div)
            cout << i.prime << ":" << i.power << " ";
        cout << endl;
        int added = terms.size();
        for(int b = 2; b <= M; b++)
        {
            temp = div;
            for(divisor &d : temp)
                d.power *= b;
            if(find(terms.begin(), terms.end(), temp) == terms.end())
                terms.push_back(temp);
        }
        added -= terms.size();
        added *= -1;
        cout << "added " << added << " terms" << endl;
    }


    /* this dont work
    for(int a = 2; a <= M; a++)
    {

        if(is_prime(a))
        {
            cout << a << " prime gave " << M-1 << " new terms " << endl;
            terms += M-1;
        }
        else
        {
            vector<divisor> d = prime_divisors(a);
            set<int> powers = {};
            for(auto div : d)
                powers.insert(div.power);
            int gcdpow = gcd(powers);
            //based on the gcd of powers, we have to remove 1/that of the terms this part adds
            if(gcdpow != 1)
            {
                int temp = M-M/gcdpow;
                for(int i = gcdpow-1; i > 1; i--)
                    temp -= M/gcdpow;
                cout << a << " gave " << temp << " new terms " << endl;
                terms += temp;
            }
            else
            {
                cout << a << " simple gave " << M - 1 << " new terms " << endl;
                terms += M - 1;
            }
        }
    }*/

    cout << "the sum was " << terms.size();
    return 0;

}
