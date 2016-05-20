#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

vector<int>digits(long long n)
{
  vector<int> m;

  while (n > 0)
  {
    m.push_back(n % 10);
    n /= 10;
  }
  return m;
}

void digit(multiset<int>& m, int n)
{
  while (n > 0)
  {
    m.insert(n % 10);
    n /= 10;
  }
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

bool pandigital(int x)
{
  static set<int> s;
  const multiset<int> pan = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  multiset<int> ret;
  digit(ret, x);

  if (ret == pan)
  {
    return true;
  }
  else return false;
}

int main()
{
  long long best = 0;
  long long c    = 0;

  for (int i = 1; i < 10000; i++)
  {
    vector<int> pal;
    int pandigit;

    for (int mult = 1; digits(i).size() * mult < 10; mult++)
    {
      vector<int> d = digits(i * mult);
      d = vector<int>(d.rbegin(), d.rend());

      for (int n : d) pal.push_back(n);

      pandigit = number(vector<int>(pal.rbegin(), pal.rend()));

      if (pandigital(pandigit))
      {
        c++;

        // cout << i << " >^ " << mult << " = " << pandigit << endl;

        if (pandigit > best) best = pandigit;
      }
    }
  }

  cout << "The count was " << c << "." << endl;
  cout << "The best was " << best << "." << endl;

  return best;
}
