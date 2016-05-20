#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

// find the one pythagorean triplet a+b+c=1000

int main()
{
  for (int a = 1; a < 1000 - 1; a++)
    for (int b = a; b < 1000; b++)
    {
      if (((a * a) + (b * b)) == (1000 - a - b) * (1000 - a - b))
      {
        cout << "The triplet was " << a << " " << b << " " << (1000 - a - b);
        cout << " = " << (1000 - a - b) * a * b << endl;
        return (1000 - a - b) * a * b;
      }
    }
  return 0; // fail
}
