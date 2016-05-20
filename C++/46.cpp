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

int main()
{
  bool found = false;

  vector<long long> *p = primes(1000);
  int i                = 3;

  for (; !found; i += 2)
  {
    // cout << "testing " << i << endl;
    bool found_this = false;

    if (i > p->size()) p = primes(i + 1000);

    for (auto n : *p)
    {
      if (n > i) break;
      int s = (sqrt(i - n) / 2);

      if (s < 0) s = 0;

      for (; (2 * s * s) + n < i; s++) ;

      if ((2 * s * s) + n == i)
      {
        // cout << s << " * 2 * " << s << " + " << n << " = " << i << endl;
        found_this = true;
        break;
      }
    }

    if (!found_this) found = true;
  }

  cout << "The first number to fail the conjecture was " << i - 2 << "." << endl;

  return 0;
}
