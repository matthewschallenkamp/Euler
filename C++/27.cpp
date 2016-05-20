#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <fstream>

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
        for (int j = i * i; j < m; j += i) sieve.at(j) = 0;
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
  if (n < 0) return 0;

  vector<long long> *ps = primes(n);

  return binary_search(ps->begin(), ps->end(), n);
}

int quad_primes(int a, int b)
{
  int i;

  for (i = 0; is_prime(i * i + a * i + b); i++);
  return i;
}

int main()
{
  int p, maxp = 0, maxa, maxb;

  for (int a = -999; a < 999; a++)
  {
    // cout << a << endl;

    for (int b = -999; b < 999; b++)
    {
      p = quad_primes(a, b);

      if (p > maxp)
      {
        maxp = p;
        maxa = a;
        maxb = b;
      }
    }
  }
  cout << "the best quadratic had " << maxp << " primes:" << endl;
  cout << "n * n + " << maxa << " * n + " << maxb << endl;
  cout << "a * b = " << maxa * maxb << endl;
  return maxa * maxb;
}
