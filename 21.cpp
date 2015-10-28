#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

struct divisor
{
    long long prime = 0;
    int power = 0;
};

bool operator== (divisor l, divisor r)
{
    return l.prime == r.prime;
}

vector<divisor>::iterator find(vector<divisor> &d, long long prime)
{
    for(vector<divisor>::iterator it = d.begin(); it != d.end(); it++)
    {
        //cout << it->prime;
        if(it->prime == prime)
            return it;
    }
    return d.end();
}

vector<divisor> operator+ (vector<divisor> l, vector<divisor> r)
{
    for(auto i : l)
    {
        //cout << "finding " << i.prime << "    ";
        vector<divisor>::iterator it = find(r, i.prime);
        if(it != r.end())
        {
            //cout << " found\n";
            it->power += i.power;
        }
        else
        {
            //cout << " not found\n";
            r.push_back(i);
        }
    }
    return r;
}

vector<long long> *primes(long long m)
{
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


void print_primes(vector<divisor> d)
{
    for(auto i : d)
        cout << i.prime << "^" << i.power << " ";
}

vector<vector<divisor> > *sieve_divisors(long long n)
{
    //add static in later
    static vector<vector<divisor> > sieve;
    vector<long long> *prime = primes(n);
    vector<divisor> d;
    d.resize(1);
    d[0].power = 1;
    if(n > sieve.size())
    {
        sieve.resize(n+1, {});
        for(auto &item : sieve)
            item.clear();
        //for each prime number
        for(long long p : *prime)
        {
            //cout << "adding divisors for prime " << p << endl;
            d[0].prime = p;
            //for each power of each prime
            for(long long ppow = p; ppow <= n; ppow *= p)
            {
                //cout << "sieveing " << ppow << endl;
                //for each multiple of each power of each prime
                for(long long i = 1; i * ppow <= n; i++)
                {
                    //add one power of that divisor to the list of divisors
                    //cout << "adding " << ppow << " to " << i*ppow << endl;
                    sieve[i*ppow] = d + sieve[i*ppow];
                    //cout << i*ppow << "has ";
                    //print_primes(sieve[i*ppow]);
                }
            }
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
    return &sieve;
}


long long sum_divisors(vector<divisor> d)
{
    long long total = 1;
    for(auto div : d)
    {
        long long psum = 1, prime = div.prime;
        for(int i = 0; i < div.power; i++)
        {
            psum += prime;
            prime *= div.prime;
        }
        total *= psum;
    }
    return total;
}


int main()
{
    vector<vector<divisor> > *d = sieve_divisors(10005);
    long long sum = 0;
    // slow way
    for(long long x = 2; x < 10000; x++)
    {
        //cout << "divisors for " << x << " ";
        //print_primes(d->at(x));
        //cout << endl;
        long long amicable = sum_divisors(d->at(x)) - x;
        if(amicable < 10000 && amicable != x && sum_divisors(d->at(amicable)) - amicable == x)
        {
            cout << x << endl;
            sum += x;
        }
    }
    cout << "sum was " << sum;
    return 0;
}
