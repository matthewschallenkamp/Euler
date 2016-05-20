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

    for (long long i = 2; i < top; i++)
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

  if (binary_search(ps->begin(), ps->end(), n)) return true;

  return false;
}

vector<vector<bool> >filter_length(vector<vector<bool> >p, int l)
{
  vector<vector<bool> > ret;

  for (auto n : p)
    if (n.size() == l) ret.push_back(n);
  return ret;
}

set<vector<bool> >replaces(int digits, int replaced)
{
  set<vector<bool> > oldpossibles, newpossibles;

  if (replaced == 0)
  {
    vector<bool> b;
    b.resize(digits, 0);
    newpossibles.insert(b);
    return newpossibles;
  }
  oldpossibles = replaces(digits, replaced - 1);

  for (auto bits : oldpossibles)
  {
    for (auto && b : bits)
    {
      if (!b)
      {
        b = 1;
        newpossibles.insert(bits);
        b = 0;
      }
    }
  }
}

vector<int>digits(int n)
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

int main()
{
  bool found = false;

  vector<long long>    *p = primes(10);
  vector<vector<bool> > repl;
  int last_len = 0;
  long long prime;

  for (int i = 0; i < p->size() && !found; i++)
  {
    prime = p->at(i);
    vector<int> d = digits(prime);

    if (d.size() != last_len)
    {
      cout << "getting primes upto " << pow(10, last_len + 2) << endl;
      p = primes(pow(10, last_len + 2));

      // cout << "increasing mask length to " << d.size() << endl;
      repl.clear();

      for (int replaced = 1; replaced <= d.size(); replaced++)
      {
        for (auto bits : replaces(d.size(), replaced))
        {
          repl.push_back(bits);
        }
      }
      last_len = d.size();

      // cout << "running tests " << endl;
    }

    // cout << "testing " << prime << endl;
    // for(auto i : d)
    //  cout << " " << i;
    // cout << endl;
    for (auto mask : repl)
    {
      int pcount = 0;

      for (int replacer = 0; replacer < 10; replacer++)
      {
        vector<int> dmod = d;

        for (int i = 0; i < mask.size(); i++)
        {
          if (mask[i]) dmod[i] = replacer;
        }

        // cout << "replaced some, got " << number(dmod) << endl;
        if (is_prime(number(dmod)) && (dmod.back() != 0))
        {
          // cout << number(dmod) << " ";
          pcount++;
        }
      }

      // cout << "got a pcount " << pcount << endl;
      if (pcount > 7)
      {
        cout << "Found it " << prime << endl;
        cout << "mask ";

        for (auto bit : mask) cout << bit;
        cout << endl << "numbers " << endl;

        for (int replacer = 0; replacer < 10; replacer++)
        {
          vector<int> dmod = d;

          for (int i = 0; i < mask.size(); i++)
          {
            if (mask[i]) dmod[i] = replacer;
          }
          cout << number(dmod) << " " << (is_prime(number(dmod)) ? "is prime" : "") << endl;
        }
        found = true;
        break;
      }
    }

    if (found) break;
  }
  return prime;
}
