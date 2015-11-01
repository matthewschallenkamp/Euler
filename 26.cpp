#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

vector<int> unit_fraction(int n, int &cycle_length)
{
    int remainder = 1;
    vector<int> rems = {}, digits = {0};
    while(find(rems.begin(), rems.end(), remainder) == rems.end())
    {
        rems.push_back(remainder);
        remainder *= 10;
        remainder %= n;
        //cout << remainder << endl;
    }
    cycle_length = rems.end() - find(rems.begin(), rems.end(), remainder);
    if(rems.back() == 0)
    {
        cycle_length--;
        rems.pop_back();
    }
    for(int i : rems)
    {
         digits.push_back(10*i / n);
         //cout << i << endl;
    }
    return digits;
    /*
    do
    {
        v.push_back(remainder / n);
        remainder %= n;
        cout << remainder << " : " << remainder / n << endl;
        if(remainder == 0)
            {cout << "here";break;}
        remainder *= 10;
    } while(find(v.begin(), v.end(), remainder / n) == v.end());
    */
}

int main()
{
    int n, c, maxc = 0, maxn = 0;
    for(n = 2; n < 1000; n++)
    {
        vector<int> v = unit_fraction(n, c);
        cout << n << " has cycle " << c << ":\t";
        cout << v[0] << ".";
        for(int i = 1; i < v.size(); i++)
        {
            if(v.size() - i == c && c > 0)
                cout << "(";
            cout << v[i];
        }
        if(c > 0)
            cout << ")";
        cout << endl;
        if(c > maxc)
        {
            //cout << "bigger cycle " << c << endl;
            maxc = c;
            maxn = n;
        }
    }
    cout << "the longest cycle was " << maxc << " coming from " << maxn;
    return 0;
}
