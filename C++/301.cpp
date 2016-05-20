#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip>


using namespace std;

typedef unsigned long long ull;


int main()
{
  ull total = 0;

  for (long long n = 1; n <= 1073741824; n++)
  {
    //if (!(n % 1000000)) cout << n << endl;
    total += ((n xor 2 * n xor 3 * n) == 0);
  }
  cout << "The total was " << total << "." << endl;
  return 0;
}
