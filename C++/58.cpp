#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <cmath>

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
  vector<long long> *ps = primes(2*n);

  if (binary_search(ps->begin(), ps->end(), n)) return true;

  return false;
}

//much faster
bool is_prime_td(long long n) {
	//special case - we know we will have no evens and no 1's
  if (n < 9) return true;
  if (n % 3 == 0) return false;

  long long counter = 5;
  while ((counter * counter) <= n)
  {
    if (n % counter == 0) return false;
    counter += 2;
  }

  return true;
}

int main()
{
	bool found = false;
	long long count = 0;
	long long current = 1;
	long long i;
	for(i = 1; !found; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			current += 2*i;
			count += is_prime_td(current);
		}
		//cout << "side " << i << " count " << count << " possible " << 4*i << endl;
		found = count * 10 <= 4*i;
	}
	cout << "the side length was " << 2*i - 1 << endl;
}