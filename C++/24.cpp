#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

vector<int>nth_permute_s(int& n, int s)
{
  vector<int> v;

  for (int i = 0; i < s; i++)
  {
    v = nth_permute_s(n, s - 1);

    if (n == 0)
    {
      for (int& num : v)
        if (num >= i) num++;
      v.push_back(i);
      return v;
    }
  }

  if (s == 0) n--;
  return {};
}

int main()
{
  int nth       = 1000000;
  long long num = 0;

  vector<int> v = nth_permute_s(nth, 10);

  for (int i = v.size() - 1; i >= 0; i--)
  {
    num *= 10;
    num += v.at(i);

    // cout << v.at(i);
  }
  cout << "The number is " << num << "." << endl;
  return num;
}
