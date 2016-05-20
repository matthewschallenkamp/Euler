#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include "BigInt.h"

using namespace std;


int main()
{
  int n;

  vector<vector<int> > chains;
  ifstream fin;
  fin.open("keylog.txt");

  while (fin >> n)
  {
    int a = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int c = n;
    chains.push_back({ c, b, a });
  }
  bool xbeforey[10][10] = { 0 };

  for (auto chain : chains)
  {
    xbeforey[chain[0]][chain[1]] = 1;
    xbeforey[chain[1]][chain[2]] = 1;
    xbeforey[chain[0]][chain[2]] = 1;
  }

  cout << "    0 1 2 3 4 5 6 7 8 9 " << endl;

  for (int i = 0; i < 10; i++)
  {
    cout << i << " | ";

    for (int j = 0; j < 10; j++)
    {
      if (i != j) cout << xbeforey[i][j] << " ";
      else cout << "  ";
    }
    cout << endl;
  }
  
  return 0;
}
