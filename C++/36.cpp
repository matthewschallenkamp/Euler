#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

vector<int>digits(long long n)
{
  vector<int> m;

  while (n > 0)
  {
    m.push_back(n % 10);
    n /= 10;
  }
  return m;
}

bool palindrome(int n)
{
  vector<int> v = digits(n);

  for (int i = 0; i < (v.size() / 2); i++)
  {
    if (!(v.at(i) == v.at(v.size() - i - 1))) return 0;
  }
  return 1;
}

vector<int>b2digits(long long n)
{
  vector<int> m;

  while (n > 0)
  {
    m.push_back(n % 2);
    n /= 2;
  }
  return m;
}

bool b2palindrome(int n)
{
  vector<int> v = b2digits(n);

  for (int i = 0; i < (v.size() / 2); i++)
  {
    if (!(v.at(i) == v.at(v.size() - i - 1))) return 0;
  }
  return 1;
}

int main()
{
  long long sum = 0;
  long long c   = 0;

  for (int i = 0; i < 1000000; i++)
  {
    if (palindrome(i))
      if (b2palindrome(i))
      {
        bitset<sizeof(int) *8> bits = i;
        string s                    = bits.to_string();
        s = i ? s.substr(s.find('1')) : "0";
        //cout << "b10: " << ios::dec << i << endl;
        //cout << "b2: " << s << endl;
        sum += i;
        c++;
      }
  }

  cout << "the count was " << c << "." << endl;
  cout << "the sum was " << sum << "." << endl;

  return sum;
}
