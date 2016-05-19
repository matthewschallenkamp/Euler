#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

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


int main()
{
    int ct = 0;
    vector<long long> *p = primes(10000);
    set<int> nums;
    cout << "biggest prime used " << p->back() << endl;
    for(int f = 0; p->at(f)*p->at(f)*p->at(f)*p->at(f) < 50000000; f++)
    {
        cout << f << ": " << p->at(f) << endl;
        long long quad = p->at(f)*p->at(f)*p->at(f)*p->at(f);
        for(int t = 0; p->at(t)*p->at(t)*p->at(t) + quad < 50000000; t++)
        {
            long long triple = p->at(t)*p->at(t)*p->at(t);
            for(int s = 0; p->at(s)*p->at(s)+triple+quad < 50000000; s++)
            {
                long long square = p->at(s)*p->at(s);
                nums.insert(square + triple + quad);
                ct++;
            }
        }
    }
    cout << "the set size was " << nums.size() << " (right answer)" << endl;
    cout << "the ct was " << ct << " (wrong answer)"<< endl;
    return 0;
}
