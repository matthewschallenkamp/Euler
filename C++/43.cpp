#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

bool checkdiv(const vector<int>& it, int div)
{
  int n   = it.size();
  int num = 0;

  num += it[n - 3];
  num *= 10;
  num += it[n - 2];
  num *= 10;
  num += it[n - 1];
  return num % div == 0;
}

vector<vector<int> >children(vector<int>& parent)
{
  vector<vector<int> > ret;

  for (int i = 0; i <= 9; i++)
  {
    if (find(parent.begin(), parent.end(), i) == parent.end())
    {
      parent.push_back(i);
      ret.push_back(parent);
      parent.pop_back();
    }
  }
  return ret;
}

int main()
{
  long long sum = 0;

  vector<vector<int> > newpossibles, possibles =
  { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 }, { 9 } };
  vector<int> div = { 1, 1, 1, 2, 3, 5, 7, 11, 13, 17 };

  for (int i = 1; i < 3; i++)
  {
    for (auto& num : possibles)
    {
      for (auto& add : children(num))
      {
        newpossibles.push_back(add);
      }
    }
    possibles.clear();
    possibles.swap(newpossibles);
  }

  for (int i = 3; i <= 9; i++)
  {
    for (auto& num : possibles)
    {
      for (auto& add : children(num))
      {
        if (checkdiv(add, div[i])) newpossibles.push_back(add);
      }
    }
    possibles.clear();
    possibles.swap(newpossibles);
  }

  for (int i = 0; i < 10; i++)
  {
    sum *= 10;

    for (auto num : possibles)
    {
      sum += num[i];
    }
  }
  cout << "The sum was " << sum << "." << endl;
  return sum;
}
