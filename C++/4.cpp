#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

// biggest palindrome product of 2 3 digit #'s

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

bool palindrome(int n)
{
  vector<int> v = digits(n);

  for (int i = 0; i < v.size(); i++)
  {
    if (!(v.at(i) == v.at(v.size() - i - 1))) return 0;
  }
  return 1;
}

int main()
{
  int m = 0;

  for (int i = 999; i > 99; i--)
    for (int j = 999; j > 99; j--)
    {
      if (palindrome(i * j) && (i * j > m))
      {
        m = i * j;

        // cout << i << " * " << j << " = " << i * j << endl;
      }
    }
  cout << "The largest palindrome was " << m << "." << endl;
  return m;
}
