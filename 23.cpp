#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

long long sum_divisors(long long n)
{
    long long sum = 1;
    for(long long i = 2; i < n; i++)
    {
        if(n % i == 0)
            sum += i;
    }
    return sum;
}

int main()
{
    vector<long long> abundants;
    for(long long i = 1; i < 28123; i++)
    {
        if(i < sum_divisors(i))
        {
             abundants.push_back(i);
             cout << i << " is abundant" << endl;
        }
    }
    vector<bool> numbers;
    numbers.resize(28124, true);
    for(int a : abundants)
        for(int b : abundants)
            if(a+b <= 28123)
                numbers[a+b] = false;
    long long sum = 0;
    for(int i = 1; i < numbers.size(); i++)
    {
        if(numbers.at(i))
        {
            cout << "adding " << i << endl;
            sum += i;
        }
    }
    cout << "sum was " << sum;
    return 0;
}
