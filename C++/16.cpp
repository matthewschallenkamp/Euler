#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    //sum digits 2^1000
    vector<short> v = {2};
    for(int i = 1; i < 1000; i++)
    {
        for(auto &i : v)
            i *= 2;
        for(int i = 1; i < v.size(); i++)
        {
            if(v[i-1] >= 10)
            {
                v[i-1] -= 10;
                v[i]++;
            }
        }
        if(v.back() >= 10)
        {
            v.back() -= 10;
            v.push_back(1);
        }
        for(auto i : v)
            cout << i;
        cout << endl;
    }
    int t = 0;
    for(auto i : v)
        t += i;
    cout << "the sum of the digits was " << t;
    return 0;
}
