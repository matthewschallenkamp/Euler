#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include "BigInt.h"
#include "BigInt.cpp"

using namespace std;

int main()
{
  int dmax = 0, curr = 0;
  for(int i = 0; i < 100; i++)
  {
    BigInt acc(1);
    BigInt a(i);
    for(int j = 1; j < 100; j++)
    {
      acc = a * acc;
      curr = acc.digit_sum();
      dmax = max(dmax, curr);
    }
  }
  cout << dmax << endl;
}
