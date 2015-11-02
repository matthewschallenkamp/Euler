#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

vector<long long> pentagonals_to_n(long long n)
{
    static vector<long long> p = {0};
    while(n > p.back())
        p.push_back(p.size()*(3*p.size()-1)/2);
    return p;
}

vector<long long> pentagonals(int n)
{
    static vector<long long> p;
    if(n >= p.size())
    {
        for(int i = p.size(); i <= n; i++)
            p.push_back(i*(3*i-1)/2);
    }
    return p;
}

bool is_pentagonal(long long n)
{
    double t = (sqrt(1 + 24 * n) + 1.0) / 6.0;
    return abs(t - (long long)t) < 0.0001;
}

int main()
{
    /**ok, so some thinking
    we want difference to be minimized
    assume one pentagonal is >than the other
    the difference between two pentagonals increases as their index does
    so loop through the pentagonals
    first two that we find is the answer

    difference between two pentagonals for n and n+m is
    6nm + m^2 - m / 2
    */
    int b, t, d;
    for(int top = 1; top < 27000; top++)
    {
        int topnum = top*(3*top-1)/2;
        for(int dist = top - 1; dist > 0; dist--)
        {
            int botnum = (top-dist)*(3*(top-dist) - 1)/2;
            if(is_pentagonal(botnum+topnum))
            {
                if(is_pentagonal(topnum - botnum))
                {
                    b = top-dist;
                    t = top;
                    d = topnum - botnum;
                    cout << "pentagonal " << t << ": " << topnum << endl;
                    cout << "pentagonal " << b << ": " << botnum << endl;
                    cout << "difference " << d << endl;
                    cout << "sum " << topnum + botnum << endl;
                }
            }
        }
    }
    return 0;
}
