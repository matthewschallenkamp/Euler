#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct divisor
{
  long long prime;
  short     power;
};

bool operator<(divisor l, divisor r)
{
  if (l.prime != r.prime) return l.prime < r.prime;

  if (l.power != r.power) return l.power < r.power;

  return false;
}

bool operator==(vector<divisor>l, vector<divisor>r)
{
  divisor& d = l.front();

  for (divisor dr : r)
  {
    bool found = 0;

    for (divisor& dl : l)
      if (dr.prime == dl.prime)
      {
        d     = dl;
        found = 1;
        break;
      }

    if (!found) return false;

    if (dr.power != d.power) return false;
  }
  return true;
}

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

vector<divisor>prime_divisors(long long n)
{
  vector<divisor> divisors;
  divisor div;
  vector<long long> p = *primes(sqrt(n) + 1);

  for (int i = 0; i < p.size() && n > 1; i++)
  {
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

int gcd(set<int>& v)
{
  for (int i = *(v.begin()); i > 0; i--)
  {
    bool is = 1;

    for (auto n : v)
    {
      if (n % i != 0)
      {
        is = false;
        break;
      }
    }

    if (is) return i;
  }
  return 1;
}

const int M = 100;

int main()
{
  // how many terms are in a^b for 2 - 100 each
  set<vector<divisor> > terms = {};
  vector<divisor> div = {}, temp = {};

  for (int a = 2; a <= M; a++)
  {
    div = prime_divisors(a);
    cout << a << " has divisors ";

    for (auto i : div) cout << i.prime << ":" << i.power << " ";
    cout << endl;
    int added = terms.size();

    for (int b = 2; b <= M; b++)
    {
      temp = div;

      for (divisor& d : temp) d.power *= b;

      terms.insert(temp);
    }
    added -= terms.size();
    added *= -1;
    cout << "added " << added << " terms" << endl;
  }

  cout << "The sum was " << terms.size() << "." << endl;
  return terms.size();
}
