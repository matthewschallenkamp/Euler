#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;


int nth_prime(int n)
{
  static set<int> primes = { 2, 3, 5, 7, 11, 13 };

  if (n > (primes.size()))
  {
    for (int i = *(primes.rbegin()); primes.size() < n + 10; i += 2)
    {
      bool prime = true;

      for (auto it : primes)
      {
        if (i % it == 0)
        {
          prime = false;
          break;
        }

        if (it * it > i + 10) break;
      }

      if (prime) primes.insert(i);
    }
  }
  set<int>::iterator it = primes.begin();

  for (int i = 1; i < n; i++) it++;
  return *it;
}

// gets from end for easier things.

int next_prime()
{
  static set<int> primes = { 2, 3 };
  static int n           = 2;

  n++;

  if (n > (primes.size()))
  {
    for (int i = *(primes.rbegin()); primes.size() < n; i += 2)
    {
      bool prime = true;

      for (auto it : primes)
      {
        if (i % it == 0)
        {
          prime = false;
          break;
        }

        if (it * it > i + 10) break;
      }

      if (prime) primes.insert(i);
    }
  }
  return *primes.rbegin();
}

int main()
{
  long long total = 5; // inital 2 primes
  long long p     = next_prime();

  for (int i = 3; p < 2000000; i++)
  {
    // cout << i << endl;
    total += p;
    p      = next_prime();
  }
  cout << "The total was " << total << "." << endl;
  return total;
}
