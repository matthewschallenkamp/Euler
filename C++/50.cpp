#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;


vector<long long>* primes(long long m)
{
  static vector<bool> sieve       = { 0, 0, 1 };
  static vector<long long> primes = { 2 };

  if (m > sieve.size())
  {
    long long last = sieve.size();
    sieve.resize(m, 1);
    long long top = sqrt(sieve.size()) + 1;

    for (int i = 2; i < top; i++)
    {
      if (sieve[i])
      {
        for (int j = i * i; j < m; j += i) sieve[j] = 0;
      }
    }

    for (int i = last; i < m; i++)
    {
      if (sieve[i]) primes.push_back(i);
    }
  }
  return &primes;
}

bool is_prime(long long n)
{
  vector<long long> *ps = primes(n);

  if (find(ps->begin(), ps->end(), n) != ps->end()) return true;

  return false;
}

int main()
{
  // do by length
  int terms      = 2;
  long long best = 0;

  vector<long long> *p = primes(1000000);

  for (int b = 0; b < p->size(); b++)
  {
    // cout << b << endl;
    for (int len = terms; len + b <= p->size(); len++)
    {
      int sum = 0;

      for (int i = b; i < b + len; i++)
      {
        sum += p->at(i);
      }

      if (sum > 1000000) break;

      if (is_prime(sum))
      {
        if (len > terms)
        {
          best  = sum;
          terms = len;
        }
      }
    }
  }
  cout << "the best was " << best << " with " << terms - 1 << " terms." << endl;

  return best;
}
