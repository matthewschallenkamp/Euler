#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<long long>* primes(long long m)
{
  m++;
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
        // cout << "seiving " << i << endl;
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
  vector<long long> *ps = primes(n + 1);

  if (find(ps->begin(), ps->end(), n) != ps->end()) return true;

  return false;
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

bool rotates_prime(int n)
{
  vector<int> d = digits(n);

  for (auto i : d)
    if (i % 2 == 0) return false;

  rotate(d.begin(), d.begin() + 1, d.end());

  int rotated = number(d);

  while (rotated != n)
  {
    // cout << rotated << endl;
    if (!is_prime(rotated)) return false;

    rotate(d.begin(), d.begin() + 1, d.end());
    rotated = number(d);
  }
  return true;
}

int main()
{
  long long sum = 2;
  long long c   = 1; // count two specially

  vector<long long> *p = primes(1000000);

  for (long long n : *p)
  {
    if (rotates_prime(n))
    {
      // cout << n << " rotates" << endl;
      sum += n;
      c++;
    }
  }
  cout << "The count was " << c << "." << endl;
  cout << "The sum was " << sum << "." << endl;

  return c;
}
