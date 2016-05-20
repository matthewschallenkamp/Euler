#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


// sum of even fibonaccis under 4 mill
int main()
{
  long long total = 0;
  long long a     = 1, b = 1, c = 1;

  while (b < 4000000)
  {
    c = b;
    b = a + b;
    a = c;

    // cout << "fib " << b << endl;
    if (b % 2 == 0)
    {
      total += b;
    }
  }
  cout << "The sum was " << total << "." << endl;
  return total;
}
