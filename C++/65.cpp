#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
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
  // cout << "before " << f << endl;
  auto temp = (f.denom * a);

  // cout << "to add to top " << temp << endl;
  auto temp2 = temp + f.num;

  // cout << "added to top " << temp2 << endl;
  f.num = temp2;

  // cout << "assigned to top " << f << endl;
  return f;
}

frac frac_from_seq(vector<long long>seq)
{
  frac f;

  f.num   = 0;
  f.denom = 1;

  for (int i = seq.size() - 1; i >= 0; i--)
  {
    //cout << "seq " << i << ": " << seq[i] << " | ";
    f = f + seq[i];
    //cout << f << " | ";
    f = reciprocal(f);
    //cout << f << endl;
  }
  f = reciprocal(f);

  // reduce(f);
  return f;
}

int main()
{
  vector<long long> seq = { 2 };
  //cout << seq[0] << " ";

  for (int i = 1; i < 100; i++)
  {
    if (i % 3 == 2) seq.push_back((i / 3 + 1) * 2);
    else seq.push_back(1);

    // cout << seq[i] << " ";
  }

  frac f = frac_from_seq(seq);
  cout << "The fraction is " << endl;
  cout << f << endl;
  cout << "The digit sum is " << endl;
  cout << f.num.digit_sum() << endl;

  return f.num.digit_sum();
}
