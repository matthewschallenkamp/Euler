#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;



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

/*
vector<int> list_prime_factor_powers(int n)
{
    vector<long long> *p = (primes(1000));
    vector<int> pows;
    for(int i = 0; i < p->size(); i++)
    {
        if(p->at(i) > n) break;
        int temp = 0;
        while(n % p->at(i) == 0)
        {
            temp++;
            n /= p->at(i);
        }
        if(temp) pows.push_back(temp);
    }
    if(n != 1) pows.push_back(1);
    return pows;
}*/

int totient(int n)
{
    vector<long long> *p = primes(1000);
    int tot = n;
    for(auto prime : *p)
    {
        if(n % prime == 0)
        {
            tot /= prime;
            tot *= (prime-1);
        }
    }
    return tot;
}

int main()
{
    vector<long long> *p = primes(1000);
    double bestrat = 1, rat;
    int best = 1, current;
    for(int i = 2; i < 1000000; i++)
    {
        if(i % 10000 == 0) cout << i << endl;
        rat = (double)i / (double)totient(i);
        if(rat > bestrat)
        {
            cout << "new best " << i << " ratio " << rat;
            bestrat = rat;
            best = i;
        }
    }
    cout << "The best was " << best << " with ratio " << bestrat << endl;
    return 0;
}
