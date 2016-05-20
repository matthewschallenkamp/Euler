#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

bool is_triangle(long long n)
{
  n *= 2;
  long long sq = sqrt(n);

  for (long long i = sq - 5; i < sq + 5; i++)
  {
    if (i * (i + 1) == n)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  ifstream fin;

  fin.open("words.txt");

  if (!fin)
  {
    cout << "failed to open words.txt" << endl;
    return 0;
  }
  int count = 0;
  long long n;
  string    s;

  while (fin >> s)
  {
    n = 0;

    for (char c : s) n += c - 'A' + 1;

    if (is_triangle(n))
    {
      // cout << s << " gives " << n << " which is " << "a triangle" << endl;
      count++;
    }

    // else cout << s << " gives " << n << " which is " << "not " << "a triangle" << endl;
  }
  cout << "the final count was " << count << "." << endl;

  return count;
}
