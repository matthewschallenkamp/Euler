#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int collatz(long long n)
{
  if (n == 1) return 1;
  else if ((n % 2) == 0) return 1 + collatz(n / 2);
  else return 1 + collatz(3 * n + 1);
}

int main()
{
  long long m = 0, t, n;

  for (long long i = 1; i < 1000000; i++)
  {
    t = collatz(i);

    // cout << i << " gave " << t << endl;
    n = m > t ? n : i;
    m = m > t ? m : t;
  }
  cout << "The longest sequence was " << n << " with " << m << " length." << endl;
  return n;
}
