#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

double ncr(long long n, long long r)
{
  double total   = 1;
  long long oldn = n;

  while (n > r) total *= n--;
  r = oldn - r;

  while (r > 1) total /= r--;
  return total;
}

int main()
{
  int sum = 0;

  for (int n = 1; n <= 100; n++)
  {
    for (int r = 0; r <= n; r++)
    {
      if (ncr(n, r) > 1000000)
      {
        sum += 1;

        // cout << n << " c " << r << " = " << ncr(n, r) << endl;
      }
    }
  }

  cout << "The total over 1 mill was " << sum << "." << endl;
  return 0;
}
