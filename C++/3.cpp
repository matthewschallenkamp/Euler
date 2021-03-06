#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;


// biggest prime factor of 600851475143
bool is_prime(int n)
{
  static set<int> primes = { 2, 3, 5, 7, 11, 13 };

  if (n > *(primes.rbegin()))
  {
    for (int i = *(primes.rbegin()); i < n + 10; i += 2)
    {
      bool prime = true;

      for (auto it : primes)
      {
        if (i % it == 0)
        {
          prime = false;
          break;
        }

        if (it * it > n + 10) break;
      }

      if (prime) primes.insert(i);
    }

    // build more upto n
  }

  return primes.find(n) != primes.end();
}

int main()
{
  int i = 0;

  for (i = sqrt(600851475143) + 1; i > 2; i--)
  {
    if ((600851475143 % i == 0) && is_prime(i))
    {
      cout << "The greatest prime factor was " << i << "." << endl;
      break;
    }
  }
  return i;
}
