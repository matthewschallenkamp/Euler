#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;


int main()
{
  long long digits = 0;

  for (int i = 1; i < 1000; i++)
  {
    long long mult = 1;

    for (int pow = 0; pow < i; pow++)
    {
      mult *= i;
      mult %= 10000000000;
    }
    digits += mult;
    digits %= 10000000000;
  }

  cout << "The last 10 digits are " << digits << "." << endl;

  return 0;
}
