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

  return binary_search(ps->begin(), ps->end(), n);
}

vector<int>digits(long long n)
{
  vector<int> m;

  while (n > 0)
  {
    m.push_back(n % 10);
    n /= 10;
  }
  return m;
}

int number(vector<int>m)
{
  int n = 0;

  while (m.size())
  {
    n *= 10;
    n += m.back();
    m.pop_back();
  }
  return n;
}

vector<long long>permutes(long long num)
{
  vector<int> d = digits(num);
  vector<long long> p;
  sort(d.begin(), d.end());
  p.push_back(number(d));

  while (next_permutation(d.begin(), d.end())) p.push_back(number(d));
  return p;
}

vector<long long>filter_prime(vector<long long>p)
{
  vector<long long> ret;

  for (auto n : p)
    if (is_prime(n)) ret.push_back(n);
  return ret;
}

vector<long long>filter_length(vector<long long>p, int l)
{
  vector<long long> ret;

  for (auto n : p)
    if (digits(n).size() == l) ret.push_back(n);
  return ret;
}

int main()
{
  vector<long long> perm;

  for (int n = 1000; n < 3000; n++)
  {
    perm = permutes(n);
    perm = filter_prime(perm);
    perm = filter_length(perm, 4);

    if (perm.size() < 3) continue;

    // should be sorted already
    for (auto a : perm)
      for (auto b : perm)
        for (auto c : perm)
        {
          if ((n == c) && (a - b == b - c) && (a - b > 0) && n != 1487)
          {
            cout << "The sequence starting with " << n << ": " << endl;
            cout << c << b << a << endl;
            return n;
          }
        }
  }

  return 0;
}
