#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


int len_dfs_pows(int n, int cut, vector<int>& v)
{
  if (cut == -1) cut = n;

  if (v.size() >= cut) return cut;

  if (v.back() > n) return cut;

  if (v.back() == n) return v.size();

  if (v.back() * pow(2, cut - v.size()) < n) return cut;

  int c;

  for (int i = 0; i < v.size(); i++)
  {
    for (int j = i; j < v.size(); j++)
    {
      if (v[i] + v[j] > v.back())
      {
        v.push_back(v[i] + v[j]);
        c = len_dfs_pows(n, cut, v);
        v.pop_back();

        if (c < cut) cut = c;
      }
    }
  }
  return c;
}

int len_dfs_pows(int n, int cut = -1)
{
  vector<int> v = { 1 };
  return len_dfs_pows(n, cut, v);
}

int main()
{
  int total = 0, c = 3;

  for (int i = 1; i <= 200; i++)
  {
    c = len_dfs_pows(i, c + 1);
    cout << i << " used " << c << " powers " << endl;
    total += c - 1;
  }
  cout << "The total was " << total << "." << endl;
  return total;
}
