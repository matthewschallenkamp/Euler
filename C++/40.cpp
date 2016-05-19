#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

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


int main()
{
    int c = 0;
    int mult = 1;
    int current = 0;
    for(int i = 1; c <= 1000000; i++)
    {
        vector<int> d = digits(i);
        while(d.size() > 0)
        {
            current = d.back();
            d.pop_back();
            c++;
            // i know this is ugly, but it works and more extensible isnt worth
            if(c == 1
               || c == 10
               || c == 100
               || c == 1000
               || c == 10000
               || c == 100000
               || c == 1000000)
            {
                mult *= current;
            }
        }
    }

    cout << mult;

    return 0;
}
