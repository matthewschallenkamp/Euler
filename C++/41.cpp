#include <iostream>
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

void digit(multiset<int>& m, int n)
{
  while (n > 0)
  {
    m.insert(n % 10);
    n /= 10;
  }
}

bool pandigital(int x)
{
  multiset<int> pan = {};

  for (int i = digits(x).size(); i > 0; i--)
  {
    pan.insert(i);
  }
  multiset<int> ret = {};
  digit(ret, x);

  if (ret == pan)
  {
    return true;
  }
  else return false;
}

int main()
{
  // 1+2+3+4+5+6+7+8 = 36 is divisible by 3
  // 1+2+3+4+5+6+7+8+9 = 45 is divisible by 3
  // we know that the prime will be length 4 or 7 because lengths 8 and 9 are both divisible by
  // three
  vector<long long> *ps = primes(10000000);

  long long largest = 0;

  // cout << "here" << endl;

  for (long long n : *ps)
  {
    // cout << n << endl;
    if (pandigital(n))
    {
      // cout << n << endl;
      largest = n;
    }
  }

  cout << "The largest was " << largest << "." << endl;

  return largest;
}
