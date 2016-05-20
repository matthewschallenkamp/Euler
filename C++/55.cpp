#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include "BigInt.h"

using namespace std;

bool palindrome(string s)
{
  string rs = s;

  for (int i = 0; i < s.size(); i++)
  {
    rs[i] = s[s.size() - i - 1];
  }
  return s == rs;
}

bool lychrel(long long n)
{
  BigInt num(n), temp;
  string s;

  // cout << num << endl;
  for (int i = 1; i <= 50; i++)
  {
    s = num.to_string();
    reverse(s.begin(), s.end());
    temp = num + BigInt(s);
    num  = temp;

    // cout << num << endl;
    if (palindrome(num.to_string()))
    {
      // cout << n << " took " << i << " iterations" << endl;
      return false;
    }
  }

  // cout << n << " is lychrel" << endl;
  return true;
}

int main()
{
  string i, m;

  int tot = 0;

  for (int i = 1; i < 10000; i++)
  {
    if (lychrel(i)) tot++;
  }

  cout << "The total was " << tot << "." << endl;
  return 0;
}
