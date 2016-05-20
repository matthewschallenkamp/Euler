#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;


struct divisor
{
  long long prime;
  short     power;
};

vector<divisor>::iterator findp(vector<divisor>& d, long long prime)
{
  for (vector<divisor>::iterator it = d.begin(); it != d.end(); it++)
  {
    // cout << it->prime;
    if (it->prime == prime) return it;
  }
  return d.end();
}

vector<divisor>& operator+(vector<divisor>& l, vector<divisor>& r)
{
  // r.reserve(l.size()+r.size());
  for (auto i : l)
  {
    // cout << "finding " << i.prime << "    ";
    vector<divisor>::iterator it = findp(r, i.prime);

    if (it != r.end())
    {
      // cout << " found\n";
      it->power += i.power;
    }
    else
    {
      // cout << " not found\n";
      r.push_back(i);
    }
  }
  return r;
}

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

vector<divisor>prime_divisors(long long n)
{
  vector<divisor> divisors;
  divisor div;
  vector<long long> p = *primes(sqrt(n) + 1);

  // cout << "got primes" << endl;
  for (int i = 0; i < p.size() && n > 1; i++)
  {
    // cout << "testing " << p[i] << endl;
    div.prime = p[i];
    div.power = 0;

    while (n % p[i] == 0)
    {
      n /= p[i];
      div.power++;
    }

    if (div.power > 0) divisors.push_back(div);
  }

  if (n != 1)
  {
    div.prime = n;
    div.power = 1;
    divisors.push_back(div);
  }
  return divisors;
}

int main()
{
  // first four consecutive numbers with four prime factors each
  vector<divisor> a, b, c, d;
  a = prime_divisors(1);
  b = prime_divisors(2);
  c = prime_divisors(3);
  d = prime_divisors(4);
  bool found = false;
  int  i     = 5;

  for (; !found; i++)
  {
    a = b;
    b = c;
    c = d;
    d = prime_divisors(i);

    if ((a.size() >= 4)
        && (b.size() >= 4)
        && (c.size() >= 4)
        && (d.size() >= 4)) found = true;
  }
  cout << "The smallest number was " << i - 4 << "." << endl;

  return 0;
}
