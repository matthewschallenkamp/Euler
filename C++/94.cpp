#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

long long heron(long long a, long long b)
{
  long long ht2 = a * a - (b * b / 4);
  long long ht  = sqrt(ht2);

  if ((ht * ht == ht2) && !(b % 2)) return a + b + a;

  return 0;
}

int main()
{
  unsigned long long total = 0;
  long long temp           = 0;

  for (long long t = 2; 3 * t < 1000000000; t++)
  {
    // if(!(t % 1000000))
    // cout << t << " " << total << endl;
    long long b = t - 1;
    temp = heron(t, b);

    //if (temp) cout << t << " " << t << " " << b << " " << temp << endl;
    total += temp;
    b      = t + 1;
    temp   = heron(t, b);

    //if (temp) cout << t << " " << t << " " << b << " " << temp << endl;
    total += temp;
  }
  total += heron(333333334, 333333332);
  cout << "The total of integer perimeters was " << total << "." << endl;
  return total;
}
