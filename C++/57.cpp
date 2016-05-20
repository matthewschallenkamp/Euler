#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include "BigInt.h"

using namespace std;

struct frac
{
  BigInt num, denom;
};

ostream& operator<<(ostream& out, frac f)
{
  out << f.num << " / " << f.denom;
  return out;
}

frac reciprocal(frac f)
{
  auto temp = f.num;

  f.num   = f.denom;
  f.denom = temp;
  return f;
}

frac operator+(frac f, long long a)
{
  auto temp  = (f.denom * a);
  auto temp2 = temp + f.num;

  f.num = temp2;
  return f;
}

frac frac_from_seq(vector<long long>seq)
{
  frac f;

  f.num   = 0;
  f.denom = 1;

  for (int i = seq.size() - 1; i >= 0; i--)
  {
    f = f + seq[i];
    f = reciprocal(f);
  }
  f = reciprocal(f);
  return f;
}

int main()
{
  // going for sqrt 2
  vector<long long> seq = { 1 };
  int c                 = 0;

  for (int i = 0; i < 1000; i++)
  {
    // cout << i << endl;
    seq.push_back(2);
    frac f = frac_from_seq(seq);

    if (f.num.log10() > f.denom.log10()) c++;
  }
  cout << "The count of topheavy expansions was " << c << "." << endl;
  return c;
}
