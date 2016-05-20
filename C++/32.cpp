#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

void digit(multiset<int>& m, int n)
{
  while (n > 0)
  {
    m.insert(n % 10);
    n /= 10;
  }
}

int pandigital(int x, int y)
{
  static set<int> s;
  static multiset<int> pan = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  multiset<int> ret;
  digit(ret, x);
  digit(ret, y);
  digit(ret, x * y);

  if (ret == pan)
  {
    return x * y;
  }
  else return 0;
}

int main()
{
  long long total = 0;
  int temp        = 0;

  set<int> added;

  for (int x = 1; x < 10000; x++)
  {
    // cout << "working on " << x << endl;
    if (x < 100);
    else if (x < 1000)
    {
      for (int y = 10; y < x; y++)
      {
        temp = pandigital(x, y);

        // if (temp) cout << "x: " << x << " and y: " << y << " gave " << temp << endl;

        if (added.find(temp) == added.end())
        {
          total += temp;
          added.insert(temp);
        }
      }
    }
    else
    {
      for (int y = 1; y < 10; y++)
      {
        temp = pandigital(x, y);

        // if (temp) cout << "x: " << x << " and y: " << y << " gave " << temp << endl;

        if (added.find(temp) == added.end())
        {
          total += temp;
          added.insert(temp);
        }
      }
    }
  }
  cout << "total was " << total << "." << endl;
  return total;
}
