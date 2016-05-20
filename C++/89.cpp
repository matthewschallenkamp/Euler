#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include "BigInt.h"

using namespace std;

long long roman_to_ll(string s)
{
  long long tot = 0;

  for (int i = 0; i < s.size(); i++)
  {
    switch (s[i])
    {
    case 'I':
      if (i < s.size() - 1)
        if ((s[i + 1] == 'V') || (s[i + 1] == 'X')) tot -= 2;
      tot += 1;
      break;

    case 'V':
      tot += 5;
      break;

    case 'X':
      if (i < s.size() - 1)
        if ((s[i + 1] == 'L') || (s[i + 1] == 'C')) tot -= 20;
      tot += 10;
      break;

    case 'L':
      tot += 50;
      break;

    case 'C':
      if (i < s.size() - 1)
        if ((s[i + 1] == 'D') || (s[i + 1] == 'M')) tot -= 200;
      tot += 100;
      break;

    case 'D':
      tot += 500;
      break;

    case 'M':
      tot += 1000;
      break;
    }
  }
  return tot;
}

string ll_to_roman(long long n)
{
  string s;

  while (n >= 1000)
  {
    s += "M";
    n -= 1000;
  }

  if (n >= 900)
  {
    s += "CM";
    n -= 900;
  }

  while (n >= 500)
  {
    s += "D";
    n -= 500;
  }

  if (n >= 400)
  {
    s += "CD";
    n -= 400;
  }

  while (n >= 100)
  {
    s += "C";
    n -= 100;
  }

  if (n >= 90)
  {
    s += "XC";
    n -= 90;
  }

  while (n >= 50)
  {
    s += "L";
    n -= 50;
  }

  if (n >= 40)
  {
    s += "XL";
    n -= 40;
  }

  while (n >= 10)
  {
    s += "X";
    n -= 10;
  }

  if (n >= 9)
  {
    s += "IX";
    n -= 9;
  }

  while (n >= 5)
  {
    s += "V";
    n -= 5;
  }

  if (n >= 4)
  {
    s += "IV";
    n -= 4;
  }

  while (n >= 1)
  {
    s += "I";
    n -= 1;
  }
  return s;
}

int main()
{
  string   i, m;
  ifstream fin;

  fin.open("roman.txt");
  long long total = 0;
  long long temp  = 0;

  while (fin >> i)
  {
    temp = roman_to_ll(i);
    m    = ll_to_roman(temp);
    //cout << temp << " or " << m << " was " << i << endl;
    //cout << "saved " << i.length() - m.length() << " letters" << endl;
    total += i.length() - m.length();
  }
  cout << "The total amount saved was " << total << "." << endl;
  return 0;
}
