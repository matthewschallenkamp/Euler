#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

// 100001th prime

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

int main()
{
  int p = nth_prime(10001);

  cout << "The 10001st prime is " << p << "." << endl;
  return p;
}
