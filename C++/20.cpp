#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

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
  vector<int> v = { 1 };

  for (int i = 1; i < 100; i++)
  {
    for (auto& item : v) item *= i;

    for (int i = 1; i < v.size(); i++)
    {
      while (v[i - 1] >= 10)
      {
        v[i - 1] -= 10;
        v[i]++;
      }
    }

    while (v.back() >= 10)
    {
      int t = v.back() / 10;
      v.back() %= 10;
      v.push_back(t);
    }

    // for (auto i : v) cout << i;
    // cout << endl;
  }

  int t = 0;

  for (auto i : v) t += i;

  cout << "the sum of the digits was " << t << "." << endl;
  return t;
}
