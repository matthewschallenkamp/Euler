#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int chain(int i)
{
  int acc = 0;

  while (i > 0)
  {
    acc += (i % 10) * (i % 10);
    i   /= 10;
  }
  return acc;
}

bool eightynine(int i)
{
  while (i != 89 && i != 1)
  {
    i = chain(i);
  }
  return i == 89;
}

int main()
{
  int tot = 0;

  for (int i = 1; i < 10000000; i++)
  {
    //if (!(i % 10000)) cout << i << endl;

    if (eightynine(i)) tot++;
  }
  cout << "The total was " << tot << "." << endl;
  return tot;
}
