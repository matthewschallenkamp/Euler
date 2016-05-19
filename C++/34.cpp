#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


vector<int> digits(long long n)
{
    vector<int> m;
    while(n > 0)
    {
        m.push_back(n % 10);
        n /= 10;
    }
    return m;
}

long long fact(int n)
{
    long long ret = 1;
    for(;n>1;n--)
        ret *= n;
    return ret;
}

int main()
{
    //nums that are sum of fact of their digits
    //9! = 362880
    //7 * that = 2100000
    //so rough upper bound of 4000000
    vector<int> d;
    long long sum = 0;
    for(long long i = 3; i < 4000000; i++)
    {
        d = digits(i);
        int s = 0;
        for(auto n : d)
            s += fact(n);
        if(s == i)
        {
            sum += s;
            cout << s << endl;
        }
    }

    cout << "the sum was " << sum;

    return 0;
}
