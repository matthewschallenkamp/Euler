#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> digitize(int n);

int factorial(int n);
int sum_factorials(vector<int> v);
int next_step(int n);

int main()
{
  set<int> v;
  int total = 0;
  int step;

  for (int i = 1; i < 1000000; i++)
  {
    // cout << "here" << endl;
    v.clear();
    v.insert(i);
    step = sum_factorials(digitize(i));

    if (!(i % 1000)) cout << "Chaining from " << i << endl;

    while (v.find(step) == v.end() && v.size() <= 60)
    {
      // cout << "did not find " << step << endl;
      v.insert(step);
      step = next_step(step);
    }

    if (v.size() == 60) total++;

    // cout << " gave " << v.size() << " stones" << endl;
  }
  cout << "there is a total of " << total << " chains with length 60" << endl;
  return total;
}

int next_step(int n)
{
  static vector<int> memo(5000000,0);
  if(n < 5000000 && !memo[n])
  {
    memo[n] =  sum_factorials(digitize(n));
  }
  if(n < 5000000)
  {
    return memo[n];
  }
  else
  {
    return sum_factorials(digitize(n));
  }
}

int sum_factorials(vector<int> v)
{
  // cout << "summing" << endl;
  int total = 0;

  for (int i = 0; i < v.size(); i++) total += factorial(v.at(i));
  return total;
}

int factorial(int n)
{
  // cout << "factoring" << endl;
  int total = 1;

  for (int i = 1; i <= n; i++) total *= i;
  return total;
}

vector<int> digitize(int n)
{
  // cout << "digitizing" << endl;
  vector<int> v;

  while (n > 0)
  {
    v.push_back(n % 10);
    n /= 10;
  }
  return v;
}
