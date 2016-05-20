#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// list all numbers that can be written as 5th powers of their digits
// ignore 1-10
// upper bound
// 9^5 = 59049
// 6 digits * 59049 ~= 300000
// 7 digits * 59049 ~= 400000

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

int main()
{
  int sum = 0, dfive;

  vector<int> d;

  for (int i = 10; i < 1000000; i++)
  {
    dfive = 0;
    d     = digits(i);

    for (int n : d) dfive += n * n * n * n * n;

    if (dfive == i)
    {
      cout << i << " is the sum of 5th powers of its digits" << endl;
      sum += i;
    }
  }
  cout << "The sum was " << sum << "." << endl;
  return sum;
}
